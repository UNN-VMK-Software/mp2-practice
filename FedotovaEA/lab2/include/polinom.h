#ifndef _POLINOM_
#define _POLINOM_

#pragma once
#include "monom.h"

class TPolinom
{
	TRinglist<TMonom> pol;
public:
	TPolinom() {}
	TPolinom(const TPolinom &p);
	TPolinom(const string &s);
	~TPolinom() {}
	const TPolinom& operator=(const TPolinom &p);
	TPolinom operator+(const TPolinom &p) const;
	TPolinom operator*(const TPolinom &p) const;
	TPolinom operator*(const double d) const;
	bool operator==(const TPolinom &p) const;
	bool operator!=(const TPolinom &p) const;
	friend ostream& operator<<(ostream& out, const TPolinom &p);
	friend TPolinom operator*(const double d, const TPolinom &p)
	{
		return (p*d);
	}
};

double rank_number(const double a, const int i);
double converter_in_number(const string &s);

#endif