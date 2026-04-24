#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int n, x;
    set<int> s;
    vector<int> v;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
        s.insert(x);
    }

    cout << "\nUnique elements (using set): ";
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }

    vector<int> uniqueVec(s.begin(), s.end());

    cout << "\nUnique elements (converted to vector): ";
    for (auto i : uniqueVec)
        cout << i << " ";

    return 0;
}
