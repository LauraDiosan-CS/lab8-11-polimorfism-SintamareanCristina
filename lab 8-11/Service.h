#pragma once
#include "RepoFile.h"
#include "RepoTemplate.h"
#include "Serie.h"
#include "Drona.h"
#include "Telefon.h"
#include "User.h"
#include "TelefonValidator.h"
#include "SerieValidator.h"
#include "DronaValidator.h"

class Service
{
private:
	RepoTemplate<Serie*>& repo;
	RepoTemplate<User*>& repoUser;
	User activeUser;
	SerieValidator sv;
	TelefonValidator tv;
	DronaValidator dv;

public:
	Service(RepoTemplate<Serie*>& r, RepoTemplate<User*>& rep) : repo(r), repoUser(rep) { repo = r; repoUser = rep; };
	bool login(string, string);
	bool logedIn();
	void logout();
	list<Serie*> getAllSeries();
	int size();
	Serie* getItemFromPos(int);
	~Service();
	void addElem(Serie*& s);
	void delElem(Serie*& s);
	list<Serie*> searchByName(const char*);
	void updateElem(Serie*& c, Serie* newC);
	//void loadFromFile(string, char);
	void validateTelefon(Telefon);
	void validateDrona(Drona);
	bool findElem(Serie*&);
};

