#include "monom.h"
#include "polinom.h"


monom::monom(const double cf, const unsigned int abc2)
{
	coeff = cf;
	abc = abc2;
}
monom::monom(const monom &n)
{
	coeff = n.coeff;
	abc = n.abc;
}
monom::monom(const string &s)//создание монома
{
	string c = s + ' ';
	bool f = true;
	int min = 1, i;
	abc = 0;
	string cof;
	if (c[0] == '-')
	{
		min = -1;
		c.erase(0, 1); //удаление элемента
	}
	int len = c.length();
	for (i = 0; f; i++)
	{
		if (((c[i] >= '0') && (c[i] <= '9')) || (c[i] == '.'))
		{
			cof = cof + c[i];
		}
		else
		{
			f = false;
			if (cof != "")
			{
				double cof1 = atof(cof.c_str());
				coeff = min * cof1;
			}
			else
				coeff = min;
		}
	}
	for (int j = i - 1; j<len; j++)
	{
		if (c[j] == 'x')
		{
			if ((c[j + 1] >= '0') && (c[j + 1] <= '9'))
			{
				abc = abc + 100 * (c[j + 1] - '0');
				j++;
			}
			else
				abc = abc + 100;
		}
		else
			if (c[j] == 'y')
			{
				if ((c[j + 1] >= '0') && (c[j + 1] <= '9'))
				{
					abc = abc + 10 * (c[j + 1] - '0');
					j++;
				}
				else
					abc = abc + 10;
			}
			else
				if (c[j] == 'z')
				{
					if ((c[j + 1] >= '0') && (c[j + 1] <= '9'))
					{
						abc = abc + (c[j + 1] - '0');
						j++;
					}
					else
						abc = abc + 1;
				}
	}
}

const monom& monom::operator=(const monom &m)
{
	coeff = m.coeff;
	abc = m.abc;
	return *this;
}
bool monom::operator==(const monom &m) const
{
	if (abc == m.abc)
		return true;
	else
		return false;
}
bool monom::operator!=(const monom &m) const
{
	if (abc != m.abc)
		return true;
	else
		return false;
}
bool monom::operator<(const monom &m) const
{
	if (abc<m.abc)
		return true;
	else
		return false;
}
bool monom::operator>(const monom &m) const
{
	if (abc>m.abc)
		return true;
	else
		return false;
}
monom monom::operator*(const double d) const
{
	monom t(coeff*d, abc);
	return t;
}
monom monom::operator*(const monom &m) const
{
	if (abc + m.abc > 999)
		throw "error";
	else
	{
		monom t(coeff * m.coeff, abc + m.abc);
		return t;
	}
}
ostream & operator<<(ostream &os, const monom &n)
{
	os << n.coeff << "*x" << n.abc / 100 << "*y" << (n.abc / 10) % 10 << "*z" << n.abc % 10;
	return os;
}


polinom::polinom(const polinom &p)
{
	pol = p.pol;
}

polinom::polinom(const string &s)
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
				monom b(mon);
				mon = "";
				node<monom>* t = pol.search(b);//ищем звено с данными b
				if (t != NULL)
				{
					t->data.coeff += b.coeff; // считаем подобные
				}
				else
					pol.insert_up(b);
			}
			if (c[i] == '-')
				min = true;
			else
				min = false;
		}
	}
}

const polinom& polinom::operator=(const polinom &p)
{
	pol = p.pol;
	return *this;
}

polinom polinom::operator+(const polinom &p) const
{
	ringlist<monom> pol1 = pol;
	ringlist<monom> thispol = p.pol;
	pol1.reset();  //запись в head
	thispol.reset();
	pol1.getnext();
	thispol.getnext();
	polinom summa;
	while ((!pol1.isended()) && (!thispol.isended())) //пока полиномы не закончились
	{
		monom a(pol1.getdata());
		monom b(thispol.getdata());
		if (a > b)
		{
			summa.pol.insert_to_tail(a);
			pol1.getnext();
		}
		else
			if (a < b)
			{
				summa.pol.insert_to_tail(b);
				thispol.getnext();
			}
			else
			{
				monom c(a.coeff + b.coeff, a.abc);
				if (c.coeff != 0)
					summa.pol.insert_to_tail(c);
				pol1.getnext();
				thispol.getnext();
			}
	}
	while (!pol1.isended())
	{
		summa.pol.insert_to_tail(pol.getdata());
		pol1.getnext();
	}
	while (!thispol.isended())
	{
		summa.pol.insert_to_tail(thispol.getdata());
		thispol.getnext();
	}
	return summa;
}



polinom polinom::operator*(const polinom &p) const
{
	ringlist<monom> pol1 = pol;
	ringlist<monom> thispol = p.pol;
	pol1.reset();
	thispol.reset();
	pol1.getnext();
	thispol.getnext();
	polinom mult;
	while (!pol1.isended())
	{
		while (!thispol.isended())
		{
			monom c(pol1.getdata() * thispol.getdata());
			if (c.coeff != 0.0)
			{
				node<monom>* t = mult.pol.search(c);
				if (t != NULL)
				{
					t->data.coeff += c.coeff;
					if (t->data.coeff == 0.0)
						mult.pol.delet(t);
				}
				else
				{
					mult.pol.insert_up(c);
				}
			}
			thispol.getnext();
		}
		pol1.getnext();
		thispol.reset();
		thispol.getnext();
	}
	return mult;
}

polinom polinom::operator*(const double d) const
{
	ringlist<monom> pol1 = pol;
	polinom multip;
	if (d != 0)
	{
		pol1.reset();
		pol1.getnext();
		while (!pol1.isended())
		{
			multip.pol.insert_to_tail(pol1.getdata()*d);
			pol1.getnext();
		}
	}
	return multip;
}

bool polinom::operator==(const polinom &p) const
{
	if (this != &p)
	{
		bool flag = true;
		polinom pol1(*this), pol2(p);
		pol1.pol.reset();
		pol1.pol.getnext();
		pol2.pol.reset();
		pol2.pol.getnext();
		while ((flag) && (!pol1.pol.isended()) && (!pol2.pol.isended()))
		{
			monom a = pol1.pol.getdata();
			monom b = pol2.pol.getdata();
			if (a == b)
			{
				if (a.coeff != b.coeff)
					flag = false;
			}
			else
				flag = false;
			pol1.pol.getnext();
			pol2.pol.getnext();
		}
		if ((!pol1.pol.isended()) || (!pol2.pol.isended()))
			flag = false;
		return flag;
	}
	else
		return true;
}

bool polinom::operator!=(const polinom &p) const
{
	return !(*this == p);
}

ostream & operator<<(ostream & out, const polinom &p)
{
	out << p.pol;
	return out;
}



/*double rank_number(const double a, const int i)
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
}*/