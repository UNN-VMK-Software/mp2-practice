#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include "RingList.h"

using namespace std;

struct Tmonom {
	double cf;
	unsigned int abc;
	Tmonom(const double d = 0.0, const unsigned int m = 0) { cf = d; abc = m; };
	Tmonom(const Tmonom& _Tmonom) {
		cf = _Tmonom.cf;
		abc = _Tmonom.abc;
	};
	const Tmonom& operator = (const Tmonom& _Tmonom)
	{
		cf = _Tmonom.cf;
		abc = _Tmonom.abc;
		return *this;
	};
	bool operator < (const Tmonom& _tmonom) const
	{
		return abc < _tmonom.abc;
	};
	bool operator != (const Tmonom& _tmonom) const
	{
		return abc != _tmonom.abc;
	};
	bool operator == (const Tmonom& _tmonom) const
	{
		return abc == _tmonom.abc;
	};
};





class TPolinom {
private:
	TRingList<Tmonom> monoms;
public:
	TPolinom() {  }
	TPolinom(const string & s);
	TPolinom(const TPolinom &);
	~TPolinom();
	TPolinom operator+ (const TPolinom & _polinom);
	TPolinom operator* (const TPolinom & _polinom);
	TPolinom operator* (double d);
	const TPolinom& operator = (const TPolinom& _polinom);
	friend ostream& operator<< (ostream &out, const TPolinom& _polinom)
	{
		TPolinom copy_of_polinom = _polinom;
		copy_of_polinom.monoms.Reset();
		
		for (copy_of_polinom.monoms.current; !copy_of_polinom.monoms.IsEnded(); copy_of_polinom.monoms.GetNext())
		{
			out << copy_of_polinom.monoms.current->data.cf
				<< "x^" << (copy_of_polinom.monoms.current->data.abc / 100)
				<< "y^" << (copy_of_polinom.monoms.current->data.abc / 10) % 10
				<< "z^" << (copy_of_polinom.monoms.current->data.abc) % 10 << "+";
		}
		out << endl;
		return out;
	}
};





TPolinom::TPolinom(const string& s)
{
	string str = s;
	if (str[0] != '\0')
	{
		string num = "";
		double number = 0;
		int i = 0;
		int nMonoms = 0;
		bool flag;
		while (i < str.length() - 2)
		{
			flag = false;
			if ((str[i] == '-' || str[i] == '+'))
			{
				if (isalpha(s[i + 1]))
				{
					number = 1;
				}
				if (str[i] == '-')
				{
					flag = true;
					i++;
				}
				else if (str[i] == '+')
				{
					flag = false;
					i++;
				}
			}
			while (isdigit(str[i]) || (str[i] == '.'))
			{
				num += str[i];
				i++;
			}// не обрабатывается моном нулевой степени 
			number = atof(num.c_str());
			if (number == 0.0)
				number += 1;
			Tmonom temp;
			if (flag)
				number *= (-1);
			temp.cf = number;
			if ((str[i] == 'x') && (!(str[i + 1] == '^')))
			{
				temp.abc += 1 * 100;
				i += 1;
			}
			else if ((str[i] == 'x') && (str[i + 1] == '^'))
			{
				temp.abc += atoi(&str[i + 2]) * 100;
				i += 3;
			}
			if ((str[i] == 'y') && (!(str[i + 1] == '^')))
			{
				temp.abc += 1 * 10;
				i += 1;
			}
			else if ((str[i] == 'y') && (str[i + 1] == '^'))
			{
				temp.abc += atoi(&str[i + 2]) * 10;
				i += 3;
			}
			if ((str[i] == 'z') && (!(str[i + 1] == '^')))
			{
				temp.abc += 1;
				i += 1;
			}
			else if ((str[i] == 'z') && (str[i + 1] == '^'))
			{
				temp.abc += atoi(&str[i + 2]);
				i += 3;
			}
			monoms.Insert(temp);
			num.clear();
		}
	}

}


TPolinom::TPolinom(const TPolinom & _polinom)
{
	monoms = _polinom.monoms;
}

TPolinom::~TPolinom()
{
}

TPolinom TPolinom::operator+ (const TPolinom & _polinom)
{
	(*this).monoms.Reset();
	TPolinom copy_of_polinom = _polinom;
	copy_of_polinom.monoms.Reset();
	TPolinom res = (*this);
	bool a = true;
	for (this->monoms.current; a; this->monoms.GetNext())
	{
		for (copy_of_polinom.monoms.current; a; copy_of_polinom.monoms.GetNext())
		{
			TLink<Tmonom>* link = res.monoms.Search(copy_of_polinom.monoms.current->data);
			if (link != NULL)
				link->data.cf += copy_of_polinom.monoms.current->data.cf;
			else
				res.monoms.Insert(_polinom.monoms.current->data);
			if (copy_of_polinom.monoms.IsEnded() || this->monoms.IsEnded()) a = false;
		}
	}
	return res;
}

TPolinom TPolinom::operator* (const TPolinom & _polinom)
{
	(*this).monoms.Reset();
	TPolinom copy_of_polinom = _polinom;
	copy_of_polinom.monoms.Reset();
	TPolinom res = (*this);
	bool a = true;
	for (this->monoms.current; a; this->monoms.GetNext())
	{
		for (copy_of_polinom.monoms.current; a; copy_of_polinom.monoms.GetNext())
		{
			unsigned int tmpabc = (*this).monoms.current->data.abc + copy_of_polinom.monoms.current->data.abc;
			if (tmpabc < 1000)
			{
				Tmonom tmp((*this).monoms.current->data.cf * copy_of_polinom.monoms.current->data.cf, tmpabc);
				TLink<Tmonom>* tmp2 = res.monoms.Search(tmp);
				if (tmp2 != NULL)
					tmp2->data.cf += (*this).monoms.current->data.cf + copy_of_polinom.monoms.current->data.cf;
				else
					res.monoms.Insert(tmp);
				if (copy_of_polinom.monoms.IsEnded() || this->monoms.IsEnded()) a = false;
			}
			else throw "Power is more then expected";
		}
	}
	return *this;
}

TPolinom TPolinom::operator* (double d)
{
	(*this).monoms.Reset();
	TPolinom res = (*this);
	if (d == 0)
		res.monoms.Clean();
	else {
		while (!(monoms.IsEnded()))
		{
			res.monoms.current->data.cf *= d;
			res.monoms.GetNext();
		}
	}
	return res;
}
const TPolinom& TPolinom::operator =(const TPolinom& _polinom)
{
	monoms = _polinom.monoms;
	return *this;
};
