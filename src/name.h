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
	void setFirstName(const string firstName);
	void setLastName(const string lastName);
	string getFirstName() const;
	string getLastName() const;
};

#endif /* NAME_H_ */
