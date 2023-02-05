#include <iostream>
using namespace std;

// function to reverse digits of an integer
int reverse(int m) {
    int reversed = 0;
    while (m > 0) {
        reversed = reversed * 10 + m % 10;
        m /= 10;
    }
    return reversed;
}

// function to check if an integer is prime
bool isPrime(int m) {
    if (m <= 1) return false;
    if (m <= 3) return true;
    if (m % 2 == 0 || m % 3 == 0) return false;
    for (int i = 5; i * i <= m; i += 6) {
        if (m % i == 0 || m % (i + 2) == 0) return false;
    }
    return true;
}

// function to perform reverse or prime check based on ch
void calculate(int m, char ch = 'r') {

    cout << "case 0" << endl;
    cout << "Reversed number: " << reverse(m) << endl;

}

void calculate(char ch, int m){
    cout << "case 1" << endl;
    if (isPrime(m)) {
        cout << m << " is a prime number." << endl;
    } else {
        cout << m << " is not a prime number." << endl;
    }
}

int main() {
    int m;
    char ch;

    cout << "Enter an integer: ";
    cin >> m;
    cout << "Enter 'r' to reverse digits or 'p' to check for prime: ";
    cin >> ch;

    if (m < 10){
        cout << "Number must be atleast 2 digits!" << endl;
        exit(1);
    }
    if (ch == 'p'){
        calculate(ch, m);
    }else if (ch == 'r'){
        calculate(m, ch);
    }else{
        cout << "Invalid Ops" << endl;
    }

    return 0;
}
