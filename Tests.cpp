#include "Serie.h"
#include "Telefon.h"
#include "RepoTemplate.h"
#include "Serializer.h"
#include "SerializerSerie.h"
#include "SerializerUser.h"
#include "RepoFile.h"
#include "Service.h"
#include "Drona.h"
#include "RepoFileCSV.h"
#include "RepoFileHTML.h"
#include <assert.h>
#include <string.h>
#include <iostream>
#include <vector>

void testSerie() {
	Serie s;
	assert(s.getProducator() == NULL);
	assert(s.getModel() == NULL);
	assert(s.getUnitati() == 0);

	Serie s1("x", "y", 100);
	assert(strcmp(s1.getModel(), "y") == 0);
	assert(strcmp(s1.getProducator(), "x") == 0);
	assert(s1.getUnitati() == 100);

	s1.setProducator("a");
	assert(strcmp(s1.getProducator(), "a") == 0);
	s1.setModel("b");
	assert(strcmp(s1.getModel(), "b") == 0);
	s1.setUnitati(900);
	assert(s1.getUnitati() == 900);

	Serie s2(s1);
	assert(s1 == s2);
}

void testTelefon() {
	vector<string> x;
	string op;
	op = "abc";
	x.push_back(op);
	Telefon c("a", "b", 300, x);
	assert(strcmp(c.getProducator(), "a") == 0);
	assert(strcmp(c.getModel(), "b") == 0);
	assert(c.getUnitati() == 300);
	assert(c.getOperatori() == x);

	Telefon c1;
	vector<string> z;
	assert(c1.getProducator() == NULL);
	assert(c1.getModel() == NULL);
	assert(c1.getUnitati() == 0);
	assert(c1.getOperatori() == z);

	Telefon c2(c);
	assert(strcmp(c.getProducator(), "a") == 0);
	assert(strcmp(c.getModel(), "b") == 0);
	assert(c.getUnitati() == 300);
	assert(c2.getOperatori() == x);
	c.setProducator("aa");
	assert(strcmp(c.getProducator(), "aa") == 0);
	c.setModel("bb");
	assert(strcmp(c.getModel(), "bb") == 0);
	c.setUnitati(120);
	assert(c.getUnitati() == 120);

	vector<string> y;
	string opp;
	opp = "abc";
	y.push_back(opp);
	Telefon c3("aa", "bb", 120, y);
	assert(c == c3);
}


void testDrona() {
	Drona d;
	assert(d.getRotoare() == 0);
	Drona d1;
	Serie* s = &d1;
	d1.setModel("a");
	d1.setProducator("b");
	d1.setRotoare(2);
	d1.setUnitati(500);
	assert(strcmp(d1.getModel(), "a") == 0);
	assert(strcmp(d1.getProducator(), "b") == 0);
	assert(d1.getRotoare() == 2);
	assert(d1.getUnitati() == 500);

	Drona c("a", "b", 100, 2);
	assert(strcmp(c.getProducator(), "a") == 0);
	assert(strcmp(c.getModel(), "b") == 0);
	assert(c.getUnitati() == 100);
	assert(c.getRotoare() == 2);

	Drona c1;
	assert(c1.getProducator() == NULL);
	assert(c1.getModel() == NULL);
	assert(c1.getUnitati() == 0);
	assert(c1.getRotoare() == 0);

	Drona c2(c);
	assert(strcmp(c2.getProducator(), "a") == 0);
	assert(strcmp(c2.getModel(), "b") == 0);
	assert(c2.getUnitati() == 100);
	assert(c2.getRotoare() == 2);

	c.setProducator("aa");
	assert(strcmp(c.getProducator(), "aa") == 0);
	c.setModel("bb");
	assert(strcmp(c.getModel(), "bb") == 0);
	c.setUnitati(104);
	assert(c.getUnitati() == 104);
	c.setRotoare(6);
	assert(c.getRotoare() == 6);

	Drona c3("aa", "bb", 104, 6);
	assert(c == c3);
}

void testRepoTemplate() {
	vector<string> v;
	string op;
	op = "abc";
	v.push_back(op);
	Serie* elem1 = new Telefon("a", "x", 200, v);
	Serie* elem2 = new Telefon("b", "y", 300, v);
	Serie* elem3 = new Telefon("c", "z", 400, v);
	RepoTemplate<Serie*> repo;
	repo.addElem(elem1);
	repo.addElem(elem2);
	repo.addElem(elem3);
	assert(repo.size() == 3);
	assert(*repo.getAll().front() == *elem1);
	assert(*repo.getAll().back() == *elem3);
	assert(*repo.getItemFromPos(1) == *elem2);
	repo.delElem(elem3);
	assert(repo.size() == 2);
	delete[] elem1;
	delete[] elem2;
	delete[] elem3;
}

/*void testService() {
	SerializerSerie* s = new SerializerSerie();
	SerializerUser* u = new SerializerUser();
	RepoFile<Serie*> repof("Tests.txt", ' ', s);
	RepoFile<User*> repo("Users.txt", ' ', u);
	Service serv(repof, repo);
	User* u1 = new User("ana", "1234");
	User* u2 = new User("ion", "123");
	repo.addElem(u1);
	repo.addElem(u2);
	assert(serv.login("ana", "1234") == 1);
	Serie* s1 = new Drona("a", "b", 150, 3);
	serv.addElem(s1);
	assert(serv.getAllSeries().size() == 4);
	serv.delElem(s1);
	assert(serv.getAllSeries().size() == 3);
	delete[] s1;
}*/

/*void testRepoFileCSV() {
	SerializerSerie* s = new SerializerSerie();
	RepoFileCSV<Serie*>repo("Tests.csv", s);
	vector<string>v;
	string c;
	c = "vodafone";
	v.push_back(c);
	assert(repo.size() == 3);
	Serie* x = new Telefon("a", "b", 500, v);
	repo.addElem(x);
	assert(repo.size() == 4);
	repo.delElem(x);
	list<Serie*> rez = repo.getAll();
	assert(rez.size() == 3);
	delete[] x;
}*/

/*void testRepoFileHTML() {
	SerializerSerie* s = new SerializerSerie();
	RepoFileHTML<Serie*> repo("Tests.html", s);
	vector<string>v;
	string c;
	c = "vodafone";
	v.push_back(c);
	assert(repo.size() == 3);
	Serie* x = new Telefon("a", "b", 500, v);
	repo.addElem(x);
	assert(repo.size() == 4);
	repo.delElem(x);
	list<Serie*> rez = repo.getAll();
	assert(rez.size() == 3);
	delete[] x;
}*/

/*void testRepoFileSerie() {
	SerializerSerie* s = new SerializerSerie();
	RepoFile<Serie*> repo("Tests.txt", ' ', s);
	vector<string> v;
	string c;
	c = "vodafone";
	v.push_back(c);
	assert(repo.size() == 3);
	Serie* t = new Telefon("a", "b", 200, v);
	repo.addElem(t);
	assert(repo.size() == 4);
	//repo.delElem(t);
	//assert(repo.findElem(t) == -1);
	//assert(repo.size() == 3);
}*/

void tests() {
	testSerie();
	testTelefon();
	testDrona();
	testRepoTemplate();
	//testService();
	//testRepoFileCSV();
	//testRepoFileHTML();
	//testRepoFileSerie();
}
