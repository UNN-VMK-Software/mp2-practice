
#include "Pol_Mon.h"

Monom::Monom(const Monom& _Tmonom)
{
	cf = _Tmonom.cf;
	stmonom = _Tmonom.stmonom;
}

const Monom& Monom::operator = (const Monom& _Tmonom)
{
	cf = _Tmonom.cf;
	stmonom = _Tmonom.stmonom;
	return *this;
}

bool Monom::operator < (const Monom& _tmonom) const
{
	return stmonom < _tmonom.stmonom;
}

bool Monom::operator != (const Monom& _tmonom) const
{
	return stmonom != _tmonom.stmonom;
}

bool Monom::operator == (const Monom& _tmonom) const
{
	return stmonom == _tmonom.stmonom;
}

bool Monom::operator > (const Monom& _tmonom) const
{
	return stmonom > _tmonom.stmonom;
}

Monom Monom::operator+ (const Monom& _tmonom)
{
	Monom res;
	if ((*this).stmonom == _tmonom.stmonom)
	{
		res.stmonom = (*this).stmonom;
		res.cf = (*this).cf + _tmonom.cf;
	}
	else throw "unable to sum monoms!";
	return res;
}