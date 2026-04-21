#include <iostream>
#include <vector>
using namespace std;

// ---------- Base Class ----------
class Person
{
protected:
    string name;
    int age;

public:
    Person(string n = "", int a = 0)
    {
        name = n;
        age = a;
    }

    string getName()
    {
        return name;
    }

    void display()
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// ---------- Derived Class ----------
class Employee : public Person
{
protected:
    int empID;

public:
    Employee(int id = 0, string n = "", int a = 0)
        : Person(n, a)
    {
        empID = id;
    }

    void display()
    {
        cout << "Employee ID: " << empID
             << ", Name: " << name
             << ", Age: " << age << endl;
    }
};

// ---------- Derived Class ----------
class Manager : public Employee
{
private:
    string department;

public:
    Manager(string dept = "", int id = 0, string n = "", int a = 0)
        : Employee(id, n, a)
    {
        department = dept;
    }

    void display()
    {
        cout << "Manager ID: " << empID
             << ", Name: " << name
             << ", Age: " << age
             << ", Department: " << department << endl;
    }
};

// ---------- MAIN ----------
int main()
{
    vector<Person> persons;
    vector<Employee> employees;
    vector<Manager> managers;

    int choice;

    while (true)
    {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Add Person" << endl;
        cout << "2. Add Employee" << endl;
        cout << "3. Add Manager" << endl;
        cout << "4. Display Names" << endl;
        cout << "5. Display Details" << endl;
        cout << "6. Exit" << endl;

        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                string name;
                int age;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Age: ";
                cin >> age;

                persons.push_back(Person(name, age));
                break;
            }

            case 2:
            {
                string name;
                int age;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Age: ";
                cin >> age;

                int id = employees.size() + 1;
                employees.push_back(Employee(id, name, age));
                break;
            }

            case 3:
            {
                string name, dept;
                int age;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter Department: ";
                cin >> dept;

                int id = managers.size() + 1;
                managers.push_back(Manager(dept, id, name, age));
                break;
            }

            case 4:
            {
                cout << "\nPersons:\n";
                for (int i = 0; i < persons.size(); i++)
                {
                    cout << i + 1 << ". " << persons[i].getName() << endl;
                }

                cout << "\nEmployees:\n";
                for (int i = 0; i < employees.size(); i++)
                {
                    cout << i + 1 << ". " << employees[i].getName() << endl;
                }

                cout << "\nManagers:\n";
                for (int i = 0; i < managers.size(); i++)
                {
                    cout << i + 1 << ". " << managers[i].getName() << endl;
                }
                break;
            }

            case 5:
            {
                int type, id;
                cout << "1. Person\n2. Employee\n3. Manager\n";
                cout << "Enter type: ";
                cin >> type;
                cout << "Enter ID: ";
                cin >> id;

                if (type == 1 && id <= persons.size())
                    persons[id - 1].display();
                else if (type == 2 && id <= employees.size())
                    employees[id - 1].display();
                else if (type == 3 && id <= managers.size())
                    managers[id - 1].display();
                else
                    cout << "Invalid ID!" << endl;

                break;
            }

            case 6:
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
