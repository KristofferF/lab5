/*
 * HousingQ.cpp
 *
 *  Created on: April 22, 2015
 *      Author: kristoffer
 */

#include "HousingQ.h"
#include <algorithm>

//------------------------------------------------------------------------------
// run
// K�r programmet
//------------------------------------------------------------------------------
void HousingQ::run(){
    fileName = "HousingQueue.txt"; // TODO Make CONST
    //readFromFile(); // TODO FIX
    qList.enque(Person("A", "A", "A", "A", "A", "A", 45));
    qList.enque(Person("B", "A", "A", "A", "A", "A", 45));
    qList.enque(Person("C", "A", "A", "A", "A", "A", 45));
    qList.enque(Person("D", "A", "A", "A", "A", "A", 45));
    size = 4;
    menu();
}

//------------------------------------------------------------------------------
// menu
// Visar menyn
//------------------------------------------------------------------------------
void HousingQ::menu(){
	int selection = 0;
	bool active = true;
	cout << "V�lkommen till bostadsk�n" << endl;
	while(active){
		cout << endl << "1. St�ll en person sist i bostadsk�n\n2. Erbjud en person bostad"
				"\n3. Skriv ut hela bostadsk�n\n4. Skriv ut data om en person\n5. Ta bort en person ur bostadsk�n\n6. Spara k�n"
				"\n7. Avsluta\nChoose an alternative: ";
		cin >> selection;
		while(cin.fail() || selection < 1 || selection > 7){
			cin.clear();
			cin.ignore(256,'\n');
			cout << "Du m�ste v�lja ett giltigt val. F�rs�k igen: ";
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
	cout << "Tack f�r att du anv�nde bostadsk�n" << endl;
}

//------------------------------------------------------------------------------
// enque
// L�gger till ett Personobjekt i slutet p� k�listan
//------------------------------------------------------------------------------
void HousingQ::enque(){
//	vector<string> entries = {"first name", "last name", "address", "postal number", "city", "personal number"};
//	vector<string> answers(entries.size(), "");
//	int shoeSize = 0;
//	cin.ignore();
//	for(size_t i = 0; i < entries.size(); i++){
//		cout << "Enter " << entries[i] << ": ";
//		getline(cin, answers[i]);
//	}
//	cout << "Enter shoe size: ";
//	cin >> shoeSize;
//	while(cin.fail() || shoeSize < 1 || shoeSize > 60){
//		cin.clear();
//		cin.ignore(256,'\n');
//		cout << "You have to enter a number between 1-60. Please enter your selection again: ";
//		cin >> shoeSize;
//	}
//	qList.enque(Person(answers[0], answers[1], answers[2], answers[3], answers[4], answers[5], shoeSize));
    vector<string> entries = {"first name"};
	vector<string> answers(entries.size(), "");
	int shoeSize = 0;
	cin.ignore();
	for(size_t i = 0; i < entries.size(); i++){
		cout << "Enter " << entries[i] << ": ";
		getline(cin, answers[i]);
	}
    qList.enque(Person(answers[0], "A", "A", "A", "A", "A", 45));
    size++;
}

//------------------------------------------------------------------------------
// offerHousing
// Skapa erbjudande om bostad till en person
//------------------------------------------------------------------------------
void HousingQ::offerHousing(){
	Item tmpItem;
	if(qList.deque(tmpItem)){
        cout << tmpItem.getName().getFirstName() << " " << tmpItem.getName().getLastName() <<
                " Har blivit erbjuden en bostad." << endl;
    }
    else{
        cout << "Det finns inga personer i bostadskön!" << endl;
    }

}

//------------------------------------------------------------------------------
// printQueue
// Skriver ut bostadsk�n
//------------------------------------------------------------------------------
void HousingQ::printQueue(){
    cout << "Skriver ut hela bostadskön: " << endl << endl;
    int i = 1;
    for(auto it=qList.begin(); it!=qList.end(); it++){
        cout << i << ":" << (*it).getName().getFirstName() << " " << (*it).getName().getLastName() << endl <<
                (*it).getAddress().getStreetAdress() << endl << (*it).getAddress().getPostalNumber() <<
                " " << (*it).getAddress().getCity() << endl << (*it).getPersNr() << endl << endl;
        i++;
    }

}

//------------------------------------------------------------------------------
// printInfo
// Skriver ut information om en person
//------------------------------------------------------------------------------
void HousingQ::printInfo(){

}

//------------------------------------------------------------------------------
// deque
// Tar bort ett Personobjekt ur k�listan
//------------------------------------------------------------------------------
void HousingQ::deque(){
	//printQueue(); // med siffror framf�r

//	cout << "Ange namnet p� den pers: ";
//	getline(cin, answers[i]);

	//qList.deque();
}

//------------------------------------------------------------------------------
// inputFileName
// L�ter anv�ndaren mata in ett filnamn att l�sa fr�n eller skriva till
//------------------------------------------------------------------------------
void HousingQ::inputFileName(string direction) {
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
// Sparar listan till en fil med namnet fr�n parametern fileName
//------------------------------------------------------------------------------
void HousingQ::writeToFile(){
	inputFileName("save to: ");
	list.writeToFile();
}


//------------------------------------------------------------------------------
// readFromFile
// Laddar en lista fr�n filen med namnet fr�n parametern fileName
//------------------------------------------------------------------------------
void HousingQ::readFromFile(){

    //TODO IMPLEMENT
	inputFileName("read from: ");
	list.readFromFile();
}

//------------------------------------------------------------------------------
// sortName
// Sortera listan med avseende p� namn
//------------------------------------------------------------------------------
void HousingQ::sortName(){
	list.sortName();
}

//------------------------------------------------------------------------------
// sortPersNr
// Sortera listan med avseende p� personnummer
//------------------------------------------------------------------------------
void HousingQ::sortPersNr(){
	list.sortPersNr();
}

//------------------------------------------------------------------------------
// sortShoeSize
// Sortera listan med avseende p� skostorlek
//------------------------------------------------------------------------------
void HousingQ::sortShoeSize(){
	list.sortShoeSize();
}

