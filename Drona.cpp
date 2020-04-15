#include "Drona.h"
#include "Comanda.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
using namespace std;

//constructor default(fara param)
Drona::Drona() :Comanda() {
}

Drona::Drona(int rotoare)
{
}

Drona::Drona(const Drona& c)
{
}

//destructor
Drona::~Drona() {
}

//getter
int Drona::getRotoare() {
	return this->rotoare;
}

//suprascrie operatorul "=" 
Drona& Drona::operator=(const Drona& a) {
	if (this == &a) return *this; //self-assignment
	rotoare = a.rotoare;
	return *this;
}

//operatorul de egalitate
bool Drona:: operator==(const Drona& a) {
	return  this->rotoare == a.rotoare;
}

//pt afisare
ostream& operator<<(ostream& os, const Drona& a)
{
	Comanda c;
	os << "Producator - " << c.getProducator() << ", model - " << c.getModel() << ", unitati - " << c.getUnitati() << ", rotoare - " << a.rotoare;
	return os;
}