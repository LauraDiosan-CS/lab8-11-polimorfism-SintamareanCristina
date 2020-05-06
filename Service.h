#pragma once
#include "RepoFile.h"
#include "RepoTemplate.h"
#include "Serie.h"
#include "Drona.h"
#include "Telefon.h"
#include "User.h"

class Service
{
private:
	RepoTemplate<Serie*>& repo;
	RepoTemplate<User*>& repoUser;
	User activeUser;


public:
	//Service();
	Service(RepoTemplate<Serie*>& r, RepoTemplate<User*>& rep) : repo(r), repoUser(rep) { repo = r; repoUser = rep; };
	bool login(string, string);
	bool logedIn();
	void logout(string, string);
	list<Serie*> getAllSeries();
	int size();
	Serie* getItemFromPos(int);
	~Service();
	//void addElem(Serie* &s);
	//void delElem(Serie* &s);
	//void loadFromFile(string, char);
};
