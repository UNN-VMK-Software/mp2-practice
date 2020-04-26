#pragma once
#include <math.h>
//Класс Моном

class monom
{
public:
	double cf;		//Коэффициент перед мономом
	int abc;		//Свёрнутая степень
	bool operator< (const monom& m) const { return (abc<m.abc); }								//Оператор сравнения
	bool operator> (const monom& m) const { return (abc>m.abc); }								//Оператор сравнения
	bool operator==(const monom& m) const { return (abc == m.abc); }	//перегружено ==
	bool operator!=(const monom& m) const { return !(*this == m); }							//перегружено не равно
	monom(double indexcf = 0, unsigned int indexabc = 0) { cf = indexcf; abc = indexabc; }//Конструктор
	const monom& operator=(const monom& src) { cf = src.cf; abc = src.abc; return *this; }	//Оператор присваивания
};