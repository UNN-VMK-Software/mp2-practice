#pragma once

#include "ringlist.h"

template <typename T>
class Polinom {
	string s;
private:
	RingList<T> monoms;
public:
	Polinom(const string &str) {
	s = str;
	int i = 0;
	while (i<s.size())
	{

	}
	};
	Polinom(const Polinom &p1);
	~Polinom();
	Polinom operator+(const Polinom &p1);
	Polinom operator*(const Polinom &p1);
	Polinom operator*(const double &d);
	const Polinom& operator=(const Polinom &p1);
};
