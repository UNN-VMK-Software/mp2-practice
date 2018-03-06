#pragma once


class monom
{
public:
	double coeff;				                                    //Коэффициент перед мономом
	unsigned int abc;	                                            //Обобщённая степень
	monom(double c = 0, unsigned int a = 0);                        //Конструктор
	monom& operator=(const monom& m);                              //Оператор присваивания
	bool operator< (const monom& m);		 
	bool operator> (const monom& m);		
	bool operator==(const monom& m);
	bool operator!=(const monom& m);
};