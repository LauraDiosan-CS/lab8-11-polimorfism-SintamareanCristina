#include "UI.h"
#include <iostream>
#include <string.h>
using namespace std;



int UI::login()
{
	string user, pass;
	cout << "Username: ";
	cin >> user;
	cout << endl << "Password: ";
	cin >> pass;
	return s.login(user, pass);
}

void UI::logout()
{
	s.logout();
}

void UI::addElem() {
	cout << "What do you want to add?" << endl;
	cout << "	a. Phone" << endl;
	cout << "	b. Drone" << endl;
	try {
		string response = "";
		cin >> response;
		Serie* ser;
		if (response == "a") {
			try {
				Telefon p;
				cin >> p;
				s.validateTelefon(p);
				ser = p.clone();
				s.addElem(ser);
			}
			catch (TelefonException e)
			{
				for (int i = 0; i < e.getErrors().size(); i++)
					cout << e.getErrors()[i];
			}
		}
		else {
			try {
				Drona d;
				cin >> d;
				s.validateDrona(d);
				ser = d.clone();
				s.addElem(ser);
			}
			catch (SerieException e) {
				for (int i = 0; i < e.getErrors().size(); i++)
					cout << e.getErrors()[i];
			}
		}

		cout << "Added!" << endl;
		//delete[] ser;
	}
	catch (exception e) { cout << "Exception occured!" << "->"; cout << e.what(); }
}

void UI::delElem() {
	cout << "What do you want to delete? :" << endl;
	cout << "	a. Phone" << endl;
	cout << "	b. Drone" << endl;
	try {
		string response = "";
		cin >> response;
		Serie* ser;
		if (response == "a") {
			Telefon p;
			cin >> p;
			ser = p.clone();
		}
		else {
			Drona p;
			cin >> p;
			ser = p.clone();
		}
		s.delElem(ser);
		cout << "Deleted!" << endl;
		delete[] ser;
	}
	catch (exception e) { cout << "Exception occured!" << "->"; cout << e.what(); }
}

void UI::updateElem() {
	cout << "What do you want to update? :" << endl;
	cout << "	a. Phone" << endl;
	cout << "	b. Drone" << endl;
	try {
		string response = "";
		cin >> response;
		Serie* ser;
		if (response == "a") {
			cout << "Introduce the phone you want to update:" << endl;
			Telefon t;
			cin >> t;
			Serie* cln = t.clone();
			bool rez = s.findElem(cln);
			if (rez == true) {
				try {
					cout << "Introduce the new information: " << endl;
					Telefon tNew;
					cin >> tNew;
					s.validateTelefon(tNew);
					Serie* ser = tNew.clone();
					s.updateElem(cln, ser);
					cout << "Updated!" << endl;
				}
				catch (SerieException e) {
					for (int i = 0; i < e.getErrors().size(); i++)
						cout << e.getErrors()[i];
				}
				//delete[] ser;
				delete[] cln;
			}
			else cout << "The phone hasn't been found!" << endl;
		}
		else {
			cout << "Introduce the drone you want to update: " << endl;
			Drona d;
			cin >> d;
			Serie* cln = d.clone();
			bool rez = s.findElem(cln);
			if (rez == true) {
				try {
					cout << "Introduce the new information:" << endl;
					Drona dNew;
					cin >> dNew;
					s.validateDrona(dNew);
					Serie* ser = dNew.clone();
					s.updateElem(cln, ser);
					cout << "Updated!" << endl;
					delete[] ser;
				}
				catch (SerieException e) {
					for (int i = 0; i < e.getErrors().size(); i++)
						cout << e.getErrors()[i];
				}
				//delete[] ser;
				delete[] cln;
			}
			else cout << "The drone hasn't been found!" << endl;
		}
	}
	catch (exception e) {
		cout << "Exception occured!" << "->"; cout << e.what();
	}
}


void UI::showByName() {
	cout << "Introduce the producer's name: ";
	char* name = new char[20];
	cin >> name;
	list<Serie*> rez = s.searchByName(name);
	if (rez.size() == 0)cout << "Could not find the producer!" << endl;
	else {
		for (list<Serie*>::iterator it = rez.begin(); it != rez.end(); it++)
			cout << (*it)->toString() << endl;
	}
	delete[] name;
}

void UI::showMenu()
{
	bool gata = false;
	bool stop = false;
	cout << endl;
	cout << endl;
	cout << "Would you like to log in?" << endl;
	cout << "	a. yes" << endl;
	cout << "	b. no" << endl;
	char r;
	cin >> r;
	if (r == 'a') {
		if (login()) {
			while (!gata) {
				cout << endl;
				cout << "      *** OPTIONS ***" << endl;
				cout <<endl;
				cout << "|---------------------------|" << endl;
				cout << "|1. Add                     |" << endl;
				cout << "|2. Delete                  |" << endl;
				cout << "|3. Update                  |" << endl;
				cout << "|4. Search by producer name |" << endl;
				cout << "|5. Show all                |" << endl;
				cout << "|6. Log out                 |" << endl;
				cout << "|0. Exit                    |" << endl;
				cout << "|---------------------------|" << endl;
				cout << endl;
				int opt;
				cout << "Introduce the number of the option you want: ";
				cin >> opt;
				cout << endl;
				switch (opt) {
					case 1: {
						addElem(); 
						break; 
						}
					case 2: { 
						delElem(); 
						break; 
						}
					case 3: { updateElem(); break; }
					case 4: {
						showByName(); 
						break; 
						}
					case 5: {
						showAll(); 
						break;
						}
					case 6: {
						logout(); 
						cout << "Loged out" << endl; 
						gata = true;  
						break; 
						}
					case 0: {
						gata = true; 
						}
					//default: { cout << "There is no such option" << endl; }
				}
			}
		}
		else cout << "Incorrect username or password!" << endl;
	}
	else gata = true;
}


UI::~UI()
{

}

void UI::showAll() {
	list<Serie*>::iterator it;
	for (int i = 0; i < s.size(); i++)cout << (*s.getItemFromPos(i)).toString() << endl;
}