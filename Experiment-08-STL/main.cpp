#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    int marks;
};

int main() {
    vector<Student> students = {
        {103, "Meera", 86},
        {101, "Arjun", 92},
        {104, "Kabir", 74},
        {102, "Sara", 92},
        {105, "Ishaan", 68}
    };

    // map: stores keys in sorted order.
    map<int, string> rollToName;
    // unordered_map: average marks grouped by first letter (illustrative use).
    unordered_map<char, int> countByInitial;

    for (const auto& student : students) {
        rollToName[student.roll] = student.name;
        ++countByInitial[student.name.front()];
    }

    cout << "Student records sorted by marks (descending):\n";
    sort(students.begin(), students.end(),
         [](const Student& a, const Student& b) {
             return a.marks > b.marks;
         });

    for (const auto& student : students) {
        cout << student.roll << " | " << student.name
             << " | " << student.marks << '\n';
    }

    // find_if: locate the first student with marks below 75.
    auto lowScorer = find_if(students.begin(), students.end(),
                             [](const Student& s) { return s.marks < 75; });

    if (lowScorer != students.end())
        cout << "\nFirst student below 75: " << lowScorer->name
             << " (" << lowScorer->marks << ")\n";

    // transform: extract marks into a separate vector.
    vector<int> marks(students.size());
    transform(students.begin(), students.end(), marks.begin(),
              [](const Student& s) { return s.marks; });

    double average = static_cast<double>(
        accumulate(marks.begin(), marks.end(), 0)) / marks.size();
    cout << "\nClass average: " << average << '\n';

    cout << "\nmap (roll number order):\n";
    for (const auto& entry : rollToName)
        cout << entry.first << " -> " << entry.second << '\n';

    cout << "\nunordered_map (count by name initial):\n";
    for (const auto& entry : countByInitial)
        cout << entry.first << " -> " << entry.second << '\n';

    return 0;
}
