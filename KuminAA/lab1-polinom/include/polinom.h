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
	bool operator==(const Monom& m) const { return (abc == m.abc); }
	bool operator!=(const Monom& m) const { return !(*this == m); }

	Monom& operator=(const Monom& m) { coeff = m.coeff; abc = m.abc; return *this; }
};


class Polinom
{
	Ringlist<Monom> pol;
	int AddTheSame(const Monom& c, Ringlist<Monom> r);
	Ringlist<Monom> Parse(const string& s);

public:
	Polinom();
	Polinom(const string& str);
	Polinom(const Polinom& p);

	Polinom& operator=(const Polinom& p);
	Polinom& operator+(const Polinom& p);
	Polinom& operator*(const int& c);
	Polinom& operator*(const Polinom& p);

	/*friend ostream& operator<< (ostream& os, const Polinom& p);*/
	/*bool operator== (const Polinom& p) const { return pol == p; }
	bool operator!= (const Polinom& p) const { return pol != p; }*/
};