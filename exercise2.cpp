/*Q1 – Write a function compareDates, describe as follows: 

int compareDates(int year1, int month1, int day1, int year2, int month2, int day2) 

 

This function returns  

-1 if date1 < date2 

0 if date1 == date2 

1 if date1 > date2 

 

Q2 – Write the main() function to  input the dates and output the result 

Make sure your code work for all the above test cases 

 

Q3 – (BONUS) We want to ensure the input values for year, month, and day are valid: */

#include <iostream>
using namespace std;

int compareDates(int year1, int month1, int day1, int year2, int month2, int day2);
bool isValidDate(int year, int month, int day);
bool isLeap(int year);

int main() {
    int year1, month1, day1;
    int year2, month2, day2;

    // Input for the first date
    cout << "Enter the first date (year month day): ";
    cin >> year1 >> month1 >> day1;

    // Input for the second date
    cout << "Enter the second date (year month day): ";
    cin >> year2 >> month2 >> day2;

    // Validate both dates
    if (!isValidDate(year1, month1, day1) || !isValidDate(year2, month2, day2)) {
        cout << "Invalid dates" << endl;
    } else {
        // Compare the two dates
        int result = compareDates(year1, month1, day1, year2, month2, day2);

        // Output the result of who is younger
        if (result == -1)
            cout << "The second person is younger." << endl;
        else if (result == 0)
            cout << "Both are the same age." << endl;
        else
            cout << "The first person is younger." << endl;
    }

    return 0;
}

int compareDates(int year1, int month1, int day1, int year2, int month2, int day2) {
    if (year1 < year2)
        return -1;
    else if (year1 > year2)
        return 1;
    else {
        if (month1 < month2)
            return -1;
        else if (month1 > month2)
            return 1;
        else {
            if (day1 < day2)
                return -1;
            else if (day1 > day2)
                return 1;
            else
                return 0;
        }
    }
}

bool isLeap(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool isValidDate(int year, int month, int day) {
    if (year < 1) return false;  // Year must be positive
    if (month < 1 || month > 12) return false;  // Month must be between 1 and 12

    // Array of days in each month for non-leap years
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Adjust February days for leap years
    if (month == 2 && isLeap(year)) {
        daysInMonth[2] = 29;
    }

    if (day < 1 || day > daysInMonth[month]) return false;  // Check if day is valid for the given month

    return true;
}