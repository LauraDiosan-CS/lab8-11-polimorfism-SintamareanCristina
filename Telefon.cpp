#include "Telefon.h"
#include <string.h>
#include <sstream>
#include "Utils.h"
using namespace std;

//constructor default(fara param)
Telefon::Telefon() :Serie() {
	this->operatori = {};
}

Telefon::Telefon(const char* producator, const char* model, int unitati, vector<string> operatori) : Serie(producator, model, unitati) {
	this->operatori = operatori;
}

Telefon::Telefon(const Telefon& s) : Serie(s) {
	this->operatori = s.operatori;
}

//destructor
Telefon::~Telefon() {
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

vector<string> Telefon::getOperatori() {
	return this->operatori;
}

void Telefon::setOperatori(vector<string> operatori) {
	this->operatori = operatori;
}

Telefon& Telefon::operator=(const Telefon& a) {
	if (this == &a) return *this; //self-assignment
	Serie::operator=(a);
	operatori = a.operatori;
	return *this;
}

//operatorul de egalitate
bool Telefon:: operator==(const Telefon& a) {
	return (Serie::operator==(a) && (operatori == a.operatori));
}

//pt afisare
ostream& operator<<(ostream& os, Telefon a)
{
	os << "Producator: " << a.producator << " || model: " << a.model << " || unitati: " << a.unitati << " || operatori: ";
	for (int i = 0; i < a.operatori.size() - 1; i++)
	{
		os << a.operatori[i] << "-";
	}
	os << a.operatori[a.operatori.size() - 1] << endl;
	return os;
}

istream& operator>>(istream& is, Telefon& c)
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
	int i = 0;
	vector<string>operatori;
	cout << "Operatori: ";
	char* op = new char[10];
	is >> op;
	while (strcmp(op, "0") != 0)operatori.push_back(op);
	c.setProducator(nume);
	c.setModel(model);
	c.setUnitati(unitati);
	c.setOperatori(operatori);
	delete[] nume;
	delete[] model;
	delete[] op;
	return is;
}

Telefon::Telefon(string line, char delim) {
	vector<string> tokens = splitLine(line, delim);
	this->producator = new char[tokens[0].length() + 1];
	strcpy_s(this->producator, tokens[0].length() + 1, tokens[0].c_str());

	this->model = new char[tokens[0].length() + 1];
	strcpy_s(this->model, tokens[0].length() + 1, tokens[0].c_str());

	unitati = stoi(tokens[2]);

	vector<string> tok = splitLine(tokens[3], '-');
	for (int i = 0; i < tok.size(); i++) { this->operatori.push_back(tok[i]); }
}

Serie* Telefon::clone() {
	Telefon* newSerie = new Telefon();
	newSerie->setProducator(this->producator);
	newSerie->setModel(this->model);
	newSerie->setUnitati(this->unitati);
	newSerie->setOperatori(this->operatori);
	return newSerie;
}

string Telefon::toString() {
	string x, y, z;
	x = this->producator;
	y = this->model;
	z = this->operatori[0];
	for (int i = 1; i < this->operatori.size(); i++)
		z = z + "-" + this->operatori[i];
	return x + " " + y + " " + to_string(this->unitati) + " " + z;
}

string Telefon::toStringDelimiter(char delim) {
	string x, y, z;
	x = this->producator;
	y = this->model;
	z = this->operatori[0];
	for (int i = 1; i < this->operatori.size(); i++)
		z = z + "-" + this->operatori[i];
	return x + delim + y + delim + to_string(this->unitati) + delim + z;
}