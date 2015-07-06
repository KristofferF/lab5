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
	bool itemPresentInQueue(string persNr) const;
	void offerHousing();
	void printQueue() const;
	void printInfo() const;
	void printItem(Item& item) const;
	void removeFromQueue();
	void writeToFile();
	void readFromFile();
	string selectPerson() const;

public:
	void run();

};

#endif /* USER_INTERFACE_H_ */
