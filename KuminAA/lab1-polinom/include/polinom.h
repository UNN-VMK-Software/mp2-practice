#pragma once

#include "list.h"
#include <iostream>
#include <string>
using namespace std;


class Monom
{
public:
	double coeff;
	int abc;

	Monom(double coeff1 = NULL, int abc1 = NULL) { coeff = coeff1; abc = abc1; }

	bool operator< (const Monom& m) const { return (abc<m.abc); }
	bool operator> (const Monom& m) const { return (abc>m.abc); }
	bool operator==(const Monom& m) const 
	{ 
		int k = 1;
		if (coeff)
			k = (abc == m.abc && coeff == m.coeff);
		return k; 
	}
	bool operator!=(const Monom& m) const { return !(*this == m); }
	Monom& operator=(const Monom& m) { coeff = m.coeff; abc = m.abc; return *this; }
};


class Polinom
{
	Ringlist<Monom> pol;
	Ringlist<Monom> Parse(const string& s);

public:
	Polinom();
	Polinom(const string& str);
	Polinom(const Polinom& p);
	Polinom(const Ringlist<Monom>& p) { pol = p; }
	Ringlist<Monom> AddSameAndInsert(const Monom& c, const Ringlist<Monom>& p);

	Polinom& operator=(const Polinom& p);
	Polinom operator+(const Polinom& p);
	Polinom operator-(const Polinom& p)
	{
		Polinom temp(*this);
		temp = temp + (-1) * p;
		return temp;
	}
	Polinom operator*(const int& c);
	Polinom operator*(const Polinom& p);
	friend Polinom operator*(const int c, const Polinom& p)
	{
		Polinom temp(p);
		temp = temp * c;
		return temp;
	}

	friend ostream& operator<< (ostream& os, const Polinom& p);
	int operator== (const Polinom& p) const { return pol == p.pol; }
	int operator!= (const Polinom& p) const { return pol != p.pol; }
};