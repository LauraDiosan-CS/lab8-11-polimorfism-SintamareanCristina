#pragma once
#include <list>
#include <algorithm>
#include "Serie.h"
#include <iterator>
using namespace std;

template <class T> class RepoTemplate {
protected:
	list<T> elem;
public:
	RepoTemplate<T>() {}
	virtual int addElem(T);
	virtual int delElem(T);
	int findElem(T);
	virtual void updateElem(T, T);
	int size();
	list<T> getAll();
	T getItemFromPos(int);
	void clearElem();
	~RepoTemplate();
};


template<class T>
int RepoTemplate<T>::addElem(T e)
{
	typename list<T>::iterator it;
	for (it = elem.begin(); it != elem.end(); ++it) {
		if ((*it)->toString() == e->toString()) return -1;
	}
	elem.push_back(e->clone());
	return 0;
}

template<class T>
int RepoTemplate<T>::findElem(T e)
{
	/*auto it = std::find(elem.begin(), elem.end(), e);
	if (it != elem.end()) return distance(elem.begin(), it);
	return -1;*/

	typename list<T>::iterator it;
	int i = 0;
	for (it = elem.begin(); it != elem.end(); ++it) {
		if ((*it)->toString() == e->toString())return i;
		i++;
	}
	return -1;
}

template<class T>
void RepoTemplate<T>::updateElem(T vechi, T nou)
{
	//std::replace(elem.begin(), elem.end(), vechi, nou);
	typename list<T>::iterator it;
	for (it = elem.begin(); it != elem.end(); ++it) {
		if ((*it)->toString() == vechi->toString()) vechi = nou->clone();
	}
}

template<class T>
int RepoTemplate<T>::delElem(T e)
{
	typename list<T>::iterator it;
	for (it = elem.begin(); it != elem.end(); ++it) {
		if ((*it)->toString() == e->toString()) {
			elem.erase(it);
			return 0;
		}
	}
	return -1;
}

template<class T>
inline int RepoTemplate<T>::size()
{
	return elem.size();
}

template<class T>
list<T> RepoTemplate<T>::getAll()
{
	return elem;
	return list<T>();
}

template<class T>
T RepoTemplate<T>::getItemFromPos(int i) {
	typename list<T>::iterator it;
	int k = 0;
	for (it = elem.begin(); it != elem.end(); it++) {
		if (k == i)return *it;
		k++;
	}
}

template<class T>
void RepoTemplate<T>::clearElem() {
	elem.clear();
}

template<class T>
RepoTemplate<T>::~RepoTemplate() {
}