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
// Kï¿½r programmet
//------------------------------------------------------------------------------
void HousingQ::run(){
    fileName = "HousingQueue.txt"; // TODO Make CONST
    //readFromFile(); // TODO FIX
    qList.enque(Person("A", "A", "A", "A", "A", "1", 45));
    qList.enque(Person("B", "A", "A", "A", "A", "2", 45));
    qList.enque(Person("C", "A", "A", "A", "A", "3", 45));
    qList.enque(Person("D", "A", "A", "A", "A", "4", 45));
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
	cout << "Vï¿½lkommen till bostadskï¿½n" << endl;
	while(active){
		cout << endl << "1. Stï¿½ll en person sist i bostadskï¿½n\n2. Erbjud en person bostad"
				"\n3. Skriv ut hela bostadskï¿½n\n4. Skriv ut data om en person\n5. Ta bort en person ur bostadskï¿½n\n6. Spara kï¿½n"
				"\n7. Avsluta\nChoose an alternative: ";
		cin >> selection;
		while(cin.fail() || selection < 1 || selection > 7){
			cin.clear();
			cin.ignore(256,'\n');
			cout << "Du mï¿½ste vï¿½lja ett giltigt val. Fï¿½rsï¿½k igen: ";
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
			printInfo();
			break;
		case 5:
			removeFromQueue();
			break;
		case 6:
			writeToFile();
			break;
		case 7:
			active = false;
			break;
		}
	}
	cout << "Tack fï¿½r att du anvï¿½nde bostadskï¿½n" << endl;
}

//------------------------------------------------------------------------------
// enque
// Lï¿½gger till ett Personobjekt i slutet pï¿½ kï¿½listan
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
	cin.ignore();
	for(size_t i = 0; i < entries.size(); i++){
		cout << "Enter " << entries[i] << ": ";
		getline(cin, answers[i]);
	}
    qList.enque(Person(answers[0], "A", "A", "A", "A", "5", 45));


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
        cout << "Det finns inga personer i bostadskÃ¶n!" << endl;
    }
	size--;
}

//------------------------------------------------------------------------------
// printQueue
// Skriver ut bostadskï¿½n
//------------------------------------------------------------------------------
void HousingQ::printQueue(){
	if(!qList.isEmpty()){
		cout << "Skriver ut hela bostadskÃ¶n, antal: " << size << endl << endl;
		int i = 1;
		for(auto it=qList.begin(); it!=qList.end(); it++){
			cout << i << ":" << (*it).getName().getFirstName() << " " << (*it).getName().getLastName() << endl <<
					(*it).getAddress().getStreetAdress() << endl << (*it).getAddress().getPostalNumber() <<
					" " << (*it).getAddress().getCity() << endl << (*it).getPersNr() << endl << endl;
			i++;
		}
	}
	else{
		cout << "Det finns inga personer i bostadskÃ¶n!" << endl;
	}
}

//------------------------------------------------------------------------------
// printInfo
// Skriver ut information om en person
//------------------------------------------------------------------------------
void HousingQ::printInfo(){
	if(!qList.isEmpty()){
		string persNr = selectPerson();
		int i = 0;
		for(auto it=qList.begin(); it!=qList.end(); it++){
			i++;
			if((*it).getPersNr() == persNr){
				cout << i << ":" << (*it).getName().getFirstName() << " " << (*it).getName().getLastName() << endl <<
						(*it).getAddress().getStreetAdress() << endl << (*it).getAddress().getPostalNumber() <<
						" " << (*it).getAddress().getCity() << endl << (*it).getPersNr() << endl << endl;
			}
		}
	}
	else{
		cout << "Det finns inga personer i bostadskÃ¶n!" << endl;
	}
}

//------------------------------------------------------------------------------
// deque
// Tar bort ett Personobjekt ur kï¿½listan
//------------------------------------------------------------------------------
void HousingQ::removeFromQueue(){
	if(!qList.isEmpty()){
		string persNr = selectPerson();
		bool found = false;
		for(auto it=qList.begin(); it!=qList.end(); it++){
			if((*it).getPersNr() == persNr){
				cout << "Tar bort " << (*it).getName().getFirstName() << " " << (*it).getName().getLastName() <<
						endl << (*it).getPersNr() << endl;
				found = true;
				qList.del((*it));
				size--;
				break;
			}
		}
		if(!found){
			cout << "Kunde inte hitta någon person med det personnummret!" << endl;
		}
	}
	else{
		cout << "Det finns inga personer i bostadskÃ¶n!" << endl;
	}
}

//------------------------------------------------------------------------------
// inputFileName
// Lï¿½ter anvï¿½ndaren mata in ett filnamn att lï¿½sa frï¿½n eller skriva till
//------------------------------------------------------------------------------
string HousingQ::selectPerson() {
	cout << "Mata in personnummer för aktuell person: ";
	string persNr;
	cin >> persNr;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Läsning misslyckades. Var god försök igen:";
		cin >> persNr;
	}
	return persNr;

}


//------------------------------------------------------------------------------
// writeToFile
// Sparar listan till en fil med namnet frï¿½n parametern fileName
//------------------------------------------------------------------------------
void HousingQ::writeToFile(){
	//TODO IMPLEMENT
	list.writeToFile();
}


//------------------------------------------------------------------------------
// readFromFile
// Laddar en lista frï¿½n filen med namnet frï¿½n parametern fileName
//------------------------------------------------------------------------------
void HousingQ::readFromFile(){
    //TODO IMPLEMENT
	list.readFromFile();
}
