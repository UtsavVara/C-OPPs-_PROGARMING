#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

class Sum {
public:
    long long recursiveSum(vector<int>& arr, int n) {
        if (n <= 0) return 0;
        return arr[n - 1] + recursiveSum(arr, n - 1);
    }

    long long iterativeSum(vector<int>& arr) {
        long long sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
        }
        return sum;
    }
};

int main() {
    int n;
    Sum sum;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = 50 + i;
    }

    auto start1 = chrono::high_resolution_clock::now();
    long long rec = sum.recursiveSum(arr, n);
    auto end1 = chrono::high_resolution_clock::now();

    auto start2 = chrono::high_resolution_clock::now();
    long long ite = sum.iterativeSum(arr);
    auto end2 = chrono::high_resolution_clock::now();

    chrono::duration<double> t1 = end1 - start1;
    chrono::duration<double> t2 = end2 - start2;

    cout << "Recursive Sum: " << rec << endl;
    cout << "Iterative Sum: " << ite << endl;
    cout << "Time Recursive: " << t1.count() << endl;
    cout << "Time Iterative: " << t2.count() << endl;

    return 0;
}
