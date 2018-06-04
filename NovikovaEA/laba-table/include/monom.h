#pragma once

#include "node.h"
#include "list.h"

class monom
{
public:
	double coeff;
	unsigned int abc;
	monom(const double cf = 0.0, const unsigned int abc2 = 0);
	monom(const monom &n);
	monom(const string &s);
	~monom() {}
	const monom& operator=(const monom &m);
	bool operator==(const monom &m) const;
	bool operator!=(const monom &m) const;
	bool operator<(const monom &m) const;
	bool operator>(const monom &m) const;
	monom operator*(const double d) const;
	monom operator*(const monom &m) const;
	friend monom operator*(const double d, const monom &m)
	{
		return (m*d);
	}
	friend ostream & operator<<(ostream &os, const monom &n);
};




