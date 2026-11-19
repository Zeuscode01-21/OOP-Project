#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Generic Stack class using a class template.
template <typename T>
class Stack {
private:
    vector<T> elements;

public:
    void push(const T& value) {
        elements.push_back(value);
    }

    bool empty() const {
        return elements.empty();
    }

    T pop() {
        if (empty()) throw underflow_error("Stack is empty.");
        T topValue = elements.back();
        elements.pop_back();
        return topValue;
    }

    const T& top() const {
        if (empty()) throw underflow_error("Stack is empty.");
        return elements.back();
    }

    size_t size() const { return elements.size(); }
};

template <typename T>
void testStack(const string& label, const T& first, const T& second) {
    Stack<T> stack;
    stack.push(first);
    stack.push(second);

    cout << label << " stack (top to bottom): ";
    while (!stack.empty()) cout << stack.pop() << ' ';
    cout << "\n";
}

int main() {
    testStack<int>("Integer", 10, 20);
    testStack<float>("Float", 1.5F, 2.5F);
    testStack<string>("String", "C++", "Templates");
    return 0;
}
