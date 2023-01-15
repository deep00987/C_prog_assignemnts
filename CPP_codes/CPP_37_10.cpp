#include <iostream>
using namespace std;

// function to calculate volume of cube
double volume(float side) {
    return side * side * side;
}

// function to calculate volume of cuboid
double volume(double length, double width, double height) {
    return length * width * height;
}

// function to calculate volume of cone
double volume(double radius, double height, bool isCone) {
    if (isCone) {
        return (1.0/3.0) * 3.14159 * radius * radius * height;
    }
    else {
        return -1;
    }
}

// function to calculate volume of cylinder
double volume(double radius, double height) {
    return 3.14159 * radius * radius * height;
}

// function to calculate volume of sphere
double volume(double radius) {
    return (4.0/3.0) * 3.14159 * radius * radius * radius;
}

int main() {
    int choice;
    double length, width, height, radius;
    float side;

    cout << "1. Cube" << endl;
    cout << "2. Cuboid" << endl;
    cout << "3. Cone" << endl;
    cout << "4. Cylinder" << endl;
    cout << "5. Sphere" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter side of cube: ";
            cin >> side;
            cout << "Volume of cube: " << volume(side) << endl;
            break;
        case 2:
            cout << "Enter length of cuboid: ";
            cin >> length;
            cout << "Enter width of cuboid: ";
            cin >> width;
            cout << "Enter height of cuboid: ";
            cin >> height;
            cout << "Volume of cuboid: " << volume(length, width, height) << endl;
            break;
        case 3:
            cout << "Enter radius of cone: ";
            cin >> radius;
            cout << "Enter height of cone: ";
            cin >> height;
            cout << "Volume of cone: " << volume(radius, height, true) << endl;
            break;
        case 4:
            cout << "Enter radius of cylinder: ";
            cin >> radius;
            cout << "Enter height of cylinder: ";
            cin >> height;
            cout << "Volume of cylinder: " << volume(radius, height) << endl;
            break;
        case 5:
            cout << "Enter radius of sphere: ";
            cin >> radius;
            cout << "Volume of sphere: " << volume(radius) << endl;
            break;
        default:
            cout << "Invalid choice. Please select a valid option." << endl;
    }

    return 0;
}
