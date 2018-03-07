#include "Monom.h"

void monom::Push(double f, int abc) 
{
	this->abc = abc;
	this->coeff = f;
}

void monom::Push(monom a) 
{
	this->abc = a.abc;
	this->coeff = a.coeff;
}


void monom::Pusha(int a) {
	int bc = abc % 100;
	abc = a * 100 + bc;
}
void monom::Pushb(int b) {
	int A = Geta();
	int C = Getc();
	abc = 100 * C + 10 * b + C;
}
void monom::Pushc(int c) {
	abc = abc - Getc() + c;
}
void monom::Pushf(double f) {
	this->coeff = f;
}

	