#pragma once

#include "list.h"

class Polinom
{
	Ringlist *list;
public:
	Polinom(const string&);
	Polinom(const Polinom&);
	~Polinom();

	Polinom& operator=(const Polinom&);
	Polinom& operator+(const Polinom&);
	Polinom& operator*(const int&);
	Polinom& operator*(const Polinom&);
};