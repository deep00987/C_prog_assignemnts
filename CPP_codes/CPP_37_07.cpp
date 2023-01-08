#include <iostream>
// unfinished 
using namespace std;

class String
{
private:
    string str;

public:
    // Constructor to initialize the string
    String(string str)
    {
        this->str = str;
    }

    // Member function to display the string
    void display()
    {
        cout << str << endl;
    }

    // User-defined function to join two strings
    String join(String s2)
    {
        return String(str + " " + s2.str);
    }
};

int main()
{
    string str1, str2;
    cout << "enter string 1 \n";
    cin >> str1;
    cout << "enter string 2 \n";
    cin >> str2;


    String s1(str1);
    String s2(str2);

    // Display the strings
    s1.display();
    s2.display();

    // Join the two strings
    String s3 = s1.join(s2);
    s3.display();

    return 0;
}
