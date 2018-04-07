#pragma once

#include "monom.h"
#include "list.h"
#include <iostream>
#include <string>


using namespace std;


class polynom
{
private:
	list<monom> list_pol;		                                                                                     //Полином - список из мономов
public:
	list<monom> similar_terms(list <monom> sp);
	polynom(const string pol = "" );                                                                             //Разбор строки
	polynom(const polynom& pol);                           							                                 //Конструктор копирования
	polynom& operator=(const polynom &pol);                                                                          //Присваивание
	polynom operator+(const polynom& pol) const;			                                                         //Сложение полиномов
	polynom operator*(const double a) const;				                                                         //Умножение на константу слева
    friend polynom operator*(const double a,const polynom& pol) { return pol*a; }	                                 //Умножение на константу справа
	polynom operator-(const polynom& pol) const { return *this + pol*(-1.0); }		                                 //Разность полиномов
	polynom operator*(const polynom& pol) const;			                                                         //Умножение полиномов 	
    polynom operator-() const { return (-1.0)*(*this); }                                                             //Унарный минус
    friend ostream& operator<<(ostream &ostr, const polynom &pol);	                                                 //Оператор вывода
	bool operator==(const polynom& pol) const { return list_pol == pol.list_pol; }		
	bool operator!=(const polynom& pol) const { return list_pol != pol.list_pol; }

	polynom(list<monom> &list) : list_pol(list) {}								                                     //Конструктор по списку
};
