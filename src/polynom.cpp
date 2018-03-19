#include "polynom.h"

const string xyz = "xyz";

polynom::polynom(const string expr) {
	plist = parse(expr);
	plist = reduction(plist);
};

list<monom> polynom::reduction(list <monom> p) {
	list<monom> res;	
	p.Reset();
	res.Reset();
	node<monom> temp(p.GetCurr()->data.cf);
	while (!(p.IsEnded()))
	{
		temp.data.abc = p.GetCurr()->data.abc;
		if (p.GetCurr()->data.abc == p.GetCurr()->next->data.abc)
		{			
			temp.data.cf += p.GetCurr()->next->data.cf;			
		}
		else
		{
			if (temp.data.cf)
			{
				res.Insert(res.GetCurr(), temp.data);
				res.GetNext();
			}
			temp.data.cf = p.GetCurr()->next->data.cf;
		}		
		p.GetNext();
	}
	return res;
}

list<monom> polynom::parse(const string expr) {
	int k[3] = { 100,10,1 };		
	list<monom> list;
	
	string str = expr, part;
	int pos;
	while (str.length())
	{
		monom m;
		pos = 1;
		while (pos < str.length() && str[pos] != '+' && str[pos] != '-')
			pos++;
		part = str.substr(0, pos);
		str.erase(0, pos);

		pos = 0;						
		while (pos < part.length() && (isdigit(part[pos]) || part[pos] == '+' || part[pos] == '-'))
			pos++;
		if (pos == 1 && (part[0] == '-' || part[0] == '+') || pos == 0)

			if (part[0] == '-')
				m.cf = -1;
			else
				m.cf = 1;		
		else
			m.cf = stod(part.substr(0, pos));

		part.erase(0, pos);
		part += ' ';

		for (int i = 0; i < 3; i++)
		{
			pos = part.find(xyz[i]);
			if (pos > -1)
				if (part[pos + 1] != '^')
					m.abc += k[i];
				else m.abc += k[i] * stoi(part.substr(pos+2,1));
		}

		list.InsertOrd(m);
	}
	return list;
}

polynom polynom::operator+(const polynom& pol) const
{
	polynom res;
	list<monom> list2 = pol.plist, list1 = plist;
	list1.Reset();
	list2.Reset();
	res.plist.Reset();
	while (!list1.IsEnded() && !list2.IsEnded())
	{
		if (list1.GetCurr()->data > list2.GetCurr()->data)
		{
			res.plist.Insert(res.plist.GetCurr(), list1.GetCurr()->data);
			list1.GetNext();
			res.plist.GetNext();
		}
		else 
			if (list1.GetCurr()->data < list2.GetCurr()->data)
			{
				res.plist.Insert(res.plist.GetCurr(), list2.GetCurr()->data);
				list2.GetNext();
				res.plist.GetNext();
			}
			else
			{
				double rcf = list1.GetCurr()->data.cf + list2.GetCurr()->data.cf;
				if (rcf)
				{
					monom temp(rcf, list1.GetCurr()->data.abc);
					res.plist.Insert(res.plist.GetCurr(), temp);
					
					res.plist.GetNext();
				}
				list1.GetNext();
				list2.GetNext();
			}
	}
	
	while (!list1.IsEnded())
	{
		res.plist.Insert(res.plist.GetCurr(), list1.GetCurr()->data);
		list1.GetNext();
		res.plist.GetNext();
	}
	while (!list2.IsEnded())
	{
		res.plist.Insert(res.plist.GetCurr(), list2.GetCurr()->data);
		list2.GetNext();
		res.plist.GetNext();
	}

	return res;
}

polynom polynom::operator*(const double c) const {

	polynom res;
	if (c)
	{
		res = *this;
		res.plist.Reset();
		while (!(res.plist.IsEnded()))
		{
			res.plist.GetCurr()->data.cf *= c;
			res.plist.GetNext();
		}
	}
	return res;
}

polynom polynom::operator*(const polynom& pol) const {

	polynom res;
	double l1cf;
	int l1abc;
	list<monom> list1 = plist, list2 = pol.plist;
	list1.Reset();
	list2.Reset();
	while (!(list1.IsEnded()))
	{
		l1cf = list1.GetCurr()->data.cf;
		l1abc = list1.GetCurr()->data.abc;
		polynom temp(pol);
		temp.plist.Reset();
		while (!(temp.plist.IsEnded()))
		{
			int tabc = temp.plist.GetCurr()->data.abc;
			if ((tabc % 10 + l1abc % 10) < 10 && (tabc / 100 + l1abc / 100) < 10 && (tabc / 10 % 10 + l1abc / 10 % 10) < 10)
			{
				temp.plist.GetCurr()->data.abc += l1abc;
				temp.plist.GetCurr()->data.cf *= l1cf;
			}
			else 
				throw "Too much degree";
			temp.plist.GetNext();
		}
		res = res + temp;
		list1.GetNext();
	}
	return res;
}

ostream& operator<<(ostream& os, const polynom& pol)
{
	int k[3] = { 100,10,1 };
	polynom p = pol;
	node<monom> temp;	
	p.plist.Reset();
	node<monom>*start = p.plist.GetCurr();
	while (!(p.plist.IsEnded()))
	{
		temp = p.plist.GetCurr()->data;
		if (temp.data.cf > 0 && p.plist.GetCurr()!=start)
			os << '+';
		if (temp.data.cf != 1 && temp.data.cf != -1)
			os << temp.data.cf;
		else 
			if (temp.data.cf == -1)
				os << '-';
		for (int i = 0; i < 3; i++)
		{
			if (temp.data.abc / k[i] % 10 != 0)
			{
				os << xyz[i];
				if (temp.data.abc / k[i] % 10 != 1)
					os << '^' << temp.data.abc / k[i] % 10;
			}
		}		
		p.plist.GetNext();
	}
	return os;
}