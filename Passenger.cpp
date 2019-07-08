#include "Passenger.h"

#include <string>

using std::cout;
using std::endl;
using namespace PassengerReservation;



Passenger::Passenger() {}



Passenger::Passenger(string& firstName, string& lastName, string& birthDate, char& gender, string& emailAddress)

{
	this->FirstName = firstName;
	this->LastName = lastName;
	this->BirthDate = birthDate;
	this->Gender = gender;
	this->EmailAddress = emailAddress;
}


bool PassengerReservation::Passenger::operator==(const Passenger& planePassenger) const

{

	return planePassenger.FirstName.compare(this->FirstName) == 0 &&
		planePassenger.LastName.compare(this->LastName) == 0 &&
		planePassenger.EmailAddress.compare(this->EmailAddress) == 0;

}



void PassengerReservation::Passenger::DisplayPassengerInfo()

{
	cout << "Passenger Name: " << this->PassengerFirstName() << " " << this->PassengerLastName() << endl;
	cout << "Date of Birth: " << this->PassengerBirthDate() << endl;
	cout << "Gender: " << this->PassengerGender() << endl;
	cout << "Email address: " << this->PassengerEmail() << endl;

}