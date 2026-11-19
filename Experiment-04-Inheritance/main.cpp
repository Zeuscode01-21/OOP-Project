#include <iostream>
#include <string>
using namespace std;

// Single inheritance: Student inherits from Person.
// Multilevel inheritance: GraduateStudent inherits from Student.
class Person {
protected:
    string name;
    int age;

public:
    Person(const string& personName, int personAge)
        : name(personName), age(personAge) {}

    void displayPerson() const {
        cout << "Name: " << name << "\nAge: " << age << '\n';
    }
};

class Student : public Person {
protected:
    int rollNumber;
    string course;

public:
    Student(const string& name, int age, int roll, const string& courseName)
        : Person(name, age), rollNumber(roll), course(courseName) {}

    void displayStudent() const {
        displayPerson();
        cout << "Roll number: " << rollNumber << "\nCourse: " << course << '\n';
    }
};

class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    GraduateStudent(const string& name, int age, int roll,
                    const string& courseName, const string& topic)
        : Student(name, age, roll, courseName), researchTopic(topic) {}

    void display() const {
        cout << "=== Graduate Student Record ===\n";
        displayStudent();
        cout << "Research topic: " << researchTopic << '\n';
    }
};

int main() {
    GraduateStudent student("Ananya Patil", 23, 501, "M.Tech Computer Science",
                            "Machine Learning");
    student.display();
    return 0;
}
