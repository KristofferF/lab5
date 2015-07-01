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
	cout << "Välkommen till bostadskön" << endl;
	while(active){
		cout << endl << "1. Ställ en person sist i bostadskön\n2. Erbjud en person bostad"
				"\n3. Skriv ut hela bostadskön\n4. Skriv ut data om en person\n5. Ta bort en person ur bostadskön\n6. Spara kön"
				"\n7. Avsluta\nChoose an alternative: ";
		cin >> selection;
		while(cin.fail() || selection < 1 || selection > 7){
			cin.clear();
			cin.ignore(256,'\n');
			cout << "Du måste välja ett giltigt val. Försök igen: ";
			cin >> selection;
		}
		cout << endl;
		switch (selection){
		case 1:
			enque();
			break;
		case 2:
			offerHousing();
			break;
		case 3:
			printQueue();
			break;
		case 4:
			readFromFile();
			break;
		case 5:
			sortName();
			break;
		case 6:
			writeToFile();
			sortPersNr();
			break;
		case 7:
			active = false;
			break;
		}
	}
	cout << "Tack för att du använde bostadskön" << endl;
}

//------------------------------------------------------------------------------
// enque
// Lägger till ett Personobjekt i slutet på kölistan
//------------------------------------------------------------------------------
void UserInterface::enque(){
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
	qList.enque(Person(answers[0], answers[1], answers[2], answers[3], answers[4], answers[5], shoeSize));
}

//------------------------------------------------------------------------------
// offerHousing
// Skapa erbjudande om bostad till en person
//------------------------------------------------------------------------------
void UserInterface::offerHousing(){

}

//------------------------------------------------------------------------------
// printQueue
// Skriver ut bostadskön
//------------------------------------------------------------------------------
void UserInterface::printQueue(){

}

//------------------------------------------------------------------------------
// printInfo
// Skriver ut information om en person
//------------------------------------------------------------------------------
void UserInterface::printInfo(){

}

//------------------------------------------------------------------------------
// deque
// Tar bort ett Personobjekt ur kölistan
//------------------------------------------------------------------------------
void UserInterface::deque(){
	printQueue(); // med siffror framför

//	cout << "Ange namnet på den pers: ";
//	getline(cin, answers[i]);

	//qList.deque();
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
	inputFileName("save to: ");
	list.writeToFile();
}


//------------------------------------------------------------------------------
// readFromFile
// Laddar en lista från filen med namnet från parametern fileName
//------------------------------------------------------------------------------
void UserInterface::readFromFile(){
	inputFileName("read from: ");
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

