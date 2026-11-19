#include <iostream>
#include <memory>
#include <vector>
#include <iomanip>
using namespace std;

// Abstract base class
class Shape {
public:
    virtual double area() const = 0; // Pure virtual function
    virtual void display() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;

public:
    explicit Circle(double r) : radius(r) {}
    double area() const override { return 3.141592653589793 * radius * radius; }
    void display() const override {
        cout << "Circle area: " << area() << '\n';
    }
};

class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() const override { return length * width; }
    void display() const override {
        cout << "Rectangle area: " << area() << '\n';
    }
};

class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() const override { return 0.5 * base * height; }
    void display() const override {
        cout << "Triangle area: " << area() << '\n';
    }
};

int main() {
    cout << fixed << setprecision(2);
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Circle>(5.0));
    shapes.push_back(make_unique<Rectangle>(4.0, 6.0));
    shapes.push_back(make_unique<Triangle>(3.0, 8.0));

    cout << "Runtime polymorphism using Shape pointers:\n";
    for (const auto& shape : shapes) {
        shape->display(); // Correct derived implementation selected at runtime
    }
    return 0;
}
