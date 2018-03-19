#pragma once

struct monom{
	double cf;
	unsigned int abc;
	monom(double cf1 = 0, unsigned int abc1 = 0) { cf = cf1; abc = abc1; }
	bool operator< (const monom& a) { return (abc<a.abc); }								 
	bool operator> (const monom& a) { return (abc>a.abc); }
	bool operator== (const monom& a) const { return ((abc == a.abc) && (cf==a.cf)); }
	bool operator!= (const monom& a) const{ return !(*this == a); }
};