#include <iostream>
#include <cmath>
using namespace std;

inline double square(double num) {
  return num * num;
}

int main() {
  double num;
  cout << "Enter a number: ";
  cin >> num;
  cout << "The square of " << num << " is " << square(num)<< endl;
  return 0;
}
