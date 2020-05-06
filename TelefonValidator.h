#pragma once
#include "Telefon.h"
#include "SerieValidator.h"

class TelefonValidator : public SerieValidator {
public:
	TelefonValidator() {}
	void validate(Telefon& t);
};