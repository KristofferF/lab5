/*
 * personList.cpp
 *
 *  Created on: April 20, 2015
 *      Author: kristoffer
 */

#include "personList.h"
#include <algorithm>

string PersonList::getFileName(){
	return fileName;
}

void PersonList::setFileName(const string fileName){
	this->fileName = fileName;
}

void PersonList::addPerson(const Person person){
	persons.push_back(person);
}


Person PersonList::getPerson(const size_t index) const{
	if(index < persons.size()){
		return persons[index];
	}
	return Person();
}

int PersonList::getSize() const{
	return persons.size();
}

void PersonList::sortName(){
	sort(persons.begin(), persons.end());
}

bool sortByPersNr(Person p1, Person p2) {
	return p1.getPersNr() < p2.getPersNr();
}

void PersonList::sortPersNr(){
	sort(persons.begin(), persons.end(), sortByPersNr);
}

bool sortByShoeSize(Person p1, Person p2) {
	return p1.getShoeSize() < p2.getShoeSize();
}
void PersonList::sortShoeSize(){
	sort(persons.begin(), persons.end(), sortByShoeSize);
}

void PersonList::readFromFile(){

}

void PersonList::writeToFile(){

}
