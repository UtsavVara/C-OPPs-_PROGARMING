#include <iostream>
using namespace std;

template <class T>
void display(T arr[], int n)
{
    cout << "Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

template <class T>
void reverseArray(T arr[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        T temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

template <class T>
T findMax(T arr[], int n)
{
    T max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

template <class T>
void findLeaders(T arr[], int n)
{
    cout << "Leader elements: ";

    T maxRight = arr[n - 1];
    cout << maxRight << " ";

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > maxRight)
        {
            maxRight = arr[i];
            cout << maxRight << " ";
        }
    }
    cout << endl;
}

int main()
{
    int arr1[] = {16, 17, 4, 3, 5, 2};
    float arr2[] = {1.1, 2.5, 0.5, 3.2, 2.0};
    char arr3[] = {'a', 'z', 'b', 'y', 'c'};

    int n1 = 6, n2 = 5, n3 = 5;

    cout << "\n--- Integer Array ---\n";
    display(arr1, n1);
    cout << "Max: " << findMax(arr1, n1) << endl;
    reverseArray(arr1, n1);
    display(arr1, n1);
    findLeaders(arr1, n1);

    cout << "\n--- Float Array ---\n";
    display(arr2, n2);
    cout << "Max: " << findMax(arr2, n2) << endl;
    reverseArray(arr2, n2);
    display(arr2, n2);
    findLeaders(arr2, n2);

    cout << "\n--- Character Array ---\n";
    display(arr3, n3);
    cout << "Max: " << findMax(arr3, n3) << endl;
    reverseArray(arr3, n3);
    display(arr3, n3);
    findLeaders(arr3, n3);

    return 0;
}
