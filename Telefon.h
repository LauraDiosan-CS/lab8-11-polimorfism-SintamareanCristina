#pragma once
#include <ostream>
#include "Comanda.h"
#include <list>;
using namespace std;

class Telefon : public Comanda {
private:
	list <char*> operatori;
public:
	Telefon();
	Telefon(list <char*> operatori);
	Telefon(const Telefon& c);
	~Telefon();
	list <char*> getOperatori();
	Telefon& operator=(const Telefon& c);
	bool operator==(const Telefon& c);
	friend ostream& operator<<(ostream& os, const Telefon& c);
};
