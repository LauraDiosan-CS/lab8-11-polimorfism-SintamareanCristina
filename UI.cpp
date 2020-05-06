#include "UI.h"
#include <iostream>
#include <string.h>
using namespace std;



int UI::login()
{
	string user, pass;
	cout << "Username: ";
	cin >> user;
	cout << endl << "Password:";
	cin >> pass;
	return s.login(user, pass);
}

/*void UI::logout()
{
	s.logout();
}*/

void UI::showMenu()
{
	bool gata = false;
	bool stop = false;
	int rez = login();
	while (!gata) {

		cout << "Would you like to log in?" << endl;
		cout << "		a. yes" << endl;
		cout << "			b. no" << endl;
		char r;
		cin >> r;
		if (r == 'a') {
			if (login()) {
				/*cout << "What format would you like?";
				cout << "	a. HTML" << endl;
				cout <<"	b. CSV" << endl;
				char response;
				cin >> response;
				if (r == 'a') {
					s.loadFromFile("Elements.html");
				else s.loafFromFile("Elements.csv");*/
				cout << "OPTIONS:" << endl;
				//cout << "		1. Add" << endl;
				//cout << "		2. Delete" << endl;
				//cout << "		3. Update" << endl;
				//cout << "		4. Show" << endl;
				//cout << "		5. Log out" << endl;
				cout << "		0. Exit" << endl;
				int opt;
				cout << "Introduce the number of the option you want: " << endl;
				cin >> opt;
				switch (opt) {
					//case 1: {findFlights(); break; }
					//case 2: {soldTickets(); break; }
					//case 3: {availablePlaces(); break; }
				case 4: {showAll(); break; }
				//case 5: {logout(); cout << "Loged out" << endl; break; }         // AICI AM MODIFICAT
				case 0: {gata = true; }
				}
			}
			else cout << "Incorrect username or password!" << endl;
		}
		else gata = true;
	}
}


UI::~UI()
{

}

void UI::showAll() {
	list<Serie*>::iterator it;
	for (int i = 0; i < s.size(); i++)cout << (*s.getItemFromPos(i)).toString() << endl;
}