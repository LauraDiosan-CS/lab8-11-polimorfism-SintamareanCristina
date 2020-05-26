#pragma once
#include "RepoTemplate.h"
#include<list>
#include<fstream>
#include<iostream>
#include "Telefon.h"
#include "Serializer.h"
using namespace std;

template <class T>
class RepoFile : public RepoTemplate<T>
{

private:
	//protected:
	const char* fileName;
	char delim;
	Serializer<T>* s;

public:
	RepoFile();
	RepoFile(const char*, const char, Serializer<T>* sr);
	virtual void saveToFile();
	virtual void loadFromFile(const char*, const char);
	int addElem(T);
	int delElem(T);
	void updateElem(T, T);
	~RepoFile();
};


template<class T>
RepoFile<T>::RepoFile() :RepoTemplate<T>()
{
	fileName = "";
	delim = ' ';
}

template<class T>
RepoFile<T>::RepoFile(const char* fileName, const char delim, Serializer<T>* sr)
{
	this->fileName = fileName;
	s = sr;
	loadFromFile(fileName, delim);
}

template<class T>
RepoFile<T>::~RepoFile()
{

}

template<class T>
void RepoFile<T>::saveToFile()
{
	if (fileName == NULL)return;
	std::ofstream out(this->fileName);
	for (T t : this->getAll()) {
		out << t->toStringDelimiter(this->delim) << '\n';
	}
	out.close();
}

template<class T>
void RepoFile<T>::loadFromFile(const char* fileName, const char delim)
{
	if (fileName == NULL)return;
	try {
		this->fileName = fileName;
		this->delim = delim;
		std::ifstream inf(this->fileName);
		RepoTemplate<T>::clearElem();
		string line;
		if (inf.is_open()) {
			while (getline(inf, line)) {
				RepoTemplate<T>::addElem(s->fromString(line, delim));
			}
			inf.close();
		}
	}
	catch (int e) {
		std::cout << "Failed loading from file!\n";
	};
}

template<class T>
int RepoFile<T>::addElem(T e) {
	int r = RepoTemplate<T>::addElem(e);
	cout << r;
	if (r != -1) {
		saveToFile();
		return 0;
	}
	return -1;
}

template<class T>
int RepoFile<T>::delElem(T e) {
	int r = RepoTemplate<T>::delElem(e);
	cout << r;
	if (r != -1) {
		saveToFile();
		return 0;
	}
	return -1;
}

template<class T>
void RepoFile<T>::updateElem(T e1, T e2) {
	RepoTemplate<T>::updateElem(e1, e2);
	saveToFile();
}