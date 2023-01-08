#include <iostream>
#include <cmath>

class Triangle
{
private:
    double a, b, c;

public:
    double area();
    double perimeter();
    void input()
    {
        std::cout << "Enter the sides of the triangle: ";
        std::cin >> a >> b >> c;
    }

    void print()
    {
        std::cout << "Sides of the triangle: " << a << " " << b << " " << c << std::endl;
    }
};

double Triangle::area()
{
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double Triangle::perimeter()
{
    return a + b + c;
}

int main()
{
    Triangle t;
    t.input();

    double area_result = t.area();
    double perimeter_result = t.perimeter();

    t.print();
    std::cout << "Area of the triangle: " << area_result << std::endl;
    std::cout << "Perimeter of the triangle: " << perimeter_result << std::endl;

    return 0;
}