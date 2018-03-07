#pragma once
// структура Монома
struct monom
{
private:
	int abc; //степень
	double coeff;
public:
	monom(int a = 0, double f = 0){abc = a;coeff = f;}
	void Pusha(int a = 0);
	void Pushb(int b = 0);
	void Pushc(int c = 0);
	void Pushf(double f = 0);
	int Geta() {return (abc / 100);}
	int Getb() {return ((abc % 100));}
	int Getc() {return ((abc % 100) % 10);}
	void Push(double f = 0, int abc = 0);
	void Push(monom a);
	double Getf() { return coeff; }
	int Getabc() { return abc; }
};