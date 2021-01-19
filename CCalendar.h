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
int zellersCongruence(int month, int year){
    int final = 0;
    string days[] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    final += 1; //step 1
    final += ((13 * (month + 1))/5); //step 2
    final += (year%100); //step 3
    final += (year%100)/4; //step 4
    final += (year/100)/4; //step 5
    final += 5 * (year/100); //step 6
    final = final%7;
    // cout << final << "=" << 1 << " + " << ((13 * (month + 1))/5) << " + " << year % 100 << " + " << (year % 100)/4 <<  " + " << (year/100)/4 << " + " << 5 * (year/100) << endl;
    cout << days[final] << endl;
    return final;
}

bool printCalendar(int month, int year){
    string months[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    cout << months[month-1] << " of Year " << year << endl;
    cout << "  S  M  T  W  T  F  S  " << endl;
    // cout << zellersCongruence(2,2021) << endl;
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
                    cout << "That was not a valid month.";
                    responseMonth = "";
                }
            }
            string responseYear;
            while (responseYear == ""){
                try{
                    cout << "Input the year in A.D. you would like to view.\n I.E. Type in 2021 to view the year 2021." << endl;
                    cin >> responseYear;
                    
                }
                catch (invalid_argument e){
                    cout << "That was not a valid year.";
                    responseMonth = "";
                }
            }
        }
        else{ //invalid response
            cout << "That was not a valid response. Please input a valid response." << endl;
            cout << "[Y] will bring up the current month." << endl << "[N] will allow you to select a month of your choosing." << endl;
            cout << "[Q] will quit the application" << endl;
        }
        
        cin >> response;
    }
    cout << "Quitting Calendar Application..." << endl;
    return true;
}








#endif