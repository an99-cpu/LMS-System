#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ==========================
// BASE CLASS (POLYMORPHISM)
// ==========================
class Person {
protected:
    int id;
    string name;

public:
    Person(int i, string n) : id(i), name(n) {}

    virtual void displayInfo() const {
        cout << "ID: " << id << ", Name: " << name << endl;
    }

    virtual ~Person() {}
};

// ==========================
// STUDENT
// ==========================
class Student : public Person {
private:
    vector<float> grades;

public:
    Student(int i, string n) : Person(i, n) {}

    void addGrade(float g) {
        grades.push_back(g);
    }

    float getAverage() const {
        if (grades.empty()) return 0;

        float sum = 0;
        for (float g : grades)
            sum += g;

        return sum / grades.size();
    }

    void displayInfo() const override {
        cout << "\n--- STUDENT ---\n";
        Person::displayInfo();
        cout << "Average Grade: " << getAverage() << endl;
    }
};

// ==========================
// INSTRUCTOR
// ==========================
class Instructor : public Person {
private:
    string department;

public:
    Instructor(int i, string n, string d)
        : Person(i, n), department(d) {}

    void displayInfo() const override {
        cout << "\n--- INSTRUCTOR ---\n";
        Person::displayInfo();
        cout << "Department: " << department << endl;
    }
};

// ==========================
// COURSE
// ==========================
class Course {
private:
    int courseId;
    string title;
    Instructor* instructor;
    vector<Student*> students;

public:
    Course(int id, string t, Instructor* ins)
        : courseId(id), title(t), instructor(ins) {}

    void enrollStudent(Student* s) {
        students.push_back(s);
        cout << "Student enrolled in " << title << endl;
    }

    void displayInfo() const {
        cout << "\n--- COURSE ---\n";
        cout << "ID: " << courseId << endl;
        cout << "Title: " << title << endl;
        cout << "Instructor: ";
        instructor->displayInfo();

        cout << "Students Enrolled: " << students.size() << endl;
    }
};

// ==========================
// MAIN (REAL POLYMORPHISM)
// ==========================
int main() {

    cout << "===== SMART LMS SYSTEM =====\n";

    // 🔥 REAL POLYMORPHISM
    Person* p1 = new Student(101, "Ahmed");
    Person* p2 = new Instructor(1, "Dr. Ali", "Computer Science");

    p1->displayInfo();
    p2->displayInfo();

    cout << "\n===========================\n";

    // REAL SYSTEM
    Instructor* ins = new Instructor(1, "Dr. Ali", "CS");

    Student* s1 = new Student(101, "Ahmed");
    Student* s2 = new Student(102, "Sara");

    Course c1(10, "OOP in C++", ins);

    c1.enrollStudent(s1);
    c1.enrollStudent(s2);

    s1->addGrade(90);
    s1->addGrade(85);

    s2->addGrade(88);
    s2->addGrade(92);

    c1.displayInfo();

    cout << "\n===========================\n";

    delete p1;
    delete p2;
    delete ins;
    delete s1;
    delete s2;

    return 0;
}