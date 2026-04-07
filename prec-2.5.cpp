#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Bank_Loan
{
    string name;
    int loan_id;
    float loan_amount;
    float interest_rate;   
    int tenure;            
public:
    Bank_Loan()
    {
        name = "null";
        loan_id = -1;
        loan_amount = 1000;
        interest_rate = 8;
        tenure = 1;
    }

    Bank_Loan(string user_name_input, int loan_id_input,
              float loan_amount_input, float interest_rate_input,
              int tenure_input)
    {
        name = user_name_input;
        loan_id = loan_id_input;
        loan_amount = loan_amount_input;
        interest_rate = interest_rate_input / 100; 
        tenure = tenure_input;
    }

    float EMI()
    {
        float r = interest_rate;
        float emi = (loan_amount * r * pow(1 + r, tenure)) /
                    (pow(1 + r, tenure) - 1);
        return emi;
    }

    void display()
    {
        cout << "\nUser Name: " << name << endl;
        cout << "Loan ID: " << loan_id << endl;
        cout << "Principal Amount: " << loan_amount << endl;
        cout << "Tenure: " << tenure << endl;
        cout << "Interest Rate: " << interest_rate * 100 << "%" << endl;
        cout << "Loan EMI: " << EMI() << endl;
    }
};

int main()
{
    int choice;
    int t = 0;
    int loan_id;
    string name;
    float loan_amount;
    float interest_rate;
    int tenure;

    Bank_Loan loan[10];

    while (true)
    {
        cout << "\n===== Bank Loan Menu =====" << endl;
        cout << "1. Add User" << endl;
        cout << "2. View Loan Summary" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (t < 10)
            {
                cout << "Enter User Name: ";
                cin.ignore();
                getline(cin, name);

                cout << "Enter Loan Amount: ";
                cin >> loan_amount;

                cout << "Enter Tenure (months): ";
                cin >> tenure;

                cout << "Enter Interest Rate (%): ";
                cin >> interest_rate;

                loan[t] = Bank_Loan(name, t, loan_amount, interest_rate, tenure);
                t++;
            }
            else
            {
                cout << "Maximum Loan Records Reached!" << endl;
            }
            break;

        case 2:
            cout << "Enter Loan ID: ";
            cin >> loan_id;

            if (loan_id >= 0 && loan_id < t)
                loan[loan_id].display();
            else
                cout << "Invalid Loan ID!" << endl;
            break;

        case 3:
            cout << "Thank You! Visit Again." << endl;
            return 0;

        default:
            cout << "Invalid Choice! Try Again." << endl;
        }
    }
}
