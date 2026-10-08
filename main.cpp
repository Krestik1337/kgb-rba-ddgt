#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Figure {
protected:
    string* figureName;
    bool* created;

public:
    Figure(string n = "Figure") {
        cout << "Figure created" << endl;
        figureName = new string(n);
        created = new bool(true);
    }

    Figure(const Figure&) = delete;
    Figure& operator=(const Figure&) = delete;

    virtual ~Figure() {
        cout << "Figure deleted" << endl;
        delete figureName;
        delete created;
    }

    string getName() { return *figureName; }
    void setName(string n) { *figureName = n; }

    virtual void printInfo() {
        cout << "Figure name: " << *figureName << endl;
    }

    virtual double CalcArea() = 0;
};

class Circle : public Figure {
private:
    double* r;

public:
    Circle(string n = "Circle", double radius = 1) : Figure(n) {
        cout << "Circle created" << endl;
        r = new double(radius);
    }

    Circle(const Circle&) = delete;
    Circle& operator=(const Circle&) = delete;

    ~Circle() override {
        cout << "Circle deleted" << endl;
        delete r;
    }

    double getR() { return *r; }
    void setR(double radius) { *r = radius; }

    void printInfo() override {
        cout << "Circle name: " << *figureName << ", radius = " << *r << endl;
    }

    double CalcArea() override {
        cout << "Circle::CalcArea called" << endl;
        double pi = 3.141592653589793;
        return pi * (*r) * (*r);
    }
};

class Rectangle : public Figure {
private:
    double* a;
    double* b;

public:
    Rectangle(string n = "Rectangle", double sideA = 2, double sideB = 3) : Figure(n) {
        cout << "Rectangle created" << endl;
        a = new double(sideA);
        b = new double(sideB);
    }

    Rectangle(const Rectangle&) = delete;
    Rectangle& operator=(const Rectangle&) = delete;

    ~Rectangle() override {
        cout << "Rectangle deleted" << endl;
        delete a;
        delete b;
    }

    double getA() { return *a; }
    double getB() { return *b; }
    void setA(double sideA) { *a = sideA; }
    void setB(double sideB) { *b = sideB; }

    void printInfo() override {
        cout << "Rectangle name: " << *figureName << ", sides = " << *a << " x " << *b << endl;
    }

    double CalcArea() override {
        cout << "Rectangle::CalcArea called" << endl;
        return (*a) * (*b);
    }
};

class Triangle : public Figure {
private:
    double* x;
    double* y;
    double* z;

public:
    Triangle(string n = "Triangle", double s1 = 3, double s2 = 4, double s3 = 5) : Figure(n) {
        cout << "Triangle created" << endl;
        x = new double(s1);
        y = new double(s2);
        z = new double(s3);
    }

    Triangle(const Triangle&) = delete;
    Triangle& operator=(const Triangle&) = delete;

    ~Triangle() override {
        cout << "Triangle deleted" << endl;
        delete x;
        delete y;
        delete z;
    }

    double getX() { return *x; }
    double getY() { return *y; }
    double getZ() { return *z; }
    void setX(double s) { *x = s; }
    void setY(double s) { *y = s; }
    void setZ(double s) { *z = s; }

    void printInfo() override {
        cout << "Triangle name: " << *figureName << ", sides = "
            << *x << ", " << *y << ", " << *z << endl;
    }

    double CalcArea() override {
        cout << "Triangle::CalcArea called" << endl;
        double half = (*x + *y + *z) / 2;
        return sqrt(half * (half - *x) * (half - *y) * (half - *z));
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    int number;
    cout << "1 - Circle" << endl;
    cout << "2 - Rectangle" << endl;
    cout << "3 - Triangle" << endl;
    cout << "Choose figure: ";
    cin >> number;

    Figure* f = nullptr;

    if (number == 1) {
        double radius;
        cout << "Radius: ";
        cin >> radius;
        f = new Circle("MyCircle", radius);
    }
    else if (number == 2) {
        double sideA, sideB;
        cout << "Side A: ";
        cin >> sideA;
        cout << "Side B: ";
        cin >> sideB;
        f = new Rectangle("MyRectangle", sideA, sideB);
    }
    else if (number == 3) {
        double s1, s2, s3;
        cout << "Side 1: ";
        cin >> s1;
        cout << "Side 2: ";
        cin >> s2;
        cout << "Side 3: ";
        cin >> s3;
        f = new Triangle("MyTriangle", s1, s2, s3);
    }
    else {
        cout << "Wrong choice" << endl;
        return 0;
    }

    cout << endl;
    f->printInfo();
    cout << "Area = " << f->CalcArea() << endl;

    delete f;

    return 0;
}