#include "monom.h"
Monom::Monom(double ff, int abcc) {
	f = ff;
	abc = abcc;
}
void Monom::Push(double f, int abc) {
	this->abc = abc;
	this->f = f;
}
void Monom::Push(Monom a) {
	this->abc = a.abc;
	this->f = a.f;
}
int Monom::Getx() {
	return (abc / 100);
}
int Monom::Gety() {
	return ((abc % 100) / 10);
}
int Monom::Getz() {
	return ((abc % 100) % 10);
}
double Monom::Getf() {
	return f;
}

void Monom::Pushx(int x) {
	int bc = abc % 100;
	abc = x * 100 + bc;
}
void Monom::Pushy(int y) {
	int x = Getx();
	int z = Getz();
	abc = 100 * x + 10 * y + z;
}
void Monom::Pushz(int z) {
	abc = abc - Getz() + z;
}
void Monom::Pushf(double f) {
	this->f = f;
}

int Monom::Getabc() {
	return abc;
}