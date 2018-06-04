#pragma once

#include "Monom.h"
#include "List.h"
#include <iostream>
#include <string>

using namespace std;
class Polinom
{
private:
	list<monom> Plist;//список из мономов
	list<monom> similar_terms(list <monom> sp);//приведение подобных в полиноме   	                                                                                    
public:
	Polinom(const string pol = "");//разбор строки                                                                     
	Polinom(const Polinom& pol);//конструтор копирования         							                                 
	Polinom& operator=(const Polinom &pol);//перекгрузка опреатора присваивания                                                                   
	Polinom operator+(const Polinom& pol) const;//перегрузка оператора сложения
	Polinom operator*(const double a) const;//перегрузка оператока умножения с параметром-константа(умножение на констранту слева)          
	friend Polinom operator*(const double a, const Polinom& pol) { return pol * a; }//умножение на констранту справа
	Polinom operator-(const Polinom& pol) const { return *this + pol * (-1.0); }//перегрузка оператора вычитания	                                
	Polinom operator*(const Polinom& pol) const;//перегрузка оператока умножения с параметром-полином(умножение полиномов)		                                                        
	Polinom operator-() const { return (-1.0)*(*this); }//унарный минус                                                       
	friend ostream& operator<<(ostream &ostr, const Polinom &pol);//перегрузка оператора вывода       
	//перегрузка операторов сравнения
	bool operator==(const Polinom& pol) const { return Plist == pol.Plist; }
	bool operator!=(const Polinom& pol) const { return Plist != pol.Plist; }

	Polinom(list<monom> &list) : Plist(list) {}//конструктор по списку
};
