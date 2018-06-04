#pragma once

#include "TRingList.h"

class TPolinom
{
private:
	TRingList<TMonom> monoms; // список 
public:
	TPolinom() {}; // конструктор 
	TPolinom(const string s); // конструктор по строке
	TPolinom(const TPolinom &poli2); // конструктор копирования
	~TPolinom() {}; // деструктор

	TPolinom operator + (const TPolinom& poli2); // сумма полиномов
	TPolinom operator - (const TPolinom& poli2); // разность полиномов
	TPolinom operator * (const TPolinom& poli2); // произведение полиномов 
	TPolinom operator * (double cf2); // произведение полинома и числа
	friend TPolinom operator *(double cf2, const TPolinom& poli2); // произведение числа и полинома
	TPolinom& operator = (const TPolinom& tmp); // оператор копирвоания
	bool operator == (const TPolinom& poli2) const; // оператор сравнения 
	void PrivPod(); // приведение подобных

	friend ostream& operator <<(ostream& ostr, const TPolinom& poli2); // печать полинома 
};