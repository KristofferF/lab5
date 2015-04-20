/*
 * person.cpp
 *
 *  Created on: Feb 17, 2015
 *      Author: kristoffer
 */

#include "person.h"
#include<iomanip>

//------------------------------------------------------------------------------
// Förvald konstruktor (Default constructor)
//------------------------------------------------------------------------------
Person::Person(){
	persNr = "";
	shoeSize = 0;
}

//------------------------------------------------------------------------------
// Konstruktor för initiering av datamedlemmarna
//------------------------------------------------------------------------------
Person::Person(const string firstName, const string lastName, const string streetAddress, const string postalNumber,
			const string city, const string persNr, const int shoeSize){
	name = Name(firstName, lastName);
	address = Address(streetAddress, postalNumber, city);
	this->persNr = persNr;
	this->shoeSize = shoeSize;
}

//------------------------------------------------------------------------------
// setName
// Datamedlemmen name ges värdet av parametern name
//------------------------------------------------------------------------------
void Person::setName(const Name name){
	this->name = name;
}

//------------------------------------------------------------------------------
// setAddress
// Datamedlemmen address ges värdet av parametern address
//------------------------------------------------------------------------------
void Person::setAddress(const Address address){
	this->address = address;
}

//------------------------------------------------------------------------------
// setPersNr
// Datamedlemmen persNr ges värdet av parametern persNr
//------------------------------------------------------------------------------
void Person::setPersNr(const string persNr){
	this->persNr = persNr;
}

//------------------------------------------------------------------------------
// ssetShoeSize
// Datamedlemmen shoeSize ges värdet av parametern shoeSize
//------------------------------------------------------------------------------
void Person::setShoeSize(const int shoeSize){
	this->shoeSize = shoeSize;
}

//------------------------------------------------------------------------------
// getName
// Returnera datamedlemmen name (Name)
//------------------------------------------------------------------------------
Name Person::getName() const{
	return name;
}

//------------------------------------------------------------------------------
// getAddress
// Returnera datamedlemmen address (Address)
//------------------------------------------------------------------------------
Address Person::getAddress() const{
	return address;
}

//------------------------------------------------------------------------------
// getPersNr
// Returnera datamedlemmen persNr (string)
//------------------------------------------------------------------------------
string Person::getPersNr() const{
	return persNr;
}

//------------------------------------------------------------------------------
// getShoeSize
// Returnera datamedlemmen shoeSize (int)
//------------------------------------------------------------------------------
int Person::getShoeSize() const{
	return shoeSize;
}

//------------------------------------------------------------------------------
// overloaded == operator
//
//------------------------------------------------------------------------------
bool Person::operator==(const Person &person) const {
	//return name == person.getName;// && address == person.getAddress && persNr == person.getPersNr() && shoeSize == person.getShoeSize();
	return true;
}

//------------------------------------------------------------------------------
// overloaded < operator
//
//------------------------------------------------------------------------------
bool Person::operator<(const Person &person) const {
	if (name < person.getName()) {
		return true;
	} else if (name == person.getName()) {
		if(address == person.getAddress()){
			return true;
		}
	}
	return false;
}

ostream &operator<<(ostream &os, const Person &person){
	os << setw(2) << person.getName() << " " << setw(2) << person.getAddress()
			<< " " << setw(2) << person.getPersNr() << " " << setw(2) << person.getShoeSize();
	return os;
}

istream &operator>>(istream &is, Person &person){
	Name tmpName;
	Address tmpAddress;
	string tmpPersNr;
	int tmpShoeSize;
	is >> tmpName;
	is >> tmpAddress;
	cout << "Personal number: ";
	is >> tmpPersNr;
	cout << "Shoe Size: ";
	is >> tmpShoeSize;
	person.setName(tmpName);
	person.setAddress(tmpAddress);
	person.setPersNr(tmpPersNr);
	person.setShoeSize(tmpShoeSize);
	return is;
}
