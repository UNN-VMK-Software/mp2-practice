#include "polinom.h"
#include <conio.h>

void main()
{
	cout << "Input correct polinoms" << endl;
	char c = 0;
	string pol1;
	string pol2;

	while (!c || (c == ' '))
	{
		cout << "-------------------------" << endl;
		cout << endl;
		cout << "Enter first polinom:" << endl;
		getline(cin, pol1);
		if (pol1 == "")
			getline(cin, pol1);
		Polinom p1(pol1);
		cout << "p1 = " << p1 << endl;

		cout << "Enter second polinom:" << endl;
		getline(cin, pol2);
		if (pol2 == "")
			getline(cin, pol2);
		Polinom p2(pol2);
		cout << "p2 = " << p2 << endl;

		cout << "-------------------------" << endl;

		Polinom res = p1 + p2;
		cout << "p1 + p2 = " << res << endl;

		cout << "-------------------------" << endl;

		res = p1 - p2;
		cout << "p1 - p2 = " << res << endl;

		cout << "-------------------------" << endl;

		res = p1 * p2;
		cout << "p1 * p2 = " << res << endl;

		cout << "-------------------------" << endl;

		cout << "Press SPACE to retry" << endl;
		cout << "Press any key to exit" << endl;
		
		c = _getch();
	}
}