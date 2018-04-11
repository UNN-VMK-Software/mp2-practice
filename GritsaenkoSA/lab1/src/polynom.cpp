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

		if (abs(temp.cf) > EPS)
		{
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

		
	}

	listmonom = unic(listmonom);
}

//объединение
list<monom> polynom::unic(list <monom> sp) 
{
	list<monom> res;//результат
	res.Reset();
	sp.Reset();
	node<monom> mon(sp.GetCurr()->data.cf);
	while (sp.IsNotOver())
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
polynom polynom::operator+(const polynom& pmr) const
{
	polynom res;
	node<monom>* leftpol = listmonom.GetHead();
	node<monom>* righpol = pmr.listmonom.GetHead();
	node<monom>* resh = res.listmonom.GetHead();
	node<monom>* cl = leftpol->next;
	node<monom>* cr = righpol->next;
	while (cl != leftpol && cr != righpol)
	{
		if (cl->data < cr->data)//для упорядочивания
		{
			resh->next = new node<monom>(cl->data);
			cl = cl->next;
			resh = resh->next;
		}
		else if (cl->data > cr->data)
		{
			resh->next = new node<monom>(cr->data);
			cr = cr->next;
			resh = resh->next;
		}
		else
		{
			double coef = cl->data.cf + cr->data.cf;//cкладываем коэф
			if (abs(coef) > EPS)
			{
				resh->next = new node<monom>(monom(coef, cl->data.abc));
				resh = resh->next;
			}
			cl = cl->next;
			cr = cr->next;
		}
	}
	while (cl != leftpol)
	{
		resh->next = new node<monom>(cl->data);
		cl = cl->next;
		resh = resh->next;
	}
	while (cr != righpol)
	{
		resh->next = new node<monom>(cr->data);
		cr = cr->next;
		resh = resh->next;
	}
	resh->next = res.listmonom.GetHead();
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

	while (pthis.listmonom.IsNotOver())
	{
		double pthis_cf = pthis.listmonom.GetCurr()->data.cf;
		int pthis_abc = pthis.listmonom.GetCurr()->data.abc;
		polynom temp(pol); 
		temp.listmonom.Reset();
		while (temp.listmonom.IsNotOver())
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
		while (res.listmonom.IsNotOver())
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
	node<monom>* curr = pm.listmonom.GetHead();
	node<monom>* head = curr;
	while (curr->next != head)
	{
		curr = curr->next;
		monom temp = curr->data;

		if (abs(temp.cf - 1) > EPS && abs(temp.cf + 1) > EPS || temp.abc == 0)
			ostr << temp.cf;
		else if (abs(temp.cf + 1) < EPS && abs(temp.cf - 1) > EPS)
			ostr << '-';
		int p = temp.abc / 100;
		if(p>1)
			ostr << "x^" << p;
		else if (p == 1) ostr << "x";
		p = temp.abc / 10 % 10;
		if(p>1)
			ostr << "y^" << p;
		else if (p == 1) ostr << "y";
		p = temp.abc % 10;
		if(p>1)
			ostr<< "z^" << p;
		else if (p == 1) ostr << "z";
		if(curr->next != head && curr->next->data.cf>0)
			ostr << "+";
	}
	return ostr;
}

