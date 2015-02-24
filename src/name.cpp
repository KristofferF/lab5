/*
 * name.cpp
 *
 *  Created on: Feb 16, 2015
 *      Author: Kristoffer Freiholtz
 */

#include "name.h"

//------------------------------------------------------------------------------
// Förvald konstruktor (Default constructor)
//------------------------------------------------------------------------------
Name::Name(){
	firstName = "";
	lastName = "";
}

//------------------------------------------------------------------------------
// Konstruktor för initiering av datamedlemmarna
//------------------------------------------------------------------------------
Name::Name(const string firstName,const string lastName){
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
void Name::setLastName(const string lastName){
	this->lastName = lastName;
}

//------------------------------------------------------------------------------
// getFirstName
// Returnera datamedlemmen firstName (string)
//------------------------------------------------------------------------------
string Name::getFirstName() const{
	return firstName;
}

//------------------------------------------------------------------------------
// getLastName
// Returnera datamedlemmen lastName (string)
//------------------------------------------------------------------------------
string Name::getLastName() const{
	return lastName;
}


