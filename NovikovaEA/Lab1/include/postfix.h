/*
#pragma once
#include <string>
#include "list.h"

class monom
{
public:
	double coeff;
	unsigned int xyz;
	monom(const double c = 0.0, const unsigned int w = 0);
	monom(const monom &m);
	monom(const string &s);
	~monom() {}
	const monom& operator=(const monom &m);
	bool operator==(const monom &m) const;
	bool operator!=(const monom &m) const;
	bool operator<(const monom &m) const;
	bool operator>(const monom &m) const;
	monom operator*(const double d) const;
	monom operator*(const monom &m) const;
	friend ostream & operator<<(ostream &out, const monom &m)
	{
			out << m.coeff << " " << m.xyz;
			return out;
	}
	friend monom operator*(const double d, const monom &m) { return (m*d); }
};

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
	polinom operator*(const double d)const;
	friend ostream & operator<<(ostream &out, const polinom &p)
	{
		out << p.pol;
		return out;
	}
	friend polinom operator*(const double d, const polinom &p) { return (p*d); }
	bool operator==(const polinom &p) const;
	bool operator!=(const polinom &p) const;
};

double rank_number(const double a, const int i);
double converter_in_number(const string &s);

*/