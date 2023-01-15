#include <iostream>
#include <cstring>
using namespace std;

class String {
    private:
        char *str;
    public:
        // constructor
        String(const char *s) {
            int len = strlen(s);
            str = new char[len + 1];
            strcpy(str, s);
            cout << "len of str: " << strlen(str) << endl;
        }

        String() {
            str = new char[1];
            strcpy(str, " ");
            cout << "len of str: " << strlen(str) << endl;

        }

        // display function
        void display() {
            fputs(this->str, stdout);
        }

        // join function
        void join(String s1, String s2) {
            int len1 = strlen(this->str);
            int len2 = strlen(s1.str);
            str = new char[len1 + len2 + 1];
            strcpy(str, s1.str);
            strcat(str, s2.str);
        }
};

int main() {

    String s1("This is a ");
    String s2("String");
    String s3;
    s1.display();
    cout << endl;
    s2.display();
    cout << endl;
    s3.join(s1, s2);
    s3.display();
    return 0;
}
