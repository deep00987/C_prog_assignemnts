#include <iostream>
using namespace std;

class Base {
    protected:
        int x;
    public:
        Base(){
            x = 0;
        }
        // Parameterized constructor
        Base(int x) {
            cout << "Base class parameterized constructor: " << x << endl;
            this->x = x;
        }

        // Copy constructor
        Base(const Base& obj) {
            cout << "Base class copy constructor called." << endl;
            x = obj.x;
        }

        // Virtual destructor
        virtual ~Base() {
            cout << "Base class destructor called." << endl;
        }

        void set_val(int x){
            this->x = x;
        }

        void display(){
            cout << "Value in Base class: " << x << endl;
        }
};

class Derived : public Base {
    protected:
        int y;
    public:
        // Parameterized constructor
        Derived(int x, int y) : Base(x) {
            cout << "Derived class parameterized constructor: " << y << endl;
            this->y = y;
        }

        //derived destructor
        ~Derived() {
            cout << "Derived class destructor called." << endl;
        }
};

int main() {
    // Derived d1(10, 20);
    // cout << "Creating copy of d1" << endl;
    // Derived d2 = d1;

    Base b1(10);
    Base b2 = b1;


    b1.display();
    b1.set_val(1);
    b1.display();
    b2.display();


    // polymorphysm situatiuon 
    // Not using virtual destructor, will not call the destrucxtor of derived class
    // using the Virtual destructor, calls virtual destructor, therefore not memory leaks

    Base *b3 = new Derived(10, 12);
    delete b3;

    return 0;
}
