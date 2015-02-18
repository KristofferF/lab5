/*
 * name.h
 *
 *  Created on: Feb 16, 2015
 *      Author: Kristoffer Freiholtz
 */

#ifndef NAME_H_
#define NAME_H_

#include<string>
using std::string;

class Name{
private:
	string firstName;
	string lastName;
public:
	Name();
	Name(const string firstName,const string lastName);
	void setFirstName(const string fName);
	void setLastName(const string lName);
	string getFirstName() const;
	string getLastName() const;
};

#endif /* NAME_H_ */
