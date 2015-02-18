/*
 * address.cpp
 *
 *  Created on: Feb 16, 2015
 *      Author: Kristoffer Freiholtz
 */

#include"address.h"

Address::Address(){
	address = "";
	postalNumber = "";
	city = "";
}
Address::Address(const string address, const string postalNumber, const string city){
	this->address = address;
	this->postalNumber = postalNumber;
	this->city = city;
}
void Address::setAddress(const string address){
	this->address = address;
}
void Address::setPostalNumber(const string postalNumber){
	this->postalNumber = postalNumber;
}
void Address::setCity(const string city){
	this->city = city;
}
string Address::getAdress() const{
	return address;
}
string Address::getPostalNumber() const{
	return postalNumber;
}
string Address::getCity() const{
	return city;
}


