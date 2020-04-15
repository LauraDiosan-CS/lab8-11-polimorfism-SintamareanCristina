#include "Comanda.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
using namespace std;

//constructor default(fara param)
Comanda::Comanda() {
	this->producator = NULL;
	this->model = NULL;
	this->unitati = NULL;
}

//constructor cu param
Comanda::Comanda(const char* producator, const char* model, int unitati)
{
	this->producator = new char[strlen(producator) + 1];
	strcpy_s(this->producator, 1 + strlen(producator), producator);
	this->model = new char[strlen(model) + 1];
	strcpy_s(this->model, 1 + strlen(model), model);
	this->unitati = unitati;
}

//constructor de copiere
Comanda::Comanda(const Comanda& a) {
	if (a.producator) {
		this->producator = new char[strlen(a.producator) + 1];
		strcpy_s(this->producator, 1 + strlen(a.producator), a.producator);
	}
	if (a.model) {
		this->model = new char[strlen(a.model) + 1];
		strcpy_s(this->model, 1 + strlen(a.model), a.model);
	}
	this->unitati = a.unitati;
}

//destructor
Comanda::~Comanda() {
	if (producator) delete[]producator;
	producator = NULL;
	model = NULL;
	unitati = -1;
}

//getter 
char* Comanda::getProducator() {
	return this->producator;
}

//getter 
char* Comanda::getModel() {
	return this->model;
}

//getter 
int Comanda::getUnitati() {
	return this->unitati;
}

//setter 
void Comanda::setProducator(const char* producator)
{
	if (this->producator) {
		delete[] this->producator;
	}
	this->producator = new char[strlen(producator) + 1];
	strcpy_s(this->producator, strlen(producator) + 1, producator);
}

//setter 
void Comanda::setModel(const char* model)
{
	if (this->model) {
		delete[] this->model;
	}
	this->model = new char[strlen(model) + 1];
	strcpy_s(this->model, strlen(model) + 1, model);
}

//setter 
void Comanda::setUnitati(int unitati)
{
	this->unitati = unitati;
}

//suprascrie operatorul "=" pentru un element de tip Comanda
Comanda& Comanda::operator=(const Comanda& a) {
	if (this == &a) return *this; //self-assignment
	if (producator) delete[] producator;
	if (a.producator) {
		this->producator = new char[strlen(a.producator) + 1];
		strcpy_s(producator, strlen(a.producator) + 1, a.producator);
	}
	unitati = a.unitati;
	if (model) delete[] model;
	if (a.model) {
		this->model = new char[strlen(a.model) + 1];
		strcpy_s(model, strlen(a.model) + 1, a.model);
	}
	return *this;
}

//operatorul de egalitate
bool Comanda:: operator==(const Comanda& a) {
	return strcmp(this->producator, a.producator) == 0 && strcmp(this->model, a.model) == 0 && this->unitati == a.unitati;
}

//pt afisare
ostream& operator<<(ostream& os, const Comanda& a)
{
	os << "Producator: " << a.producator << " || model: " << a.model << " || unitati: " << a.unitati;
	return os;
}