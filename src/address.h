/*
 * address.h
 *
 *  Created on: Feb 16, 2015
 *      Author: Kristoffer Freiholtz
 */

#ifndef ADDRESS_H_
#define ADDRESS_H_

#include<string>
using std::string;

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
};



#endif /* ADDRESS_H_ */
