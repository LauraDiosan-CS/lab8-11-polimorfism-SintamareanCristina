#include "Serie.h"
#include <sstream>
#include <string>

using namespace std;

Serie::Serie() {
	producator = NULL;
	model = NULL;
	unitati = 0;
}

Serie::Serie(const char* n, const char* l, int s) {
	if (n) {
		producator = new char[strlen(n) + 1];
		strcpy_s(producator, strlen(n) + 1, n);
	}
	if (l) {
		model = new char[strlen(l) + 1];
		strcpy_s(model, strlen(l) + 1, l);
	}
	this->unitati = s;
}

Serie::Serie(const Serie& s) {
	if (s.producator) {
		producator = new char[strlen(s.producator) + 1];
		strcpy_s(producator, strlen(s.producator) + 1, s.producator);
	}
	if (s.model) {
		model = new char[strlen(s.model) + 1];
		strcpy_s(model, strlen(s.model) + 1, s.model);
	}
	unitati = s.unitati;
}

Serie::~Serie() {
	if (producator)
	{
		delete[] producator;
		producator = NULL;
	}
	if (model)
	{
		delete[] model;
		model = NULL;
	}
	unitati = 0;
}

char* Serie::getProducator() {
	return this->producator;
}

char* Serie::getModel() {
	return model;
}

int Serie::getUnitati() {
	return unitati;
}

void Serie::setProducator(const char* n) {
	if (producator)
		delete[] producator;
	producator = new char[strlen(n) + 1];
	strcpy_s(producator, strlen(n) + 1, n);
}

void Serie::setModel(const char* l) {
	if (model)
		delete[] model;
	model = new char[strlen(l) + 1];
	strcpy_s(model, strlen(l) + 1, l);
}

void Serie::setUnitati(int s) {
	unitati = s;
}

Serie& Serie::operator=(const Serie& e) {
	if (this == &e) return *this; //in case of self assignment
	if (e.producator) {
		if (this->producator)delete[]this->producator;
		this->producator = new char[strlen(e.producator) + 1];
		strcpy_s(this->producator, strlen(e.producator) + 1, e.producator);
	}
	if (e.model) {
		if (this->model)delete[]this->model;
		this->model = new char[strlen(e.model) + 1];
		strcpy_s(this->model, strlen(e.model) + 1, e.model);
	}
	this->unitati = e.unitati;
	return *this;
}

bool Serie::operator==(const Serie& c) {
	if (c.producator and c.model)
		return (strcmp(producator, c.producator) == 0 and strcmp(model, c.model) == 0 and unitati == c.unitati);
	return false;
}

//pt afisare
ostream& operator<<(ostream& os, Serie a)
{
	os << "Producator: " << a.producator << " || model: " << a.model << " || unitati: " << a.unitati;
	return os;
}


istream& operator>>(istream& is, Serie& c)
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
	c.setProducator(nume);
	c.setModel(model);
	c.setUnitati(unitati);
	delete[] nume;
	delete[] model;
	return is;
}

Serie::Serie(string line, char delim) {
	vector<string> tokens = splitLine(line, delim);
	this->producator = new char[tokens[0].length()];
	strcpy_s(this->producator, tokens[0].length() + 1, tokens[0].c_str());

	this->model = new char[tokens[0].length()];
	strcpy_s(this->model, tokens[0].length() + 1, tokens[0].c_str());

	unitati = stoi(tokens[2]);
}

Serie* Serie::clone() {
	Serie* newSerie = new Serie();
	newSerie->setProducator(this->producator);
	newSerie->setModel(this->model);
	newSerie->setUnitati(this->unitati);
	return newSerie;
}

string Serie::toString() {
	string x, y;
	x = this->producator;
	y = this->model;
	return x + " " + y + " " + to_string(this->unitati);
}

string Serie::toStringDelimiter(char delim) {
	string x, y;
	x = this->producator;
	y = this->model;
	return x + delim + y + delim + to_string(this->unitati);
}