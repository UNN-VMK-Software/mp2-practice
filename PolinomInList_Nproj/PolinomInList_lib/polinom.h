#pragma once

#include "ringlist.h"

template <typename T>
class Polinom {
	string s;
private:
	RingList<T> *monoms;
public:
	Polinom() {};
	Polinom(const string &s1);
	Polinom(const Polinom &p1);
	~Polinom();
	Polinom operator+(const Polinom &p1);
	Polinom operator*(const Polinom &p1);
	*const operator+(const double d);
	const Polinom& operator=(const Polinom &p1);
};
