#include <iostream>
#include <cstdio>
#include <string>

#include "Pol_List.h"
#include "Pol_Mon.h"

using namespace std;

class TPolinom {
private:
	TRingList<Monom> curmon;
public:
	TPolinom() {  }
	TPolinom(const string &s);
	TPolinom(const TPolinom &);
	~TPolinom();
	//TRingList<Monom> similar_terms(TRingList <Monom> sp);
	TPolinom operator+ (const TPolinom & _pol);
	TPolinom operator- (const TPolinom & _pol)
	{
		TPolinom res = (*this) + (-1.0) * _pol;
		return res;
	}
	TPolinom& operator+= (const TPolinom & _pol);
	TPolinom operator* (const TPolinom & _pol);
	TPolinom operator* (double d);
	TPolinom& operator = (const TPolinom& _pol);
	bool operator == (const TPolinom& curpol) const { return (*this).curmon == curpol.curmon; };
	bool operator != (const TPolinom& curpol) const { return !((*this) == curpol); };
	bool operator < (const TPolinom& curpol) const { return (*this).curmon <curpol.curmon; };
	bool operator > (const TPolinom& curpol) const { return (*this).curmon > curpol.curmon; };
	friend ostream& operator<< (ostream &out, const TPolinom& _pol)
	{
		TPolinom copy_of_polinom(_pol);
		copy_of_polinom.curmon.Reset();
		cout << copy_of_polinom.curmon.GetCurrent()->data.cf;
		if ((copy_of_polinom.curmon.GetCurrent()->data.stmonom / 100) != 0) {
			if ((copy_of_polinom.curmon.GetCurrent()->data.stmonom / 100) == 1)
				out << "x";
			else
				out << "x^" << (copy_of_polinom.curmon.GetCurrent()->data.stmonom / 100);
		}

		if ((copy_of_polinom.curmon.GetCurrent()->data.stmonom / 10) % 10 != 0) {
			if ((copy_of_polinom.curmon.GetCurrent()->data.stmonom / 10) % 10 == 1)
				out << "y";
			else out << "y^" << (copy_of_polinom.curmon.GetCurrent()->data.stmonom / 10) % 10;
		}
		if ((copy_of_polinom.curmon.GetCurrent()->data.stmonom) % 10 != 0) {
			if ((copy_of_polinom.curmon.GetCurrent()->data.stmonom % 10) == 1)
				out << "z";
			else out << "z^" << (copy_of_polinom.curmon.GetCurrent()->data.stmonom) % 10;
		}
		TLink<Monom>* cur = copy_of_polinom.curmon.GetNext();
		for (cur; !copy_of_polinom.curmon.IsEnded(); copy_of_polinom.curmon.GetNext())
		{
			if (copy_of_polinom.curmon.GetCurrent()->data.cf > 0)
			{
				out << " +" << copy_of_polinom.curmon.GetCurrent()->data.cf;
			}
			else out << " " << copy_of_polinom.curmon.GetCurrent()->data.cf;
			if ((copy_of_polinom.curmon.GetCurrent()->data.stmonom / 100) != 0) {
				if ((copy_of_polinom.curmon.GetCurrent()->data.stmonom / 100) == 1)
					out << "x";
				else
					out << "x^" << (copy_of_polinom.curmon.GetCurrent()->data.stmonom / 100);
			}

			if ((copy_of_polinom.curmon.GetCurrent()->data.stmonom / 10) % 10 != 0)
			{
				if ((copy_of_polinom.curmon.GetCurrent()->data.stmonom / 10) % 10 == 1)
					out << "y";
				else out << "y^" << (copy_of_polinom.curmon.GetCurrent()->data.stmonom / 10) % 10;
			}
			if ((copy_of_polinom.curmon.GetCurrent()->data.stmonom) % 10 != 0) {
				if ((copy_of_polinom.curmon.GetCurrent()->data.stmonom % 10) == 1)
					out << "z";
				else out << "z^" << (copy_of_polinom.curmon.GetCurrent()->data.stmonom) % 10;
			}

		}
		out << endl;
		return out;
	}
	friend TPolinom operator* (double d, const TPolinom &p)
	{
		TPolinom res(p);
		res.curmon.Reset();
		if (d == 0)
			res.curmon.Clean();
		else {
			for (res.curmon.GetCurrent(); !res.curmon.IsEnded(); res.curmon.GetNext())
			{
				res.curmon.GetCurrent()->data.cf *= d;
			}
		}
		return res;
	};
};

