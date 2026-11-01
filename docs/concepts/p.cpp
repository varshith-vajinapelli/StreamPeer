// So we need a comapny and then the employees (struct)
#include <iostream>
#include <string.h>
/*

enum class Status
{
    active,
    onleave,
    terminated,
};

struct Employee
{
    int id{};
    std::string name{};
    int age{};
    double hourlyWage{};
    Status status{};

    bool updateHourlyWage(double wage)
    {
        hourlyWage = wage;
        return true;
    }
};

void displayEmployeeDetails(const Employee &employee)
{
    std::cout << "Employee Details\n";
    std::cout << "-----------------------------------\n";
    std::cout << "Employee ID:     " << employee.id << "\n";
    std::cout << "Name:            " << employee.name << "\n";
    std::cout << "Age:             " << employee.age << "\n";
    std::cout << "Hourly Wage:     $" << employee.hourlyWage << "\n";
    std::cout << "-----------------------------------\n";
}

void printStatus(Status status)
{
    switch (status)
    {
    case Status::active:
        std::cout << "Active";
        break;

    case Status::onleave:
        std::cout << "On Leave";
        break;

    case Status::terminated:
        std::cout << "Terminated";
        break;
    }
}

Employee createEmployee(int id, const std::string &name, int age, double hourlyWage, Status status)
{
    return {id, name, age, hourlyWage, status};
};

void updateEmployeeStatus(Employee &employee, Status status)
{
    employee.status = status;
    printStatus(employee.status);
};

int main()
{
    Employee e1 = createEmployee(101, "John", 25, 20.0, Status::active);
    displayEmployeeDetails(e1);

    e1.updateHourlyWage(25);

    displayEmployeeDetails(e1);
}
*/

// We're building Peer class for StreamPeer
enum class ConnectionStatus
{
    Disconnected,
    Connected,
    Streaming,
};

class Peer
{

public:
    static int LivePeerCount;
    static constexpr int MAX_PEERS = 4;

    static int getActiveCount()
    {
        return LivePeerCount;
    }

    void print() const
    {
        std::string status;
        switch (m_status)
        {
        case ConnectionStatus::Disconnected:
            status = "Disconnected";
            break;
        case ConnectionStatus::Connected:
            status = "Connected";
            break;
        case ConnectionStatus::Streaming:
            status = "Streaming";
            break;
        }

        std::cout << m_id << " / " << m_name << " / " << m_port << " / " << status << '\n';
    }

    int GetId() const
    {
        return m_id;
    }

    ConnectionStatus GetStatus() const
    {
        return m_status;
    }

    explicit Peer(const std::string &name, int port = 8080)
    {
        m_name = name;
        m_port = port;

        if (port < 1024 || port > 65535)
        {
            m_port = 8080;
        }

        // Assign the Unique ID
        m_id = ++Id;
        LivePeerCount++;
        std::cout << "Created Peer" << std::endl;
    }

    // Destructor
    ~Peer()
    {
        LivePeerCount--;
        std::cout << "Cleaning all the resources, Destroyed Peer!" << std::endl;
    }

    bool connect()
    {
        if (LivePeerCount > MAX_PEERS)
        {
            return false;
        }

        m_status = ConnectionStatus::Connected;
        return true;
    }

    bool startStreaming()
    {
        if (m_status != ConnectionStatus::Connected)
        {
            return false;
        }

        m_status = ConnectionStatus::Streaming;
        return true;
    }

    bool disconnect()
    {
        m_status = ConnectionStatus::Disconnected;
        return true;
    }

private:
    static int Id;

    int m_id{};
    std::string m_name{};
    int m_port{};
    ConnectionStatus m_status{ConnectionStatus::Disconnected};
};

int Peer::LivePeerCount = 0;
int Peer::Id = 0;

int main()
{
    // when we get a request from the frontend, new peer has joined so we make a new object
    // get and lods details from db adn pour into the object construtor and the object is created

    // So we're build a single connected peer right now!
    // Create a Peer Object usig the member intizilation list

    std::cout << "Live Peer Count: " << Peer::LivePeerCount << std::endl;
    Peer a{"v1", 7387};
    Peer b{"v2", 10};
    Peer c{"v3", 1414141};
    std::cout << "Live Peer Count: " << Peer::LivePeerCount << std::endl;

    {
        Peer d{"v8", 5000};
        std::cout << "Live Peer Count: " << Peer::LivePeerCount << std::endl;
    }

    std::cout << "Live Peer Count: " << Peer::LivePeerCount << std::endl;
    return 0;
}
