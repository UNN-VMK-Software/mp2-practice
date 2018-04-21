#pragma once

#include "TRingList.h"

class TPolinom
{
private:
	TRingList<TMonom> monoms;
public:
	TPolinom() {};
	TPolinom(const string s);
	TPolinom(const TPolinom &poli2);
	~TPolinom() {};

	TPolinom operator + (const TPolinom& poli2); // сумма полиномов
	TPolinom operator - (const TPolinom& poli2); // разность полиномов
	TPolinom operator * (const TPolinom& poli2); // произведение полиномов 
	TPolinom operator * (double cf2); // произведение полинома и числа
	friend TPolinom operator *(double cf2, const TPolinom& poli2); // произведение числа и полинома
	TPolinom& operator = (const TPolinom& tmp);
	bool operator == (const TPolinom& poli2) const;

	friend ostream& operator <<(ostream& ostr, const TPolinom& poli2); // печать полинома 
};