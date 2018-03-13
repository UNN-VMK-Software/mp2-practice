#pragma once

#include "ringlist.h"


class Polinom {
	string s;
	RingList <Monom> monoms;
public:
	Polinom() {};
	~Polinom() {};
	Polinom(const string &str);
	Polinom(const Polinom &p1);
	Polinom operator+(const Polinom &p1);
	Polinom operator*(const Polinom &p1);
	Polinom operator*(const double &d);
	const Polinom& operator=(const Polinom &p1);
};