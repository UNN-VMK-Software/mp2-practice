#ifndef TMONOM_H
#define TMONOM_H

struct Tmonom {
	double cf;
	unsigned int abc;
	Tmonom(const double d = 0.0, const unsigned int m = 0) { cf = d; abc = m; };
	Tmonom(const Tmonom& _Tmonom);
	const Tmonom& operator = (const Tmonom& _Tmonom);
	bool operator < (const Tmonom& _tmonom) const;
	bool operator != (const Tmonom& _tmonom) const;
	bool operator == (const Tmonom& _tmonom) const;
	bool operator > (const Tmonom& _tmonom) const;
	Tmonom operator+ (const Tmonom& _tmonom);
};

#endif
