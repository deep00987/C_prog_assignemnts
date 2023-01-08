#include <iostream>

using namespace std;

class Swap {
  private:
    int num1;
    int num2;

  public:
    // Constructor to initialize the numbers
    Swap(int num1, int num2) {
      this->num1 = num1;
      this->num2 = num2;
    }

    // Friend function to swap the numbers
    friend void swap_num(Swap&);
    void print_vars();
};

void Swap::print_vars(){
    cout << "NUM 1: " << num1 << " NUM 2: " << num2 << endl;
}


// Friend function definition
void swap_num(Swap &s) {
  s.num1 = s.num1 + s.num2;
  s.num2 = s.num1 - s.num2;
  s.num1 = s.num1 - s.num2;
}

int main() {
  int num1, num2;
  cout << "Enter two numbers: ";
  cin >> num1 >> num2;

  // Create an instance of the Swapper class
  Swap s(num1, num2);

    cout << "Before swapping: ---\n";
  s.print_vars(); 

  // Swap the numbers
  swap_num(s);

  // Print the numbers after swapping
  cout << "After swapping: ---\n";
  s.print_vars(); 
  return 0;
}
