#include <iostream>
using namespace std;

class Student
{
    string name;
    int roll_no;
    float m1, m2, m3;

public:
    Student()
    {
        name = "Not Assigned";
        roll_no = 0;
        m1 = m2 = m3 = 0;
    }

    Student(string input_name, int roll, float marks1, float marks2, float marks3)
    {
        name = input_name;
        roll_no = roll;
        m1 = marks1;
        m2 = marks2;
        m3 = marks3;
    }

    void display()
    {
        cout << "\nName: " << name << endl;
        cout << "Roll No: " << roll_no << endl;
    }

    void get_average_marks()
    {
        float avg = (m1 + m2 + m3) / 3;
        cout << "Average Marks: " << avg << endl;
    }
};

int main()
{
    Student s1;  // Default Constructor
    Student s2("Megh", 99, 95.5, 94.8, 100);  // Parameterized Constructor

    cout << "Student 1 Details:" << endl;
    s1.display();
    s1.get_average_marks();

    cout << "\nStudent 2 Details:" << endl;
    s2.display();
    s2.get_average_marks();

    return 0;
}
