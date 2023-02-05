#include <iostream>
using namespace std;

class Time {
    private:
        int hours;
        int minutes;
        int seconds;
    public:
        // Overloaded '>>' operator to accept time from user
        friend istream& operator>>(istream& input, Time& t) {
            input >> t.hours >> t.minutes >> t.seconds;
            return input;
        }

        // Overloaded '+' operator to add two different user-given times
        Time operator+(const Time& t) {
            Time temp;
            temp.seconds = seconds + t.seconds;
            temp.minutes = minutes + t.minutes + temp.seconds / 60;
            temp.hours = hours + t.hours + temp.minutes / 60;
            temp.seconds %= 60;
            temp.minutes %= 60;
            return temp;
        }

        // Overloaded '<<' operator to display time in hours:mins:sec format
        friend ostream& operator<<(ostream& output, Time& t) {
            output << t.hours << ":" << t.minutes << ":" << t.seconds;
            return output;
        }

        // Overloaded '==' operator to check whether two user-given times are equal or not
        bool operator==(const Time& t) {
            return (hours == t.hours && minutes == t.minutes && seconds == t.seconds);
        }
};

int main() {
    Time t1, t2, t3;
    cout << "Enter time 1 (hours:mins:secs): ";
    cin >> t1;
    cout << "Enter time 2 (hours:mins:secs): ";
    cin >> t2;

    t3 = t1 + t2; // Add t1 and t2 using overloaded '+' operator

    cout << "Time 1: " << t1 << endl;
    cout << "Time 2: " << t2 << endl;
    cout << "Time 1 + Time 2: " << t3 << endl;

    if (t1 == t2) // Compare t1 and t2 using overloaded '==' operator
        cout << "Time 1 and Time 2 are equal." << endl;
    else
        cout << "Time 1 and Time 2 are not equal." << endl;

    return 0;
}
