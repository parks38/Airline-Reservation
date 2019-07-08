// FlightReservation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Passenger.h"

using namespace std;
using namespace PassengerReservation;
int firstClassSold, coachClassSold, coachSold = 0;
int currentFirst, currentC1, currentC2 = 0;
int numTicks = 0;
char coach1[5][6];
char coach2[5][6];
char firstClass[5][4];
char flight[1];

void displayMenu();
void getMenuSelection();
void reserveSeat();
void flightSchedule();
void passengerInfo();
void seatAssign();
void checkEmptySeat();
void checkSeatAvaliable(int, int);
void showSeatingChart();
void fillSeatingChart();




int main()
{
	fillSeatingChart();
	displayMenu();
}

void fillSeatingChart() {
	for (int row = 0; row < 5; row++) {
		for (int col = 0; col < 4; col++) {
			firstClass[row][col] = '#';
		}
	}

	for (int row = 0; row < 5; row++) {
		for (int col = 0; col < 6; col++) {
			coach1[row][col] = '#';
		}
	}

	for (int row = 0; row < 5; row++) {
		for (int col = 0; col < 6; col++) {
			coach2[row][col] = '#';
		}
	}
}

void displayMenu() {
	cout << "Welcome to Flight Booking Program" << endl << endl;
	cout << "Main Menu: " << endl;
	cout << "1. Flight Schedule" << endl;
	cout << "0. Exit Program" << endl;

	cout << "Please select your choice: ";
	getMenuSelection();
	cout << endl;
}

void getMenuSelection() {
	const int
		FLIGHT_SCHEDULE = 1,
		EXIT = 0;

	int choice;
	cin >> choice;
	cout << "------------------------------";

	while (choice > 1 || choice < 0) {
		cout << "Please re-enter valid menu choice: ";
		cin >> choice;
	}
	cout << endl;

	switch (choice) {

	case  FLIGHT_SCHEDULE:
		flightSchedule();
		break;


	case EXIT:
		exit(0);
	}

	cout << "*********************************" << endl;

	}


	void showSeatingChart() {
		cout << "***Seating Chart***" << endl;
		cout << "\t" << "1 2 3 4" << endl;
		for (int row = 0; row < 5; row++) {
			cout << "Row " << (row + 1) << "\t";
			for (int col = 0; col < 4; col++) {
				cout << firstClass[row][col] << " ";
			}
			cout << endl;
		}

		cout << "\t" << "1 2 3  4 5 6" << endl;
		for (int row = 0; row < 5; row++) {
			cout << "Row " << (row + 6) << "\t";
			for (int col = 0; col < 6; col++) {
				cout << coach1[row][col] << " ";
				if (col == 2)
					cout << " ";
			}
			cout << endl;
		}
		for (int row = 0; row < 5; row++) {
			cout << "Row " << (row + 11) << "\t";
			for (int col = 0; col < 6; col++) {
				cout << coach2[row][col] << " ";
				if (col == 2)
					cout << " ";
			}
			cout << endl;
		}
		cout << endl;

	}

	void reserveSeat() {
		showSeatingChart();
		double  currentTotal = 0;
		int numTickets;
		cout << "How many tickets would you like to reserve?: ";
		cin >> numTickets;
		cout << endl;
		
		for (int i = 0; i < numTickets; i++) {
			numTicks++;
			seatAssign();
		}
		passengerInfo();
	}

	void seatAssign() {
		int row, col;
		cout << "What row do you want your seat? (First Class: 1 - 4/ Coach: 6 - 15): ";
		cin >> row;
		while (row < 1 || row > 15) {
			cout << "Choose a valid row. Please enter a row 1 - 15: ";
			cin >> row;
		}

		cout << "What column do you want your seat? (First Class: 1-4 / Coach: 1 - 6): ";
		cin >> col;
		cout << endl;
		if (row >= 1 && row <= 5) {
			while (col < 1 || col > 4) {
				cout << "First class seating only has 4 columns." << endl
					<< "Please enter a column 1 - 4: ";
				cin >> col;
				cout << endl;
			}
		}
		else if (row >= 6 && row <= 15) {
			while (col < 1 || col > 6) {
				cout << "Coach seating only has 6 columns." << endl
					<< "Please enter a column 1 - 6: ";
				cin >> col;
				cout << endl;
			}
		}
		checkSeatAvaliable(row, col);
		checkEmptySeat();
		

	}

	void checkSeatAvaliable(int row, int col) {
		if (row >= 1 && row <= 5) {
			if (firstClass[row - 1][col - 1] == '*'){
				cout << "Sorry, that seat is already taken." << endl;
				seatAssign();
			}
			if (firstClass[row - 1][col - 1] != '*') {
				firstClass[row - 1][col - 1] = '*';
				currentFirst++;
			}
		}

		if (row >= 6 && row <= 10) {
			if (coach1[row - 6][col - 1] == '*') {
				cout << "Sorry, that seat is already taken." << endl;
				seatAssign();
			}

			if (coach1[row - 6][col - 1] != '*') {
				coach1[row - 6][col - 1] = '*';
				currentC1++;
			}
		}

		if (row >= 11 && row <= 15) {
			if (coach2[row - 11][col - 1] == '*') {
				cout << "Sorry, that seat is already taken." << endl;
				seatAssign();
			}

			if (coach2[row - 11][col - 1] != '*') {
				coach2[row - 11][col - 1] = '*';
				currentC2++;
			}
		}
	}

	void checkEmptySeat() {
		int emptyTotal, emptyFirst = 0, emptyC1 = 0, emptyC2 = 0;
		for (int row = 0; row < 5; row++) {
			for (int col = 0; col < 4; col++) {
				if (firstClass[row][col] == '#') {
					emptyFirst++;
				}
			}


			for (int row = 0; row < 5; row++) {
				for (int col = 0; col < 6; col++) {
					if (coach1[row][col] == '#') {
						emptyC1++;
					}
				}
			}

			for (int row = 0; row < 5; row++) {
				for (int col = 0; col < 6; col++) {
					if (coach2[row][col] == '#') {
						emptyC2++;
					}
				}
			}
		}

		emptyTotal = emptyFirst + emptyC1 + emptyC2;
		cout << "There are " << emptyTotal << " empty seats on the plane." << endl << endl
			<< "First Class empty: " << emptyFirst << " seats" << endl
			<< "Coach Class empty: " << emptyC1 + emptyC2 << " seats" << endl
			<< "    Section 1: " << emptyC1 << endl
			<< "    Section 2: " << emptyC2 << endl << endl;


	}

	void flightSchedule() {
		cout << "[ Flight Schedule ]" << endl
			<< "SEATAC -----------------> LAX" << endl
			<< "1. Alaska   8:35 AM - 2:06 PM    5h 31m    1stop     $156" << endl
			<< "2. United   12:00 PM - 5:04 PM    5h 4m    1stop     $156" << endl
			<< "3. Alaska   4:35 PM - 9:37 PM    5h 07m    1stop     $156" << endl
			<< "4. Delta    3:36 PM - 6:26 PM    2h 50m    1stop     $177" << endl
			<< "5. Americ   12:25 PM - 3:09 PM   2h 44m    1stop     $194" << endl
			<< "6. Alaska   6:25 AM - 9:10 PM    2h 45m    1stop     $209" << endl
			<< "7. Americ   7:05 PM - 9:45 PM    2h 40m    1stop     $218" << endl
			<< "8. Alaska   10:25 AM - 1:25 PM   3h 00m    1stop     $237" << endl
			<< "9. Delta    7:55 AM - 10:55 AM   3h 00m    1stop     $287" << endl
			<< "10. Frontier 6:32 PM - 11:08 PM   16h 36m   1stop     $327" << endl
			<< "11. Alaska   8:35 AM - 11:35 PM   3h 00m    1stop     $257" << endl
			<< " " << endl;

		cout << "Please select your choice: ";
			int choice;
			cin >> choice;
		cout << endl;

		switch (choice) {
			case 1:
				flight == "Alaska   8:35 AM - 2:06 PM    5h 31m    1stop     $156";
				break;
			case 2:
				flight == "United   12 : 00 PM - 5 : 04 PM    5h 4m    1stop     $156";
				break;
			case 3:
				flight == "Alaska   4:35 PM - 9:37 PM    5h 07m    1stop     $156";
				break;
			case 4:
				flight == "Delta    3:36 PM - 6:26 PM    2h 50m    1stop     $177";
				break;
			case 5:
				flight == "Americ   12:25 PM - 3:09 PM   2h 44m    1stop     $194";
				break;
			case 6: 
				flight == "Alaska   6:25 AM - 9:10 PM    2h 45m    1stop     $209";
				break;
			case 7:
				flight == "Americ   7:05 PM - 9:45 PM    2h 40m    1stop     $218";
				break;
			case 8:
				flight == "Alaska   10:25 AM - 1:25 PM   3h 00m    1stop     $237";
				break;
			case 9:
				flight == "Delta    7:55 AM - 10:55 AM   3h 00m    1stop     $287";
				break;
			case 10:
				flight == "Frontier 6:32 PM - 11:08 PM   16h 36m   1stop     $327";
				break;
			case 11:
				flight == "Alaska   8:35 AM - 11:35 PM   3h 00m    1stop     $257";
				break;
		}

		reserveSeat();


	}


	void passengerInfo() {
		string firstName;
		string lastName;
		string birthDate;
		string gender;
		string emailAddress;

		cout << "Enter passenger's first name: " << endl;
		cin >> firstName;
		cout << "Enter passenger's last name: " << endl;
		cin >> lastName;
		cout << "Enter passenger's date of birth (mm/dd/yyyy): " << endl;
		cin >> birthDate;
		cout << "Enter passenger's gender (F for female, M for male): " << endl;
		cin >> gender;
		cout << "Enter passenger's email address: " << endl;
		cin >> emailAddress;

		/*
		cout << firstName + lastName << endl
			<< gender << endl
			<< birthDate << endl
			<< emailAddress << endl

		*/

		 cout	<< "You reserved " << numTicks << " ticket(s) for Seattle-Tacoma Airport to LAX Airport." << endl
			<< " "  << endl;


		cout << "Confirmed Reservation. Thank you" << endl
			<< " " << endl
			<< "**************************************" << endl;
		displayMenu();
	}




