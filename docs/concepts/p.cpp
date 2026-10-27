// So we need a comapny and then the employees (struct)

#include <string.h>
#include <iostream>

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
