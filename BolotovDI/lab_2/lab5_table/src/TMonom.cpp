#include "TMonom.h"

TMonom::TMonom()
{
	cf = NULL;
	abc = NULL;
}

TMonom::TMonom(const string s)
{
	int a = 0;
	int b = 0;
	int c = 0;
	cf = 1;
	abc = 0;
	int k = s.length();

	for (int i = 0; i < k; i++)
	{
		if (isdigit(s[i]))
		{
			this->cf = atof(&s[i]);
			int j = 0;
			while ((s[i + 1 + j] != '\0') && (isdigit(s[i + 1 + j])))
			{
				j++;
			}
			i = i + j;
		}

		if (s[i] == '-')
		{
			if (isalpha(s[i + 1]))
			{
				this->cf = -1;
			}

			if (isdigit(s[i + 1]))
			{
				cf = atof(&s[i]);
				this->cf = cf;
			}

			int j = 0;
			while ((s[i + 1 + j] != '\0') && (isdigit(s[i + 1 + j])))
			{
				j++;
			}
			i = i + j;
		}

		if (s[i] == 'x')
		{
			if (s[i + 1] == '^')
			{
				a = atof(&s[i + 2]);
				int j = 0;
				while ((s[i + 2 + j] != '*') && (s[i + 2 + j] != '\0') && (s[i + 2 + j] == '+') && (s[i + 2 + j] == '-'))
				{
					j++;
				}
				i = i + j + 2;
			}
			else
			{
				a = 1;
			}
		}

		if (s[i] == 'y')
		{
			if (s[i + 1] == '^')
			{
				b = atof(&s[i + 2]);
				int j = 0;
				while ((s[i + 2 + j] != '*') && (s[i + 2 + j] != '\0') && (s[i + 2 + j] == '+') && (s[i + 2 + j] == '-'))
				{
					j++;
				}
				i = i + j + 2;
			}
			else
			{
				b = 1;
			}
		}

		if (s[i] == 'z')
		{
			if (s[i + 1] == '^')
			{
				c = atof(&s[i + 2]);
				int j = 0;
				while ((s[i + 2 + j] != '*') && (s[i + 2 + j] != '\0') && (s[i + 2 + j] == '+') && (s[i + 2 + j] == '-'))
				{
					j++;
				}
				i = i + j + 2;
			}
			else
			{
				c = 1;
			}
		}
	}

	this->abc = a * 100 + b * 10 + c;
}

TMonom::TMonom(double num, unsigned int num2)
{
	cf = num;
	abc = num2;
}

TMonom TMonom::operator + (const TMonom& monom)
{
	cf = cf + monom.cf;
	return *this;
}

TMonom TMonom::operator - (const TMonom& monom)
{
	cf = cf - monom.cf;
	return *this;
}

TMonom TMonom::operator = (const TMonom& monom)
{
	cf = monom.cf;
	abc = monom.abc;
	return *this;
}

bool TMonom::operator == (const TMonom& monom) const
{
	int k = 0;

	if (abc != monom.abc)
		k++;

	if (k == 0)
		return true;
	else
		return false;
}

bool TMonom::operator != (const TMonom& monom) const
{
	int k = 0;

	if (abc == monom.abc)
		k++;

	if (k == 0)
		return true;
	else
		return false;
}

bool TMonom::operator > (const TMonom& monom) const
{
	int k = 0;

	if (abc > monom.abc)
		k++;

	if (k != 0)
		return true;
	else
		return false;
}

bool TMonom::operator < (const TMonom& monom) const
{
	int k = 0;

	if (abc < monom.abc)
		k++;

	if (k != 0)
		return true;
	else
		return false;
}