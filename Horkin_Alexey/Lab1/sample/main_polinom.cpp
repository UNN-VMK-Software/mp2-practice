#include "monom.h"
#include "polinom.h"
#include <iostream>
#include <ostream>
using namespace std;

void main()
{
    
	int flag = 1;
	int k = 0;
	while (flag == 1)
	{
		system("cls");
		cout << "Please, write your first string" << endl;
		string s1;
		cin >> s1;
		Polinom S1(s1);
		cout << "Please, write your second string" << endl;
		string s2;
		cin >> s2;
		Polinom S2(s2);
		cout << "Please, choose operation" << endl;
		cout << "1  +" << endl;
		cout << "2  -" << endl;
		cout << "3 *" << endl;
		cout << "4 * on constant" << endl;
		cin >> k;
		switch (k)
		{
		case 1:
		{
			Polinom res = S1 + S2;
			cout << res;
			break;
		}
		case 2:
		{
			Polinom res = S1 - S2;
			cout << res;
			break;
		}
		case 3:
		{
			Polinom res = S1 * S2;
			cout << res;
			break;
		}
		case 4:
		{
			//string con;
			//cin >> con;
			double a;
			cout << "Please, write const for multyplication" << endl;
			cin >> a;
			//Polinom C(con);
			Polinom res = S1*a;
			cout << res;
			break;
		}
		default:
			break;
		}

		cout << "Repeat - 1" << endl;
		cin >> flag;
		
	}
}