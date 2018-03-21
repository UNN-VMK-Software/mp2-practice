#pragma once
#include "monom.h"
#include "list.h"
#include <string>

using namespace std;

class polynom {
private:
	list<monom> plist;
	static list<monom> parse(const string);			
public:	
	list<monom> reduction(list <monom> p);
	polynom(const string expr = "");
	polynom(list<monom> &expr) : plist(expr) {}
	polynom(const polynom& pol) : plist(pol.plist) {  }
	polynom operator+(const polynom&) const;	
	polynom operator-(const polynom& pol) const { return *this + pol*(-1); }
	polynom operator*(const double) const;
	polynom operator*(const polynom&) const;
	friend polynom operator*(const double c, const polynom& pol) { return pol*c; }
	friend ostream& operator<<(ostream& os, const polynom&);
	bool operator==(const polynom& pol) const { return plist == pol.plist; }
	bool operator!=(const polynom& pol) const { return plist != pol.plist; }
};