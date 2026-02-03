#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    string holderName;
    long long accountNo;
    double balance;

public:
    void createAccount()
    {
        cout << "\nEnter Account Holder Name: ";
        cin.ignore();
        getline(cin, holderName);

        cout << "Enter Account Number: ";
        cin >> accountNo;

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    bool searchAccount(long long accNo)
    {
        return accNo == accountNo;
    }

    void depositMoney()
    {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        balance += amount;
        cout << "Amount deposited successfully:)\n";
    }

    void withdrawMoney()
    {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawal successful:)\n";
        }
        else
        {
            cout << "Insufficient balance:(\n";
        }
    }

    void checkBalance()
    {
        cout << "\n--- Account Details ---\n";
        cout << "Name: " << holderName << endl;
        cout << "Account Number: " << accountNo << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount accounts[15];
    int count = 0;
    int choice;

    while (true)
    {
        cout << "\n===== BANK MENU =====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            if (count < 15)
            {
                accounts[count].createAccount();
                count++;
            }
            else
            {
                cout << "Account limit reached!\n";
            }
        }
        else if (choice == 2 || choice == 3 || choice == 4)
        {
            long long accNo;
            cout << "Enter Account Number: ";
            cin >> accNo;

            bool found = false;
            for (int i = 0; i < count; i++)
            {
                if (accounts[i].searchAccount(accNo))
                {
                    found = true;
                    if (choice == 2) accounts[i].depositMoney();
                    else if (choice == 3) accounts[i].withdrawMoney();
                    else accounts[i].checkBalance();
                    break;
                }
            }
            if (!found) cout << "Account not found!\n";
        }
        else if (choice == 5)
        {
            cout << "Thank you for using bank system.\n";
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
