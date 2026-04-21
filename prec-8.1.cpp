#include <iostream>
using namespace std;

int main()
{
    double a, b;
    cin >> a >> b;

    try
    {
        if (b == 0)
            throw "Division by zero!";

        cout << "Result = " << a / b;
    }
    catch (const char* msg)
    {
        cout << msg;
    }

    return 0;
}
