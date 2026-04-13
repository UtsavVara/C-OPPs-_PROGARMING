#include <iostream>
using namespace std;

class Bank_Account {
public:
    static int number;
    double acct_no;
    string name;
    double balance;

    Bank_Account() {}

    Bank_Account(string n, double b) {
        name = n;
        balance = b;
        acct_no = 1000 + number;
    }

    int search_account(double acc) {
        return acct_no == acc;
    }

    void view_bal() {
        cout << "Balance: " << balance << endl;
    }

    void deposit() {
        double amt;
        cout << "Enter amount: ";
        cin >> amt;
        balance += amt;
    }

    void withdraw() {
        double amt;
        cout << "Enter amount: ";
        cin >> amt;
        if (amt <= balance)
            balance -= amt;
        else
            cout << "Insufficient Balance!" << endl;
    }
};

int Bank_Account::number = 0;

int main() {
    Bank_Account user[10];
    int choice, i;
    double acc;
    string name;
    double bal;

menu:
    cout << "\n1.Create\n2.View\n3.Deposit\n4.Withdraw\n5.Exit\n";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Balance: ";
        cin >> bal;

        user[Bank_Account::number] = Bank_Account(name, bal);
        cout << "Account No: " << user[Bank_Account::number].acct_no << endl;
        Bank_Account::number++;
        goto menu;

    case 2:
        cout << "Enter Account No: ";
        cin >> acc;
        for (i = 0; i < Bank_Account::number; i++) {
            if (user[i].search_account(acc)) {
                user[i].view_bal();
                break;
            }
        }
        if (i == Bank_Account::number)
            cout << "Not Found\n";
        goto menu;

    case 3:
        cout << "Enter Account No: ";
        cin >> acc;
        for (i = 0; i < Bank_Account::number; i++) {
            if (user[i].search_account(acc)) {
                user[i].deposit();
                break;
            }
        }
        goto menu;

    case 4:
        cout << "Enter Account No: ";
        cin >> acc;
        for (i = 0; i < Bank_Account::number; i++) {
            if (user[i].search_account(acc)) {
                user[i].withdraw();
                break;
            }
        }
        goto menu;

    case 5:
        cout << "Exit...\n";
    }
}
