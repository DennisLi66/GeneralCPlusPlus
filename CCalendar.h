#ifndef CCalendar_H
#define CCalendar_H

#include <iostream>
#include <ctime>
#include <string.h> 
#include <stdio.h>
using namespace std;
/* 
ZELLERS CONGRUENCE
h = (1+13(m+1)/5 + K + K/4 + J/4 + 5J)modulo 7

LEAP YEARS
if (year is not divisible by 4) then (it is a common year)
else if (year is not divisible by 100) then (it is a leap year)
else if (year is not divisible by 400) then (it is a common year)
else (it is a leap year)
*/

bool checkDayExists(int day, int month, int year){
    if (year <= 0){
        cout << "This program wasn't meant to handle B.C. years. " << endl;
    }
    else if (month <= 0 || month >= 13){
        return false;}
    else if (day <= 28 && day >= 0){
        return true;
    }
    else if (day >= 32 || day <= 0){
        return false;
    }
    else if (day <= 30 && day >= 1 && month != 2){
        return true;
    }
    else if (day == 31 && day >= 1){
        // if month in [1,3,5,7,8,10,12] &&
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
            return true;
        }
        return false;
    }
    else if (month == 2 && day == 29){
        if (year % 4 != 0){
            return false;
        }
        else if (year % 100 != 0){return true;}
        else if (year % 400 != 0){return false;}
        else{return true;}
    }
    return false;
}

int getMonth(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return 1 + ltm->tm_mon;
}

int getYear(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return 1900 + ltm->tm_year;
}

bool printCalendar(int month, int year){
    string months[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    cout << months[month] << " of Year " << year << endl;
    return true;
}

bool runCalendar(){
    cout << "Welcome to the Calendar Application." << endl;
    cout << "Would you like to look at the current month?" << endl << "Pressing:" << endl;
    cout << "[Y] will bring up the current month." << endl << "[N] will allow you to select a month of your choosing." << endl;
    cout << "[Q] will quit the application" << endl;
    string response;
    cin >> response;
    while(response != "Q" && response != "q"){
        int month = 0;
        int year = 0;
        if (response == "Y" || response == "y"){
            cout << "Using Today's Date:" << endl;
            month = getMonth();
            cout << "Current Month is " << getMonth() << endl;
            cout << "Current Year is " << getYear() << endl;
            printCalendar(month,year);


        }
        cin >> response;
    }
    cout << "Quitting Calendar Application..." << endl;
    return true;
}








#endif