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
	string adress;
	string postalNumber;
	string city;
public:
	Address();
	Address(const string adress,const string postalNumber,const string city);
	void setAdress(const string adress);
	void setPostalNumber(const string postalNumber);
	void setCity(const string city);
	string getAdress() const;
	string getPostalNumber() const;
	string getCity() const;
};



#endif /* ADDRESS_H_ */
