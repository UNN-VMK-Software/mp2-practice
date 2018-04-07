#include "polinom.h"
using namespace std;


list<monom> polynom::similar_terms(list <monom> sp) 
{
	list<monom> res;
	res.Reset();
	sp.Reset();
	unit<monom> mon(sp.GetAct()->data.coeff);
	while (sp.IsNotOver())
	{
		mon.data.abc = sp.GetAct()->data.abc;
		if (sp.GetAct()->data.abc == sp.GetAct()->next->data.abc && (sp.GetAct()->next->data.coeff || sp.GetAct()->next->data.abc))
			mon.data.coeff += sp.GetAct()->next->data.coeff;
		else
		{
			if (mon.data.coeff)
			{
				res.InsertToTail(mon.data);
				res.Step();
			}
			mon.data.coeff = sp.GetAct()->next->data.coeff;
		}
		sp.Step();
	} 	
	return res;
}

//Разбор строки
polynom::polynom(string pol)
{
	list<monom> res;
	while (pol.length())
	{
		string part;
		monom temp;
		int pos = 1; 
		while (pos < pol.length() && pol[pos] != '+' && pol[pos] != '-')
			pos++;
		part = pol.substr(0, pos);              // substr возвращает строку, являющуюся подстрокой исходной строки (начиная с какого, сколько)
		pol.erase(0, pos);                      // erase удаляет из строки последовательность символ заданной длины, начиная с указанной позиции (начиная с какого, сколько)
		pos = 0;
		while (part[pos] != 'x' && part[pos] != 'y' && part[pos] != 'z' && pos < part.length())
			pos++;

		string c = part.substr(0,pos);            // с - коэф  part
		if (c == "+" || c.length() == 0)
			temp.coeff = 1;
		else 
			if (c == "-")
				temp.coeff = -1;
		else
			temp.coeff = stod(c);                // stod извлекает число с плавающей точкой из строки 
	
		part.erase(0, pos);                       // удаляем коэф
		part += ' ';
		int a[3] = { 100,10,1 };
		for (int i = 0; i < 3; i++)
		{
			pos = part.find((char)(120 + i));     // 120 - код символа x, 121 - y, 122 - z
			if (pos > -1)
			{
				if (part[pos + 1] != '^')
					part.insert(pos + 1, "^1");
				temp.abc += a[i] * stoi(part.substr(pos + 2, 1));          // stoi преобразует последовательность символов в целое число.
				part.erase(pos, 3);
			}
		}
		list_pol.Insert(temp);

	}
		list_pol = similar_terms(list_pol);
}	


 //Конструктор копирования
polynom:: polynom (const polynom& pol)
{
	list_pol = pol.list_pol;
}								    
 
//Присваивание
polynom& polynom:: operator=(const polynom &pol)
{
	list_pol = pol.list_pol;
	return *this;
}	     


//Сложение полиномов
polynom polynom::operator+(const polynom& pol) const
{
	polynom res;
	polynom pthis = *this;
	polynom p = pol;

	pthis.list_pol.Reset();
	p.list_pol.Reset();
	res.list_pol.Reset();

	while (pthis.list_pol.IsNotOver() && p.list_pol.IsNotOver())
	{
		if (pthis.list_pol.GetAct()->data > p.list_pol.GetAct()->data)
		{
			res.list_pol.InsertToTail(p.list_pol.GetAct()->data);            
			p.list_pol.Step();
			res.list_pol.Step();
		}
		else 
			if (pthis.list_pol.GetAct()->data < p.list_pol.GetAct()->data)
			{
				res.list_pol.InsertToTail(pthis.list_pol.GetAct()->data);
				pthis.list_pol.Step();
				res.list_pol.Step();
			}
			else
			{
				double new_coeff = pthis.list_pol.GetAct()->data.coeff + p.list_pol.GetAct()->data.coeff;
				if (new_coeff)
				{
					monom temp(new_coeff, pthis.list_pol.GetAct()->data.abc);
					res.list_pol.InsertToTail(temp);
					res.list_pol.Step();
				}
				pthis.list_pol.Step();
				p.list_pol.Step();
			}
	}
	while (pthis.list_pol.IsNotOver())
	{
		res.list_pol.InsertToTail(pthis.list_pol.GetAct()->data);
		pthis.list_pol.Step();
		res.list_pol.Step();
	}
	while (p.list_pol.IsNotOver())
	{
		res.list_pol.InsertToTail(p.list_pol.GetAct()->data);
		p.list_pol.Step();
		res.list_pol.Step();
	}
	return res;
}


//Умножение на константу слева
polynom polynom::operator*(const double a) const
{
	polynom res;
	if (a)
	{
		res = *this;
		res.list_pol.Reset();
		while (res.list_pol.IsNotOver())
		{
			res.list_pol.GetAct()->data.coeff *= a;
			res.list_pol.Step();
		}
	}
	return res;
}


//Умножение полиномов
polynom polynom::operator*(const polynom& pol) const
{
	polynom res;
	polynom pthis = *this;
	polynom p = pol;

	pthis.list_pol.Reset();
	p.list_pol.Reset();

	while (pthis.list_pol.IsNotOver())
	{
		double pthis_coeff = pthis.list_pol.GetAct()->data.coeff;
		int pthis_abc = pthis.list_pol.GetAct()->data.abc;
		polynom temp(pol); 
		temp.list_pol.Reset();
		while (temp.list_pol.IsNotOver())
		{
			int temp_abc = temp.list_pol.GetAct()->data.abc;
			if ((temp_abc % 10 + pthis_abc % 10) < 10     &&    (temp_abc/10 % 10 + pthis_abc/10 % 10) < 10     &&    (temp_abc/100 + pthis_abc/100) < 10)
			{
				temp.list_pol.GetAct()->data.abc += pthis_abc;
				temp.list_pol.GetAct()->data.coeff *= pthis_coeff;
			}
			else 
				throw "large index";
			temp.list_pol.Step();
		}
		res = res + temp;
		pthis.list_pol.Step();
	}
	return res;
}



//Оператор вывода
ostream& operator<<(ostream &ostr,const polynom& pol)
{
	polynom p = pol;
	p.list_pol.Reset();

	while (p.list_pol.IsNotOver())
	{
		monom temp = p.list_pol.GetAct()->data;

		if (temp.coeff > 0)
		{
			ostr << "+";
			if (temp.coeff == 1 && temp.abc ==0)
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
			ostr<< "z^" << a;
		else
			if (a == 1) 
				ostr << "z";
		p.list_pol.Step();  
	}
	return ostr;
}