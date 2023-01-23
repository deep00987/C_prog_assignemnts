#include <iostream>
using namespace std;
typedef unsigned long long int u_lld64;

int main(){
    int N;
    u_lld64 a, b, c;
    cout << "enter the binary string length: " << endl;
    cin >> N;
    
    if (N < 0 || N < 2){
        cout << "Undefined !" << endl;
        return 0;
    }

    if (N < 4){
        cout << "Result: " << 2 << endl;
        return 0;
    }
    a = 2;
    b = 2;
    for (int i = 4; i <= N; i++){
        c = (a + b) % 1000000007;
        a = b;
        b = c;
    }

    cout << "Result: " << c << endl;
    return 0;
}