#pragma once
#include<iostream>
using namespace std;
template<class T> class Serializer {
public:
	Serializer() {};
	virtual T fromString(string line, char delim) = 0;
	~Serializer() {};
};

