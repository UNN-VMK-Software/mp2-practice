#include "polinom.h"

Ringlist<Monom> Polinom::AddSameAndInsert(const Monom& c,const Ringlist<Monom> r)
{
	Ringlist<Monom> temp = r;
	temp.reset();
	int k = 0;
	while (!temp.isended())
	{
		if (c.abc == temp.GetCurr().abc)
		{
			temp.GetCurr().coeff += c.coeff;
			k++;
			if (!temp.GetCurr().coeff)
				temp.GetCurr().abc = 0;
		}
		temp.SetNext();
	}
	temp.reset();
	if (!k)
		temp.InsertToOrdered(c);
	return temp;
}

Ringlist<Monom> Polinom::Parse(const string& s)
{
	Ringlist<Monom> r;

	string temp = s;
	int l = temp.length();
	for (int i = 0; i < temp.length(); i++)
		if ((temp[i] == ' ') || (temp[i] == '^'))
		{
			temp.erase(i, 1);
			i--;
		}

	for (int i = 0; i < temp.length();)
	{
		string a;
		int abc = 0;
		int j = i;
		if ((temp[i] == '-') || (temp[i] == '+'))
		{
			if (temp[i] == '-')
			{
				i++;
				j++;
				while (isdigit(temp[j]) || temp[j] == '.')
					j++;
				if (j - i)
				{
					a = "-" + temp.substr(i, j - i);
					i = j;
				}
				else
					a = "-1";
			}

			if (temp[i] == '+')
			{
				i++;
				j++;
				while (isdigit(temp[j]) || temp[j] == '.')
					j++;
				if (j - i)
				{
					a = temp.substr(i, j - i);
					i = j;
				}
				else
					a = "1";
			}
		}
		else
		{
			while (isdigit(temp[j]) || temp[j] == '.')
				j++;
			if (j - i)
			{
				a =  temp.substr(i, j - i);
				i = j;
			}
			else
				a =  "1";
		}

		while ((temp[i] != '+') && (temp[i] != '-') && (i < temp.length()))
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
					abc += 100;
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
		r = AddSameAndInsert(c, r);
	}
	return r;
}

Polinom::Polinom()
{
	Ringlist<Monom> A;
	pol = A;
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

Polinom Polinom::operator+(const Polinom& p)
{	
	Polinom temp(*this);
	Ringlist<Monom> p1 = p.pol;
	p1.reset();
	temp.pol.reset();
	while (!p1.isended())
	{
		temp.pol = AddSameAndInsert(p1.GetCurr(), temp.pol);
		p1.SetNext();
	}
	return temp;
}

Polinom Polinom::operator*(const int& a)
{
	Polinom temp(*this);
	temp.pol.reset();

	while (!temp.pol.isended())
	{
		temp.pol.GetCurr().coeff *= a;
		temp.pol.SetNext();
	}
	temp.pol.reset();
	return temp;
}

Polinom Polinom::operator*(const Polinom& p)
{
	Polinom temp;
	Ringlist<Monom> p1 = p.pol;
	p1.reset();
	while (!p1.isended())
	{
		Polinom temp1(*this);
		temp1.pol.reset();

		int abc = p1.GetCurr().abc;
		if (abc)
		{
			while (!temp1.pol.isended())
			{
				int tmp = temp1.pol.GetCurr().abc;
				if ((tmp % 10 + abc % 10) < 10 && (tmp / 10 % 10 + abc / 10 % 10) < 10 && (tmp / 100 + abc / 100) < 10)
				{
					temp1.pol.GetCurr().coeff *= p1.GetCurr().coeff;
					temp1.pol.GetCurr().abc += abc;
				}
				else
					throw "abc > 9";
				temp1.pol.SetNext();
			}
		}
		else
			temp1 = temp1 * p1.GetCurr().coeff;
		temp1.pol.reset();
		temp = temp + temp1;
		p1.SetNext();
	}
	return temp;
}

ostream& operator<< (ostream& os, const Polinom& p)
{
	Polinom tempP = p;
	tempP.pol.reset();
	Monom tempM;
	Monom FNode = tempP.pol.GetCurr();
	if (FNode.coeff)
	{
		while (!tempP.pol.isended())
		{

			tempM = tempP.pol.GetCurr();
			if (tempM.coeff > 0 && tempM != FNode)
				os << " + ";
			if (tempM.coeff != 1 && tempM.coeff != -1 && tempM.coeff != 0)
				os << ' ' << tempM.coeff;
			else
				if (tempM.coeff == -1 && tempM.abc != 0)
					os << " - ";
				else
					if ((tempM.coeff == 1 || tempM.coeff == -1) && tempM.abc == 0)
						os << ' ' << tempM.coeff;
			if (tempM.abc / 100)
			{
				if (tempM.abc / 100 == 1)
					os << "a";
				else
					os << "a^" << tempM.abc / 100;
			}

			if (((tempM.abc % 100) - (tempM.abc % 10)) / 10)
			{
				if (((tempM.abc % 100) - (tempM.abc % 10)) / 10 == 1)
					os << 'b';
				else
					os << "b^" << ((tempM.abc % 100) - (tempM.abc % 10)) / 10;
			}

			if (tempM.abc % 10)
			{
				if (tempM.abc % 10 == 1)
					os << 'c';
				else
					os << "c^" << tempM.abc % 10;
			}
			tempP.pol.SetNext();
		}
	}
	else
		os << " 0";
	tempP.pol.reset();

	return os;
}


