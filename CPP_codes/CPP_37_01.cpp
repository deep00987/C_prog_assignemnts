#include <iostream>
#include <cmath>

#define _PI 3.14159265358979323846

using namespace std;

class Shape
{
    protected:
        double radius;
};

class Circle : public Shape
{
    private:
        double area;

    public:
        // Constructor to set the radius of the circle
        Circle(double radius)
        {
            this->radius = radius;
        }

        // Member function to calculate the area of the circle
        double calculate_area()
        {
            area = _PI * radius * radius;
            return area;
        }
};

int main()
{
    double radius;
    cout << "Enter the radius of the circle: ";
    cin >> radius;

    // Create an instance of the Circle class
    Circle circle(radius);

    // Calculate and print the area of the circle
    cout << "Area of the circle: " << circle.calculate_area() << endl;

    return 0;
}
