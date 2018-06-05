#pragma once
#include <string>
#include <cstdlib>
#include  <cctype>
#include <iostream>

using namespace std;

class Monom {
	double cf; //коэффициент (может быть отрицательный)
	unsigned int abc; //степени x*100+y*10+z
public:
	Monom();
	Monom(double d, unsigned int st);
	void SetCoeff(double cval) { cf = cval; }
	double GetCoeff(void) { return cf; }
	void SetIndex(int ival) { abc = ival; }
	unsigned int GetIndex(void) { return abc; }
	Monom& operator=(const Monom &m);
	Monom& operator+(const Monom &m);
	Monom& operator*(const double &d);
	Monom& operator*(const Monom &m);
	bool operator==(const Monom &m) const;
	bool operator!=(const Monom &m) const;
	bool operator<(const Monom &m) const;
	friend ostream& operator<<(ostream& os, const Monom& m)
	{
		Monom Mon;
		Mon = m;
		int stx = (int)Mon.abc / 100;
		int sty = (int)(Mon.abc / 10 - stx * 10);
		int stz = (int)(Mon.abc % 10);
		cout << Mon.cf << "x^" << stx << "y^" << sty << "z^" << stz;
		return os;
	};
};