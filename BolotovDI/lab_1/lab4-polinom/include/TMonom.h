#pragma once

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

struct TMonom
{
	double cf;
	unsigned int abc;

	TMonom();
	TMonom(const string s);
	TMonom(double num, unsigned int num2);
	~TMonom() {}

	TMonom operator + (const TMonom& monom);
	TMonom operator - (const TMonom& monom);
	TMonom operator = (const TMonom& monom);
	bool operator == (const TMonom& monom) const;
	bool operator != (const TMonom& monom) const;
	bool operator > (const TMonom& monom) const;
	bool operator < (const TMonom& monom) const;
};