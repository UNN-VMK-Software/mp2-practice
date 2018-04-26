#include "Polinom.h"
using namespace std;


list<monom> Polinom::similar_terms(list <monom> sp)
{
	list<monom> res;
	sp.Reset(); 
	res.Reset();
	monom tmp;
	
	Node<monom>* p = sp.GetCur();
	sp.Step();

	if (sp.IsNotOver())
	{
		sp.Reset();

		while (sp.IsNotOver())
		{
			tmp.coeff = sp.GetCur()->data.coeff;
			tmp.abc = sp.GetCur()->data.abc;

			while ((sp.GetCur()->data.abc == sp.GetCur()->next->data.abc) && (sp.IsNotOver()))
			{
				tmp.coeff += sp.GetCur()->next->data.coeff;
				sp.Step();
			}

			if (tmp.coeff)
			{
				res.Insert(tmp);
				res.Step();
			}

			if (sp.GetCur())
				sp.Step();
		}
		res.Reset();
		if (res.GetCur()->data.abc == 0 && res.GetCur()->data.coeff == 0)
			res.InsertAfter(res.GetCur(), NULL);
	}
	else
		res = sp;

	return res;
}


Polinom::Polinom(string pol)
{
	list<monom> res;
	while (pol.length())
	{
		string part;
		monom temp;
		int pos = 1;
		while (pos < pol.length() && pol[pos] != '+' && pol[pos] != '-')
			pos++;
		part = pol.substr(0, pos);              // substr 
		pol.erase(0, pos);                      // erase
		pos = 0;
		while (part[pos] != 'x' && part[pos] != 'y' && part[pos] != 'z' && pos < part.length())
			pos++;

		string c = part.substr(0, pos);          
		if (c == "+" || c.length() == 0)
			temp.coeff = 1;
		else
			if (c == "-")
				temp.coeff = -1;
			else
				temp.coeff = stod(c);                

		part.erase(0, pos);                   
		part += ' ';
		int a[3] = { 100,10,1 };
		for (int i = 0; i < 3; i++)
		{
			pos = part.find((char)(120 + i));     // 120 - x, 121 - y, 122 - z
			if (pos > -1)
			{
				if (part[pos + 1] != '^')
					part.insert(pos + 1, "^1");
				temp.abc += a[i] * stoi(part.substr(pos + 2, 1));          
				part.erase(pos, 3);
			}
		}
		Plist.Insert(temp);

	}
	Plist = similar_terms(Plist);
}



Polinom::Polinom(const Polinom& pol)
{
	Plist = pol.Plist;
}


Polinom& Polinom:: operator=(const Polinom &pol)
{
	Plist= pol.Plist;
	return *this;
}



Polinom Polinom::operator+(const Polinom& pol) const
{
	Polinom res;
	Polinom pthis = *this;
	Polinom p = pol;

	pthis.Plist.Reset();
	p.Plist.Reset();
	res.Plist.Reset();

	while (pthis.Plist.IsNotOver() && p.Plist.IsNotOver())
	{
		if (pthis.Plist.GetCur()->data > p.Plist.GetCur()->data)
		{
			res.Plist.InsertToTail(p.Plist.GetCur()->data);
			p.Plist.Step();
			res.Plist.Step();
		}
		else
			if (pthis.Plist.GetCur()->data < p.Plist.GetCur()->data)
			{
				res.Plist.InsertToTail(pthis.Plist.GetCur()->data);
				pthis.Plist.Step();
				res.Plist.Step();
			}
			else
			{
				double new_coeff = pthis.Plist.GetCur()->data.coeff + p.Plist.GetCur()->data.coeff;
				if (new_coeff)
				{
					monom temp(new_coeff, pthis.Plist.GetCur()->data.abc);
					res.Plist.InsertToTail(temp);
					res.Plist.Step();
				}
				pthis.Plist.Step();
				p.Plist.Step();
			}
	}
	while (pthis.Plist.IsNotOver())
	{
		res.Plist.InsertToTail(pthis.Plist.GetCur()->data);
		pthis.Plist.Step();
		res.Plist.Step();
	}
	while (p.Plist.IsNotOver())
	{
		res.Plist.InsertToTail(p.Plist.GetCur()->data);
		p.Plist.Step();
		res.Plist.Step();
	}
	return res;
}


Polinom Polinom::operator*(const double a) const
{
	Polinom res;
	if (a)
	{
		res = *this;
		res.Plist.Reset();
		while (res.Plist.IsNotOver())
		{
			res.Plist.GetCur()->data.coeff *= a;
			res.Plist.Step();
		}
	}
	return res;
}


Polinom Polinom::operator*(const Polinom& pol) const
{
	Polinom res;
	Polinom pthis = *this;
	Polinom p = pol;

	pthis.Plist.Reset();
	p.Plist.Reset();

	while (pthis.Plist.IsNotOver())
	{
		double pthis_coeff = pthis.Plist.GetCur()->data.coeff;
		int pthis_abc = pthis.Plist.GetCur()->data.abc;
		Polinom temp(pol);
		temp.Plist.Reset();
		while (temp.Plist.IsNotOver())
		{
			int temp_abc = temp.Plist.GetCur()->data.abc;
			if ((temp_abc % 10 + pthis_abc % 10) < 10 && (temp_abc / 10 % 10 + pthis_abc / 10 % 10) < 10 && (temp_abc / 100 + pthis_abc / 100) < 10)
			{
				temp.Plist.GetCur()->data.abc += pthis_abc;
				temp.Plist.GetCur()->data.coeff *= pthis_coeff;
			}
			else
				throw "large index";
			temp.Plist.Step();
		}
		res = res + temp;
		pthis.Plist.Step();
	}
	return res;
}


ostream& operator<<(ostream &ostr, const Polinom& pol)
{
	Polinom p = pol;
	p.Plist.Reset();

	while (p.Plist.IsNotOver())
	{
		monom temp = p.Plist.GetCur()->data;

		if (temp.coeff > 0)
		{
			ostr << "+";
			if (temp.coeff == 1 && temp.abc == 0)
				ostr << "1";
			else
				if (temp.coeff != 1)
					ostr << temp.coeff;
		}
		else
			ostr << temp.coeff;

		int a = temp.abc / 100;
		if (a>1)
			ostr << "x^" << a;
		else
			if (a == 1)
				ostr << "x";
		a = temp.abc / 10 % 10;
		if (a>1)
			ostr << "y^" << a;
		else
			if (a == 1)
				ostr << "y";
		a = temp.abc % 10;
		if (a>1)
			ostr << "z^" << a;
		else
			if (a == 1)
				ostr << "z";
		p.Plist.Step();
	}
	return ostr;
}
