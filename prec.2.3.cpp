#include <iostream>
#include <string>
using namespace std;

class Bank_Account
{
    string account_holder_name;
    long double balance; 
    int acct_no; 

public:
    Bank_Account()
    {
        account_holder_name = "null";
        balance = 0;
        acct_no = -1;
    }

    Bank_Account(string name, long double bal, int id)
    {
        account_holder_name = name;
        balance = bal;
        acct_no = id;
        cout << "Your Account Number is: " << id << endl;
    }

    bool search_account(int account_no_input)
    {
        return acct_no == account_no_input;
    }

    void withdraw()
    {
        long double amount;
        cout << "Enter Amount to Withdraw: ";
        cin >> amount;

        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawal Successful!" << endl;
        }
        else
        {
            cout << "Insufficient Funds or Invalid Amount!" << endl;
        }
    }

    void deposit()
    {
        long double amount;
        cout << "Enter Amount to Deposit: ";
        cin >> amount;

        if (amount > 0)
        {
            balance += amount;
            cout << "Deposit Successful!" << endl;
        }
        else
        {
            cout << "Invalid Amount!" << endl;
        }
    }

    void view_bal()
    {
        cout << "\nAccount Holder: " << account_holder_name << endl;
        cout << "Current Balance: Rs. " << balance << endl;
    }
};

int main()
{
    int choice, i;
    int t = 0;
    int acct_no;
    string name;
    long double balance;

    Bank_Account user[10];

    while (true)
    {
        cout << "\n===== Welcome to the Bank =====" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. View Balance" << endl;
        cout << "3. Deposit Money" << endl;
        cout << "4. Withdraw Money" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (t < 10)
            {
                cout << "Enter User's Name: ";
                cin.ignore();
                getline(cin, name);

                cout << "Enter Initial Balance: ";
                cin >> balance;

                user[t] = Bank_Account(name, balance, t);
                t++;
            }
            else
            {
                cout << "Maximum Accounts Reached!" << endl;
            }
            break;

        case 2:
            cout << "Enter Account Number: ";
            cin >> acct_no;

            for (i = 0; i < t; i++)
            {
                if (user[i].search_account(acct_no))
                {
                    user[i].view_bal();
                    break;
                }
            }
            if (i == t)
                cout << "Account Not Found!" << endl;
            break;

        case 3:
            cout << "Enter Account Number: ";
            cin >> acct_no;

            for (i = 0; i < t; i++)
            {
                if (user[i].search_account(acct_no))
                {
                    user[i].deposit();
                    break;
                }
            }
            if (i == t)
                cout << "Account Not Found!" << endl;
            break;

        case 4:
            cout << "Enter Account Number: ";
            cin >> acct_no;

            for (i = 0; i < t; i++)
            {
                if (user[i].search_account(acct_no))
                {
                    user[i].withdraw();
                    break;
                }
            }
            if (i == t)
                cout << "Account Not Found!" << endl;
            break;

        case 5:
            cout << "Thank You! Visit Again." << endl;
            return 0;

        default:
            cout << "Invalid Choice! Try Again." << endl;
        }
    }
}
