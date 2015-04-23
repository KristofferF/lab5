/*
 * personList.h
 *
 *  Created on: April 20, 2015
 *      Author: kristoffer
 */

#ifndef PERSON_LIST_H_
#define PERSON_LIST_H_

#include "person.h"
#include <vector>
#include <string>

using namespace std;

class PersonList{

private:
	vector<Person> persons;
	string fileName;

public:
	PersonList();
	string getFileName();
	void setFileName(const string fileName);
	void addPerson(const Person person);
	Person getPerson(const size_t index) const;
	int getSize() const;
	void sortName();
	void sortPersNr();
	void sortShoeSize();
	void readFromFile();
	void writeToFile();
	void printList();
};

#endif /* PERSON_LIST_H_ */
