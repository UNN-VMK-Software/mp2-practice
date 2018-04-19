#include "polinom.h"

int Polinom::AddTheSame(const Monom& c, Ringlist<Monom> r)
{
	 int k = 0;
		 r.reset();
		 while (!r.isended())
		 {
			 if (c == r.GetCurr())
			 {
				 r.GetCurr().coeff += c.coeff;
				 k++;
			 }
			 r.SetNext();
		 }
		 r.reset();
	 return k;
}

Ringlist<Monom> Polinom::Parse(const string& s)
{
	Ringlist<Monom> r;

	string temp = s;
	int l = temp.length();
	for (int i = 0; i < l; i++)
		if ((temp[i] == ' ') || (temp[i] == '^'))
			temp.erase(i, 1);

	for (int i = 0; i < l; i++)
	{
		string a;
		int abc = 0;
		int j = i;
		if ((temp[i] = '-') || (temp[i] = '+'))
		{
			char tmp = temp[i];
			i++;
			while (isdigit(temp[j]))
				j++;
			if (j - i)
			{
				a = tmp + temp.substr(i, j - i);
				i = j;
			}
			else
				a = tmp + "1";
		}
		else
		{
			while (isdigit(temp[j]))
				j++;
			if (j - i)
			{
				a =  temp.substr(i, j - i);
				i = j;
			}
			else
				a =  "1";
		}

		while ((temp[i] != '+') && (temp[i] != '-') && (i < l))
		{
			switch (temp[i])
			{
			case 'a':
			{
				if (isdigit(temp[i + 1]))
				{
					i++;
					int st = temp[i] - '0';
					abc += 100 * st;
				}
				else
					abc = 100;
				break;
			}

			case 'b':
			{
				if (isdigit(temp[i + 1]))
				{
					i++;
					int st = temp[i] - '0';
					abc += 10 * st;
				}
				else
					abc += 10;
				break;
			}

			case 'c':
			{
				if (isdigit(temp[i + 1]))
				{
					i++;
					int st = temp[i] - '0';
					abc += st;
				}
				else
					abc += 1;
				break;
			}
			}
			i++;
		}
		Monom c(stod(a), abc);

		if (!AddTheSame(c, r))
			r.InsertToOrdered(c);
	}
	return r;
}

Polinom::Polinom()
{
	Ringlist<Monom> a;
	pol = a;
}

Polinom::Polinom(const string& s)
{
	pol = Parse(s);
}

Polinom::Polinom(const Polinom& p)
{
	Ringlist<Monom> A(p.pol);
	pol = A;
}

Polinom& Polinom::operator=(const Polinom& p)
{
	Ringlist<Monom> A(p.pol);
	pol = A;
	return *this;
}

Polinom& Polinom::operator+(const Polinom& p)
{	
	Polinom temp(*this);
	Ringlist<Monom> p1 = p.pol;
	Ringlist<Monom> p2 = temp.pol;
	p1.reset();
	p2.reset();
	while (!p1.isended())
	{
		if (!AddTheSame(p1.GetCurr(), pol))
		{
			p2.InsertToOrdered(p1.GetCurr());
			p1.SetNext();
		}
	}

	p2.reset();
	return temp;
}

Polinom& Polinom::operator*(const int& a)
{
	Polinom temp(*this);
	Ringlist<Monom> p1 = temp.pol;
	p1.reset();

	while (!p1.isended())
	{
		p1.GetCurr().coeff *= a;
		p1.SetNext();
	}
	p1.reset();
	return temp;
}

Polinom& Polinom::operator*(const Polinom& p)
{
	Polinom temp;
	Ringlist<Monom> p1 = p.pol;
	Ringlist<Monom> p2 = temp.pol;
	p1.reset();
	p2.reset();
	while (p1.isended())
	{
		Polinom temp1(*this);
		Ringlist<Monom> p3 = temp.pol;
		p3.reset();

		int abc = p1.GetCurr().abc;
		while (p3.isended())
		{
			int tmp = p3.GetCurr().abc;

			if ((tmp % 10 + abc % 10) < 10 && (tmp / 10 % 10 + abc / 10 % 10) < 10 && (tmp / 100 + abc / 100) < 10)
			{
				p3.GetCurr().coeff *= p1.GetCurr().coeff;
				tmp += abc;
			}
			else
				throw "abc > 9";
			p3.SetNext();
		}
		p3.reset();
		temp = temp + temp1;
	}

	return temp;
}


