#pragma once

#include "ringlist.h"


class Polinom {
	string s;
	RingList <Monom> monoms;
public:
	Polinom(const string &str) {
		s = str;
		int f = 0;
		int i = 0, j, k, st = 0;
		double x = 1; //коэффициент
		Monom tmp;
		while (i<s.size())
		{
			char a[20], c[10], p[1];
			string as;

			if (s[i] == '-')
			{
				x = -1;
				i++;
			}

			j = 0;
			while ((s[i] != '+') && (s[i] != '-'))
			{
				a[j] = s[i];
				j++;
				i++;
			}
			if (a != NULL)
			{
				i--;
				as = a;
				as.erase(j);
				k = 0;
				while (k < as.length())
				{

					if (isdigit(as[k]) != 0)
					{
						while ((isdigit(as[k]) != 0) && (as[k] == '.') && (k < as.length()))
						{
							if (c[k] == '.')
								f = 1;
							c[k] = as[k];
							k++;
						}
						if (!f)
						{
							c[k] = '.';
						}
						x *= atof(c);
					}

					tmp.SetCoeff(x);

					if (as[k] == 'x')
					{
						if (as[k + 1] == '^')
						{
							p[0] = as[k + 2];
							st += atoi(p) * 100;
							k += 3;
						}
						else
						{
							st += 100;
							k++;
						}
					}

					if (as[k] == 'y')
					{
						if (as[k + 1] == '^')
						{
							p[0] = as[k + 2];
							st += atoi(p) * 10;
							k += 3;
						}
						else
						{
							st += 10;
							k++;
						}
					}

					if (as[k] == 'z')
					{
						if (as[k + 1] == '^')
						{
							p[0] = as[k + 2];
							st += atoi(p);
							k += 3;
						}
						else
						{
							st += 1;
							k++;
						}
					}
				}
				tmp.SetIndex(st);
				monoms.InsertToTail(tmp);
				st = 0;
				x = 1;
			}
			i++; // итерация
		}
	};
	Polinom(const Polinom &p1);
	Polinom operator+(const Polinom &p1);
	Polinom operator*(const Polinom &p1);
	Polinom operator*(const double &d);
	const Polinom& operator=(const Polinom &p1);
};