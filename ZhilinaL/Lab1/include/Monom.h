#pragma once

class monom
{
public:
	double coeff;//коэффициент монома				                                   
	unsigned int abc;//степень монома, x^a,y^b,z^c
	monom(double c = 0, unsigned int a = 0);//конструктор с параметрами                  
	monom& operator=(const monom& m);//перегрузка оператора присваивания                     
	bool operator< (const monom& m) const;//перегрузка оператора меньше, сравнивает общую степень и коэфф.
	bool operator> (const monom& m) const;//перегрузка оператора больше, сравнивает общую степень и коэфф.
	//перегрузка операторов сравнения
	bool operator==(const monom& m) const;
	bool operator!=(const monom& m) const;
};
