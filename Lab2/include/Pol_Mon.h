#pragma once
struct Monom {
	double cf;
	unsigned int stmonom;
	Monom(const double d = 0.0, const int m = 0) { cf = d; stmonom = m; };
	Monom(const Monom& _Tmonom);
	const Monom& operator = (const Monom& _Tmonom);
	bool operator < (const Monom& _tmonom) const;
	bool operator != (const Monom& _tmonom) const;
	bool operator == (const Monom& _tmonom) const;
	bool operator > (const Monom& _tmonom) const;
	Monom operator+ (const Monom& _tmonom);
};
