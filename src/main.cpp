//============================================================================
// Name        : main.cpp
// Author      : Kristoffer Freiholtz
// Version     :
// Copyright   : 
// Description : Lab2 in C++, Ansi-style
//============================================================================

#include "person.h"
#include <iostream>
#include <vector>
using namespace std;

void createExamples(vector<Person>& personelRegister);
void selection(vector<Person>& personelRegister, vector<string>& entries, vector<string>& answers);
void addData(vector<Person>& personelRegister, vector<string>& entries, vector<string>& answers);
void showData(vector<Person>& personelRegister);

int main() {
	vector<Person> personelRegister;
	vector<string> entries = {"first name", "last name", "address", "postal number", "city", "personal number"};
	vector<string> answers(entries.size(), "");
	createExamples(personelRegister);
	selection(personelRegister, entries, answers);
	return 0;
}

////------------------------------------------------------------------------------
//// Skapa tre exempel personer
////------------------------------------------------------------------------------
void createExamples(vector<Person>& personelRegister){
	personelRegister.push_back (Person("Kristoffer", "Freiholtz", "Lindholmsallen 37", "41756", "Göteborg", "870316-5996", 42));
	personelRegister.push_back (Person("Anders", "Karlsson", "Ekgatan 2", "53592", "Vara", "650403-6745", 43));
	personelRegister.push_back (Person("Linda", "Göransson", "Storgatan 4", "65743", "Linköping", "781121-1876", 37));
}

////------------------------------------------------------------------------------
//// Välj vilket kommando man vill utföra
////------------------------------------------------------------------------------

void selection(vector<Person>& personelRegister, vector<string>& entries, vector<string>& answers){
	int selection = 0;
	bool active = true;
	cout << "Welcome to the lab2 personnel register" << endl;
	while(active){
			cout << endl << "1. Enter data for a new person\n2. Show all data\n3. Exit\nChoose an alternative: ";
			cin >> selection;
			while(cin.fail() || selection < 1 || selection > 3){
				cin.clear();
				cin.ignore(256,'\n');
				cout << "You have to enter 1, 2 or 3. Please enter your selection again: ";
				cin >> selection;
			}
			switch (selection){
			case 1:
				addData(personelRegister, entries, answers);
				break;
			case 2:
				showData(personelRegister);
				break;
			case 3:
				active = false;
				break;
			}
	}
	cout << "Thanks for using lab2 personnel register" << endl; // prints !!!Hello World!!!
}

////------------------------------------------------------------------------------
//// Lägg till data till vectorn
////------------------------------------------------------------------------------

void addData(vector<Person>& personelRegister, vector<string>& entries, vector<string>& answers){
	int shoeSize = 0;
	cin.ignore();
	for(size_t i = 0; i < entries.size(); i++){
		cout << "Enter " << entries[i] << ": ";
		getline (cin, answers[i]);
	}
	cout << "Enter shoe size: ";
	cin >> shoeSize;
	while(cin.fail() || shoeSize < 1 || shoeSize > 60){
		cin.clear();
		cin.ignore(256,'\n');
		cout << "You have to enter a number between 1-60. Please enter your selection again: ";
		cin >> shoeSize;
	}
	personelRegister.push_back (Person(answers[0], answers[1], answers[2], answers[3], answers[4], answers[5], shoeSize));
}

////------------------------------------------------------------------------------
//// Skriv ut datan i vectorn
////------------------------------------------------------------------------------

void showData(vector<Person>& personelRegister){
	for (Person x: personelRegister){
		cout << endl << x.getFirstName() << endl << x.getLastName() << endl << x.getAddress() << endl << x.getPostalNumber() << endl
				<< x.getCity() << endl << x.getPersNr() << endl << "Shoe size " << x.getShoeSize() << endl;
	}
}
