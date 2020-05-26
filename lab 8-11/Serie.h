#pragma once
#include <iostream>
#include "Utils.h"
#include <string>
using namespace std;

class Serie {
protected:
	char* producator;
	char* model;
	int unitati;
public:
	Serie();
	Serie(const char*, const char*, int);
	Serie(const Serie&);
	Serie(string, char);
	virtual string toString();
	virtual string toStringDelimiter(char);
	virtual ~Serie();
	char* getProducator();
	char* getModel();
	int getUnitati();
	void setProducator(const char*);
	void setModel(const char*);
	void setUnitati(int);
	virtual Serie& operator=(const Serie&);
	virtual bool operator==(const Serie&);
	friend ostream& operator<<(ostream& os, Serie);
	friend istream& operator>>(istream&, Serie&);
	virtual Serie* clone();
};

