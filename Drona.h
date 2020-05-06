#pragma once
#include <iostream>
#include "Serie.h"
#include <string>
#include <vector>;
using namespace std;

class Drona : public Serie {
private:
	int rotoare;
public:
	Drona();
	Drona(const char*, const char*, int, int);
	Drona(const Drona&);
	Drona(string, char);
	Serie* clone();
	~Drona();
	int getRotoare();
	void setRotoare(int rotoare);
	Drona& operator=(const Drona& c);
	bool operator==(const Drona& c);
	friend ostream& operator<<(ostream& os, Drona c);
	friend istream& operator>>(istream&, Drona&);
	string toString();
	string toStringDelimiter(char);
};
