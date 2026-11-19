#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <limits>
using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    string course;
    double marks;

public:
    Student(int roll, const string& studentName,
            const string& studentCourse, double studentMarks)
        : rollNumber(roll), name(studentName),
          course(studentCourse), marks(studentMarks) {}

    int getRollNumber() const { return rollNumber; }
    string getName() const { return name; }
    string getCourse() const { return course; }
    double getMarks() const { return marks; }

    void display() const {
        cout << left << setw(12) << rollNumber
             << setw(22) << name
             << setw(20) << course
             << fixed << setprecision(2) << marks << '\n';
    }

    string toCSV() const {
        // This small project expects names/courses without commas.
        ostringstream out;
        out << rollNumber << ',' << name << ',' << course << ',' << marks;
        return out.str();
    }
};

class StudentManagementSystem {
private:
    vector<Student> students;
    const string filename = "student_records.csv";

    bool rollExists(int roll) const {
        return any_of(students.begin(), students.end(),
                      [roll](const Student& s) {
                          return s.getRollNumber() == roll;
                      });
    }

    void loadFromFile() {
        ifstream in(filename);
        if (!in) return; // First run: file does not exist yet.

        string line;
        while (getline(in, line)) {
            stringstream parser(line);
            string rollText, name, course, marksText;

            if (!getline(parser, rollText, ',') ||
                !getline(parser, name, ',') ||
                !getline(parser, course, ',') ||
                !getline(parser, marksText, ',')) {
                continue;
            }

            try {
                int roll = stoi(rollText);
                double marks = stod(marksText);
                if (!rollExists(roll))
                    students.emplace_back(roll, name, course, marks);
            } catch (const exception&) {
                // Ignore malformed rows rather than stopping the application.
            }
        }
    }

    void saveToFile() const {
        ofstream out(filename);
        if (!out) {
            cerr << "Error: unable to save student records.\n";
            return;
        }
        for (const auto& student : students)
            out << student.toCSV() << '\n';
    }

    static void printHeading() {
        cout << left << setw(12) << "Roll No."
             << setw(22) << "Name"
             << setw(20) << "Course" << "Marks\n";
        cout << string(65, '-') << '\n';
    }

public:
    StudentManagementSystem() {
        loadFromFile();
    }

    void addStudent() {
        int roll;
        string name, course;
        double marks;

        cout << "Enter roll number: ";
        if (!(cin >> roll)) {
            cout << "Invalid roll number.\n";
            resetInput();
            return;
        }
        if (rollExists(roll)) {
            cout << "A student with this roll number already exists.\n";
            return;
        }

        cout << "Enter student name (no commas): ";
        getline(cin >> ws, name);
        cout << "Enter course (no commas): ";
        getline(cin, course);
        cout << "Enter marks (0-100): ";
        if (!(cin >> marks) || marks < 0 || marks > 100) {
            cout << "Invalid marks. Enter a value from 0 to 100.\n";
            resetInput();
            return;
        }

        students.emplace_back(roll, name, course, marks);
        saveToFile();
        cout << "Student added successfully.\n";
    }

    void displayAll() const {
        if (students.empty()) {
            cout << "No student records found.\n";
            return;
        }
        printHeading();
        for (const auto& student : students) student.display();
    }

    void searchStudent() const {
        int roll;
        cout << "Enter roll number to search: ";
        if (!(cin >> roll)) {
            cout << "Invalid roll number.\n";
            resetInput();
            return;
        }

        auto it = find_if(students.begin(), students.end(),
                          [roll](const Student& s) {
                              return s.getRollNumber() == roll;
                          });
        if (it == students.end()) {
            cout << "Student not found.\n";
        } else {
            printHeading();
            it->display();
        }
    }

    void deleteStudent() {
        int roll;
        cout << "Enter roll number to delete: ";
        if (!(cin >> roll)) {
            cout << "Invalid roll number.\n";
            resetInput();
            return;
        }

        auto oldSize = students.size();
        students.erase(remove_if(students.begin(), students.end(),
                                 [roll](const Student& s) {
                                     return s.getRollNumber() == roll;
                                 }),
                       students.end());

        if (students.size() == oldSize) {
            cout << "Student not found.\n";
        } else {
            saveToFile();
            cout << "Student deleted successfully.\n";
        }
    }

    void showClassAverage() const {
        if (students.empty()) {
            cout << "No records available to calculate average.\n";
            return;
        }
        double total = 0;
        for (const auto& student : students) total += student.getMarks();
        cout << "Class average: " << fixed << setprecision(2)
             << total / students.size() << '\n';
    }

    static void resetInput() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void run() {
        int choice;
        do {
            cout << "\n====== STUDENT MANAGEMENT SYSTEM ======\n"
                 << "1. Add student\n"
                 << "2. Display all students\n"
                 << "3. Search student by roll number\n"
                 << "4. Delete student\n"
                 << "5. Calculate class average\n"
                 << "0. Exit\n"
                 << "Enter your choice: ";

            if (!(cin >> choice)) {
                cout << "Please enter a valid menu number.\n";
                resetInput();
                continue;
            }

            switch (choice) {
                case 1: addStudent(); break;
                case 2: displayAll(); break;
                case 3: searchStudent(); break;
                case 4: deleteStudent(); break;
                case 5: showClassAverage(); break;
                case 0: cout << "Records saved. Exiting program.\n"; break;
                default: cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 0);
    }
};

int main() {
    StudentManagementSystem system;
    system.run();
    return 0;
}
