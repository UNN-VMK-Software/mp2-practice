#pragma once

#include "monom.h"

class polinom
{
	ringlist<monom> pol;
public:
	polinom() {}
	polinom(const polinom &p);
	polinom(const string &s);
	~polinom() {}
	const polinom& operator=(const polinom &p);
	polinom operator+(const polinom &p) const;
	polinom operator*(const polinom &p) const;
	polinom operator*(const double d) const;
	bool operator==(const polinom &p) const;
	bool operator!=(const polinom &p) const;
	friend polinom operator*(const double d, const polinom &p)
	{
		return (p*d);
	}
	friend ostream& operator<<(ostream& out, const polinom &p);
};

//double rank_number(const double a, const int i);
//double converter_in_number(const string &s);





