#pragma once
#include <string>
#include "list.h"
using namespace std;

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
	friend ostream & operator<<(ostream &out, const monom &m);
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
	polinom operator+(polinom &p);
	polinom operator*(polinom &p);
	polinom operator*(const double d);
	friend ostream & operator<<(ostream &out, const polinom &p);
};

double rank_number(const double a, const int i);
double converter_in_number(const string &s);