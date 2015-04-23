/*
 * userinterface.cpp
 *
 *  Created on: April 22, 2015
 *      Author: kristoffer
 */

#include "userinterface.h"

//------------------------------------------------------------------------------
// run
// Kör programmet
//------------------------------------------------------------------------------
void UserInterface::run(){
	menu();
}

//------------------------------------------------------------------------------
// menu
// Visar menyn
//------------------------------------------------------------------------------
void UserInterface::menu(){
	int selection = 0;
	bool active = true;
	cout << "Welcome to the personnel register" << endl;
	while(active){
		cout << endl << "1. Enter data for a new person\n2. Show all data"
				"\n3. Save to file\n4. Load from file\n5. Sort by name\n6. Sort by personel number"
				"\n7. sort by shoe size\n8. Exit\nChoose an alternative: ";
		cin >> selection;
		while(cin.fail() || selection < 1 || selection > 8){
			cin.clear();
			cin.ignore(256,'\n');
			cout << "You have to enter a valid choice. Please enter your selection again: ";
			cin >> selection;
		}
		cout << endl;
		switch (selection){
		case 1:
			addPerson();
			break;
		case 2:
			printList();
			break;
		case 3:
			writeToFile();
			break;
		case 4:
			readFromFile();
			break;
		case 5:
			sortName();
			break;
		case 6:
			sortPersNr();
			break;
		case 7:
			sortShoeSize();
			break;
		case 8:
			active = false;
			break;
		}
	}
	cout << "Thanks for using personnel register" << endl;
}

//------------------------------------------------------------------------------
// addPerson
// Lägger till ett Personobjekt i slutet på listan
//------------------------------------------------------------------------------
void UserInterface::addPerson(){
	vector<string> entries = {"first name", "last name", "address", "postal number", "city", "personal number"};
	vector<string> answers(entries.size(), "");
	int shoeSize = 0;
	cin.ignore();
	for(size_t i = 0; i < entries.size(); i++){
		cout << "Enter " << entries[i] << ": ";
		getline(cin, answers[i]);
	}
	cout << "Enter shoe size: ";
	cin >> shoeSize;
	while(cin.fail() || shoeSize < 1 || shoeSize > 60){
		cin.clear();
		cin.ignore(256,'\n');
		cout << "You have to enter a number between 1-60. Please enter your selection again: ";
		cin >> shoeSize;
	}
	list.addPerson(Person(answers[0], answers[1], answers[2], answers[3], answers[4], answers[5], shoeSize));
}

//------------------------------------------------------------------------------
// printList
// Skriver ut listan med personer
//------------------------------------------------------------------------------
void UserInterface::printList(){
	list.printList();
}

//------------------------------------------------------------------------------
// inputFileName
// Låter användaren mata in ett filnamn att läsa från eller skriva till
//------------------------------------------------------------------------------
void UserInterface::inputFileName(string direction) {
	cout << "Enter file name to " + direction;
	string fileName;
	cin >> fileName;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Failed to read your input. Try again:";
		cin >> fileName;
	}
	list.setFileName(fileName);
}


//------------------------------------------------------------------------------
// writeToFile
// Sparar listan till en fil med namnet från parametern fileName
//------------------------------------------------------------------------------
void UserInterface::writeToFile(){
	inputFileName("save to:");
	list.writeToFile();
}


//------------------------------------------------------------------------------
// readFromFile
// Laddar en lista från filen med namnet från parametern fileName
//------------------------------------------------------------------------------
void UserInterface::readFromFile(){
	inputFileName("read from:");
	list.readFromFile();
}

//------------------------------------------------------------------------------
// sortName
// Sortera listan med avseende på namn
//------------------------------------------------------------------------------
void UserInterface::sortName(){
	list.sortName();
}

//------------------------------------------------------------------------------
// sortPersNr
// Sortera listan med avseende på personnummer
//------------------------------------------------------------------------------
void UserInterface::sortPersNr(){
	list.sortPersNr();
}

//------------------------------------------------------------------------------
// sortShoeSize
// Sortera listan med avseende på skostorlek
//------------------------------------------------------------------------------
void UserInterface::sortShoeSize(){
	list.sortShoeSize();
}

