// Tests for the Peer exercise, using the names from p.cpp.
// Put this next to p.cpp, then:
//   g++ -std=c++17 peer_test.cpp -o test && ./test

#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>

// Rename p.cpp's main so this file's main runs instead
#define main original_main
#include "p.cpp"
#undef main

const char *GREEN = "\033[32m";
const char *RED = "\033[31m";
const char *RESET = "\033[0m";

std::ostream *out = nullptr; // where test results go (real terminal)
int total = 0;
int passed = 0;

void check(bool ok, const char *what)
{
    total++;
    *out << "Test " << total << ") " << what << ": ";
    if (ok)
    {
        *out << GREEN << "Passed" << RESET << '\n';
        passed++;
    }
    else
    {
        *out << RED << "Failed" << RESET << '\n';
    }
}

// Runs print() and returns what it printed
std::string printed(const Peer &p)
{
    std::stringstream text;
    std::streambuf *old = std::cout.rdbuf(text.rdbuf());
    p.print();
    std::cout.rdbuf(old);
    return text.str();
}

bool hasPort(const Peer &p, const std::string &port)
{
    return printed(p).find("/ " + port + " /") != std::string::npos;
}

// Only compiles if print/getters are const
void constCheck(const Peer &p)
{
    p.print();
    p.GetId();
    p.GetStatus();
}

// "Peer p = "Sai";" must NOT be allowed
static_assert(!std::is_convertible<const char *, Peer>::value,
              "Constructor is not explicit");

void runTests()
{
    // IDs and count
    Peer a("Alice");
    Peer b("Bob", 9000);
    Peer c("Carol", 80);  // bad port
    Peer d("Dan", 70000); // bad port

    check(a.GetId() == 1 && b.GetId() == 2 && c.GetId() == 3 && d.GetId() == 4,
          "IDs are 1, 2, 3, 4");
    check(Peer::getActiveCount() == 4, "Active count is 4");

    // Ports
    check(hasPort(a, "8080"), "Default port is 8080");
    check(hasPort(b, "9000"), "Valid custom port kept");
    check(hasPort(c, "8080"), "Port 80 falls back to 8080");
    check(hasPort(d, "8080"), "Port 70000 falls back to 8080");

    // State rules
    check(a.GetStatus() == ConnectionStatus::Disconnected, "Starts Disconnected");
    check(!a.startStreaming(), "Can't stream before connecting");
    check(a.GetStatus() == ConnectionStatus::Disconnected, "Still Disconnected after failed stream");

    check(a.connect(), "Connect succeeds (4 peers, at the max)");
    check(a.GetStatus() == ConnectionStatus::Connected, "Status is Connected");
    check(a.startStreaming(), "Stream succeeds after connect");
    check(a.GetStatus() == ConnectionStatus::Streaming, "Status is Streaming");

    check(a.disconnect(), "Disconnect succeeds");
    check(a.GetStatus() == ConnectionStatus::Disconnected, "Back to Disconnected");

    // Max peers
    Peer e("Eve"); // 5th peer, over MAX_PEERS
    check(Peer::getActiveCount() == 5, "Active count is 5");
    check(!e.connect(), "5th peer can't connect");
    check(e.GetStatus() == ConnectionStatus::Disconnected, "5th peer stays Disconnected");

    // Destructor
    {
        Peer temp("Temp");
        check(Peer::getActiveCount() == 6, "Count goes up inside scope");
        check(temp.GetId() == 6, "Temp gets ID 6");
    }
    check(Peer::getActiveCount() == 5, "Count drops after scope ends");

    Peer f("Frank");
    check(f.GetId() == 7, "IDs are not reused (next is 7)");

    // Const methods
    constCheck(b);
    check(true, "print/getters work on a const Peer");
}

int main()
{
    // Send results to the terminal, hide everything Peer prints
    std::ostream terminal(std::cout.rdbuf());
    out = &terminal;
    std::stringstream hidden;
    std::cout.rdbuf(hidden.rdbuf());

    terminal << "== Peer Exercise\n";
    terminal << "== Running tests\n";

    runTests();

    std::cout.rdbuf(terminal.rdbuf()); // restore cout

    const char *color = (passed == total) ? GREEN : RED;
    terminal << "\nRan " << total << "/" << total << " Requested Tests\n";
    terminal << color << "Passed " << passed << "/" << total << " Tests" << RESET << '\n';

    return total - passed;
}