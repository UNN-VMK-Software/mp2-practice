#include "polinom.h"
#include "ringlist.h"
#include "iostream"

using namespace std;
int main()
{
	string s;
	int f;
	Polinom Res;
	cout << "Enter your polynom, using only letters x,y,z, without spaces and multiplication signs:\n";
	getline(cin, s);
	Polinom P(s);
    cout << "Choose that would you like to do with your polinom: 1 - multiply by a constant, 2 - multiply two polynoms, 3 - add two polynoms" << endl;
	cin >> f;
	switch (f) {
	case 1: {

		double d;
		cout << "Enter your constant value: " << endl;
		cin >> d;
		Res = P*d;
		break;
	}
	case 2: {
		string s1;
		cout << "Enter second polynom: " << endl;
		getline(cin, s1);
		Polinom P1(s1);
		Res = P*P1;
		break;
	}
	case 3: {
		string s2;
		cout << "Enter second polynom: " << endl;
		getline(cin, s2);
		Polinom P2(s2);
		Res = P + P2;
		break;
	}

	}
	//здесь печать полинома - результата 
	return 0;
}