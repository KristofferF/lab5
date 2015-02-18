/*
 * name.cpp
 *
 *  Created on: Feb 16, 2015
 *      Author: Kristoffer Freiholtz
 */

#include "name.h"

Name::Name(){
	firstName = "";
	lastName = "";
}

Name::Name(const string firstName,const string lastName){
	this->firstName = firstName;
	this->lastName = lastName;
}

void Name::setFirstName(const string firstName){
	this->firstName = firstName;
}

void Name::setLastName(const string lastName){
	this->lastName = lastName;
}

string Name::getFirstName() const{
	return firstName;
}

string Name::getLastName() const{
	return lastName;
}


