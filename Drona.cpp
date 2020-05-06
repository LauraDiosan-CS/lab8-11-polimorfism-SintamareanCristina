#include "Drona.h"
#include "Serie.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
#include <sstream>
#include "Utils.h"
using namespace std;


Drona::Drona() {
	rotoare = 0;
}

Drona::Drona(const char* producator, const char* model, int unitati, int nr) :Serie(producator, model, unitati) {
	rotoare = nr;
}

Drona::Drona(const Drona& s) : Serie(s) {
	rotoare = s.rotoare;
}

//destructor
Drona::~Drona() {
	/*if (this->producator)
	{
		delete[] this->producator;
		this->getProducator = NULL;
	}
	if (this->model) {
		delete[] this->model;
		this->getModel = NULL;
	}*/
}

//getter
int Drona::getRotoare() {
	return this->rotoare;
}

void Drona::setRotoare(int rotoare) {
	this->rotoare = rotoare;
}

//suprascrie operatorul "=" 
Drona& Drona::operator=(const Drona& a) {
	if (this == &a) return *this; //self-assignment
	/*if (a.producator) {
		if (this->producator) delete[] this->producator;
		this->producator = new char[strlen(a.producator) + 1];
		strcpy(this->producator, strlen(a.producator) + 1, a.producator);
	}
	if (a.model) {
		if (this->model) delete[] this->model;
		this->model = new char[strlen(a.model) + 1];
		strcpy(this->model, strlen(a.model) + 1, a.model);
	}
	this->unitati = a.unitati;*/
	Serie::operator=(a);
	rotoare = a.rotoare;
	return *this;
}

//operatorul de egalitate
bool Drona:: operator==(const Drona& a) {
	return (Serie::operator==(a) && (rotoare = a.rotoare));
}

//pt afisare
ostream& operator<<(ostream& os, Drona a)
{
	Serie c;
	os << "Producator: " << a.producator << " || model: " << a.model << " || unitati: " << a.unitati << " || rotoare: " << a.rotoare;
	return os;
}

istream& operator>>(istream& is, Drona& c)
{
	cout << "Producator: ";
	char* nume = new char[20];
	is >> nume;
	cout << "Model: ";
	char* model = new char[20];
	is >> model;
	cout << "Unitati: ";
	int unitati;
	is >> unitati;
	cout << "Rotoare: ";
	int nr;
	is >> nr;
	c.setProducator(nume);
	c.setModel(model);
	c.setUnitati(unitati);
	c.setRotoare(nr);
	delete[] nume;
	delete[] model;
	return is;
}

Drona::Drona(string line, char delim) {
	vector<string> tokens = splitLine(line, delim);
	this->producator = new char[tokens[0].length() + 1];
	strcpy_s(this->producator, tokens[0].length() + 1, tokens[0].c_str());

	this->model = new char[tokens[0].length() + 1];
	strcpy_s(this->model, tokens[0].length() + 1, tokens[0].c_str());

	unitati = stoi(tokens[2]);
	rotoare = stoi(tokens[3]);
}

Serie* Drona::clone() {
	Drona* newSerie = new Drona();
	newSerie->setProducator(this->producator);
	newSerie->setModel(this->model);
	newSerie->setUnitati(this->unitati);
	newSerie->setRotoare(this->rotoare);
	return newSerie;
}

string Drona::toString() {
	string x, y;
	x = this->producator;
	y = this->model;
	return x + " " + y + " " + to_string(this->unitati) + " " + to_string(this->rotoare);
}

string Drona::toStringDelimiter(char delim) {
	string x, y;
	x = this->producator;
	y = this->model;
	return x + delim + y + delim + to_string(this->unitati) + delim + to_string(this->rotoare);
}