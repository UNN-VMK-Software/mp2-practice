#pragma once
#include "node.h"
#include "list.h"


class TMonom
{
public:
	double coeff;
	unsigned int abc;
	TMonom(const double cf = 0.0, const unsigned int abc2 = 0);
	TMonom(const TMonom &n);
	TMonom(const string &s);
	~TMonom() {}
	const TMonom& operator=(const TMonom &m);
	bool operator==(const TMonom &m) const;
	bool operator!=(const TMonom &m) const;
	bool operator<(const TMonom &m) const;
	bool operator>(const TMonom &m) const;
	TMonom operator*(const double d) const;
	TMonom operator*(const TMonom &m) const;
	friend ostream & operator<<(ostream &os, const TMonom &n);
};

class TPolinom
{
	TRinglist<TMonom> pol;
public:
	TPolinom() {}
	TPolinom(const TPolinom &p);
	TPolinom(const string &s);
	~TPolinom() {}
	const TPolinom& operator=(const TPolinom &p);
	TPolinom operator+(TPolinom &p);
	TPolinom operator*(TPolinom &p);
	TPolinom operator*(const double d);
	bool operator==(const TPolinom &p) const;
	bool operator!=(const TPolinom &p) const;
	friend ostream& operator<<(ostream& out, const TPolinom &p); 
};

double rank_number(const double a, const int i);
double converter_in_number(const string &s);