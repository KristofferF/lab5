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

void selection();
void addData();
void showData();

vector<Person> personelRegister;
vector<string> entries = {"first name", "last name", "address", "postal number", "city", "personal number"};
vector<string> answers(entries.size(), "");
int shoeSize = 0;

int main() {
	cout << "Welcome to the lab2 personnel register" << endl;
	selection();
	return 0;
}

void selection(){
	int selection = 0;
	bool active = true;
	while(active){
			cout << "1. Enter data for a new person\n2. Show all data\n3. Exit\nChoose an alternative: ";
			cin >> selection;
			while(cin.fail() || selection < 1 || selection > 3){
				cin.clear();
				cin.ignore(256,'\n');
				cout << "You have to enter 1, 2 or 3. Please enter your selection again: ";
				cin >> selection;
			}
			switch (selection){
			case 1:
				addData();
				break;
			case 2:
				showData();
				break;
			case 3:
				active = false;
				break;
			}
	}
	cout << "Thanks for using lab2 personnel register" << endl; // prints !!!Hello World!!!
}

void addData(){
	for(size_t i = 0; i < entries.size(); i++){
		cout << "Enter " << entries[i] << ": ";
		cin >> answers[i];
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

void showData(){
	for (Person x: personelRegister){
		cout << x.getFirstName() << endl << x.getLastName() << endl << x.getAddress() << endl << x.getPostalNumber() << endl
				<< x.getCity() << endl << x.getPersNr() << endl << x.getShoeSize() << "\n\n\n";
	}
}
