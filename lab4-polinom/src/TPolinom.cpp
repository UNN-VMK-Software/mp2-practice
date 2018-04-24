#include "TPolinom.h"

TPolinom& TPolinom::operator = (const TPolinom& tmp)
{
	monoms = tmp.monoms;
	return *this;
}

TPolinom::TPolinom(const string s)
{
	int k = s.length();
	string c;

	if (k != 0)
	{
		for (int i = 0; i < k; i++)
		{
			if ((isdigit(s[i])) || (isalpha(s[i])) || (s[i] == '-'))
			{
				int j = 0;
				while ((s[i + 1 + j] != '+') && (s[i + 1 + j] != '-') && ((s[i + 1 + j] != '\0')))
				{
					j++;
				}
				c = s.substr(i, j + 1);
				TMonom tmp(c);
				monoms.Insert(tmp);
				i = i + j;
			}
		}
	}
}

TPolinom::TPolinom(const TPolinom &poli2)
{
	monoms = poli2.monoms;
}

TPolinom TPolinom::operator + (const TPolinom& poli2)
{
	TPolinom C;

	TPolinom tmp(poli2);
	monoms.Reset();
	tmp.monoms.Reset();

	while ((monoms.IsEnded() == false) && (tmp.monoms.IsEnded() == false))
	{
		if (monoms.GetLink()->data > tmp.monoms.GetLink()->data)
		{
			C.monoms.Insert(monoms.GetLink()->data);
			monoms.Next();
		}

		else if (monoms.GetLink()->data < tmp.monoms.GetLink()->data)
		{
			C.monoms.Insert(tmp.monoms.GetLink()->data);
			tmp.monoms.Next();
		}

		else if (monoms.GetLink()->data == tmp.monoms.GetLink()->data)
		{
			if ((monoms.GetLink()->data.cf + tmp.monoms.GetLink()->data.cf) != 0)
			{
				C.monoms.Insert(monoms.GetLink()->data + tmp.monoms.GetLink()->data);
			}
			monoms.Next();
			tmp.monoms.Next();
		}
	}

	while (monoms.IsEnded() == false)
	{
		C.monoms.Insert(monoms.GetLink()->data);
		monoms.Next();
	}

	while (tmp.monoms.IsEnded() == false) 
	{
		C.monoms.Insert(tmp.monoms.GetLink()->data);
		tmp.monoms.Next();
	}

	return C;
}

TPolinom TPolinom::operator - (const TPolinom& poli2)
{
	TPolinom C;

	TPolinom tmp(poli2);
	monoms.Reset();
	tmp.monoms.Reset();

	while (tmp.monoms.IsEnded() == false)
	{
		tmp.monoms.GetLink()->data.cf = -tmp.monoms.GetLink()->data.cf;
		tmp.monoms.Next();
	}

	tmp.monoms.Reset();

	while ((monoms.IsEnded() == false) && (tmp.monoms.IsEnded() == false))
	{
		if (monoms.GetLink()->data > tmp.monoms.GetLink()->data)
		{
			C.monoms.Insert(monoms.GetLink()->data);
			monoms.Next();
		}

		if (monoms.GetLink()->data < tmp.monoms.GetLink()->data)
		{
			C.monoms.Insert(tmp.monoms.GetLink()->data);
			tmp.monoms.Next();
		}

		if (monoms.GetLink()->data == tmp.monoms.GetLink()->data)
		{
			if ((monoms.GetLink()->data.cf + tmp.monoms.GetLink()->data.cf) != 0)
			{
				C.monoms.Insert(monoms.GetLink()->data + tmp.monoms.GetLink()->data);
			}
			monoms.Next();
			tmp.monoms.Next();
		}
	}

	while (monoms.IsEnded() == false)
	{
		C.monoms.Insert(monoms.GetLink()->data);
		monoms.Next();
	}

	while (tmp.monoms.IsEnded() == false)
	{
		C.monoms.Insert(tmp.monoms.GetLink()->data);
		tmp.monoms.Next();
	}

	return C;
}

TPolinom TPolinom::operator * (const TPolinom& poli2)
{
	TPolinom C;
	TPolinom tmp(poli2);
	monoms.Reset();

	while (monoms.IsEnded() == false)
	{
		tmp.monoms.Reset(); 
		while (tmp.monoms.IsEnded() == false)
		{
			TMonom monom;
			monom.cf = tmp.monoms.GetLink()->data.cf * monoms.GetLink()->data.cf;
			if (monom.cf != 0)
			{
				int ABC = tmp.monoms.GetLink()->data.abc + monoms.GetLink()->data.abc;
				if ((ABC / 100 < 10) && (ABC / 10 % 10 < 10) && (ABC % 10 < 10))
					monom.abc = ABC;
				else
					throw "Error";

				TPolinom tmp2;
				tmp2.monoms.Insert(monom);
				C = C + tmp2;
			}
			tmp.monoms.Next();
		}
		monoms.Next();
	}

	return C;
}

TPolinom TPolinom::operator * (double cf2)
{
	TPolinom C;
	monoms.Reset();

	while (monoms.IsEnded() == false)
	{
		monoms.GetLink()->data.cf = cf2 * monoms.GetLink()->data.cf;
		C.monoms.Insert(monoms.GetLink()->data);
		monoms.Next();
	}

	return C;
}

TPolinom operator *(double cf2, const TPolinom& poli2)
{
	TPolinom C;
	TPolinom tmp(poli2);
	tmp.monoms.Reset();

	while (tmp.monoms.IsEnded() == false)
	{
		tmp.monoms.GetLink()->data.cf = cf2 * tmp.monoms.GetLink()->data.cf;
		C.monoms.Insert(tmp.monoms.GetLink()->data);
		tmp.monoms.Next();
	}

	return C;
}

ostream& operator <<(ostream& ostr, const TPolinom& poli2)
{
	TPolinom B(poli2);
	B.monoms.Reset();

	/*while (B.monoms.IsEnded() == false)
	{
		if (B.monoms.GetLink()->data.cf > 0)
		{
			if (B.monoms.GetLink()->data.abc != 0)
			{
				if (B.monoms.GetLink()->data.cf == 1)
				{
					ostr << "+";
				}
				else
				{
					ostr << "+" << B.monoms.GetLink()->data.cf;
				}
			}
			else
			{
				ostr << "+" << B.monoms.GetLink()->data.cf;
			}
		}

		if (B.monoms.GetLink()->data.cf < 0)
		{
			ostr << B.monoms.GetLink()->data.cf;
		}

		if (B.monoms.GetLink()->data.abc != 0)
		{
			int a = B.monoms.GetLink()->data.abc / 100;
			if (a > 1)
			{
				ostr << "x^" << a;
			}
			if (a == 1)
			{
				ostr << "x";
			}

			a = B.monoms.GetLink()->data.abc / 10 % 10;
			if (a > 1)
			{
				ostr << "y^" << a;
			}
			if (a == 1)
			{
				ostr << "y";
			}

			a = B.monoms.GetLink()->data.abc % 10;
			if (a > 1)
			{
				ostr << "z^" << a;
			}
			if (a == 1)
			{
				ostr << "z";
			}
		}
		B.monoms.Next();
	}*/

	if (B.monoms.IsEnded() == false)
	{
		while (B.monoms.IsEnded() == false)
		{
			if (B.monoms.GetLink()->data.cf > 0)
			{
				if (B.monoms.GetLink()->data.abc != 0)
				{
					if (B.monoms.GetLink()->data.cf == 1)
					{
						ostr << "+";
					}
					else
					{
						ostr << "+" << B.monoms.GetLink()->data.cf;
					}
				}
				else
				{
					ostr << "+" << B.monoms.GetLink()->data.cf;
				}
			}

			if (B.monoms.GetLink()->data.cf < 0)
			{
				ostr << B.monoms.GetLink()->data.cf;
			}

			if (B.monoms.GetLink()->data.abc != 0)
			{
				int a = B.monoms.GetLink()->data.abc / 100;
				if (a > 1)
				{
					ostr << "x^" << a;
				}
				if (a == 1)
				{
					ostr << "x";
				}

				a = B.monoms.GetLink()->data.abc / 10 % 10;
				if (a > 1)
				{
					ostr << "y^" << a;
				}
				if (a == 1)
				{
					ostr << "y";
				}

				a = B.monoms.GetLink()->data.abc % 10;
				if (a > 1)
				{
					ostr << "z^" << a;
				}
				if (a == 1)
				{
					ostr << "z";
				}
			}
			B.monoms.Next();
		}
	}
	else
	{
		ostr << "0";
	}
	
	return ostr;
}

bool TPolinom::operator == (const TPolinom& poli2) const
{
	TPolinom A(*this);
	TPolinom B(poli2);

	return A.monoms == B.monoms;
}