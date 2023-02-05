#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* str;
    int len;

public:
    // constructor to initialize the string
    String(const char* s = NULL) {
        if (s == NULL) {
            len = 0;
            str = new char[1];
            str[0] = '\0';
        }
        else {
            len = strlen(s);
            str = new char[len + 1];
            strcpy(str, s);
        }
    }
    // destructor to deallocate memory
    ~String() {
        delete[] str;
    }

    // function to reverse the string
    void reverse() {
        int i, j;
        for (i = 0, j = len - 1; i < j; i++, j--) {
            swap(str[i], str[j]);
        }
    }

    // overload '+' operator to concatenate strings
    void operator+(String &b) {
        // String tmp;
        // tmp.len = len + b.len;
        // delete[] tmp.str;
        // tmp.str = new char[tmp.len + 1];
        len += b.len;
        str = (char *)realloc(str, len);
        strcat(str, b.str);
    
    }

    // overload '=' operator to copy the concatenated string
    // String operator=(String &b) {
    //     if (this != &b) {
    //         len = b.len;

    //         // deallocate memory of the current object
    //         delete[] str;

    //         // allocate memory for the new concatenated string
    //         str = new char[len + 1];

    //         // copy the new concatenated string
    //         strcpy(str, b.str);
    //     }
    //     return *this;
    // }

    // function to display the concatenated string
    void display() {
        cout << str << endl;
    }
};

int main() {
    char str1[10], str2[10];

    cout << "Enter the first string: ";
    cin >> str1;

    cout << "Enter the second string: ";
    cin >> str2;

    String s1(str1), s2(str2), s3;

    s1 + s2;
    s1.display();
    s1.reverse();
    s1.display();

    return 0;
}
