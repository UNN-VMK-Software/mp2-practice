#include "Polinom.h"
int main()
{
	char number;
	string s1, s2;
	Polinom p1, p2;
	double con;
	cout << "Hello, what do you wanna do?"<<endl;
	cout << "1.Add 2 polinoms" << endl;
	cout << "2.Subtract 2 polinoms" << endl;
	cout << "3.Multiply 2 polinoms" << endl;
	cout << "4.Multiply polinom by number" << endl;
	cout << "5.Exit" << endl;
	do
	{
		cout << "Do:" << endl;
		cin >> number;
		switch (number)
		{
		case '1':
		{
			cout << "Enter first polinom: ";
			cin >> s1;
			p1 = s1;
			cout << "Enter second polinom: ";
			cin >> s2;
			p2 = s2;
			cout << "Result of operation: " << p1 + p2 << endl << endl;
			break;
		}
		case '2':
		{
			cout << "Enter first polinom: ";
			cin >> s1;
			p1 = s1;
			cout << "Enter second polinom: ";
			cin >> s2;
			p2 = s2;
			cout << "Result of operation: " << p1 - p2 << endl << endl;
			break;
		}
		case '3':
		{
			cout << "Enter first polinom: ";
			cin >> s1;
			p1 = s1;
			cout << "Enter second polinom: ";
			cin >> s2;
			p2 = s2;
			cout << "Result of operation: " << p1 * p2 << endl << endl;
			break;
		}
		case '4':
		{
			cout << "Enter polinom: ";
			cin >> s1;
			p1 = s1;
			cout << "Enter constant: ";
			cin >> con;
			cout << "Result of operation: " << con * p1 << endl << endl;
			break;
		}

		}
	}
	while (number != '5');
	return 0;
}