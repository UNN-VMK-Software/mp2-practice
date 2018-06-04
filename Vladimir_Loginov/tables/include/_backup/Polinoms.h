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


//
//friend TPolinom operator+ (const TPolinom & left_polinom, const TPolinom & right_polinom)
//{
//	TPolinom copy_of_polinom_left(left_polinom);
//	TPolinom copy_of_polinom_right(right_polinom);
//	copy_of_polinom_left.monoms.Reset();
//	copy_of_polinom_right.monoms.Reset();
//	TPolinom res(copy_of_polinom_left);
//	res.monoms.Reset();
//	for (res.monoms.current; !res.monoms.IsEnded(); res.monoms.GetNext())
//	{
//		for (copy_of_polinom_right.monoms.current; !copy_of_polinom_right.monoms.IsEnded(); copy_of_polinom_right.monoms.GetNext())
//		{
//			TLink<Tmonom>* link = res.monoms.Search(copy_of_polinom_right.monoms.current->data);
//			if (link != NULL && link->data.cf + copy_of_polinom_right.monoms.current->data.cf!= 0.0)
//				link->data.cf += copy_of_polinom_right.monoms.current->data.cf;
//			else
//				res.monoms.Insert(copy_of_polinom_right.monoms.current->data);
//		}
//	}
//	return res;
//}
//
//friend TPolinom operator* (const TPolinom &p, double d)
//{
//	TPolinom res(p);
//	res.monoms.Reset();
//	if (d == 0)
//		res.monoms.Clean();
//	else {
//		for (res.monoms.current; !res.monoms.IsEnded(); res.monoms.GetNext())
//		{
//			res.monoms.current->data.cf *= d;
//		}
//	}
//	return res;
//}
//
//friend TPolinom operator* (double d, const TPolinom &p)
//{
//	return p * d;
//}
class TPolinom {
private:
	TRingList<Tmonom> monoms;
public:
	TPolinom() {  }
	TPolinom(const string & s);
	TPolinom(const TPolinom &);
	~TPolinom();
	TPolinom operator+ (const TPolinom & _polinom);
	//TPolinom operator- (const TPolinom & _polinom) { TPolinom res = (*this) + const_cast<TPolinom>(_polinom) * (-1.0); return res; }
	TPolinom& operator+= (const TPolinom & _polinom);
	TPolinom operator* (const TPolinom & _polinom);
	TPolinom operator* (double d);
	TPolinom& operator = (const TPolinom& _polinom);
	bool operator == (const TPolinom& pol) const { return (*this).monoms == pol.monoms; };
	friend ostream& operator<< (ostream &out, const TPolinom& _polinom)
	{
		TPolinom copy_of_polinom(_polinom);
		copy_of_polinom.monoms.Reset();
		// ЧТоб было K P A C U B O;
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 3));
		out << copy_of_polinom.monoms.current->data.cf;
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 15));
		if ((copy_of_polinom.monoms.current->data.abc / 100) != 0) {
			if ((copy_of_polinom.monoms.current->data.abc / 100) == 1)
				out << "x";
			else
				out << "x^" << (copy_of_polinom.monoms.current->data.abc / 100);
		}

		if ((copy_of_polinom.monoms.current->data.abc / 10) % 10 != 0) {
			if ((copy_of_polinom.monoms.current->data.abc / 10) % 10 == 1)
				out << "y";
			else out << "y^" << (copy_of_polinom.monoms.current->data.abc / 10) % 10;
		}
		if ((copy_of_polinom.monoms.current->data.abc) % 10 != 0) {
			if ((copy_of_polinom.monoms.current->data.abc % 10) == 1)
				out << "z";
			else out << "z^" << (copy_of_polinom.monoms.current->data.abc) % 10;
		}
		copy_of_polinom.monoms.GetNext();
	//c:\Users\morko\Documents\GitHub\mp2 - lab3 - arithmetic\include\Polinoms.h
		for (copy_of_polinom.monoms.current; !copy_of_polinom.monoms.IsEnded(); copy_of_polinom.monoms.GetNext())
		{
			//TLink<Tmonom>* end = copy_of_polinom.monoms.GetNext();
			
			if (copy_of_polinom.monoms.current->data.cf > 0)
			{
				SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 3)); //system("color 0B");
				out << " +" << copy_of_polinom.monoms.current->data.cf;
				SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 15));//system("color 0F");
			}
			else out << copy_of_polinom.monoms.current->data.cf;
			if ((copy_of_polinom.monoms.current->data.abc / 100) != 0) {
				if ((copy_of_polinom.monoms.current->data.abc / 100) == 1)
					out << "x";
				else
					out << "x^" << (copy_of_polinom.monoms.current->data.abc / 100);
			}

			if ((copy_of_polinom.monoms.current->data.abc / 10) % 10 != 0)
			{
				if ((copy_of_polinom.monoms.current->data.abc / 10) % 10 == 1)
					out << "y";
				else out << "y^" << (copy_of_polinom.monoms.current->data.abc / 10) % 10;
			}
				if ((copy_of_polinom.monoms.current->data.abc) % 10 != 0) {
					if ((copy_of_polinom.monoms.current->data.abc % 10) == 1)
						out << "z";
					else out << "z^" << (copy_of_polinom.monoms.current->data.abc) % 10;
			}
			/*if ((copy_of_polinom.monoms.current->data.abc / 100) != 0) out << "x^" << (copy_of_polinom.monoms.current->data.abc / 100);
			if ((copy_of_polinom.monoms.current->data.abc / 10) % 10 != 0 ) out << " y^" << (copy_of_polinom.monoms.current->data.abc / 10) % 10;
			if ((copy_of_polinom.monoms.current->data.abc) % 10 != 0) out << " z^" << (copy_of_polinom.monoms.current->data.abc) % 10;*/
			
		}
		out << endl;
		return out;
	}
};

#endif
