#include "polynom.h"

using namespace std;


//Конструктор по строке
polynom::polynom(string ipm)
{
	int d[3] = { 100,10,1 };
	while (ipm.length())
	{
		string part;
		monom temp;
		int pos = 1; 
		while (pos < ipm.length() && ipm[pos] != '+' && ipm[pos] != '-')
			pos++;
		part = ipm.substr(0, pos);//берет с нулевой позиции pos эл-тов
		ipm.erase(0, pos);//Удаляет элементы в диапазоне
		pos = 0;
		while (part[pos] != 'x' && part[pos] != 'y' && part[pos] != 'z' && pos < part.length())
			pos++;

		string coef = part.substr(0,pos);
		if (coef == "+" || coef.length() == 0)
			temp.cf = 1;
		else if (coef == "-")
			temp.cf = -1;
		else temp.cf = stod(coef);//преобразование строки в число

		
			part.erase(0, pos);
			part += ' ';

			for (int i = 0; i < 3; i++)
			{
				pos = part.find((char)(OFFSET + i));
				if (pos > -1)
				{
					if (part[pos + 1] != '^')
						part.insert(pos + 1, "^1");
					temp.abc += d[i] * stoi(part.substr(pos + 2, 1));// преобразует последовательность элементов  в целое число.
					part.erase(pos, 3);
				}
			}

			listmonom.InsertInOrder(temp);
		}

		listmonom = unic(listmonom);
	}

	


//объединение
list<monom> polynom::unic(list <monom> & sp) 
{
	list<monom> res;//результат
	res.Reset();
	sp.Reset();
	node<monom> mon(sp.GetCurr()->data.cf);
	while (!sp.IsOver())
	{
		mon.data.abc = sp.GetCurr()->data.abc;//копируем свернутую степень
		if (sp.GetCurr()->data.abc == sp.GetCurr()->next->data.abc && (sp.GetCurr()->next->data.cf || sp.GetCurr()->next->data.abc))
			mon.data.cf += sp.GetCurr()->next->data.cf;
		else
		{
			if (mon.data.cf)
			{
				res.InsertToTail(mon.data);
				res.gonext();
			}
			mon.data.cf = sp.GetCurr()->next->data.cf;
		}
		sp.gonext();
	} 	
	return res;
}

//Конструктор копирования
polynom:: polynom (const polynom& pol)
{
	listmonom = pol.listmonom;
} 

//Перегрузка оператора присваивания
polynom& polynom:: operator=(const polynom &pol)
{
	listmonom = pol.listmonom;
	return *this;
} 

//Оператор сложения полиномов
polynom polynom::operator+(const polynom& pol) const
{

	polynom res;
	polynom pthis = *this;
	polynom p = pol;

	pthis.listmonom.Reset();
	p.listmonom.Reset();
	res.listmonom.Reset();

	while (!pthis.listmonom.IsOver() && !p.listmonom.IsOver())
	{
		if (pthis.listmonom.GetCurr()->data > p.listmonom.GetCurr()->data)//для упорядочивания
		{
			res.listmonom.InsertToTail(p.listmonom.GetCurr()->data);
			p.listmonom.gonext();
			res.listmonom.gonext();
		}
		else if (pthis.listmonom.GetCurr()->data < p.listmonom.GetCurr()->data)
		{
			res.listmonom.InsertToTail(pthis.listmonom.GetCurr()->data);
			pthis.listmonom.gonext();
			res.listmonom.gonext();
		}
		else
		{
			double new_coeff = pthis.listmonom.GetCurr()->data.cf + p.listmonom.GetCurr()->data.cf;
			if (new_coeff)
			{
				monom temp(new_coeff, pthis.listmonom.GetCurr()->data.abc);
				res.listmonom.InsertToTail(temp);
				res.listmonom.gonext();
			}
			pthis.listmonom.gonext();
			p.listmonom.gonext();
		}
	}
	while (!pthis.listmonom.IsOver())
	{
		res.listmonom.InsertToTail(pthis.listmonom.GetCurr()->data);
		pthis.listmonom.gonext();
		res.listmonom.gonext();
	}
	while (!p.listmonom.IsOver())
	{
		res.listmonom.InsertToTail(p.listmonom.GetCurr()->data);
		p.listmonom.gonext();
		res.listmonom.gonext();
	}

	return res;
}


//Оператор умножения полиномов
polynom polynom::operator*(const polynom& pol) const
{

	polynom res;
	polynom pthis = *this;
	polynom p = pol;

	pthis.listmonom.Reset();
	p.listmonom.Reset();

	while (!pthis.listmonom.IsOver())
	{
		double pthis_cf = pthis.listmonom.GetCurr()->data.cf;
		int pthis_abc = pthis.listmonom.GetCurr()->data.abc;
		polynom temp(pol); 
		temp.listmonom.Reset();
		while (!temp.listmonom.IsOver())
		{
			int temp_abc = temp.listmonom.GetCurr()->data.abc;
			if ((temp_abc % 10 + pthis_abc % 10) < 10     &&    (temp_abc/10 % 10 + pthis_abc/10 % 10) < 10     &&    (temp_abc/100 + pthis_abc/100) < 10)//остаток от деления
			{
				temp.listmonom.GetCurr()->data.abc += pthis_abc;
				temp.listmonom.GetCurr()->data.cf *= pthis_cf;
			}
			else 
				throw "large index";
			temp.listmonom.gonext();
		}
		res = res + temp;
		pthis.listmonom.gonext();
	}
return res;


}


//Умножение на константу
polynom polynom::operator*(const double a) const
{

	polynom res;
	if (a)
	{
		res = *this;
		res.listmonom.Reset();
		while (!res.listmonom.IsOver())
		{
			res.listmonom.GetCurr()->data.cf *= a;
			res.listmonom.gonext();
		}
	}
return res;

}


//Оператор вставки в поток
ostream& operator<<(ostream &ostr,const polynom& pm)
{
	polynom p = pm;
	p.listmonom.Reset();
	
	while (!p.listmonom.IsOver())
	{
	
		monom temp = p.listmonom.GetCurr()->data;

		if (temp.cf > 0)
		{
			ostr << "+";
			if (temp.cf == 1 && temp.abc == 0)
				ostr << "1";
			else
			if (temp.cf != 1)
				ostr << temp.cf;
		}
		else
			ostr << temp.cf;

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
		p.listmonom.gonext();
	}
	return ostr;
}

