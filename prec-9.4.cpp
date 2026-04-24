#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    map<string, vector<string>> dir;
    int choice;
    string folder, file;

    while (true)
    {
        cout << "\n1. Add Folder\n2. Add File\n3. Display Directory\n4. Exit\n";
        cin >> choice;

        if (choice == 4) break;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter folder name: ";
            cin >> folder;

            if (dir.find(folder) != dir.end())
                cout << "Folder already exists!\n";
            else
            {
                dir[folder];
                cout << "Folder added!\n";
            }
            break;
        }

        case 2:
        {
            cout << "Enter folder name: ";
            cin >> folder;

            if (dir.find(folder) == dir.end())
            {
                cout << "Folder not found!\n";
                break;
            }

            cout << "Enter file name: ";
            cin >> file;

            dir[folder].push_back(file);
            cout << "File added!\n";
            break;
        }

        case 3:
        {
            cout << "\nDirectory Structure:\n";

            for (auto it = dir.begin(); it != dir.end(); it++)
            {
                cout << "Folder: " << it->first << endl;

                for (auto f : it->second)
                    cout << "  - " << f << endl;
            }
            break;
        }

        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
