#pragma once
#include <ostream>
using namespace std;

class Drona {
private:
	char* producator;
	char* model;
	int unitati;
	int rotoare;
public:
	Drona();
	Drona(const char* producator, const char* model, int unitati, int rotoare);
	Drona(const Drona& d);
	virtual ~Drona();
	virtual char* getProducator();
	virtual char* getModel();
	virtual int getUnitati();
	virtual int getRotoare();
	virtual void setProducator(const char* n);
	virtual void setModel(const char* n);
	virtual void setUnitati(int n);
	virtual void setRotoare(int n);
	Drona& operator=(const Drona& c);
	bool operator==(const Drona& c);
	friend ostream& operator<<(ostream& os, const Drona& c);
};