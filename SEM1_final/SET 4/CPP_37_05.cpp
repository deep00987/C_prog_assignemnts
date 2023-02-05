#include <iostream>
#include <cmath>
using namespace std;
class Complex
{
    private:
        int real;
        int img;
    public:
        Complex()
        {
            real = 0;
            img = 0;
        }
        Complex(int a)
        {
            real = a;
            img = 0;
        }
        Complex(int a, int b)
        {
            real = a;
            img = b;
        }
        void show()
        {
            cout << real << "+" << img << "i" << endl;
        }
        void sum(Complex a, Complex b)
        {
            this->real = a.real + b.real;
            this->img = a.img + b.img;
        }         
};
int main()
{
    // int x1, y1, x2, y2;
    // cout << "Enter first imaginary number \n";
    // cout << "real part: ";
    // cin >> x1;
    // cout << "imaginary part: ";
    // cin >> y1;

    // cout << "Enter second imaginary number \n";
    // cout << "real part: ";
    // cin >> x2;
    // cout << "imaginary part: ";
    // cin >> y2;

    Complex A(5,6), B(6), C;
    A.show();
    B.show();
    C.show();
    C.sum(A, B);
    C.show();
    return 0;
}