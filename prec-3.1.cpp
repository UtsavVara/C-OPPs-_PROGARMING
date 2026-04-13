#include <iostream>
using namespace std;

class EmployeePayroll {
    string name;
    float salary, bonus;

public:
    EmployeePayroll() {}

    EmployeePayroll(string n, float s, float b) {
        name = n;
        salary = s;
        bonus = b;
    }

    void getName() {
        cout << name;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total: " << salary + bonus << endl;
    }
};

int main() {
    EmployeePayroll emp[10];
    int choice, t = 0, id;
    string name;
    float salary, bonus;

start:
    cout << "\n1.Add\n2.List\n3.View\n4.Exit\n";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Salary: ";
        cin >> salary;
        cout << "Bonus: ";
        cin >> bonus;

        emp[t] = EmployeePayroll(name, salary, bonus);
        cout << "ID: " << t << endl;
        t++;
        goto start;

    case 2:
        for (int i = 0; i < t; i++) {
            cout << "ID: " << i << " Name: ";
            emp[i].getName();
            cout << endl;
        }
        goto start;

    case 3:
        cout << "Enter ID: ";
        cin >> id;
        emp[id].display();
        goto start;

    case 4:
        cout << "Exit...\n";
    }
}
