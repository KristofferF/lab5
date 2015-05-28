/*
 * userinteface.h
 *
 *  Created on: April 22, 2015
 *      Author: kristoffer
 */

#ifndef USER_INTERFACE_H_
#define USER_INTERFACE_H_

#include "personlist.h"

class UserInterface{

private:
	PersonList list;
	void menu();
	void addPerson();
	void printList();
	void writeToFile();
	void readFromFile();
	void sortName();
	void sortPersNr();
	void sortShoeSize();
	void inputFileName(string direction);

public:
	void run();

};

#endif /* USER_INTERFACE_H_ */
