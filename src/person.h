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
using std::string;

class Person{
private:
	Name name;
	Address address;
	string persNr;
	int shoeSize;

public:
	Person();
	Person(const string firstName, const string lastname, const string address, const string postalNumber,
			const string city, const string persNr, const int shoeSize);
	void setFirstName(const string firstName);
	void setLastName(const string lastName);
	void setAddress(const string address);
	void setPostalNumber(const string postalNumber);
	void setCity(const string city);
	void setPersNr(const string persNr);
	void setShoeSize(const int shoeSize);
	string getFirstName() const;
	string getLastName() const;
	string getAddress() const;
	string getPostalNumber() const;
	string getCity() const;
	string getPersNr() const;
	int getShoeSize() const;
};


#endif /* PERSON_H_ */
