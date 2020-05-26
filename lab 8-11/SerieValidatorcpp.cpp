#include "SerieValidator.h"
using namespace std;

SerieException::SerieException(vector<string>_errors) : errors{ _errors } {}
vector<string> SerieException::getErrors() const {
	return this->errors;
}
void SerieValidator::validate(Serie& s) {
	vector<string>errors;
	if (s.getUnitati() < 100)
		errors.push_back("Numarul unitatilor trebuie sa fie >100\n");
}