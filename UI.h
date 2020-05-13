#pragma once
#include <string>
#include <vector>
#include "Service.h"
#include "TelefonValidator.h"
using namespace std;

class UI
{
private:
	Service s;
public:
	UI(Service& service) : s(service) {};
	int login();
	void logout();
	void showMenu();
	void showAll();
	void addElem();
	void delElem();
	void updateElem();
	void showByName();
	~UI();
};
