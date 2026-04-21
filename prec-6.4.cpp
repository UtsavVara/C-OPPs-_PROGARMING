#include <iostream>
#include <vector>
using namespace std;

class Account
{
protected:
    long long accNo;
    double balance;
    vector<string> history;

public:
    Account(long long a = 0, double b = 0) { accNo = a; balance = b; }

    long long getAcc() { return accNo; }

    void deposit(double amt)
    {
        if (amt <= 0) return;
        balance += amt;
        history.push_back("Deposited: " + to_string(amt));
        cout << "Deposited: " << amt << endl;
    }

    void withdraw(double amt)
    {
        if (amt > balance || amt <= 0) return;
        balance -= amt;
        history.push_back("Withdrawn: " + to_string(amt));
        cout << "Withdrawn: " << amt << endl;
    }

    void show()
    {
        cout << "Account: " << accNo << " Balance: " << balance << endl;
    }

    void transactions()
    {
        for (auto t : history) cout << t << endl;
    }

    void undo()
    {
        if (history.empty()) return;
        string last = history.back();
        history.pop_back();

        double amt = stod(last.substr(last.find(":") + 2));
        if (last[0] == 'D') balance -= amt;
        else balance += amt;

        cout << "Undo: " << last << endl;
    }
};

int main()
{
    vector<Account> accs;
    int ch;
    long long acc;
    double amt;

    while (true)
    {
        cout << "\n 1.Add\n 2.Deposit\n 3.Withdraw\n 4.Balance\n 5.Transactions\n 6.Undo\n 7.Exit\n";
        cin >> ch;

        if (ch == 7) break;

        if (ch == 1)
        {
            cout << "Enter acc no & balance: ";
            cin >> acc >> amt;
            accs.push_back(Account(acc, amt));
        }
        else
        {
            cout << "Enter acc no: ";
            cin >> acc;

            int i;
            for (i = 0; i < accs.size(); i++)
                if (accs[i].getAcc() == acc) break;

            if (i == accs.size())
            {
                cout << "Account not found!\n";
                continue;
            }

            if (ch == 2)
            {
                cout << "Enter amount: ";
                cin >> amt;
                accs[i].deposit(amt);
            }
            else if (ch == 3)
            {
                cout << "Enter amount: ";
                cin >> amt;
                accs[i].withdraw(amt);
            }
            else if (ch == 4)
                accs[i].show();
            else if (ch == 5)
                accs[i].transactions();
            else if (ch == 6)
                accs[i].undo();
        }
    }
}
