#include "ringlist.h"

Monom::Monom() {
	cf = 0;
	abc = 1003;
}
Monom::Monom(double d, unsigned int st) {
	cf = d;
	abc = st;
}
Monom& Monom::operator=(const Monom &m) {
	cf = m.cf; abc = m.abc;
	return *this;
}
int Monom::operator==(const Monom &m) {
	return  abc == m.abc;
}
int Monom::operator!=(const Monom &m) {
	return !(*this == m);
}
int Monom::operator<(const Monom &m) {
	return abc<m.abc;
}
Monom& Monom::operator+(const Monom &m) {
	cf += m.cf;
	return *this;
}
Monom& Monom::operator*(const double &d) {
	cf *= d;
	return *this;
}
Monom& Monom::operator*(const Monom &m) {
	cf *= m.cf;
	abc += m.abc;
	return *this;
}
