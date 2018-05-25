#include "TMonom.h"

Tmonom::Tmonom(const Tmonom& _Tmonom) 
{
	cf = _Tmonom.cf;
	abc = _Tmonom.abc;
}

const Tmonom& Tmonom::operator = (const Tmonom& _Tmonom)
{
	cf = _Tmonom.cf;
	abc = _Tmonom.abc;
	return *this;
}

bool Tmonom::operator < (const Tmonom& _tmonom) const
{
	return abc < _tmonom.abc;
}

bool Tmonom::operator != (const Tmonom& _tmonom) const
{
	return abc != _tmonom.abc;
}

bool Tmonom::operator == (const Tmonom& _tmonom) const
{
	return abc == _tmonom.abc;
}

bool Tmonom::operator > (const Tmonom& _tmonom) const
{
	return abc > _tmonom.abc;
}

Tmonom Tmonom::operator+ (const Tmonom& _tmonom)
{
	Tmonom res;
	if ((*this).abc == _tmonom.abc)
	{
		res.abc = (*this).abc;
		res.cf = (*this).cf + _tmonom.cf;
	}
	else throw "unable to sum monoms!";
	return res;
}