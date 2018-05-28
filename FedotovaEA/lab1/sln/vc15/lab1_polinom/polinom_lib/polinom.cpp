#include "monom.h"
#include "polinom.h"


TMonom::TMonom(const double cf, const unsigned int abc2)
{
	coeff = cf;
	abc = abc2;
}
TMonom::TMonom(const TMonom &n)
{
	coeff = n.coeff;
	abc = n.abc;
}
TMonom::TMonom(const string &s) ////// ne proveryla
{
	string c = s + ' ';
	int len = c.length();
	bool f = true;
	int min = 1;
	int g;
	double cof1;
	int ctep = 0;
	string cof;
	if (c[0] == '-')
	{
		min = -1;
		c.erase(0, 1);
	}
	for (int i = 0; f; i++)
	{
		if (((c[i] >= '0') && (c[i] <= '9')) || (c[i] == '.'))
		{
			cof = cof + c[i];
		}
		else
		{
			f = false;
			cof1 = converter_in_number(cof);
			g = i + 1;
		}
	}
	cof1 = cof1 * min;
	for (int j = g; j<len; j++)
	{
		if (c[j] == 'x')
		{
			if ((c[j + 1] >= '0') && (c[j + 1] <= '9'))
				ctep = ctep + 100 * (c[j + 1] - '0');
			else
				ctep = ctep + 100;
		}
		else
			if (c[j] == 'y')
			{
				if ((c[j + 1] >= '0') && (c[j + 1] <= '9'))
					ctep = ctep + 10 * (c[j + 1] - '0');
				else
					ctep = ctep + 10;
			}
			else
				if (c[j] == 'z')
				{
					if ((c[j + 1] >= '0') && (c[j + 1] <= '9'))
						ctep = ctep + (c[j + 1] - '0');
					else
						ctep = ctep + 1;
				}
	}
	coeff = cof1;
	abc = ctep;
}

const TMonom& TMonom::operator=(const TMonom &m)
{
	coeff = m.coeff;
	abc = m.abc;
	return *this;
}
bool TMonom::operator==(const TMonom &m) const
{
	if (abc == m.abc)
		return true;
	else
		return false;
}
bool TMonom::operator!=(const TMonom &m) const
{
	if (abc != m.abc)
		return true;
	else
		return false;
}
bool TMonom::operator<(const TMonom &m) const
{
	if (abc<m.abc)
		return true;
	else
		return false;
}
bool TMonom::operator>(const TMonom &m) const
{
	if (abc>m.abc)
		return true;
	else
		return false;
}
TMonom TMonom::operator*(const double d) const
{
	TMonom t(coeff*d, abc);
	return t;
}
TMonom TMonom::operator*(const TMonom &m) const
{
	if (abc + m.abc > 999)
		throw "error";
	else
	{
		TMonom t(coeff * m.coeff, abc + m.abc);
		return t;
	}
}
ostream & operator<<(ostream &os, const TMonom &n)
{
	os << n.coeff << "*x" << n.abc / 100 << "*y" << (n.abc / 10) % 10 << "*z" << n.abc % 10;
	return os;
}

//----------------------------------------------

TPolinom::TPolinom(const TPolinom &p)
{
	pol = p.pol;
}

TPolinom::TPolinom(const string &s)
{
	string c = s + '+';
	int len = c.length();
	bool min = false;
	string mon;
	for (int i = 0; i < len; i++)
	{
		if ((c[i] != '+') && (c[i] != '-'))
		{
			mon = mon + c[i];
		}
		else
		{
			if (mon != "")
			{
				if (min)
				{
					mon = '-' + mon;
				}
				TMonom b(mon);
				Node<TMonom>* t = pol.search(b);
				if (t != NULL)
				{
					t->data.coeff += b.coeff;
				}
				else
					pol.Insert_Up(b);
			}
			if (c[i] == '-')
				min = true;
			else
				min = false;
		}
	}
}

const TPolinom& TPolinom::operator=(const TPolinom &p)
{
	pol = p.pol;
	return *this;
}

TPolinom TPolinom::operator+(TPolinom &p) /////// drugoe
{
	pol.Reset();
	p.pol.Reset();
	pol.Getnext();
	p.pol.Getnext();
	TPolinom summa;
	while ((!pol.Isended()) && (!p.pol.Isended()))
	{
		TMonom a(pol.Getdata());
		TMonom b(p.pol.Getdata());
		if (a > b)
		{
			summa.pol.Insert_to_tail(a);
			pol.Getnext();
		}
		else
			if (a < b)
			{
				summa.pol.Insert_to_tail(b);
				p.pol.Getnext();
			}
			else
			{
				TMonom c(a.coeff + b.coeff, a.abc);
				if (c.coeff != 0)
					summa.pol.Insert_to_tail(c);
				pol.Getnext();
				p.pol.Getnext();
			}
	}
	while (!pol.Isended())
	{
		summa.pol.Insert_to_tail(pol.Getdata());
		pol.Getnext();
	}
	while (!p.pol.Isended())
	{
		summa.pol.Insert_to_tail(p.pol.Getdata());
		p.pol.Getnext();
	}
	return summa;
}



TPolinom TPolinom::operator*(TPolinom &p)
{
	pol.Reset();
	pol.Getnext();
	p.pol.Reset();
	p.pol.Getnext();
	TPolinom mult;
	while (!pol.Isended())
	{
		while (!p.pol.Isended())
		{
			TMonom c(pol.Getdata() * p.pol.Getdata());
			if (c.coeff != 0.0)
			{
				Node<TMonom>* t = mult.pol.search(c);
				if (t != NULL)
				{
					t->data.coeff += c.coeff;
					if (t->data.coeff == 0.0)
						mult.pol.del(t);
				}
				else
				{
					mult.pol.Insert_Up(c);
				}
			}
			p.pol.Getnext();
		}
		pol.Getnext();
		p.pol.Reset();
		p.pol.Getnext();
	}
	return mult;
}

TPolinom TPolinom::operator*(const double d)
{
	TPolinom multip;
	if (d != 0)
	{
		pol.Reset();
		pol.Getnext();
		while (!pol.Isended())
		{
			multip.pol.Insert_to_tail(pol.Getdata()*d);
			pol.Getnext();
		}
	}
	return multip;
}

bool TPolinom::operator==(const TPolinom &p) const
{
	if (this != &p)
	{
		bool flag = true;
		TPolinom pol1(*this), pol2(p);
		pol1.pol.Reset();
		pol1.pol.Getnext();
		pol2.pol.Reset();
		pol2.pol.Getnext();
		while ((flag) && (!pol1.pol.Isended()) && (!pol2.pol.Isended())) /////
		{
			TMonom a = pol1.pol.Getdata();
			TMonom b = pol2.pol.Getdata();
			if (a == b)
			{
				if (a.coeff != b.coeff)
					flag = false;
			}
			else
				flag = false;
			pol1.pol.Getnext();
			pol2.pol.Getnext();
		}
		if ((!pol1.pol.Isended()) || (!pol2.pol.Isended()))
			flag = false;
		return flag;
	}
	else
		return true;
}

bool TPolinom::operator!=(const TPolinom &p) const
{
	return !(*this == p);
}

ostream & operator<<(ostream & out, const TPolinom &p)
{
	out << p.pol;
	return out;
}


double rank_number(const double a, const int i)
{
	double b = 1;
	for (int j = 0; j < i; j++)
		b *= a;
	return b;
}

double converter_in_number(const string & s)
{
	int len = s.length();
	double a = 0.0;
	int i = 0;
	for (i = 0; ((i < len) && (s[i] != '.')); i++)
		a = a * 10.0 + (s[i] - '0');
	int j = i;
	if (s[j] == '.')
		for (i = j + 1; i < len; i++)
			a = a + (s[i] - '0') / (rank_number(10.0, (i - j)));
	return a;
}