#include <iostream>
using namespace std;

class Rectangle
{
    int rectangle_id;
    float length, breadth;

public:
    void area();
    void perimeter();
    void update_dimensions();
    void display_rectangle();
    void set_rectangle_data(int id);
};

void Rectangle::area()
{
    cout << "Area is: " << length * breadth << endl;
}

void Rectangle::perimeter()
{
    cout << "Perimeter is: " << 2 * (length + breadth) << endl;
}

void Rectangle::update_dimensions()
{
    cout << "Enter New Length: ";
    cin >> length;
    cout << "Enter New Breadth: ";
    cin >> breadth;
}

void Rectangle::display_rectangle()
{
    cout << "Rectangle ID: " << rectangle_id
         << " | Length: " << length
         << " | Breadth: " << breadth << endl;
}

void Rectangle::set_rectangle_data(int id)
{
    rectangle_id = id;
    cout << "Enter Length: ";
    cin >> length;
    cout << "Enter Breadth: ";
    cin >> breadth;
}

int main()
{
    int choice, i, rect_no_input, t = 0;
    Rectangle rect[10];

    while (true)
    {
        cout << "\n===== Rectangle Menu =====" << endl;
        cout << "1. Add Rectangle" << endl;
        cout << "2. Change Rectangle Dimensions" << endl;
        cout << "3. Display Rectangles" << endl;
        cout << "4. Calculate Area" << endl;
        cout << "5. Calculate Perimeter" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (t < 10)
            {
                rect[t].set_rectangle_data(t);
                t++;
            }
            else
            {
                cout << "Maximum limit reached!" << endl;
            }
            break;

        case 2:
            cout << "Enter Rectangle ID: ";
            cin >> rect_no_input;
            if (rect_no_input >= 0 && rect_no_input < t)
                rect[rect_no_input].update_dimensions();
            else
                cout << "Invalid Rectangle ID!" << endl;
            break;

        case 3:
            for (i = 0; i < t; i++)
                rect[i].display_rectangle();
            break;

        case 4:
            cout << "Enter Rectangle ID: ";
            cin >> rect_no_input;
            if (rect_no_input >= 0 && rect_no_input < t)
                rect[rect_no_input].area();
            else
                cout << "Invalid Rectangle ID!" << endl;
            break;

        case 5:
            cout << "Enter Rectangle ID: ";
            cin >> rect_no_input;
            if (rect_no_input >= 0 && rect_no_input < t)
                rect[rect_no_input].perimeter();
            else
                cout << "Invalid Rectangle ID!" << endl;
            break;

        case 6:
            cout << "Thank You!" << endl;
            return 0;

        default:
            cout << "Invalid Choice! Try Again." << endl;
        }
    }
}
