#include "monom.h"
#include <cstdlib>
Monom::Monom(double ff, int abcc) {
	f = ff;
	abc = abcc;
}

void Monom:: operator = (const Monom &A) {
	abc = A.abc;
	f = A.f;
}
bool Monom:: operator < (const Monom &A) const {
	if (abc < A.abc) return true; else return false;
}
bool Monom:: operator > (const Monom &A) const {
	if (abc > A.abc) return true; else return false;
}

Monom Monom::operator*(const Monom & A) const
{
	return Monom(this->f*A.f,this->abc+A.abc);
}


bool Monom:: operator ==(const Monom &A) const {
	if ((this->abc == A.abc) && (this->f == A.f)) return 1; else return 0;
}
bool Monom:: operator !=(const Monom &A) const {
	if ((this->abc == A.abc) && (this->f == A.f)) return 0; else return 1;
}

Monom:: Monom(const string &A)
{
	if (A != "") {
		int i = 0;
		string B = "";
		while ((A[i] != 'x') && (A[i] != 'y') && (A[i] != 'z') && (i < A.length()))
			B.push_back(A[i++]);
		if (B == "")
			f = 1; else
			if (B == "-") {
				f = -1;
			}
			else f = atof(&B[0]);
			abc = 0;
			int x = 0;
			int y = 0;
			int z = 0;
			while (i < A.length()) {
				switch (A[i])
				{
				case 'x': {
					x = atof(&A[i + 1]);
					i = i + 2;
					break;
				}
				case 'y': {
					y = atof(&A[i + 1]);
					i = i + 2;
					break;
				}
				case 'z': {
					z = atof(&A[i + 1]);
					i = i + 2;
					break;
				}
				default: {

				}
						 break;
				}

			}
			abc = x * 100 + y * 10 + z;
	}
	else {
		abc = 0;
		f = 0;
	}
}

