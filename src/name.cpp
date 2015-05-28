/*
 * name.cpp
 *
 *  Created on: Feb 16, 2015
 *      Author: Kristoffer Freiholtz
 */

#include"name.h"
#include<iomanip>
extern const char DELIM = '|';

//------------------------------------------------------------------------------
// Förvald konstruktor (Default constructor)
//------------------------------------------------------------------------------
Name::Name() {
	firstName = "";
	lastName = "";
}

//------------------------------------------------------------------------------
// Konstruktor föˆr initiering av datamedlemmarna
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

//------------------------------------------------------------------------------
// overloaded << operator
//
//------------------------------------------------------------------------------
ostream &operator<<(ostream &os, const Name &name){
	os  << name.getFirstName() << DELIM  << name.getLastName() << DELIM;
	return os;
}

//------------------------------------------------------------------------------
// overloaded >> operator
//
//------------------------------------------------------------------------------
istream &operator>>(istream &is, Name &name){
	string tmpFirstName;
	string tmpLastName;
	getline(is, tmpFirstName, DELIM);
	getline(is, tmpLastName, DELIM);
	name.setFirstName(tmpFirstName);
	name.setLastName(tmpLastName);
	return is;
}
