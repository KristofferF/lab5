/*
 * personList.cpp
 *
 *  Created on: April 20, 2015
 *      Author: kristoffer
 */

#include "personlist.h"
#include <algorithm>
#include <fstream>

//------------------------------------------------------------------------------
// Förvald konstruktor (Default constructor)
//------------------------------------------------------------------------------
PersonList::PersonList(){
	fileName = "list.txt";
}

//------------------------------------------------------------------------------
// getFileName
// Returnera datamedlemmen fileName
//------------------------------------------------------------------------------
string PersonList::getFileName(){
	return fileName;
}

//------------------------------------------------------------------------------
// setFileName
// Datamedlemmen fileName ges värdet av parametern fileName
//------------------------------------------------------------------------------
void PersonList::setFileName(const string fileName){
	this->fileName = fileName;
}

//------------------------------------------------------------------------------
// addPerson
// Lägger till ett Personobjekt i slutet på listan
//------------------------------------------------------------------------------
void PersonList::addPerson(const Person person){
	persons.push_back(person);
}

//------------------------------------------------------------------------------
// getPerson
// Returnerar Personobjektet vid plats "index" i listan
//------------------------------------------------------------------------------
Person PersonList::getPerson(const size_t index) const{
	if(index < persons.size()){
		return persons[index];
	}
	return Person();
}

//------------------------------------------------------------------------------
// getSize
// Returnerar storleken på listan
//------------------------------------------------------------------------------
int PersonList::getSize() const{
	return persons.size();
}

//------------------------------------------------------------------------------
// sortName
// Sortera listan med avseende på namn
//------------------------------------------------------------------------------
void PersonList::sortName(){
	sort(persons.begin(), persons.end());
}

//------------------------------------------------------------------------------
// sortByPersNr
// Jämförelse funktion för SortPersNr
//------------------------------------------------------------------------------
bool sortByPersNr(Person p1, Person p2) {
	return p1.getPersNr() < p2.getPersNr();
}

//------------------------------------------------------------------------------
// sortPersNr
// Sortera listan med avseende på personnummer
//------------------------------------------------------------------------------
void PersonList::sortPersNr(){
	sort(persons.begin(), persons.end(), sortByPersNr);
}

//------------------------------------------------------------------------------
// sortByPersNr
// Jämförelse funktion för SortShoeSize
//------------------------------------------------------------------------------
bool sortByShoeSize(Person p1, Person p2) {
	return p1.getShoeSize() < p2.getShoeSize();
}

//------------------------------------------------------------------------------
// sortShoeSize
// Sortera listan med avseende på skostorlek
//------------------------------------------------------------------------------
void PersonList::sortShoeSize(){
	sort(persons.begin(), persons.end(), sortByShoeSize);
}

//------------------------------------------------------------------------------
// readFromFile
// Läs från filen med namnet fileName
//------------------------------------------------------------------------------
void PersonList::readFromFile(){
	persons.clear();
	fstream inFile(fileName, ios::in);
	Person tmpPerson;
	while(inFile >> tmpPerson){
		addPerson(tmpPerson);
	}
	inFile.close();
}

//------------------------------------------------------------------------------
// writeToFile
// Skriv till filen med namnet fileName
//------------------------------------------------------------------------------
void PersonList::writeToFile(){
	fstream outFile(fileName, ios::out);
	for(Person person : persons){
		outFile << person << endl;
	}
	outFile.close();
}

//------------------------------------------------------------------------------
// printList
// Skriver ut alla personer i listan
//------------------------------------------------------------------------------
void PersonList::printList(){
	for(Person person : persons){
		cout << person << endl << endl;
	}
}
