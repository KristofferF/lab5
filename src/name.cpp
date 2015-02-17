/*
 * name.cpp
 *
 *  Created on: Feb 16, 2015
 *      Author: Kristoffer Freiholtz
 */

#include "name.h"

void Name::setFirstName(const string name){
	firstName = name;
}

void Name::setLastName(const string name){
	lastName = name;
}

string Name::getFirstName() const{
	return firstName;
}

string Name::getLastName() const{
	return lastName;
}


