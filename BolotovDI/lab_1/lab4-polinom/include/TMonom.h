#pragma once

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

struct TMonom
{
	double cf; // коэффициент монома
	unsigned int abc; // степень монов=ма 

	TMonom(); // конструктор 
	TMonom(const string s); // конструктор по строке
	TMonom(double num, unsigned int num2); // констурктор 
	~TMonom() {} // деструктор 
	 
	TMonom operator + (const TMonom& monom); // сумма мономов
	TMonom operator - (const TMonom& monom); // разность мономов
	TMonom operator = (const TMonom& monom); // конструткор копировани€ 

	// операторы сравнени€
	bool operator == (const TMonom& monom) const;
	bool operator != (const TMonom& monom) const;
	bool operator > (const TMonom& monom) const;
	bool operator < (const TMonom& monom) const;
};