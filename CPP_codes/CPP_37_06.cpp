#include <iostream>
using namespace std;
class LeapYear
{
    private:
        int year;

    public:
        // Constructor
        LeapYear(int year)
        {
            this->year = year;
        }

        // Destructor
        ~LeapYear()
        {
            cout << "Check complete. descructor called ~~~~" << endl;
        }

        bool is_leap_year()
        {
            if (year % 4 == 0)
            {
                if (year % 100 == 0)
                {
                    if (year % 400 == 0)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
        }
};

int main()
{
    int year;
    cout << "Enter a year: ";
    cin >> year;

    // Create an instance of the LeapYear class
    LeapYear *leap_year = new LeapYear(year);

    // Check if the year is a leap year
    if (leap_year->is_leap_year())
    {
        cout << year << " is a leap year." << endl;
    }
    else
    {
        cout << year << " is not a leap year." << endl;
    }
    delete leap_year;
    return 0;
}
