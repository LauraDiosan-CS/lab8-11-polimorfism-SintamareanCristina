#include "Service.h"
#include "Drona.h"
#include "Serie.h"
#include "Telefon.h"
#include "User.h"
#include "SerieValidator.h"
#include "TelefonValidator.h"

bool Service::login(string u, string p)
{
	User* usr = new User(u, p);
	this->activeUser = (*usr);
	return((repoUser.findElem(usr) != -1) and (!this->activeUser.getUserName().empty()));
}

bool Service::logedIn() {
	return !this->activeUser.getUserName().empty();
}

void Service::logout()
{
	this->activeUser.setUserName("");
	this->activeUser.setPassword("");
	//User u(name, pass);
	//return repoUser.delElem(u);

}

Service::~Service()
{
}

list<Serie*>Service::getAllSeries() {
	return repo.getAll();
}

int Service::size() {
	return repo.size();
}

Serie* Service::getItemFromPos(int i) {
	return(repo.getItemFromPos(i));
}

/*void Service::loadFromFile(string f, char delim) {
	repo.loadFromFile(f);
}*/


void Service::validateTelefon(Telefon p) {
	tv.validate(p);
}

void Service::addElem(Serie*& s) {
	sv.validate(s);
	repo.addElem(s);
}

void Service::delElem(Serie*& s) {
	if (repo.findElem(s) == -1) {
		throw exception("Could not find item!'\n'");
	}
	else {
		repo.delElem(s);
	}
}

list<Serie*> Service::searchByName(const char* name) {
	list<Serie*> elem = repo.getAll();
	list<Serie*> rez;
	list<Serie*>::iterator it;
	for (int i = 0; i < elem.size(); i++) {
		Serie* x = repo.getItemFromPos(i);
		if (strcmp((*x).getProducator(), name) == 0) rez.push_back(x);
	}
	/*if (rez.size() == 0)
		throw exception("Could not find the producer!'\n'");
	else*/
	return rez;
}

bool Service::findElem(Serie*& c) {
	return repo.findElem(c);
}

void Service::updateElem(Serie*& c, Serie* newC) {
	/*if (repo.findElem(c) == -1) {
		throw exception("Could not find item!'\n'");
	}
	else {
		repo.updateElem(c, newC);
	}*/
	repo.updateElem(c, newC);
}

void Service::validateDrona(Drona d) {
	dv.validate(d);
}