
#include <iostream>
#include <string>
using namespace std;

class Student  // Base class
{
protected:
    int roll;
    string name;
    float marks;

public:
    Student()
    {
        roll = 0;
        name = "";
        marks = 0;
    }

    void getData()
    {
        cout << "Enter Roll No: ";
        cin >> roll;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Marks: ";
        cin >> marks;
    }

    int getRoll()   //roll is protected, we cannot directly access it from outside the class
    {
        return roll;
    }

    virtual void display()
    {
        cout << "\nRoll No: " << roll;
        cout << "\nName: " << name;
        cout << "\nMarks: " << marks;
    }
};

// Derived class
class Result : public Student
{
public:
    void display() override
    {
        Student::display();

        cout << "\nGrade: ";

        if (marks >= 90)
            cout << "A";
        else if (marks >= 75)
            cout << "B";
        else if (marks >= 60)
            cout << "C";
        else if (marks >= 40)
            cout << "D";
        else
            cout << "F";

        cout << "\n-------------------";
    }
};

// Array to store students
Result s[50];
int studentCount = 0;

// Add student
void addStudent()
{
    if (studentCount == 50)
    {
        cout << "\nLimit reached!";
        return;
    }

    s[studentCount].getData();
    studentCount++;

    cout << "\nStudent added!";
}

// Display students
void displayStudents()
{
    if (studentCount == 0)
        cout << "\nNo records found!";

    for (int i = 0; i < studentCount; i++)
        s[i].display();
}

// Search student
void searchStudent()
{
    int r;
    cout << "\nEnter Roll No: ";
    cin >> r;

    for (int i = 0; i < studentCount; i++)
    {
        if (s[i].getRoll() == r)
        {
            s[i].display();
            return;
        }
    }

    cout << "\nStudent not found!";
}

// Delete student
void deleteStudent()
{
    int r;
    cout << "\nEnter Roll No: ";
    cin >> r;

    for (int i = 0; i < studentCount; i++)
    {
        if (s[i].getRoll() == r)
        {
            for (int j = i; j < studentCount - 1; j++)
                s[j] = s[j + 1];

            studentCount--;

            cout << "\nStudent deleted!";
            return;
        }
    }

    cout << "\nStudent not found!";
}

// Main function
int main()
{
    int choice;

    do
    {
        cout << "\n\n--- STUDENT MANAGEMENT SYSTEM ---";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Search Student";
        cout << "\n4. Delete Student";
        cout << "\n5. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                cout << "\nThank You!";
                break;

            default:
                cout << "\nInvalid choice!";
        }

    } while (choice != 5);

    return 0;
}
