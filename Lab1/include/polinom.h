#pragma once
#include <string>
#include "list.h"
#include "monom.h"
using namespace std;
class Polinom
{
public:
	Polinom(const string &A ="");
	Polinom(const Polinom &A); //конструктор копирования
	~Polinom();
	bool operator==(const Polinom& Polinom2) const; //оператор ==
	Polinom& operator=(const Polinom& Polinom2); //оператор = 
	Polinom operator+(const Polinom& Polinom2); //оператор +
	Polinom operator-(const Polinom& Polinom2); //оператор -
	Polinom operator * (const Polinom& Polinom2); //опрератор *
	friend ostream& operator<<(ostream& os, const Polinom& P);
	//умножение на константу;
	friend  Polinom operator * (const Polinom& A, const double a);
	friend  Polinom operator * (const double a, const Polinom& A);

private:
	list<monom> List;
	void Insert(const monom A); //ставляет Node в нужное место (приводит подобные если надо)

};
