#include "polinom.h"

Polinom::Polinom(const string Line)
{   
	List<Monom> List;
	string stringMonom, stringPol = Line;
	int k = 1;
	int cof[3] = { 100,10,1 };

	while (stringPol.length() != 0)
	{
		Monom tmp;
		k = 1;
		while (stringPol[k] != '-' && stringPol[k] != '+' && k < stringPol.length()) //выделение монома
		{
			k++;
		}
		stringMonom = stringPol.substr(0, k); // запись монома
		stringPol.erase(0, k); // удалили 
		if (stringMonom[0] == '-')// проверяем знак(- или +)
		{
			tmp.cf = -1;
			stringMonom.erase(0, 1);
		}
		else
		{
			tmp.cf = 1;
			if (stringMonom[0] == '+')
				stringMonom.erase(0, 1);
		}
		if (isdigit(stringMonom[0]))// проверяем коэффициент
		{
			k = 0;
			while (isdigit(stringMonom[k]) || stringMonom[k] == '.')
			{
				k++;
			}
			tmp.cf *= std::stod(stringMonom.substr(0, k));//записали коэффициент
			stringMonom.erase(0, k);
		}
		for (int i = 0; i < 3; i++)//ищем степени
		{
			int pos = stringMonom.find((char)(X + i));
			if (pos != -1)
				if (stringMonom[pos + 1] == '^')
				{
					tmp.abc += cof[i] * std::stoi(stringMonom.substr(pos + 2, 1));
				}
				else
					tmp.abc += cof[i];
		}
		List.InsertOrdered(tmp);
	}
	list_m = List;
}
	
Polinom Polinom::operator+(const Polinom& pol) const
{
	Polinom res;
	List<Monom> p1 = list_m;
	List<Monom>  p2 = pol.list_m;

	p1.Reset();
	p2.Reset();

	res.list_m.Reset();
	while (!p1.IsEnded() && !p2.IsEnded())// складываем мономы 
	{
		if ((p1.GetCurr()->data > p2.GetCurr()->data) && p1.GetCurr()->data.cf) // сравнииваем
		{  
			res.list_m.InsertAfter(res.list_m.GetCurr(), p1.GetCurr()->data);
			p1.GetNext();
			res.list_m.GetNext();
		}
		else
			if ((p1.GetCurr()->data < p2.GetCurr()->data) && p2.GetCurr()->data.cf)
			{
				res.list_m.InsertAfter(res.list_m.GetCurr(), p2.GetCurr()->data);
				p2.GetNext();
				res.list_m.GetNext();
			}
			else // случай равенства степеней мономов
			{
				double cf = p1.GetCurr()->data.cf + p2.GetCurr()->data.cf;
				
				if (cf) // если коэфф не ноль
				{
					Monom temp(cf, p1.GetCurr()->data.abc);
					res.list_m.InsertAfter(res.list_m.GetCurr(), temp);

					res.list_m.GetNext();
				}

				p1.GetNext();
				p2.GetNext();
			}
	}
	while (!p1.IsEnded())//  добавляем оставшиеся
	{	
		if (p1.GetCurr()->data.cf)
		{
			res.list_m.InsertAfter(res.list_m.GetCurr(), p1.GetCurr()->data);
			res.list_m.GetNext();
		}
		p1.GetNext();
	}
	while (!p2.IsEnded())
	{
		if (p2.GetCurr()->data.cf)
		{
			res.list_m.InsertAfter(res.list_m.GetCurr(), p2.GetCurr()->data);
			res.list_m.GetNext();
		}
		p2.GetNext();
	}
	res.list_m.Reset();
	if (res.list_m.GetCurr()->data.abc == 0 && res.list_m.GetCurr()->data.cf == 0)//  если при сложении получился 0
		res.list_m.InsertAfter(res.list_m.GetCurr(), NULL);
	return res;
}

Polinom Polinom::operator*(const double c) const 
{
	Polinom res;
	if (c)
	{
		res = *this;
		res.list_m.Reset();
		while (!(res.list_m.IsEnded()))
		{
			res.list_m.GetCurr()->data.cf *= c;
			res.list_m.GetNext();
		}
	}
	else
	{
		res.list_m.InsertAfter(res.list_m.GetCurr(), NULL);
	}
	return res;
}

Polinom Polinom::operator*(const Polinom& pol) const
{
	Polinom res;
	Polinom p1 = list_m, p2 = pol;
	int abc;
	double cf;

	p1.list_m.Reset();
	p2.list_m.Reset();

	while (!p2.list_m.IsEnded())
	{
		Monom tmp;
		p1.list_m.Reset();
		while (!p1.list_m.IsEnded())
		{   
			abc = p1.list_m.GetCurr()->data.abc;
			cf = p1.list_m.GetCurr()->data.cf;
			tmp = p2.list_m.GetCurr()->data;
			if ( (tmp.abc % 10 + abc % 10) < 10 && (tmp.abc /10 % 10 + abc / 10 % 10) < 10 && (tmp.abc / 100  + abc / 100 ) <10)
			{
				tmp.cf *= cf;
				tmp.abc += abc;
				res = res + tmp;
			}
			else
			{
				throw "Degree>10";
			}
			p1.list_m.GetNext();
		}
		p2.list_m.GetNext();
	}
	return res;
}

ostream& operator<<(ostream& os, const Polinom& pol)
{ 
	Polinom tmpPol = pol;
	tmpPol.list_m.Reset();
	
	Node<Monom>* FirstNode =tmpPol.list_m.GetCurr(); // указатель на первое звено спика
	Node<Monom>  tmpMon;
	while (!(tmpPol.list_m.IsEnded()))
	{
		tmpMon = tmpPol.list_m.GetCurr()->data;
		if (tmpMon.data.cf > 0 && tmpPol.list_m.GetCurr() != FirstNode)
			os << '+';
		if (tmpMon.data.cf != 1 && tmpMon.data.cf != -1 && tmpMon.data.cf !=0)
			os << tmpMon.data.cf;
		else
			if (tmpMon.data.cf == -1 && tmpMon.data.abc != 0)
				os << '-';
			else 
				if  ((tmpMon.data.cf == 1 || tmpMon.data.cf == -1 )&& tmpMon.data.abc == 0)
					os << tmpMon.data.cf;
		int cof[3] = { 100,10,1 };
		for (int i = 0; i < 3; i++)
		{
			if (tmpMon.data.abc / cof[i] % 10 != 0)
			{
				os << (char)(X + i);
				if (tmpMon.data.abc / cof[i] % 10 != 1)
					os << '^' << tmpMon.data.abc / cof[i] % 10;
			}
		}
		tmpPol.list_m.GetNext();
	}
	tmpPol.list_m.Reset();
	
	if (tmpPol.list_m.GetCurr()->data.abc == 0 && tmpPol.list_m.GetCurr()->data.cf == 0 && !(tmpPol.list_m.IsEnded()))
	{
		os << "0";
	}
	return os;
}