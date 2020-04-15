#include "Telefon.h"
#include "Comanda.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
using namespace std;

//constructor default(fara param)
Telefon::Telefon() :Comanda() {
}

Telefon::Telefon(list<char*> operatori)
{
}

Telefon::Telefon(const Telefon& c)
{
}

//destructor
Telefon::~Telefon() {
}

list<char*> Telefon::getOperatori() {
	return this->operatori;
}

Telefon& Telefon::operator=(const Telefon& a) {
	if (this == &a) return *this; //self-assignment
	operatori = a.operatori;
	return *this;
}

//operatorul de egalitate
bool Telefon:: operator==(const Telefon& a) {
	return  this->operatori == a.operatori;
}

//pt afisare
ostream& operator<<(ostream& os, const Telefon& a)
{
	Comanda c;
	os << "Producator - " << c.getProducator() << ", model - " << c.getModel() << ", unitati - " << c.getUnitati() << ", operatori - " << a.operatori;
	return os;
}