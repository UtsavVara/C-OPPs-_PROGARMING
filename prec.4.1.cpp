#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;

public:
    // Constructor
    DynamicArray() {
        arr = nullptr;
        size = 0;
    }

    // Insert at end
    void insertEnd(int value) {
        int* newArr = new int[size + 1];

        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        newArr[size] = value;

        delete[] arr;
        arr = newArr;
        size++;

        cout << "Inserted at end\n";
    }

    // Insert at specific index
    void insertAt(int index, int value) {
        if (index < 0 || index > size) {
            cout << "Invalid index!\n";
            return;
        }

        int* newArr = new int[size + 1];

        for (int i = 0, j = 0; i < size + 1; i++) {
            if (i == index) {
                newArr[i] = value;
            } else {
                newArr[i] = arr[j++];
            }
        }

        delete[] arr;
        arr = newArr;
        size++;

        cout << "Inserted at position " << index << endl;
    }

    // Delete at index
    void deleteAt(int index) {
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }

        if (index < 0 || index >= size) {
            cout << "Invalid index!\n";
            return;
        }

        int* newArr = new int[size - 1];

        for (int i = 0, j = 0; i < size; i++) {
            if (i != index) {
                newArr[j++] = arr[i];
            }
        }

        delete[] arr;
        arr = newArr;
        size--;

        cout << "Deleted element at index " << index << endl;
    }

    // Search element
    void search(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                cout << "Element found at index: " << i << endl;
                return;
            }
        }
        cout << "Element not found\n";
    }

    // Count occurrences
    void countOccurrences(int value) {
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] == value)
                count++;
        }
        cout << "Occurrences of " << value << " = " << count << endl;
    }

    // Display array
    void display() {
        if (size == 0) {
            cout << "Array is empty\n";
            return;
        }

        cout << "Array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~DynamicArray() {
        delete[] arr;
    }
};

int main() {
    DynamicArray da;
    int choice, value, index;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert at End\n";
        cout << "2. Insert at Index\n";
        cout << "3. Delete at Index\n";
        cout << "4. Search Element\n";
        cout << "5. Count Occurrences\n";
        cout << "6. Display Array\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            da.insertEnd(value);
            da.display();
            break;

        case 2:
            cout << "Enter index and value: ";
            cin >> index >> value;
            da.insertAt(index, value);
            da.display();
            break;

        case 3:
            cout << "Enter index: ";
            cin >> index;
            da.deleteAt(index);
            da.display();
            break;

        case 4:
            cout << "Enter value to search: ";
            cin >> value;
            da.search(value);
            break;

        case 5:
            cout << "Enter value: ";
            cin >> value;
            da.countOccurrences(value);
            break;

        case 6:
            da.display();
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
