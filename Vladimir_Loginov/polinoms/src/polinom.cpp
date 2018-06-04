#include "Polinoms.h"

TPolinom::TPolinom(const std::string& s)
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
			if (temp.abc != 0 && temp.cf != 0) {
				TLink<Tmonom>* link = monoms.Search(temp);
				if (link != NULL)
				{	
					if (link->data.cf + temp.cf != 0)
					{
						link->data.cf += temp.cf;
					}
					else monoms.Delete(link->data);
				}
				else 
					monoms.Insert(temp);
			}
			else if (temp.abc == 0 && temp.cf != 0)
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
		if (copy_of_polinom.monoms.GetCurrent()->data < (*this).monoms.GetCurrent()->data)
		{
			res.monoms.InsertInEnd((*this).monoms.GetCurrent()->data);
			(*this).monoms.GetNext();
		}
		else if (copy_of_polinom.monoms.GetCurrent()->data == (*this).monoms.GetCurrent()->data)
		{
			if ((*this).monoms.GetCurrent()->data.cf + copy_of_polinom.monoms.GetCurrent()->data.cf != 0.0)
			{
				res.monoms.InsertInEnd((*this).monoms.GetCurrent()->data + copy_of_polinom.monoms.GetCurrent()->data);
			}
			(*this).monoms.GetNext();
			copy_of_polinom.monoms.GetNext();
		}
		else
		{
			res.monoms.InsertInEnd(copy_of_polinom.monoms.GetCurrent()->data);
			copy_of_polinom.monoms.GetNext();
		}
	}
	while (!copy_of_polinom.monoms.IsEnded())
	{
		res.monoms.InsertInEnd(copy_of_polinom.monoms.GetCurrent()->data);
		copy_of_polinom.monoms.GetNext();
	}
	while (!(*this).monoms.IsEnded())
	{
		res.monoms.InsertInEnd((*this).monoms.GetCurrent()->data);
		(*this).monoms.GetNext();
	}
	return res;
}

TPolinom & TPolinom::operator+=(const TPolinom & _polinom)
{
	TPolinom copy_of_polinom(_polinom);
	copy_of_polinom.monoms.Reset();
	for (copy_of_polinom.monoms.GetCurrent(); !copy_of_polinom.monoms.IsEnded(); copy_of_polinom.monoms.GetNext())
	{
		TLink<Tmonom>* tmp2 = (*this).monoms.Search(copy_of_polinom.monoms.GetCurrent()->data);
		if (tmp2 != NULL)
		{
			if (tmp2->data.cf + copy_of_polinom.monoms.GetCurrent()->data.cf != 0)
			{
				tmp2->data.cf += copy_of_polinom.monoms.GetCurrent()->data.cf;
			}
			else
				(*this).monoms.Delete(tmp2->data);
		}
		else
			(*this).monoms.Insert(copy_of_polinom.monoms.GetCurrent()->data);
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
	for ((*this).monoms.GetCurrent(); !(*this).monoms.IsEnded(); (*this).monoms.GetNext())
	{
		for (copy_of_polinom.monoms.GetCurrent(); !copy_of_polinom.monoms.IsEnded(); copy_of_polinom.monoms.GetNext())
		{
			if (((*this).monoms.GetCurrent()->data.abc + copy_of_polinom.monoms.GetCurrent()->data.abc < 1000) &&
				(((*this).monoms.GetCurrent()->data.abc / 10 % 10 + copy_of_polinom.monoms.GetCurrent()->data.abc / 10 % 10) < 10) &&
				(((*this).monoms.GetCurrent()->data.abc % 10 + copy_of_polinom.monoms.GetCurrent()->data.abc % 10) < 10))
			{
				unsigned int tmpabc = (*this).monoms.GetCurrent()->data.abc + copy_of_polinom.monoms.GetCurrent()->data.abc;
				Tmonom tmp((*this).monoms.GetCurrent()->data.cf * copy_of_polinom.monoms.GetCurrent()->data.cf, tmpabc);
				TLink<Tmonom>* tmp2 = res.monoms.Search(tmp);
				if (tmp2 != NULL)
					if ((tmp2->data.cf += (*this).monoms.GetCurrent()->data.cf * copy_of_polinom.monoms.GetCurrent()->data.cf) == 0)
					{
						res.monoms.Delete(tmp2->data);
					}
					else tmp2->data.cf += (*this).monoms.GetCurrent()->data.cf * copy_of_polinom.monoms.GetCurrent()->data.cf;
				else
					res.monoms.Insert(tmp);
			}
			else throw "Power is more then expected";
		}
		copy_of_polinom.monoms.Reset();
	}
	return res;
}

TPolinom TPolinom::operator* (double d)
{
	TPolinom res = (*this);
	res.monoms.Reset();
	if (d == 0)
		res.monoms.Clean();
	else {
		while (!res.monoms.IsEnded())
		{
			res.monoms.GetCurrent()->data.cf *= d;
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
