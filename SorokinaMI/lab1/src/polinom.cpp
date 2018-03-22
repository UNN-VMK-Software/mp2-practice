#include "polinom.h"
#include "ringlist.h"


Polinom::Polinom(const string &str) {
	s = str;
	int f = 0, v = 0;
	int i = 0, j, k, st = 0;
	double x = 1; //коэффициент
	Monom tmp;

	while (i<s.size())
	{
		 
		string as;

		if (s[i] == '-')
		{
			x = -1;
			i++;
		}
		char a[20];
		j = 0;
		while ((s[i] != '+') && (s[i] != '-') && (i<s.size()))
		{
			a[j] = s[i];
			j++;
			i++;
			v++;
		}
		if (v != 0)
		{
			i--;
			as = a;
			as.erase(j);
			k = 0;
			while (k < as.length())
			{

				if (isdigit(as[k]) != 0)
				{
				    char c[10];
					string cs;
					while (((isdigit(as[k]) != 0) || (as[k] == '.')) && (k < as.length()))
					{
						c[k] = as[k];
						k++;
					}
					cs = c;
			        cs.erase(k);
					x *= stod(cs);
				}

				tmp.SetCoeff(x);

				char p[1];
				if (as[k] == 'x')
				{
					if (as[k + 1] == '^')
					{
						p[0] = as[k + 2];
						st += atoi(p) * 100;
						k += 3;
					}
					else
					{
						st += 100;
						k++;
					}
				}

				if (as[k] == 'y')
				{
					if (as[k + 1] == '^')
					{
						p[0] = as[k + 2];
						st += atoi(p) * 10;
						k += 3;
					}
					else
					{
						st += 10;
						k++;
					}
				}

				if (as[k] == 'z')
				{
					if (as[k + 1] == '^')
					{
						p[0] = as[k + 2];
						st += atoi(p);
						k += 3;
					}
					else
					{
						st += 1;
						k++;
					}
				}
			}
			tmp.SetIndex(st);
			monoms.InsertToTail(tmp);
			st = 0;
			x = 1;
		}
		v = 0;
		i++; // итерация
	}
}
Polinom::Polinom(const Polinom &p1) {
	s = p1.s;
	monoms = p1.monoms;
}
Polinom Polinom::operator+(const Polinom &p1) {
	Polinom tmp(p1);
	Link <Monom> *m1;
	monoms.Reset();
	m1 = monoms.GetNext();
	tmp.monoms.Sequencing();
	while (!monoms.IsEnded()) {
		tmp.monoms.Insert(monoms.GetValue());
		m1 = monoms.GetNext();
	}
	return tmp;
}
Polinom Polinom::operator*(const Polinom &p1) {
	Polinom tmp(p1);
	Polinom Res;
	Monom MAX(1,999);
	Link <Monom> *m1, *m2;
	monoms.Reset();
	m1 = monoms.GetNext();
	tmp.monoms.Reset();
	m2 = monoms.GetNext();
	while (!monoms.IsEnded()) {
		while (!tmp.monoms.IsEnded()) {
			if (monoms.GetValue()*tmp.monoms.GetValue() < MAX) {
				Res.monoms.Insert(monoms.GetValue()*tmp.monoms.GetValue());
			}
			m1 = monoms.GetNext();
		}
		m2 = monoms.GetNext();
	}
	return Res;
}
Polinom Polinom::operator*(const double &d) {
	Link<Monom> *tmp;
	monoms.Reset();
	tmp = monoms.GetNext();
	while (!monoms.IsEnded()) {
		tmp->data = tmp->data*d;
		tmp = monoms.GetNext();
	}
	return *this;
}
const Polinom& Polinom::operator=(const Polinom &p1) {
	if (this != &p1) {
		s = p1.s;
		monoms = p1.monoms;
	}
	return *this;
}