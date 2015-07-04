/*
 * userinteface.h
 *
 *  Created on: April 22, 2015
 *      Author: kristoffer
 */

#ifndef USER_INTERFACE_H_
#define USER_INTERFACE_H_

#include "queue.h"

class HousingQ{

private:
	QList qList;
	int size;
    string fileName;

	void menu();
	void enque();
	bool itemPresentInQueue(string persNr);
	void offerHousing();
	void printQueue();
	void printInfo();
	void printItem(Item& item);
	void removeFromQueue();
	void writeToFile();
	void readFromFile();
	string selectPerson();

public:
	void run();

};

#endif /* USER_INTERFACE_H_ */
