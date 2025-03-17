#include <iostream>
#include <cmath>

using namespace std;

class Shape {
protected:
    string position;
    string color;
    double border_thickness;

public:
    Shape(string pos, string col, double border = 1.0)
        : position(pos), color(col), border_thickness(border) {}

    virtual void draw() const = 0;
    virtual double calculate_area() const = 0;
    virtual double calculate_perimeter() const = 0;

    virtual ~Shape() {}
};

class Circle : public Shape {
    double radius;
    string center_position;

public:
    Circle(string pos, string col, double rad, string center, double border = 1.0): Shape(pos, col, border), radius(rad), center_position(center) {}

    void draw() const override {
        cout << "Drawing Circle at " << center_position << " with radius " << radius << "\n";
    }

    double calculate_area() const override {
        return 3.142 * radius * radius;
    }

    double calculate_perimeter() const override {
        return 2 * 3.142 * radius;
    }
};

class Rectangle : public Shape {
    double width, height;
    string top_left_position;

public:
    Rectangle(string pos, string col, double w, double h, string top_left, double border = 1.0)
        : Shape(pos, col, border), width(w), height(h), top_left_position(top_left) {}

    void draw() const override {
        cout << "Drawing Rectangle at " << top_left_position << " with width " << width << " and height " << height << "\n";
    }

    double calculate_area() const override {
        return width * height;
    }

    double calculate_perimeter() const override {
        return 2 * (width + height);
    }
};

class Triangle : public Shape {
    double base, height, side_a, side_b, side_c;

public:
    Triangle(string pos, string col, double b, double h, double a, double c, double border = 1.0)
        : Shape(pos, col, border), base(b), height(h), side_a(a), side_b(b), side_c(c) {}

    void draw() const override {
        cout << "Drawing Triangle with base " << base << " and height " << height << "\n";
    }

    double calculate_area() const override {
        return 0.5 * base * height;
    }

    double calculate_perimeter() const override {
        return side_a + side_b + side_c;
    }
};

class Polygon : public Shape {
    int sides;
    double side_length;

public:
    Polygon(string pos, string col, int s, double length, double border = 1.0)
        : Shape(pos, col, border), sides(s), side_length(length) {}

    void draw() const override {
        cout << "Drawing Polygon with " << sides << " sides of length " << side_length << "\n";
    }

    double calculate_area() const override {
        return (sides * side_length * side_length) / (4 * tan(3.142 / sides));
    }

    double calculate_perimeter() const override {
        return sides * side_length;
    }
};

int main() {
    Circle c("(5,5)", "Red", 10, "(5,5)");
    Rectangle r("(0,0)", "Blue", 8, 4, "(0,0)");
    Triangle t("(2,2)", "Green", 5, 4, 3, 6);
    Polygon p("(1,1)", "Yellow", 5, 6);

    cout << "\n--- Circle ---\n";
    c.draw();
    cout << "Area: " << c.calculate_area() << " | Perimeter: " << c.calculate_perimeter() << "\n";

    cout << "\n--- Rectangle ---\n";
    r.draw();
    cout << "Area: " << r.calculate_area() << " | Perimeter: " << r.calculate_perimeter() << "\n";

    cout << "\n--- Triangle ---\n";
    t.draw();
    cout << "Area: " << t.calculate_area() << " | Perimeter: " << t.calculate_perimeter() << "\n";

    cout << "\n--- Polygon ---\n";
    p.draw();
    cout << "Area: " << p.calculate_area() << " | Perimeter: " << p.calculate_perimeter() << "\n";

    return 0;
}
