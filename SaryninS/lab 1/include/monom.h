#pragma once
class Monom
{
public:
	double cf; 
	unsigned int abc; 
	
	Monom(double a= 0 , unsigned int b = 0) { cf = a; abc = b;}
	
	Monom& operator=(const Monom& m);
	bool operator< (const Monom& m) const;
	bool operator> (const Monom& m) const;

	bool operator==(const Monom& m) const;
	bool operator!=(const Monom& m) const;
};