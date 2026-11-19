#include <iostream>
#include <vector>
using namespace std;

// Function overloading: same function name, different parameter lists.
class Calculator {
public:
    int add(int a, int b) const { return a + b; }
    double add(double a, double b) const { return a + b; }
    int add(int a, int b, int c) const { return a + b + c; }
};

// Operator overloading for a Matrix class.
class Matrix {
private:
    int rows, cols;
    vector<vector<int>> values;

public:
    Matrix(int r, int c) : rows(r), cols(c), values(r, vector<int>(c, 0)) {}

    void input() {
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j) {
                cout << "Element [" << i << "][" << j << "]: ";
                cin >> values[i][j];
            }
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw invalid_argument("Matrices must have the same dimensions.");

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.values[i][j] = values[i][j] + other.values[i][j];
        return result;
    }

    friend ostream& operator<<(ostream& out, const Matrix& matrix) {
        for (const auto& row : matrix.values) {
            for (int value : row) out << value << ' ';
            out << '\n';
        }
        return out;
    }
};

int main() {
    Calculator calculator;
    cout << "Function overloading:\n";
    cout << "add(4, 5) = " << calculator.add(4, 5) << '\n';
    cout << "add(2.5, 3.1) = " << calculator.add(2.5, 3.1) << '\n';
    cout << "add(1, 2, 3) = " << calculator.add(1, 2, 3) << "\n\n";

    int rows, cols;
    cout << "Enter rows and columns for two matrices: ";
    cin >> rows >> cols;
    if (!cin || rows <= 0 || cols <= 0) {
        cerr << "Invalid dimensions.\n";
        return 1;
    }

    Matrix first(rows, cols), second(rows, cols);
    cout << "Enter first matrix:\n";
    first.input();
    cout << "Enter second matrix:\n";
    second.input();

    try {
        Matrix sum = first + second; // Overloaded + operator
        cout << "Sum of matrices:\n" << sum; // Overloaded << operator
    } catch (const exception& error) {
        cerr << "Error: " << error.what() << '\n';
    }
    return 0;
}
