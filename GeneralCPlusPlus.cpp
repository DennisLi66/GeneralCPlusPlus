#include <iostream>
#include "CCalendar.h"
#include "Grades.h"
using namespace std;

//This code will be the main hub for the other codes.

int main() {
   cout << "Welcome to the general code for C++!\n"; 
   cout << "Press:\n";
   cout << "[1] to view a calendar application\n";
   cout << "[2] to view the school grades application\n."
   cout << "[Q]uit or [q]uit to quit.\n";
   string response;
   cin >> response;
   while (response != "Q" && response != "q"){
      if (response == "1"){
         cout << "You've selected the calendar application.\n";
         runCalendar();
      }
      else if (response == "2"){
         cout << "You've selected the school grades application.\n" << endl;
         runGrades();
      }
      else{
         cout << "Sorry, that was not a valid option. Please enter a valid option.\n";
         cin >> response;
      }
      cout << "Press:\n";
      cout << "[1] to view a calendar application.\n";
      cout << "[Q]uit or [q]uit to quit.\n";
      cin >> response;
   }
   cout << "Quitting Application..." << endl;
   return 0;
}