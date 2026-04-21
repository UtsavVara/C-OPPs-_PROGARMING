#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double num;

    while (true)
    {
        cout << "Enter a number: ";
        cin >> num;

        try
        {
            if (num < 0)
                throw "Negative numbers are not allowed.";

            cout << "Square root of " << num
                 << " is " << sqrt(num) << endl;
        }
        catch (const char* msg)
        {
            cout << msg << endl;
        }
    }

    return 0;
}
