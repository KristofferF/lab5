/*
 * userinteface.h
 *
 *  Created on: April 22, 2015
 *      Author: kristoffer
 */

#ifndef USER_INTERFACE_H_
#define USER_INTERFACE_H_

#include "personList.h"
#include "queue.h"

class HousingQ{

private:
	QList qList;
	int size;
    string fileName;

	PersonList list;
	void menu();
	void enque();
	void offerHousing();
	void printQueue();
	void printInfo();
	void removeFromQueue();
	void writeToFile();
	void readFromFile();
	string selectPerson();

public:
	void run();

};

#endif /* USER_INTERFACE_H_ */
