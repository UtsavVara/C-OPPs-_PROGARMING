#include <iostream>
using namespace std;

class BankAccount
{
    double balance;

public:
    BankAccount(double b)
    {
        balance = b;
        cout << "Account Created\n";
    }

    void deposit(double amt)
    {
        if (amt <= 0)
        {
            cout << "Invalid deposit!\n";
            return;
        }
        balance += amt;
        cout << "Deposited: " << amt << endl;
    }

    void withdraw(double amt)
    {
        if (amt <= 0)
        {
            cout << "Invalid withdraw!\n";
            return;
        }
        if (amt > balance)
        {
            cout << "Insufficient funds!\n";
            return;
        }
        balance -= amt;
        cout << "Withdrawn: " << amt << endl;
    }

    void show()
    {
        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount acc(100);

    acc.deposit(50);
    acc.withdraw(200);
    acc.show();

    return 0;
}
