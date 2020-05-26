#pragma once
#include "Serie.h"
#include<string>
#include<vector>
using namespace std;

class SerieException {
protected:
	vector<string>errors;
public:
	SerieException(vector<string> _errors);
	vector<string> getErrors() const;
};

class SerieValidator {
public:
	SerieValidator() {}
	virtual void validate(Serie& s);
};
