
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter Size of Sorted Array 1: ";
    cin >> m;
    int* arr1 = new int[m];
    cout << "Enter Elements of Sorted Array 1: ";
    for (int i = 0; i < m; i++) {
        cin >> arr1[i];
    }
    cout << "Enter Size of Sorted Array 2: ";
    cin >> n;
    int* arr2 = new int[n];
    cout << "Enter Elements of Sorted Array 2: ";
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }
    int* merged = new int[m + n];
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    while (i < m) {
        merged[k++] = arr1[i++];
    }
    while (j < n) {
        merged[k++] = arr2[j++];
    }
    cout << "Merged Array: ";
    for (int i = 0; i < m + n; i++) {
        cout << merged[i] << " ";
    }
    cout << endl;
    return 0;
}

