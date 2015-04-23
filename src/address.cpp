/*
 * address.cpp
 *
 *  Created on: Feb 16, 2015
 *      Author: Kristoffer Freiholtz
 */

#include"address.h"
#include<iomanip>

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

//------------------------------------------------------------------------------
// overloaded == operator
//
//------------------------------------------------------------------------------
bool Address::operator==(const Address &address) const {
	return streetAddress == address.getStreetAdress() &&
			city == address.getCity() &&
			postalNumber == address.getPostalNumber();
}

//------------------------------------------------------------------------------
// overloaded < operator
//
//------------------------------------------------------------------------------
bool Address::operator<(const Address &address) const {
	if (city < address.getCity()) {
		return true;
	} else if (city == address.getCity()) {
		if(streetAddress < address.getStreetAdress()){
			return true;
		}
	}
	return false;
}

//------------------------------------------------------------------------------
// overloaded << operator
//
//------------------------------------------------------------------------------
ostream &operator<<(ostream &os, const Address &address){
	os << address.getStreetAdress() << " " << address.getPostalNumber()
			<< " " << address.getCity();
	return os;
}

//------------------------------------------------------------------------------
// overloaded >> operator
//
//------------------------------------------------------------------------------
istream &operator>>(istream &is, Address &address){
	string tmpStreetAddress;
	string tmpStreetAddressNumber;
	string tmpPostalNumber;
	string tmpCity;
	is >> tmpStreetAddress;
	is >> tmpStreetAddressNumber;
	is >> tmpPostalNumber;
	is >> tmpCity;
	address.setStreetAddress(tmpStreetAddress + " " + tmpStreetAddressNumber);
	address.setPostalNumber(tmpPostalNumber);
	address.setCity(tmpCity);
	return is;
}


