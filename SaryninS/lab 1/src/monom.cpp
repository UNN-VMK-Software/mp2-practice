#include "monom.h"

Monom& Monom::operator=(const Monom& m)
{ 
	cf = m.cf;
	abc = m.abc;
	return *this;
}

bool Monom:: operator< (const Monom& m) const
{
	bool res = true;
	if (abc >= m.abc)
		res = false;
	return res;
}

bool Monom:: operator> (const Monom& m) const
{
	bool res = true;
	if (abc <= m.abc)
		res = false;
	return res;
}

bool Monom:: operator==(const Monom& m) const
{
	return (abc == m.abc && cf == m.cf);
}

bool Monom:: operator!=(const Monom& m) const
{
	return !(*this == m);
}