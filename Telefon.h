#pragma once
#include <iostream>
#include "Serie.h"
#include <vector>;
#include <string.h>
using namespace std;

class Telefon : public Serie {
private:
	vector <string> operatori;
public:
	Telefon();
	Telefon(const char*, const char*, int, vector<string>);
	Telefon(const Telefon& c);
	~Telefon();
	vector <string> getOperatori();
	void setOperatori(vector<string>);
	Telefon& operator=(const Telefon& c);
	bool operator==(const Telefon& c);
	friend ostream& operator<<(ostream& os, Telefon);
	friend istream& operator>>(istream&, Telefon&);
	string toString();
	string toStringDelimiter(char delim);
	Telefon(string, char);
	Serie* clone();
};