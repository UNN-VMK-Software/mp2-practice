#pragma once

#include "monom.h"
#include "list.h"
#include <iostream>
#include <string>
using namespace std;


class polynom
{
private:
	list<monom> list_pol;		                                                                                     //Список - полином
public:
	polynom(const string pol = "");	                                                                      //Разбор строки
	polynom(const polynom& pol);                           							                                 //Конструктор копирования+
	polynom& operator=(const polynom &pol);                                                                          //Присваивание+
	polynom operator+(const polynom& pol) const;			                                                         //Сложение полиномов+
	polynom operator*(const double a) const;				                                                         //Умножение на константу слева+
	polynom operator-(const polynom& pol) const { return *this + (-1)*pol; }		                                 //Разность полиномов+
	polynom operator*(const polynom& pol) const;			                                                         //Умножение полиномов +	
    friend polynom operator*(const double a,const polynom& pol) { return pol*a; }	                                 //Умножение на константу справа+
    polynom operator-() const { return (-1)*(*this); }                                                               //Унарный минус+ ЗАЧЕМ
    friend ostream& operator<<(ostream &ostr, const polynom &pol);	                                                 //Вставка в поток+ НАДО ПРОВЕРИТЬ
};
