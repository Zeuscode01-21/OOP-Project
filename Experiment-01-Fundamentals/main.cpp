#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Demonstrates fundamental C++ concepts inside a class.
class FundamentalsDemo {
public:
    void run() const {
        // Variables and data types
        int age = 19;
        float percentage = 87.5F;
        double distance = 1234.567;
        char grade = 'A';
        bool isEnrolled = true;
        string studentName = "Aarav";

        // Constant: its value cannot be changed after initialization.
        const double PI = 3.141592653589793;

        cout << "=== C++ Fundamentals Demonstration ===\n\n";
        cout << "Student: " << studentName << '\n';
        cout << "Age (int): " << age << '\n';
        cout << "Percentage (float): " << percentage << '\n';
        cout << "Distance (double): " << distance << '\n';
        cout << "Grade (char): " << grade << '\n';
        cout << "Enrolled (bool): " << boolalpha << isEnrolled << '\n';
        cout << "Constant PI: " << setprecision(8) << PI << "\n\n";

        // Arithmetic, relational and logical operators
        int a = 20, b = 6;
        cout << "Arithmetic operators:\n";
        cout << "a + b = " << a + b << '\n';
        cout << "a - b = " << a - b << '\n';
        cout << "a * b = " << a * b << '\n';
        cout << "a / b = " << a / b << " (integer division)\n";
        cout << "a % b = " << a % b << '\n';

        cout << "\nRelational/logical operators:\n";
        cout << "a > b: " << (a > b) << '\n';
        cout << "(a > b) && (b > 0): " << ((a > b) && (b > 0)) << '\n';

        // Input/output
        string userName;
        cout << "\nEnter your name: ";
        getline(cin, userName);
        cout << "Hello, " << userName << "! Program completed.\n";
    }
};

int main() {
    FundamentalsDemo demo;
    demo.run();
    return 0;
}
