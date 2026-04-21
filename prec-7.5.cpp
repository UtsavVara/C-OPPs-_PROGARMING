#include <iostream>
#include <vector>
using namespace std;

class GradingSystem
{
protected:
    float marks;
    virtual float computeGrade() const = 0; // pure virtual

public:
    void setMarks(float m) { marks = m; }
    float getMarks() const { return marks; }

    float getGrade() const
    {
        return computeGrade();
    }
};

class Undergraduate : public GradingSystem
{
protected:
    float computeGrade() const override
    {
        if (marks >= 90) return 4.0;
        else if (marks >= 80) return 3.0;
        else if (marks >= 70) return 2.0;
        else return 1.0;
    }
};

class Postgraduate : public GradingSystem
{
protected:
    float computeGrade() const override
    {
        if (marks >= 85) return 4.0;
        else if (marks >= 75) return 3.0;
        else if (marks >= 65) return 2.0;
        else return 1.0;
    }
};

int main()
{
    vector<GradingSystem*> students;

    Undergraduate* ug = new Undergraduate();
    ug->setMarks(95);
    students.push_back(ug);

    Postgraduate* pg = new Postgraduate();
    pg->setMarks(68);
    students.push_back(pg);

    for (auto s : students)
    {
        cout << "Marks: " << s->getMarks()
             << ", Grade: " << s->getGrade() << endl;
    }

    for (auto s : students)
        delete s;

    return 0;
}
