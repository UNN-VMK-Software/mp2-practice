#include "polinom.h"
#include "List.h"
 
int main()
{
	cout << "use x,y,z " << endl << endl;
	int f = 1;
	string pol1;
	string pol2;
	Polinom res;
	while (f != 0)
	{
		cout << "enter the first polynomial" << endl;
		cin >> pol1;
		Polinom A(pol1);
		cout << "first polinomial = " << A << endl;
		cout << "enter the second polynomial" << endl;
		cin >> pol2;
		Polinom B(pol2);
		cout << "second polinomial = " << B << endl << endl;
		res = A + B;
		cout << " sum = ";
		cout << res << endl;
		res = A - B;
		cout << " difference = ";
		cout << res << endl;
		res = A * B;
		cout << " multiplication = ";
		cout << res << endl;
		cout << endl;
		cout << "enter 0 for exit and any character to continue " << endl;
		cin >> f;
		cout << endl;
	}
	return 0;
}