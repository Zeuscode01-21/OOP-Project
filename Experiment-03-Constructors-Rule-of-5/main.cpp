#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

// Owns a dynamically allocated integer array.
// Demonstrates the Rule of 5: destructor, copy/move constructors,
// and copy/move assignment operators.
class NumberArray {
private:
    int* data;
    size_t size;

public:
    // Default constructor
    NumberArray() : data(nullptr), size(0) {
        cout << "Default constructor\n";
    }

    // Parameterized constructor
    explicit NumberArray(size_t count) : data(count ? new int[count]{} : nullptr),
                                         size(count) {
        cout << "Parameterized constructor\n";
    }

    // Copy constructor: deep copy
    NumberArray(const NumberArray& other)
        : data(other.size ? new int[other.size] : nullptr), size(other.size) {
        copy(other.data, other.data + other.size, data);
        cout << "Copy constructor\n";
    }

    // Move constructor: takes ownership of the resource
    NumberArray(NumberArray&& other) noexcept
        : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
        cout << "Move constructor\n";
    }

    // Copy assignment operator
    NumberArray& operator=(const NumberArray& other) {
        if (this != &other) {
            int* newData = other.size ? new int[other.size] : nullptr;
            copy(other.data, other.data + other.size, newData);
            delete[] data;
            data = newData;
            size = other.size;
        }
        cout << "Copy assignment operator\n";
        return *this;
    }

    // Move assignment operator
    NumberArray& operator=(NumberArray&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        cout << "Move assignment operator\n";
        return *this;
    }

    // Destructor
    ~NumberArray() {
        delete[] data;
        cout << "Destructor\n";
    }

    void set(size_t index, int value) {
        if (index < size) data[index] = value;
    }

    void display() const {
        for (size_t i = 0; i < size; ++i) cout << data[i] << ' ';
        cout << '\n';
    }
};

int main() {
    NumberArray first(3);
    first.set(0, 10);
    first.set(1, 20);
    first.set(2, 30);

    cout << "Original: ";
    first.display();

    NumberArray copied(first);              // Copy constructor
    cout << "Copied: ";
    copied.display();

    NumberArray moved(std::move(first));    // Move constructor
    cout << "Moved: ";
    moved.display();

    NumberArray assigned;
    assigned = copied;                      // Copy assignment

    NumberArray moveAssigned;
    moveAssigned = std::move(moved);        // Move assignment

    cout << "Copy-assigned: ";
    assigned.display();
    cout << "Move-assigned: ";
    moveAssigned.display();

    return 0;
}
