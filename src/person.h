/*
 * person.h
 *
 *  Created on: Feb 17, 2015
 *      Author: kristoffer
 */

#ifndef PERSON_H_
#define PERSON_H_

#include "name.h"
#include "address.h"

#include <string>
#include <iostream>
using namespace std;

class Person{
private:
	Name name;
	Address address;
	string persNr;
	int shoeSize;

public:
	Person();
	Person(const string firstName, const string lastname, const string streetAddress, const string postalNumber,
			const string city, const string persNr, const int shoeSize);
	void setName(const Name name);
	void setAddress(const Address address);
	void setPersNr(const string persNr);
	void setShoeSize(const int shoeSize);
	Name getName() const;
	Address getAddress() const;
	string getPersNr() const;
	int getShoeSize() const;
	bool operator==(const Person &person) const;
	bool operator<(const Person &person) const;
};

ostream &operator<<(ostream &os, const Person &person);
istream &operator>>(istream &is, Person &person);


#endif /* PERSON_H_ */
