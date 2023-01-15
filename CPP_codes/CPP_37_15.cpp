#include <iostream>
using namespace std;

class Complex {
    private:
        int real;
        int imaginary;
    public:
        // Constructor to initialize the complex number
        Complex(int r = 0, int i = 0){
            real = r;
            imaginary = i;
        }

        // Friend function to add two complex numbers
        friend Complex add(const Complex&, const Complex&);

        // Function to print a complex number
        void print() {
            cout << real << " + " << imaginary << "i" << endl;
        }
};

Complex add(const Complex& c1, const Complex& c2){
    return Complex(c1.real + c2.real, c1.imaginary + c2.imaginary);
}

int main() {
    Complex c1(3, 4), c2(5, -6);
    Complex c3 = add(c1, c2); // Add c1 and c2 using the friend function

    cout << "Complex number 1: ";
    c1.print();
    cout << "Complex number 2: ";
    c2.print();
    cout << "Complex number 1 + Complex number 2: ";
    c3.print();

    return 0;
}
