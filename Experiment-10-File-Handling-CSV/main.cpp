#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

struct StudentRecord {
    int roll;
    string name;
    double marks;
};

class StudentFile {
private:
    const string filename = "students.csv";

public:
    void writeRecords() const {
        ofstream out(filename);
        if (!out) {
            cerr << "Could not open file for writing.\n";
            return;
        }

        out << "Roll,Name,Marks\n";
        out << "101,Aarav,88.5\n";
        out << "102,Diya,91.0\n";
        out << "103,Vihaan,79.5\n";
        out.close();
        cout << "Student records written to " << filename << ".\n";
    }

    void readRecords() const {
        ifstream in(filename);
        if (!in) {
            cerr << "Could not open file for reading.\n";
            return;
        }

        string line;
        cout << "\nContents of " << filename << ":\n";
        while (getline(in, line)) cout << line << '\n';
        in.close();
    }

    void demonstrateFilePointers() const {
        // fstream supports both input and output.
        fstream file(filename, ios::in | ios::out);
        if (!file) {
            cerr << "Could not open file for pointer demonstration.\n";
            return;
        }

        file.seekg(0, ios::end);
        streampos endPosition = file.tellg();
        cout << "\nFile size using tellg(): " << endPosition << " bytes\n";

        file.seekg(0, ios::beg);
        cout << "First 10 characters using seekg(): ";
        char ch;
        for (int i = 0; i < 10 && file.get(ch); ++i) cout << ch;
        cout << '\n';

        file.clear();
        file.seekp(0, ios::end);
        streampos writePosition = file.tellp();
        cout << "Write position at end using tellp(): " << writePosition << '\n';
        file.close();
    }
};

int main() {
    StudentFile studentFile;
    studentFile.writeRecords();
    studentFile.readRecords();
    studentFile.demonstrateFilePointers();
    return 0;
}
