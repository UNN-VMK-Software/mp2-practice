// класс или структура Монома (double коэффициент, целая свернутая степень)
#pragma once
class Monom {
private:
	int abc;
	double f;
public:
	Monom(double ff = 0, int abcc = 0);
	void Pushx(int x = 0);
	void Pushy(int y = 0);
	void Pushz(int z = 0);
	void Pushf(double f = 0);
	int Getx();
	int Gety();
	int Getz();
	void Push(double f = 0, int abc = 0);
	void Push(Monom a);
	double Getf();
	int Getabc();
};