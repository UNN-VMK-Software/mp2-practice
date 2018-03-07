#include "polinom.h"
#include <string>

Polinom::Polinom(const string& s)
{
	string temp = s;

	for (int i = 0; i < temp.length(); i++)
		if (temp[i] == ' ')
			temp.erase(i, 1);

	int l = temp.length();
	for (int i = 0; i < l; i++)
	{
		string a;
		string b;
		int j = i;
		while (isdigit(temp[j]))
			j++;
		a = temp.substr(i, j - i);
		i = j - 1;
		for (i; temp[i] != '+'; i++)
			if (isdigit(temp[i]))
				b = b + temp[i];
		Monom c(stod(a), stod(b));

		list->InsertToOrdered(c);
	}
}

Polinom::Polinom(const Polinom& P)
{
	Ringlist A(*P.list);
	list = &A;
}

Polinom::~Polinom()
{
	delete[] list;
}

Polinom& Polinom::operator=(const Polinom& P)
{
	Ringlist A(*P.list);
	list = &A;
	return *this;
}

Polinom& Polinom::operator+(const Polinom& P)
{
	Polinom temp(*this);
	P.list->reset();
	while (!P.list->isended())
	{
		temp.list->InsertToOrdered(P.list->GetNext());
	}
	return(temp);
}

Polinom& Polinom::operator*(const int& a)
{
	Polinom temp(*this);
	temp.list->reset();
	while (!temp.list->isended())
	{
		temp.list->GetNext().coeff *= a;
	}
	return temp;
}

Polinom& Polinom::operator*(const Polinom& P)
{
	return *this;
}