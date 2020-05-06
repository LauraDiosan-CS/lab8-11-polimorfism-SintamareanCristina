#include "TelefonValidator.h"

void TelefonValidator::validate(Telefon& t) {
	vector<string>errors;
	if (t.getUnitati() < 100)
		errors.push_back("Numarul unitatilor trebuie sa fie >100\n");
	if (t.getOperatori().size() < 1)
		errors.push_back("Trebuie sa existe cel putin un operator\n");
}