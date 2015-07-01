/*
 * personList.cpp
 *
 *  Created on: April 20, 2015
 *      Author: kristoffer
 */

#include "personList.h"
#include <algorithm>
#include <fstream>

//------------------------------------------------------------------------------
// F�rvald konstruktor (Default constructor)
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
// Datamedlemmen fileName ges v�rdet av parametern fileName
//------------------------------------------------------------------------------
void PersonList::setFileName(const string fileName){
	this->fileName = fileName;
}

//------------------------------------------------------------------------------
// addPerson
// L�gger till ett Personobjekt i slutet p� listan
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
// Returnerar storleken p� listan
//------------------------------------------------------------------------------
int PersonList::getSize() const{
	return persons.size();
}

//------------------------------------------------------------------------------
// sortName
// Sortera listan med avseende p� namn
//------------------------------------------------------------------------------
void PersonList::sortName(){
	sort(persons.begin(), persons.end());
}

//------------------------------------------------------------------------------
// sortByPersNr
// J�mf�relse funktion f�r SortPersNr
//------------------------------------------------------------------------------
bool sortByPersNr(Person p1, Person p2) {
	return p1.getPersNr() < p2.getPersNr();
}

//------------------------------------------------------------------------------
// sortPersNr
// Sortera listan med avseende p� personnummer
//------------------------------------------------------------------------------
void PersonList::sortPersNr(){
	sort(persons.begin(), persons.end(), sortByPersNr);
}

//------------------------------------------------------------------------------
// sortByPersNr
// J�mf�relse funktion f�r SortShoeSize
//------------------------------------------------------------------------------
bool sortByShoeSize(Person p1, Person p2) {
	return p1.getShoeSize() < p2.getShoeSize();
}

//------------------------------------------------------------------------------
// sortShoeSize
// Sortera listan med avseende p� skostorlek
//------------------------------------------------------------------------------
void PersonList::sortShoeSize(){
	sort(persons.begin(), persons.end(), sortByShoeSize);
}

//------------------------------------------------------------------------------
// readFromFile
// L�s fr�n filen med namnet fileName
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
		cout << person.getName().getFirstName() << " " << person.getName().getLastName() << endl
				<< person.getAddress().getStreetAdress() << endl
				<< person.getAddress().getPostalNumber() << " " << person.getAddress().getCity() << endl
				<< person.getPersNr() << endl
				<< "Shoe Size: " << person.getShoeSize() << endl << endl;
	}
}
