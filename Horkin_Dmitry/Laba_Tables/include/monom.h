#pragma once
#include <string>
using namespace std;
class Monom {
public:
	int abc;
	double f;
	Monom(const string &A);
	Monom(double ff = 0, int abcc = 0);
	void operator = (const Monom &A);
	bool operator ==(const Monom &A) const;
	bool operator !=(const Monom &A) const;
	bool operator < (const Monom &A) const;
	bool operator > (const Monom &A) const;
	Monom operator * (const Monom&A) const;
};