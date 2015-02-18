/*
 * person.cpp
 *
 *  Created on: Feb 17, 2015
 *      Author: kristoffer
 */

#include "person.h"

Person::Person(){
	persNr = "";
	shoeSize = 0;
}
Person::Person(const string firstName, const string lastName, const string address, const string postalNumber,
			const string city, const string persNr, const int shoeSize){
	name = Name(firstName, lastName);
	this->address = Address(address, postalNumber, city);
	this->persNr = persNr;
	this->shoeSize = shoeSize;
}
void Person::setFirstName(const string firstName){
	name.setFirstName(firstName);
}
void Person::setLastName(const string lastName){
	name.setLastName(lastName);
}
void Person::setAddress(const string address){
	this->address.setAddress(address);
}
void Person::setPostalNumber(const string postalNumber){
	address.setPostalNumber(postalNumber);
}
void Person::setCity(const string city){
	address.setCity(city);
}
void Person::setPersNr(const string persNr){
	this->persNr = persNr;
}
void Person::setShoeSize(const int shoeSize){
	this->shoeSize = shoeSize;
}
string Person::getFirstName() const{
	return name.getFirstName();
}
string Person::getLastName() const{
	return name.getLastName();
}
string Person::getAddress() const{
	return address.getAdress();
}
string Person::getPostalNumber() const{
	return address.getPostalNumber();
}
string Person::getCity() const{
	return address.getCity();
}
string Person::getPersNr() const{
	return persNr;
}
int Person::getShoeSize() const{
	return shoeSize;
}
