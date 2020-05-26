#pragma once
#include "RepoTemplate.h"
#include <list>
#include <fstream>
#include <iostream>
#include "Telefon.h"
#include "RepoFile.h"
using namespace std;

template <class T>
class RepoFileHTML : public RepoTemplate<T>
{

private:
	//protected:
	const char* fileName;
	Serializer<T>* s;

public:
	RepoFileHTML();
	RepoFileHTML(const char*, Serializer<T>* sr);
	virtual void saveToFile();
	virtual void loadFromFile(const char*);
	int addElem(T);
	int delElem(T);
	void updateElem(T, T);
	~RepoFileHTML();
};


template<class T>
RepoFileHTML<T>::RepoFileHTML() :RepoTemplate<T>()
{
	fileName = "";
}

template<class T>
RepoFileHTML<T>::RepoFileHTML(const char* fileName, Serializer<T>* sr)
{
	this->fileName = fileName;
	s = sr;
	loadFromFile(fileName);
}

template<class T>
RepoFileHTML<T>::~RepoFileHTML()
{

}

template<class T>
void RepoFileHTML<T>::saveToFile()
{
	if (fileName == NULL)return;
	std::ofstream out(this->fileName);
	for (T t : this->getAll()) {
		out << t->toStringDelimiter('/') << '\n';
	}
	out.close();
}

template<class T>
void RepoFileHTML<T>::loadFromFile(const char* fileName)
{
	if (fileName == NULL)return;
	try {
		this->fileName = fileName;
		std::ifstream inf(this->fileName);
		RepoTemplate<T>::clearElem();
		string line;
		if (inf.is_open()) {
			while (getline(inf, line)) {
				RepoTemplate<T>::addElem(s->fromString(line, '/'));
			}
			inf.close();
		}
	}
	catch (int e) {
		std::cout << "Failed loading from file!\n";
	};
}

template<class T>
int RepoFileHTML<T>::addElem(T e) {
	int r = RepoTemplate<T>::addElem(e);
	if (r != -1) {
		saveToFile();
		return 0;
	}
	return -1;
}

template<class T>
int RepoFileHTML<T>::delElem(T e) {
	int r = RepoTemplate<T>::delElem(e);
	if (r != -1) {
		saveToFile();
		return 0;
	}
	return -1;
}

template<class T>
void RepoFileHTML<T>::updateElem(T e1, T e2) {
	RepoTemplate<T>::updateElem(e1, e2);
	saveToFile();
}