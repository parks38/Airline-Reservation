#include <iostream>
#include <map>
#include <string>
#pragma once 

using std:: string;

namespace PassengerReservation {
	class Passenger {
	public :
		Passenger();
		Passenger(string& firstName, string& lastName, string& birthDate, char& gender, string& emailAddress);


		string PassengerFirstName() { return FirstName; };
		string PassengerLastName() { return LastName; };
		string PassengerBirthDate() { return BirthDate; };
		char PassengerGender() { return Gender; };
		string PassengerEmail() { return EmailAddress; };
		bool operator== (const Passenger& planePassenger) const;
		void DisplayPassengerInfo();


	private:
		string FirstName;
		string LastName;
		string BirthDate;
		char Gender = NULL;
		string EmailAddress;

	};
}