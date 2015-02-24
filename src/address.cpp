/*
 * address.cpp
 *
 *  Created on: Feb 16, 2015
 *      Author: Kristoffer Freiholtz
 */

#include"address.h"

//------------------------------------------------------------------------------
// Förvald konstruktor (Default constructor)
//------------------------------------------------------------------------------
Address::Address(){
	streetAddress = "";
	postalNumber = "";
	city = "";
}

//------------------------------------------------------------------------------
// Konstruktor för initiering av datamedlemmarna
//------------------------------------------------------------------------------
Address::Address(const string streetAddress, const string postalNumber, const string city){
	this->streetAddress = streetAddress;
	this->postalNumber = postalNumber;
	this->city = city;
}

//------------------------------------------------------------------------------
// setAddress
// Datamedlemmen address ges värdet av parametern address
//------------------------------------------------------------------------------
void Address::setStreetAddress(const string streetAddress){
	this->streetAddress = streetAddress;
}

//------------------------------------------------------------------------------
// setPostalNumber
// Datamedlemmen postalNumber ges värdet av parametern postalNumber
//------------------------------------------------------------------------------
void Address::setPostalNumber(const string postalNumber){
	this->postalNumber = postalNumber;
}

//------------------------------------------------------------------------------
// setCity
// Datamedlemmen city ges värdet av parametern city
//------------------------------------------------------------------------------
void Address::setCity(const string city){
	this->city = city;
}

//------------------------------------------------------------------------------
// getAddress
// Returnera datamedlemmen address (string)
//------------------------------------------------------------------------------
string Address::getStreetAdress() const{
	return streetAddress;
}

//------------------------------------------------------------------------------
// getPostalNumber
// Returnera datamedlemmen postalNumber (string)
//------------------------------------------------------------------------------
string Address::getPostalNumber() const{
	return postalNumber;
}

//------------------------------------------------------------------------------
// getCity
// Returnera datamedlemmen city (string)
//------------------------------------------------------------------------------
string Address::getCity() const{
	return city;
}


