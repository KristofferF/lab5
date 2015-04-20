/*
 * name.cpp
 *
 *  Created on: Feb 16, 2015
 *      Author: Kristoffer Freiholtz
 */

#include"name.h"
#include<iomanip>

//------------------------------------------------------------------------------
// Förvald konstruktor (Default constructor)
//------------------------------------------------------------------------------
Name::Name() {
	firstName = "";
	lastName = "";
}

//------------------------------------------------------------------------------
// Konstruktor för initiering av datamedlemmarna
//------------------------------------------------------------------------------
Name::Name(const string firstName, const string lastName) {
	this->firstName = firstName;
	this->lastName = lastName;
}

//------------------------------------------------------------------------------
// setFirstName
// Datamedlemmen firstName ges värdet av parametern firstName
//------------------------------------------------------------------------------
void Name::setFirstName(const string firstName){
	this->firstName = firstName;
}

//------------------------------------------------------------------------------
// setLastName
// Datamedlemmen lastName ges värdet av parametern lastName
//------------------------------------------------------------------------------
void Name::setLastName(const string lastName) {
	this->lastName = lastName;
}

//------------------------------------------------------------------------------
// getFirstName
// Returnera datamedlemmen firstName (string)
//------------------------------------------------------------------------------
string Name::getFirstName() const {
	return firstName;
}

//------------------------------------------------------------------------------
// getLastName
// Returnera datamedlemmen lastName (string)
//------------------------------------------------------------------------------
string Name::getLastName() const {
	return lastName;
}

//------------------------------------------------------------------------------
// overloaded == operator
//
//------------------------------------------------------------------------------
bool Name::operator==(const Name &name) const {
	return firstName == name.getFirstName() && lastName == name.getLastName();
}

//------------------------------------------------------------------------------
// overloaded < operator
//
//------------------------------------------------------------------------------
bool Name::operator<(const Name &name) const {
	if (lastName < name.getLastName()) {
		return true;
	} else if (lastName == name.getLastName()) {
		if(firstName < name.getFirstName()){
			return true;
		}
	}
	return false;
}

ostream &operator<<(ostream &os, const Name &name){
	os << setw(2) << name.getFirstName() << " " << setw(2) << name.getLastName();
	return os;
}

istream &operator>>(istream &is, Name &name){
	string tmpFirstName;
	string tmpLastName;
	cout << "First Name: ";
	is >> tmpFirstName;
	cout << "Last Name: ";
	is >> tmpLastName;
	name.setFirstName(tmpFirstName);
	name.setLastName(tmpLastName);
	return is;
}
