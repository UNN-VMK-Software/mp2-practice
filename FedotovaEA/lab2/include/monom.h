#ifndef _MONOM_
#define _MONOM_

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
	friend TMonom operator*(const double d, const TMonom &m)
	{
		return (m*d);
	}
};

#endif