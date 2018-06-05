#include "Pol.h"
//isalpha() - возвращает ненулевое значение, если ее аргумент ch является буквой
//substr -возвращает часть строки
//atoi - из строки в инт

TPolinom::TPolinom(const std::string& s)
{
	string str = s;
	if (str[0] != '\0')
	{
		while (str.length() > 0)
		{
			string monom = "";
			Monom temp;
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
			while (j < monom.length()) 
			{

				if (isalpha(monom[j]) && monom[j + 1] == '\0') 
				{
					switch (monom[j])
					{
					case 'x':
						temp.stmonom += 1 * 100;
						break;
					case 'y':

						temp.stmonom += 1 * 10;
						break;
					case 'z':
						temp.stmonom += 1;
						break;
					default:
						throw "Input error:end of string";
						break;
					}
					j++;
				}
				else if (isalpha(monom[j]) && isalpha(monom[j + 1])) 
				{
					switch (monom[j])
					{
					case 'x':
						temp.stmonom += 1 * 100;
						break;
					case 'y':

						temp.stmonom += 1 * 10;
						break;
					case 'z':
						temp.stmonom += 1;
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
						temp.stmonom += atoi(&monom[j + 2]) * 100;
						j += 3;
						break;
					case 'y':
						temp.stmonom += atoi(&monom[j + 2]) * 10;
						j += 3;
						break;
					case 'z':
						temp.stmonom += atoi(&monom[j + 2]) * 1;
						j += 3;
						break;
					}
				}
			}
			if ((temp.stmonom != 0 || temp.stmonom == 0) && temp.cf != 0) {
				TLink<Monom>* link = curmon.Search(temp);
				if (link != NULL)
				{
					if (link->data.cf + temp.cf != 0)
					{
						link->data.cf += temp.cf;
					}
					else curmon.Delete(link->data);
				}
				else
					curmon.Insert(temp);
			}
			/*else if (temp.stmonom == 0 && temp.cf != 0)
			{
				curmon.InsertInEnd(temp);
			}*/
			//curmon = similar_terms(curmon);
		}
	}
}

TPolinom::TPolinom(const TPolinom & _polinom)
{
	curmon = _polinom.curmon;
}

TPolinom::~TPolinom()
{
}

TPolinom TPolinom::operator+ (const TPolinom & _polinom)
{
	(*this).curmon.Reset();
	TPolinom copy_of_polinom(_polinom);
	copy_of_polinom.curmon.Reset();
	TPolinom res;
	res.curmon.Reset();
	while (!copy_of_polinom.curmon.IsEnded() && !(*this).curmon.IsEnded())
	{
		if (copy_of_polinom.curmon.GetCurrent()->data < (*this).curmon.GetCurrent()->data)
		{
			res.curmon.InsertInEnd((*this).curmon.GetCurrent()->data);
			(*this).curmon.GetNext();
		}
		else if (copy_of_polinom.curmon.GetCurrent()->data == (*this).curmon.GetCurrent()->data)
		{
			if ((*this).curmon.GetCurrent()->data.cf + copy_of_polinom.curmon.GetCurrent()->data.cf != 0.0)
			{
				res.curmon.InsertInEnd((*this).curmon.GetCurrent()->data + copy_of_polinom.curmon.GetCurrent()->data);
			}
			(*this).curmon.GetNext();
			copy_of_polinom.curmon.GetNext();
		}
		else
		{
			res.curmon.InsertInEnd(copy_of_polinom.curmon.GetCurrent()->data);
			copy_of_polinom.curmon.GetNext();
		}
	}
	while (!copy_of_polinom.curmon.IsEnded())
	{
		res.curmon.InsertInEnd(copy_of_polinom.curmon.GetCurrent()->data);
		copy_of_polinom.curmon.GetNext();
	}
	while (!(*this).curmon.IsEnded())
	{
		res.curmon.InsertInEnd((*this).curmon.GetCurrent()->data);
		(*this).curmon.GetNext();
	}
	return res;
}

TPolinom & TPolinom::operator+=(const TPolinom & _polinom)
{
	TPolinom copy_of_polinom(_polinom);
	copy_of_polinom.curmon.Reset();
	for (copy_of_polinom.curmon.GetCurrent(); !copy_of_polinom.curmon.IsEnded(); copy_of_polinom.curmon.GetNext())
	{
		TLink<Monom>* tmp2 = (*this).curmon.Search(copy_of_polinom.curmon.GetCurrent()->data);
		if (tmp2 != NULL)
		{
			if (tmp2->data.cf + copy_of_polinom.curmon.GetCurrent()->data.cf != 0)
			{
				tmp2->data.cf += copy_of_polinom.curmon.GetCurrent()->data.cf;
			}
			else
				(*this).curmon.Delete(tmp2->data);
		}
		else
			(*this).curmon.Insert(copy_of_polinom.curmon.GetCurrent()->data);
	}
	return *this;
}

TPolinom TPolinom::operator* (const TPolinom & _polinom)
{
	(*this).curmon.Reset();
	TPolinom copy_of_polinom(_polinom);
	copy_of_polinom.curmon.Reset();
	TPolinom res;
	res.curmon.Reset();
	for ((*this).curmon.GetCurrent(); !(*this).curmon.IsEnded(); (*this).curmon.GetNext())
	{
		for (copy_of_polinom.curmon.GetCurrent(); !copy_of_polinom.curmon.IsEnded(); copy_of_polinom.curmon.GetNext())
		{
			if (((*this).curmon.GetCurrent()->data.stmonom + copy_of_polinom.curmon.GetCurrent()->data.stmonom < 1000) &&
				(((*this).curmon.GetCurrent()->data.stmonom / 10 % 10 + copy_of_polinom.curmon.GetCurrent()->data.stmonom / 10 % 10) < 10) &&
				(((*this).curmon.GetCurrent()->data.stmonom % 10 + copy_of_polinom.curmon.GetCurrent()->data.stmonom % 10) < 10))
			{
				unsigned int tmpabc = (*this).curmon.GetCurrent()->data.stmonom + copy_of_polinom.curmon.GetCurrent()->data.stmonom;
				Monom tmp((*this).curmon.GetCurrent()->data.cf * copy_of_polinom.curmon.GetCurrent()->data.cf, tmpabc);
				TLink<Monom>* tmp2 = res.curmon.Search(tmp);
				if (tmp2 != NULL)
					if ((tmp2->data.cf += (*this).curmon.GetCurrent()->data.cf * copy_of_polinom.curmon.GetCurrent()->data.cf) == 0)
					{
						res.curmon.Delete(tmp2->data);
					}
					else tmp2->data.cf += (*this).curmon.GetCurrent()->data.cf * copy_of_polinom.curmon.GetCurrent()->data.cf;
				else
					res.curmon.Insert(tmp);
			}
			else throw "Power is more then expected";
		}
		copy_of_polinom.curmon.Reset();

	}
	return res;
}

TPolinom TPolinom::operator* (double d)
{
	TPolinom res = (*this);
	res.curmon.Reset();
	if (d == 0)
		res.curmon.Clean();
	else {
		while (!res.curmon.IsEnded())
		{
			res.curmon.GetCurrent()->data.cf *= d;
			res.curmon.GetNext();
		}
	}
	return res;
}

TPolinom& TPolinom::operator =(const TPolinom& _polinom)
{
	curmon = _polinom.curmon;
	return *this;
}
/*TRingList <Monom> TPolinom ::similar_terms(TRingList <Monom> sp)
{
	TRingList<Monom> res;
	res.Reset();
	sp.Reset();
	TLink <Monom> mon(sp.GetCurrent()->data.cf);
	while (sp.IsEnded())
	{
		mon.data.stmonom = sp.GetCurrent()->data.stmonom;
		if (sp.GetCurrent()->data.stmonom == sp.GetCurrent()->pNext->data.stmonom && (sp.GetCurrent()->pNext->data.cf || sp.GetCurrent()->pNext->data.stmonom))
			mon.data.cf += sp.GetCurrent()->pNext->data.cf;
		else
		{
			if (mon.data.cf)
			{
				res.InsertInEnd(mon.data);
				res.GetNext();
			}
			mon.data.cf = sp.GetCurrent()->pNext->data.cf;
		}
		sp.GetNext();
	}
	return res;
}*/