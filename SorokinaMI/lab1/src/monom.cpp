#include "monom.h"

Monom::Monom() {
	cf = 0;
	abc = 1003;
}
Monom::Monom(double d, unsigned int st) {
	cf = d;
	abc = st;
}
Monom& Monom::operator=(const Monom &m) {
	cf = m.cf; 
	abc = m.abc;
	return *this;
}
bool Monom::operator==(const Monom &m) const{
	return  abc == m.abc;
}
bool Monom::operator!=(const Monom &m) const{
	return !(*this == m);
}
bool Monom::operator<(const Monom &m) const{
	return abc<m.abc;
}
Monom& Monom::operator+(const Monom &m) {
	cf = cf+m.cf;
	return *this;
}
Monom& Monom::operator*(const double &d) {
	cf = cf*d;
	return *this;
}
Monom& Monom::operator*(const Monom &m) {
	Monom res;
	res.cf = cf*m.cf;
	res.abc = abc + m.abc;
	return res;
}
