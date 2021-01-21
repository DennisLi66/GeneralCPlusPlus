#ifndef CCalendar_H
#define CCalendar_H

#include <iostream>
#include <ctime>
#include <string.h> 
#include <stdio.h>
using namespace std;
/* 
ZELLERS CONGRUENCE
h = (q+ 13(m+1)/5 + K + K/4 + J/4 + 5J)modulo 7
h = day of week
q is the day of the month
m is the month (3 = March, 4 = April, 5 = May, ..., 14 = February)
K the year of the century (year mod 100)
J is the zero-based century (first two numbers of year) or (year / 100)
if month is january month is 13 and year is decremented
if month is february month is 14 and year is decremented

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
int zellersCongruence(int monthh, int yearr){
    int final = 0;
    int month = monthh;
    int year = yearr;
    if (monthh == 1){
        month = 13;
        year--;
    }
    if (monthh == 2){
        month = 14;
        year--;
    }
    string days[] = {"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
    final += 1; //step 1
    final += ((13 * (month + 1))/5); //step 2
    final += (year%100); //step 3
    final += (year%100)/4; //step 4
    final += (year/100)/4; //step 5
    final += 5 * (year/100); //step 6
    final = final % 7;
    // cout << final << "=" << 1 << " + " << ((13 * (month + 1))/5) << " + " << year % 100 << " + " << (year % 100)/4 <<  " + " << (year/100)/4 << " + " << 5 * (year/100) << endl;
    // cout << days << endl;
    // cout << days[final] << endl;
    if (final == 0){
        return 7;
    }
    return final;
}
int getMonthEnd(int month,int year){
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        return 31;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11 ){
        return 30;
    }
    else if (month == 2){
        if (year % 4 != 0){
            return 28;
        }
        else if (year % 100 != 0){
            return 29;
        }
        else if (year % 400 != 0){
            return 28;
        }
        return 29;
    }
    return -1;
}
bool printCalendar(int month, int year){
    string months[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    cout << months[month-1] << " of Year " << year << endl;
    cout << "S  M  T  W  T  F  S" << endl;
    int weekday = 1;
    int end = 0;
    int current = 1;
    weekday = zellersCongruence(month,year);
    end = getMonthEnd(month,year);
    for (int i = 1; i < weekday; i++){
        cout << "   ";
    }
    while (current <= end){
        if (weekday == 8){
            weekday = 1;
            cout << endl;
        }
        if (current < 10){
            cout << current << "  ";
        }
        else{
            cout << current << " ";
        }
        current++;
        weekday++;
    }
    cout << endl;
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
            year = getYear();
            // cout << "Current Month is " << month << endl;
            // cout << "Current Year is " << year << endl;
            printCalendar(month,year);
            string response2 = "";
            while (response2 != "Q" && response2 != "q"){
                cout << "Press:\n[1]: 1 Year Backwards\n[2]: 1 Month Backwards\n[3]: 1 Month Forwards\n[4]: 1 Year Forwards\n[Q]: Quit to Choosing Date"<< endl;
                cin >> response2;
                if (response2 == "1"){
                    if (year == 1){
                        cout << "Cannot go back any further." << endl;
                    }
                    else{
                        year--;
                        printCalendar(month,year);
                        }
                }
                else if (response2 == "2"){
                    if (month == 1 && year == 1){
                        cout << "Cannot go back any further." << endl;
                    }
                    else if (month == 1){
                        month = 12;
                        year--;
                        printCalendar(month,year);
                    }
                    else{
                        month--;
                        printCalendar(month,year);
                    }
                }
                else if (response2 == "Q" || response2 == "q"){}
                else if (response2 == "3"){
                    if (month == 12){
                        month = 1;
                        year++;
                        printCalendar(month,year);
                    }
                    else{
                        month++;
                        printCalendar(month,year);
                    }
                }
                else if (response2 == "4"){
                    year++;
                    printCalendar(month,year);
                }
                else{
                    response2 = "";
                    cout << "That was not a valid response." << endl;
                }
            } 
        }
        else if (response == "N" || response == "n"){
            cout << "Please input the date of the month that you would like to view." << endl;
            string responseMonth;
            while (responseMonth == ""){
                try{
                    cout << "Input the number of the month you would like to view." << endl << 
                    "[1] January\n[2] February\n[3] March\n[4] April\n[5] May\n[6] June\n[7] July\n[8] August\n[9] September\n[10] October\n[11] November\n[12] December\n";
                    cin >> responseMonth;
                    month = stoi(responseMonth);
                    if (month <= 0 || month >= 13){
                        throw;
                    }
                }
                catch (invalid_argument e){
                    cout << "That was not a valid month.\n";
                    responseMonth = "";
                }
            }
            string responseYear;
            while (responseYear == ""){
                try{
                    cout << "Input the year in A.D. you would like to view.\n I.E. Type in 2021 to view the year 2021." << endl;
                    cin >> responseYear;
                    year = stoi(responseYear);
                    if (year <= 0){
                        throw;
                    }
                    
                }
                catch (invalid_argument e){
                    cout << "That was not a valid year.";
                    responseMonth = "";
                }
            }
            printCalendar(month,year);
            string response2 = "";
            while (response2 != "Q" && response2 != "q"){
                cout << "Press:\n[1]: 1 Year Backwards\n[2]: 1 Month Backwards\n[3]: 1 Month Forwards\n[4]: 1 Year Forwards\n[Q]: Quit to Choosing Date"<< endl;
                cin >> response2;
                if (response2 == "1"){
                    if (year == 1){
                        cout << "Cannot go back any further." << endl;
                    }
                    else{
                        year--;
                        printCalendar(month,year);
                        }
                }
                else if (response2 == "2"){
                    if (month == 1 && year == 1){
                        cout << "Cannot go back any further." << endl;
                    }
                    else if (month == 1){
                        month = 12;
                        year--;
                        printCalendar(month,year);
                    }
                    else{
                        month--;
                        printCalendar(month,year);
                    }
                }
                else if (response2 == "Q" || response2 == "q"){}
                else if (response2 == "3"){
                    if (month == 12){
                        month = 1;
                        year++;
                        printCalendar(month,year);
                    }
                    else{
                        month++;
                        printCalendar(month,year);
                    }
                }
                else if (response2 == "4"){
                    year++;
                    printCalendar(month,year);
                }
                else{
                    response2 = "";
                    cout << "That was not a valid response." << endl;
                }
            }
        }
        else{ //invalid response
            cout << "That was not a valid response. Please input a valid response." << endl;
            cout << "[Y] will bring up the current month." << endl << "[N] will allow you to select a month of your choosing." << endl;
            cout << "[Q] will quit the application" << endl;
        }
            cout << "Would you like to look at the current month?" << endl << "Pressing:" << endl;
            cout << "[Y] will bring up the current month." << endl << "[N] will allow you to select a month of your choosing." << endl;
            cout << "[Q] will quit the application" << endl;
            cin >> response;
    }
    cout << "Quitting Calendar Application..." << endl;
    return true;
}








#endif