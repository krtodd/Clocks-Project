/*
 * driver.cpp
 *
 *  Created on: Jul 11, 2020
 *      Author: keri.todd
 */

#include <iostream>
#include <ctime>
#include "time.h"
#include <stdlib.h>
#include <iomanip>

using namespace std;

void ClearScreen(){ //function to clear the screen
	cout << string(100, '\n');
}
void ConvertTime(int hr, int min, int sec){ //function to convert from 24hr clock to 12hr clock
	int _12HrTime = hr - 12;

	if (hr > 12){
		std::cout << "*" << std::setw(10) << _12HrTime << ":" << min << ":" << sec << "PM" << std::setw(8) << "*";
	}
	else if (hr == 12){
		std::cout << "*" << std::setw(10) << hr << ":" << min << ":" << sec << "PM" << std::setw(8) << "*";
	}
	else if (hr < 10){
		std::cout << "*" << std::setw(10) << "0" << hr << ":" << min << ":" << sec << "AM" <<  std::setw(8) << "*";
	}
	else if (min < 10 && hr < 12){
		std::cout << "*" << std::setw(10) << hr << ":" << "0" << min << ":" << sec << "AM" << std::setw(8) << "*";
	}
	else if (hr < 10 && min < 10 && sec < 10){
		std::cout << "*" << std::setw(10) << "0" << hr << ":" << "0" << min << ":" << "0" << sec << "AM" << std::setw(8) << "*";
	}
	else if (sec < 10 && hr < 12){
		std::cout << "*" << std::setw(10) << hr << ":" << min << ":" << "0" << sec << "AM" << std::setw(8) << "*";
	}
	else if (sec < 10 && hr == 12){
		std::cout << "*" << std::setw(10) << hr << ":" << min << ":" << "0" << sec << "PM" << std::setw(8) << "*";
	}
	else if (min < 10 && hr == 12){
		std::cout << "*" << std::setw(10) << hr << ":" << "0" << min << ":" << sec << "PM" << std::setw(8) << "*";
	}
	else if (sec < 10 && hr > 12){
		std::cout << "*" << std::setw(10) << _12HrTime << ":" << min << ":" << "0" << sec << "PM" << std::setw(8) << "*";
	}
	else if (min < 10 && hr > 12){
		std::cout << "*" << std::setw(10) << _12HrTime << ":" << "0" << min << ":" << sec << "AM" << std::setw(8) << "*";
	}
	else if (hr == 12 && min < 10 && sec < 10){
		std::cout << "*" << std::setw(10) << hr << ":" << "0" << min << ":" << "0" << sec << "PM" << std::setw(8) <<"*";
	}
	else if (hr > 12 && min < 10 && sec < 10){
		std::cout << "*" << std::setw(10) << _12HrTime << ":" << "0" << min << ":" << "0" << sec << "PM" << std::setw(8) << "*";
	}
}
void DisplayClocks(int hr, int min, int sec){ //function to display both clocks
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);

	cout << "**************************\t **************************" << endl;
	std::cout << "*" << std::setw(20) << "12-Hour Clock" << std::setw(5) << "*" << std::setw(8) << "*" << std::setw(18) << "24-Hour Clock" << std::setw(7) << "*" << std::endl;

	ConvertTime(hr, min, sec); //calls ConvertTime() function to display 12hr clock

	if (hr < 10 && min < 10 && sec < 10){
		cout <<"\t *  \t  0" << hr << ":" << "0" << min << ":" << "0" << sec << "\t  *" << endl;
	}
	else if (hr < 10 && min < 10){
		cout <<"\t *  \t  " << "0" << hr << ":" << "0" << min << ":" << sec << "\t  *" << endl;
	}
	else if (hr < 10 && sec < 10){
		cout <<"\t *  \t  " << "0" << hr << ":" << min << ":" << "0" << sec << "\t  *" << endl;
	}
	else if (min < 10 && sec < 10){
		cout <<"\t *  \t  " << hr << ":" << "0" << min << ":" << "0" << sec << "\t  *" << endl;
	}
	else if (hr < 10){
		cout <<"\t *  \t  " << "0" << hr << ":" << min << ":" << sec << "\t  *" << endl;
	}
	else if (min < 10){
		cout <<"\t *  \t  " << hr << ":" << "0" << min << ":" << sec << "\t  *" << endl;
	}
	else if (sec < 10){
		cout <<"\t *  \t  " << hr << ":" << min << ":" << "0" << sec << "\t  *" << endl;
	}
	else {
	cout <<"\t *  \t  " << hr << ":" << min << ":" << sec << "\t  *" << endl;
	}

	cout << "**************************\t **************************" << endl;
}
void DisplayMenu() { //function to show the menu to the user
	cout << "**************************" << endl;
	cout << "* " << "1 - Add One Hour" << "\t *" << endl;
	cout << "* " << "2 - Add One Minute" << "\t *" << endl;
	cout << "* " << "3 - Add One Second" << "\t *" << endl;
	cout << "* " << "4 - Exit Program" << "\t *" << endl;
	cout << "**************************" << endl;
}

void AddMinute(int hr, int min, int sec){ //function to add a minute to the current time and display clocks with updated time

	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	min = timePtr -> tm_min;

	if (min == 59){
		min = 00;
	}
	else{
		min = min + 1;
	}

	DisplayClocks(timePtr -> tm_hour,min, timePtr -> tm_sec); //Calls DisplaysClocks() to output updated times
}
void AddHour(int hr, int min, int sec){ //function to add an hour
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);

		if (hr == 12){
			hr = 01;
		}
		else if (hr == 23){
			hr = 00;
		}
		else{
			hr = hr + 1;
		}

	DisplayClocks(hr,timePtr -> tm_min, timePtr -> tm_sec);
}
void AddSecond(int hr, int min, int sec){ //function to add one second to the current time
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);

			if (sec == 59){
				sec = 00;
			}
			else{
				sec = sec + 1;
			}

	DisplayClocks(timePtr -> tm_hour,timePtr -> tm_min, sec);
}
int main()
{
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	char userInput;
	int userChoice;
	bool breakOutOfLoop = false;

	DisplayClocks(timePtr -> tm_hour, timePtr -> tm_min, timePtr -> tm_sec);
	while (true){
		cin >> userInput;

		while (true){
			DisplayMenu();
			cin >> userChoice;

			switch (userChoice){
			case 1:
				ClearScreen();
				AddHour(timePtr -> tm_hour, timePtr -> tm_min, timePtr -> tm_sec);
				breakOutOfLoop = true;
				break;

			case 2:
				ClearScreen();
				AddMinute(timePtr -> tm_hour, timePtr -> tm_min, timePtr -> tm_sec);
				breakOutOfLoop = true;
				break;

			case 3:
				ClearScreen();
				AddSecond(timePtr -> tm_hour, timePtr -> tm_min, timePtr -> tm_sec);
				breakOutOfLoop = true;
				break;

			case 4:
				cout << "Exiting program." << endl;
				exit (1);

			default:
				cout << "Invalid option. Please choose again." << endl;
				break;
			}
		if (breakOutOfLoop){
			break;
		}
		}
	}

	return 0;
}



