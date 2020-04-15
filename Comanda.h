#pragma once
#include <ostream>
using namespace std;

class Comanda {
private:
	char* producator;
	char* model;
	int unitati;
public:
	Comanda();
	Comanda(const char* producator, const char* model, int unitati);
	Comanda(const Comanda& c);
	virtual ~Comanda();
	virtual char* getProducator();
	virtual char* getModel();
	virtual int getUnitati();
	virtual void setProducator(const char* name);
	virtual void setModel(const char* n);
	virtual void setUnitati(int n);
	Comanda& operator=(const Comanda& c);
	bool operator==(const Comanda& c);
	friend ostream& operator<<(ostream& os, const Comanda& c);
};
