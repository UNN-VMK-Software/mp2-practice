#include "polinom.h"
using namespace std;



//Разбор строки
polynom::polynom(string pol)
{
	int a[3] = { 100,10,1 };
	while (pol.length())
	{
		string part;
		monom temp;
		int pos = 1; 
		while (pos < pol.length() && pol[pos] != '+' && pol[pos] != '-')
			pos++;
		part = pol.substr(0, pos);          // substr возвращает строку, являющуюся подстрокой исходной строки (начиная с какого, сколько)
		pol.erase(0, pos);                  // erase удаляет из строки последовательность символ заданной длины, начиная с указанной позиции (начиная с какого, сколько)
		pos = 0;
		while (part[pos] != 'x' && part[pos] != 'y' && part[pos] != 'z' && pos < part.length())
			pos++;

		string c = part.substr(0,pos);    // с - коэф  part
		if (c == "+" || c.length() == 0)
			temp.coeff = 1;
		else if (c == "-")
			temp.coeff = -1;
		else temp.coeff = stod(c);  // stod извлекает число с плавающей точкой из строки 
	
		part.erase(0, pos);       // удаляем коэф
		part += ' ';
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
	unit<monom>* r = res.list_pol.GetHead();
	unit<monom>* a = list_pol.GetHead();
	unit<monom>* b = pol.list_pol.GetHead();
	unit<monom>* A = a->next;
	unit<monom>* B = b->next;

	while (A != a && B != b)
	{
		if (A->data < B->data)
		{
			r->next = new unit<monom>(A->data);
			A = A->next;
			r = r->next;
		}
		else 
			if (A->data > B->data)
			{
				r->next = new unit<monom>(B->data);
			    B = B->next;
			    r = r->next;
			}
			else
			{
				if (abs(A->data.coeff + B->data.coeff) != 0)                                              //!!!!!!!!!!
				{
					r->next = new unit<monom>(monom(A->data.coeff + B->data.coeff, A->data.abc));
					r = r->next;
				}		
				A = A->next;
			    B = B->next;
			}
	}
	while (A != a)
	{
		r->next = new unit<monom>(A->data);
		A = A->next;
		r = r->next;
	}
	while (B != b)
	{
		r->next = new unit<monom>(B->data);
		B = B->next;
		r = r->next;
	}
	r->next = res.list_pol.GetHead();
	return res;
}


//Умножение на константу слева
polynom polynom::operator*(const double a) const
{
	unit<monom>* actual = (*this).list_pol.GetHead()->next;
	if (a != 0)
	{
		while (actual != (*this).list_pol.GetHead())
		{ 
			actual->data.coeff *= a;
			actual = actual->next;
		}
	}
	else 
	{
		actual->data.coeff = 0;
		actual->data.abc = 0;
	}
	return *this;
}


//Умножение полиномов
polynom polynom::operator*(const polynom& pol) const
{
	polynom res;
	unit<monom>* actual = pol.list_pol.GetHead()->next;
	while (actual != pol.list_pol.GetHead())
	{
		polynom new_this(*this);
		unit<monom>* pos = new_this.list_pol.GetHead()->next;
		while (pos != new_this.list_pol.GetHead())
		{
			pos->data.coeff *= actual->data.coeff;
			int new_abc = pos->data.abc + actual->data.abc;
			if (new_abc / 100 < 10 && new_abc / 10 % 10 < 10 && new_abc % 10 < 10)                    
				pos->data.abc = new_abc;
			else
				throw "large index";
			pos = pos->next;
		}
		res = res + new_this;
		actual = actual->next;
	}
	return res;
}


//Оператор вставки в поток???????
ostream& operator<<(ostream &ostr,const polynom& pol)
{
	unit<monom>* actual = pol.list_pol.GetHead();
	unit<monom>* h = actual;
	while (actual->next != h )
	{
		actual = actual->next;
		monom temp = actual->data;

		if (temp.coeff>0)
		{
			ostr << "+";
			if (temp.coeff != 1)
				ostr << temp.coeff;
		}
		else ostr << temp.coeff;
		

		int a = temp.abc / 100;
		if(a>1)
			ostr << "x^" << a;
		else if (a == 1) ostr << "x";
		a = temp.abc / 10 % 10;
		if(a>1)
			ostr << "y^" << a;
		else if (a == 1) ostr << "y";
		a = temp.abc % 10;
		if(a>1)
			ostr<< "z^" << a;
		else if (a == 1) ostr << "z";
	}
	return ostr;
}
