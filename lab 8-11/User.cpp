#include "User.h"
#include<vector>
#include"Utils.h"

User::User()
{
}

User::User(string u, string p) :userName(u), password(p)
{
}

string User::getUserName()
{
	return userName;
}

string User::getPassword()
{
	return password;
}

void User::setUserName(string u)
{
	userName = u;
}

void User::setPassword(string p)
{
	password = p;
}

bool User::operator==(const User& u)
{
	return (userName == u.userName) and (password == u.password);
}

string User::toString()
{
	return userName + " " + password;
}

string User::toStringDelimiter(char delimiter)
{
	return userName + delimiter + password;
}


User::~User()
{
}

User::User(string line, char delim) {
	vector<string> tokens = splitLine(line, delim);
	this->userName = tokens[0];
	this->password = tokens[1];
}

void User::fromString(string line, char delim) {
	vector<string> tokens = splitLine(line, delim);
	this->userName = tokens[0];
	this->password = tokens[1];
}

User* User::clone() {
	User* newUser = new User();
	newUser->setUserName(this->userName);
	newUser->setPassword(this->password);
	return newUser;
}