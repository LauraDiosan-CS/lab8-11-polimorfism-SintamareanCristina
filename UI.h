#pragma once
#include <string>
#include "Service.h"
using namespace std;

class UI
{
private:
	Service s;
public:
	UI(Service& service) : s(service) {};
	int login();
	//int logout();
	void showMenu();
	void showAll();
	~UI();
};
