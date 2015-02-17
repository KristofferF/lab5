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

}

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


