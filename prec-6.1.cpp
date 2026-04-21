#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Shape {
protected:
    double radius;

public:
    void setRadius(double r) {
        radius = r;
    }

    double getRadius() {
        return radius;
    }
};

class Circle : public Shape {
public:
    double calculateArea() {
        return M_PI * radius * radius;
    }
};

int main() {
    int n;

    cout << "Enter number of circles: ";
    cin >> n;


    vector<Circle> dynamicCircles(n);

    cout << "\nEnter radius for dynamic method:\n";
    for (int i = 0; i < n; i++) {
        double r;
        cout << "Circle " << i + 1 << ": ";
        cin >> r;
        dynamicCircles[i].setRadius(r);
    }

    cout << "\nAreas (Dynamic Method):\n";
    for (int i = 0; i < n; i++) {
        cout << "Circle " << i + 1 << " Area = "
             << dynamicCircles[i].calculateArea() << endl;
    }


    Circle staticCircles[100];

    cout << "\nEnter radius for static method:\n";
    for (int i = 0; i < n; i++) {
        double r;
        cout << "Circle " << i + 1 << ": ";
        cin >> r;
        staticCircles[i].setRadius(r);
    }

    cout << "\nAreas (Static Method):\n";
    for (int i = 0; i < n; i++) {
        cout << "Circle " << i + 1 << " Area = "
             << staticCircles[i].calculateArea() << endl;
    }

    return 0;
}
