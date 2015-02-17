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
	void setFirstName(string name);
	void setLastName(string name);
	string getFirstName() const;
	string getLastName() const;
};

#endif /* NAME_H_ */
