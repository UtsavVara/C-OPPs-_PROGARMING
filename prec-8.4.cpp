#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    ifstream file("data.txt");
    string line;
    int lineNo = 1;

    if (!file)
    {
        cout << "File not found!\n";
        return 0;
    }

    while (getline(file, line))
    {
        stringstream ss(line);
        string word;
        double num, sum = 0;
        bool valid = true;
        int count = 0;

        while (ss >> word)
        {
            stringstream check(word);

            if (!(check >> num) || !(check.eof()))
            {
                cout << "Line " << lineNo
                     << " is invalid (non-numeric data: '"
                     << word << "'). Skipping.\n";
                valid = false;
                break;
            }

            sum += num;
            count++;
        }

        if (valid)
        {
            if (count == 0)
                cout << "Line " << lineNo
                     << " is empty or contains no numbers. Skipping.\n";
            else
                cout << "Line " << lineNo << " sum: " << sum << endl;
        }

        lineNo++;
    }

    file.close();
    return 0;
}
