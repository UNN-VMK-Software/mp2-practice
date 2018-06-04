#ifndef TPOLINOM_H
#define TPOLINOM_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <Windows.h>

#include "RingList.h"
#include "TMonom.h"

using namespace std;

class TPolinom {
private:
	TRingList<Tmonom> monoms;
public:
	TPolinom() {  }
	TPolinom(const string & s);
	TPolinom(const TPolinom &);
	~TPolinom();
	TPolinom operator+ (const TPolinom & _polinom);
	TPolinom operator- (const TPolinom & _polinom) 
	{ 
		TPolinom res = (*this) + (-1.0) * _polinom; 
		return res;
	}
	TPolinom& operator+= (const TPolinom & _polinom);
	TPolinom operator* (const TPolinom & _polinom);
	TPolinom operator* (double d);
	TPolinom& operator = (const TPolinom& _polinom);
	bool operator == (const TPolinom& pol) const { return (*this).monoms == pol.monoms; };
	bool operator != (const TPolinom& pol) const { return !((*this) == pol); };
	bool operator < (const TPolinom& pol) const { return (*this).monoms < pol.monoms; };
	bool operator > (const TPolinom& pol) const { return (*this).monoms > pol.monoms; };
	friend ostream& operator<< (ostream &out, const TPolinom& _polinom)
	{
		TPolinom copy_of_polinom(_polinom);
		copy_of_polinom.monoms.Reset();
		// ЧТоб было K P A C U B O;
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 3));
		out << copy_of_polinom.monoms.GetCurrent()->data.cf;
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 15));
		if ((copy_of_polinom.monoms.GetCurrent()->data.abc / 100) != 0) {
			if ((copy_of_polinom.monoms.GetCurrent()->data.abc / 100) == 1)
				out << "x";
			else
				out << "x^" << (copy_of_polinom.monoms.GetCurrent()->data.abc / 100);
		}

		if ((copy_of_polinom.monoms.GetCurrent()->data.abc / 10) % 10 != 0) {
			if ((copy_of_polinom.monoms.GetCurrent()->data.abc / 10) % 10 == 1)
				out << "y";
			else out << "y^" << (copy_of_polinom.monoms.GetCurrent()->data.abc / 10) % 10;
		}
		if ((copy_of_polinom.monoms.GetCurrent()->data.abc) % 10 != 0) {
			if ((copy_of_polinom.monoms.GetCurrent()->data.abc % 10) == 1)
				out << "z";
			else out << "z^" << (copy_of_polinom.monoms.GetCurrent()->data.abc) % 10;
		}
		TLink<Tmonom>* cur = copy_of_polinom.monoms.GetNext();
		for (cur; !copy_of_polinom.monoms.IsEnded(); copy_of_polinom.monoms.GetNext())
		{
			if (copy_of_polinom.monoms.GetCurrent()->data.cf > 0)
			{
				SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 3)); //system("color 0B");
				out << " +" << copy_of_polinom.monoms.GetCurrent()->data.cf;
				SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 15));//system("color 0F");
			}
			else out << " " << copy_of_polinom.monoms.GetCurrent()->data.cf;
			if ((copy_of_polinom.monoms.GetCurrent()->data.abc / 100) != 0) {
				if ((copy_of_polinom.monoms.GetCurrent()->data.abc / 100) == 1)
					out << "x";
				else
					out << "x^" << (copy_of_polinom.monoms.GetCurrent()->data.abc / 100);
			}

			if ((copy_of_polinom.monoms.GetCurrent()->data.abc / 10) % 10 != 0)
			{
				if ((copy_of_polinom.monoms.GetCurrent()->data.abc / 10) % 10 == 1)
					out << "y";
				else out << "y^" << (copy_of_polinom.monoms.GetCurrent()->data.abc / 10) % 10;
			}
				if ((copy_of_polinom.monoms.GetCurrent()->data.abc) % 10 != 0) {
					if ((copy_of_polinom.monoms.GetCurrent()->data.abc % 10) == 1)
						out << "z";
					else out << "z^" << (copy_of_polinom.monoms.GetCurrent()->data.abc) % 10;
			}
			
		}
		out << endl;
		return out;
	}
	friend TPolinom operator* (double d, const TPolinom &p)
	{
		TPolinom res(p);
		res.monoms.Reset();
		if (d == 0)
			res.monoms.Clean();
		else {
			for (res.monoms.GetCurrent(); !res.monoms.IsEnded(); res.monoms.GetNext())
			{
				res.monoms.GetCurrent()->data.cf *= d;
			}
		}
		return res;
	};
};

#endif
