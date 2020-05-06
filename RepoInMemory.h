#pragma once
#include "RepoTemplate.h"
template <class T> class RepoInMemory :
	public RepoTemplate<T>
{
public:
	RepoInMemory() :RepoTemplate<T>() {};
	~RepoInMemory() {};
};