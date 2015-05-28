/*
 * address.h
 *
 *  Created on: Feb 16, 2015
 *      Author: Kristoffer Freiholtz
 */

#ifndef ADDRESS_H_
#define ADDRESS_H_

#include<string>
#include<iostream>
using namespace std;

class Address{
private:
	string streetAddress;
	string postalNumber;
	string city;
public:
	Address();
	Address(const string streetAddress,const string postalNumber,const string city);
	void setStreetAddress(const string streetAddress);
	void setPostalNumber(const string postalNumber);
	void setCity(const string city);
	string getStreetAdress() const;
	string getPostalNumber() const;
	string getCity() const;
	bool operator==(const Address &address) const;
	bool operator<(const Address &address) const;
};

ostream &operator<<(ostream &os, const Address &address);
istream &operator>>(istream &is, Address &address);




#endif /* ADDRESS_H_ */
