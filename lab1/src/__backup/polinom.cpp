#include "Polinoms.h"

TPolinom::TPolinom(const string& s)
{
	string str = s;
	if (str[0] != '\0')
	{
		while (str.length() > 0)
		{
			string monom = "";
			Tmonom temp;
			string coeff = "";
			double number = 0;
			int i = 0, j = 1;
			j = 1;
			while (j < str.length() && str[j] != '+' && str[j] != '-')
				j++;
			monom = str.substr(0, j);
			str.erase(0, j);
			j = 0;
			while (j < monom.length() && !isalpha(monom[j]))
				j++;
			coeff = monom.substr(0, j);
			if (coeff == "" || coeff == "+")
				temp.cf = 1;
			else if (coeff == "-")
				temp.cf = -1;
			else temp.cf = atof(coeff.c_str());
			monom.erase(0, j);
			j = 0;
			while (j < monom.length()) // формирование степени
			{
				if (isalpha(monom[j]) && monom[j + 1] == '\0') // последняя буква в строке
				{
					switch (monom[j])
					{
					case 'x':
						temp.abc += 1 * 100;
						break;
					case 'y':

						temp.abc += 1 * 10;
						break;
					case 'z':
						temp.abc += 1;
						break;
					default:
						throw "Input error:end of string";
						break;
					}
					j++;
				}
				else if (isalpha(monom[j]) && isalpha(monom[j + 1])) // 2 буквы подряд
				{
					switch (monom[j])
					{
					case 'x':
						temp.abc += 1 * 100;
						break;
					case 'y':

						temp.abc += 1 * 10;
						break;
					case 'z':
						temp.abc += 1;
						break;
					default:
						throw "Input error:end of string";
						break;
					}
					j++;
				}
				else if (isalpha(monom[j]) && monom[j + 1] == '^' && monom[j + 2] != '\0' && isdigit(monom[j + 2]))
				{
					switch (monom[j])
					{
					case 'x':
						temp.abc += atoi(&monom[j + 2]) * 100;
						j += 3;
						break;
					case 'y':
						temp.abc += atoi(&monom[j + 2]) * 10;
						j += 3;
						break;
					case 'z':
						temp.abc += atoi(&monom[j + 2]) * 1;
						j += 3;
						break;
					}
				}
			}
			if (temp.abc != 0) {
				TLink<Tmonom>* link = monoms.Search(temp);
				if (link != NULL)
				{
					link->data.cf += temp.cf;
				}
				else
					monoms.Insert(temp);
			}
			else
			{
				monoms.InsertInEnd(temp);
			}
		}
	}
}

TPolinom::TPolinom(const TPolinom & _polinom)
{
	monoms = _polinom.monoms;
}

TPolinom::~TPolinom()
{
}

TPolinom TPolinom::operator+ (const TPolinom & _polinom)
{
	(*this).monoms.Reset();
	TPolinom copy_of_polinom(_polinom);
	copy_of_polinom.monoms.Reset();
	TPolinom res;
	res.monoms.Reset();
	while (!copy_of_polinom.monoms.IsEnded() && !(*this).monoms.IsEnded())
	{
		if (copy_of_polinom.monoms.current->data < (*this).monoms.current->data)
		{
			res.monoms.InsertInEnd((*this).monoms.current->data);
			(*this).monoms.GetNext();
		}
		else if ((copy_of_polinom.monoms.current->data == (*this).monoms.current->data)
			&& ((*this).monoms.current->data.cf + copy_of_polinom.monoms.current->data.cf != 0.0))
		{
			res.monoms.InsertInEnd((*this).monoms.current->data + copy_of_polinom.monoms.current->data);
			(*this).monoms.GetNext();
			copy_of_polinom.monoms.GetNext();
		}
		else
		{
			res.monoms.InsertInEnd(copy_of_polinom.monoms.current->data);
			copy_of_polinom.monoms.GetNext();
		}
	}
	while (!copy_of_polinom.monoms.IsEnded())
	{
		res.monoms.InsertInEnd(copy_of_polinom.monoms.current->data);
		copy_of_polinom.monoms.GetNext();
	}
	while (!(*this).monoms.IsEnded())
	{
		res.monoms.InsertInEnd((*this).monoms.current->data);
		(*this).monoms.GetNext();
	}
	return res;
}

TPolinom & TPolinom::operator+=(const TPolinom & _polinom)
{
	TPolinom copy_of_polinom(_polinom);
	copy_of_polinom.monoms.Reset();
	for (copy_of_polinom.monoms.current; !copy_of_polinom.monoms.IsEnded(); copy_of_polinom.monoms.GetNext())
	{
		TLink<Tmonom>* tmp2 = (*this).monoms.Search(copy_of_polinom.monoms.current->data);
		if (tmp2 != NULL)
			tmp2->data.cf += copy_of_polinom.monoms.current->data.cf;
		else
			(*this).monoms.Insert(copy_of_polinom.monoms.current->data);
	}
	return *this;
}

TPolinom TPolinom::operator* (const TPolinom & _polinom)
{
	(*this).monoms.Reset();
	TPolinom copy_of_polinom(_polinom);
	copy_of_polinom.monoms.Reset();
	TPolinom res;
	res.monoms.Reset();
	for ((*this).monoms.current; !(*this).monoms.IsEnded(); (*this).monoms.GetNext())
	{
		for (copy_of_polinom.monoms.current; !copy_of_polinom.monoms.IsEnded(); copy_of_polinom.monoms.GetNext())
		{
			if (((*this).monoms.current->data.abc + copy_of_polinom.monoms.current->data.abc < 1000) &&
				(((*this).monoms.current->data.abc / 10 % 10 + copy_of_polinom.monoms.current->data.abc / 10 % 10) < 10) &&
				(((*this).monoms.current->data.abc % 10 + copy_of_polinom.monoms.current->data.abc % 10) < 10))
			{
				unsigned int tmpabc = (*this).monoms.current->data.abc + copy_of_polinom.monoms.current->data.abc;
				Tmonom tmp((*this).monoms.current->data.cf * copy_of_polinom.monoms.current->data.cf, tmpabc);
				TLink<Tmonom>* tmp2 = res.monoms.Search(tmp);
				if (tmp2 != NULL)
					tmp2->data.cf = (*this).monoms.current->data.cf * copy_of_polinom.monoms.current->data.cf;
				else
					res.monoms.Insert(tmp);
			}
			else throw "Power is more then expected";
		}
		copy_of_polinom.monoms.Reset();
	}
	return res;
}

//const TPolinom TPolinom::operator- (const TPolinom & _polinom)
//{
//	TPolinom res, operand2;
//	operand2 = _polinom * (-1);
//	res = *this + operand2;
//	return res;
//}

TPolinom TPolinom::operator* (double d)
{
	TPolinom res = (*this);
	res.monoms.Reset();
	if (d == 0)
		res.monoms.Clean();
	else {
		while (!res.monoms.IsEnded())
		{
			res.monoms.current->data.cf *= d;
			res.monoms.GetNext();
		}
	}
	return res;
}

TPolinom& TPolinom::operator =(const TPolinom& _polinom)
{
	monoms = _polinom.monoms;
	return *this;
}
