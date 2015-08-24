/*
 * HousingQ.cpp
 *
 *  Created on: April 22, 2015
 *      Author: kristoffer
 */

#include "HousingQ.h"
#include <algorithm>
#include <fstream>
#include <vector>

//------------------------------------------------------------------------------
// run
// K�r programmet
//------------------------------------------------------------------------------
void HousingQ::run(){
    size = 0;
    fileName = "HousingQueue.txt";
    readFromFile();
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
	if(size > 0){
	    cout << size << " sökande tillagda från sparad fil!" << endl;
	}
	cout << endl;
	while(active){
		cout << "1. St�ll en person sist i bostadsk�n\n2. Erbjud en person bostad"
				"\n3. Skriv ut hela bostadsk�n\n4. Skriv ut data om en person\n5. Ta bort en person ur bostadsk�n\n6. Spara bostadsk�n"
				"\n7. Avsluta\nDitt val: ";
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
	cout << "Tack f�r att du anv�nde bostadsk�n" << endl;
}

//------------------------------------------------------------------------------
// enque
// L�gger till ett Personobjekt i slutet p� k�listan
//------------------------------------------------------------------------------
void HousingQ::enque(){
    vector<string> entries = {"förnamn", "efternamn", "adress", "postnummer", "stad", "personnummer"};
    vector<string> answers(entries.size(), "");
    int shoeSize = 0;
    cin.ignore();
    for(size_t i = 0; i < entries.size(); i++){
        while (answers[i] == ""){
            cout << "Mata in " << entries[i] << ": ";
            getline(cin, answers[i]);
        }
    }
    if(itemPresentInQueue(answers[5])){
        cout << "En sökande med detta personnummer finns redan!" << endl << endl;
    }
    else{
        qList.enque(Person(answers[0], answers[1], answers[2], answers[3], answers[4], answers[5], 0));
        cout << answers[0] << " " << answers[1] << " har blivit tillagd till bostadskön!" << endl << endl;
		size++;
    }
}

bool HousingQ::itemPresentInQueue(string persNr) const{
    for(auto it=qList.begin(); it!=qList.end(); it++){
        if((*it).getPersNr() == persNr){
            return true;
        }
    }
    return false;
}

//------------------------------------------------------------------------------
// offerHousing
// erbjuder en bostad till en person och tar bort den från kön
//------------------------------------------------------------------------------
void HousingQ::offerHousing(){
	Item tmpItem;
	if(qList.deque(tmpItem)){
        cout << tmpItem.getName().getFirstName() << " " << tmpItem.getName().getLastName() <<
                " Har blivit erbjuden en bostad." << endl << endl;
        size--;
    }
    else{
        cout << "Det finns inga personer i bostadskön!" << endl << endl;
    }
}

//------------------------------------------------------------------------------
// printQueue
// Skriver ut bostadsk�n
//------------------------------------------------------------------------------
void HousingQ::printQueue() const{
	if(!qList.isEmpty()){
		cout << "Skriver ut hela bostadskön, antal: " << size << endl << endl;
		int i = 1;
		for(auto it=qList.begin(); it!=qList.end(); it++){
			cout << i << ": ";
		    printItem(*it);
		    i++;
		}
	}
	else{
		cout << "Det finns inga personer i bostadskön!" << endl << endl;
	}
}

//------------------------------------------------------------------------------
// printInfo
// Skriver ut information om en sökt person
//------------------------------------------------------------------------------
void HousingQ::printInfo() const{
	if(!qList.isEmpty()){
		string persNr = selectPerson();
		int i = 1;
		bool found = false;
		for(auto it=qList.begin(); it!=qList.end(); it++){
			if((*it).getPersNr() == persNr){
				found = true;
			    cout << i << ": ";
				printItem(*it);
			}
			i++;
		}
		if(!found){
		    cout << "Kunde inte hitta någon sökande med detta personnummer!" << endl << endl;
		}
	}
	else{
		cout << "Det finns inga personer i bostadskön!" << endl << endl;
	}
}

//------------------------------------------------------------------------------
// printItem
// Skriver ut information om en person
//------------------------------------------------------------------------------
void HousingQ::printItem(Item& item) const{
    cout << item.getName().getFirstName() << " " << item.getName().getLastName() << endl <<
            item.getAddress().getStreetAdress() << endl << item.getAddress().getPostalNumber() <<
            " " << item.getAddress().getCity() << endl << item.getPersNr() << endl << endl;
}

//------------------------------------------------------------------------------
// deque
// Tar bort ett Personobjekt ur k�listan
//------------------------------------------------------------------------------
void HousingQ::removeFromQueue(){
	if(!qList.isEmpty()){
		string persNr = selectPerson();
		bool found = false;
        for(auto it=qList.begin(); it!=qList.end(); it++){
			if((*it).getPersNr() == persNr){
				cout << "Tar bort " << (*it).getName().getFirstName() << " " << (*it).getName().getLastName() <<
						endl << (*it).getPersNr() << " från bostadskön."<< endl << endl;
				found = true;
                qList.del((*it));
                size--;
                break;
            }
		}
		if(!found){
			cout << "Kunde inte hitta någon sökande med detta personnummer!" << endl << endl;
		}
	}
	else{
		cout << "Det finns inga personer i bostadskön!" << endl << endl;
	}
}

//------------------------------------------------------------------------------
// selectPerson
// Låter användaren mata in ett personnummer
//------------------------------------------------------------------------------
string HousingQ::selectPerson() const{
	cout << "Mata in personnummer f�r aktuell person: ";
	string persNr;
	cin >> persNr;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "L�sning misslyckades. Var god f�rs�k igen:";
		cin >> persNr;
	}
	return persNr;

}

//------------------------------------------------------------------------------
// readFromFile
// L�s fr�n filen med namnet från medlemsvariabeln fileName
//------------------------------------------------------------------------------
void HousingQ::readFromFile(){
    fstream inFile(fileName, ios::in);
    Item tmpItem;
    while(inFile >> tmpItem){
        qList.enque(tmpItem);
        size++;
    }
    inFile.close();
}

//------------------------------------------------------------------------------
// writeToFile
// Skriv till filen med namnet fileName
//------------------------------------------------------------------------------
void HousingQ::writeToFile(){
    if(!qList.isEmpty()){
        fstream outFile(fileName, ios::out);
        for(auto it=qList.begin(); it!=qList.end(); it++){
            outFile << *it << endl;
        }
        outFile.close();
		cout << "Bostadskö med "<< size << " personer har sparats!" << endl << endl;
    }
    else{
        cout << "Det finns inga personer i bostadskön!" << endl << endl;
    }
}
