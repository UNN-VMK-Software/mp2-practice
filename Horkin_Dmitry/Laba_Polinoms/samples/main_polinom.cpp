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
		cout << "You can write your polinom like" << endl;
		cout << "degree x1 or y3" << endl<< "number - 12.43"<< endl<< "Monom -12.43x1y3z1"<<endl;
		cout << "Please, write your first polinom" << endl;
		string s1;
		cin >> s1;
		polinom S1(s1);
		cout << "Please, write your second string" << endl;
		string s2;
		cin >> s2;
		polinom S2(s2);
		cout << "Please, choose operation" << endl;
		cout << "1  +" << endl;
		cout << "2  -" << endl;
		cout << "3 *" << endl;
		cout << "4 * on constant" << endl;
		cout << "Your choise is - ";
		cin >> k;
		
		switch (k)
		{
		case 1:
		{
			polinom res = S1 + S2;
			cout << res;
			break;
		}
		case 2:
		{
			polinom res = S1 - S2;
			cout << res;
			break;
		}
		case 3:
		{
			try {
				polinom res = S1 * S2;
				cout << res;
			}
			catch (...) {
				cout << "Can't multiply because"<< endl<< "you wrote very big stepen"<<endl;
			}
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
			
				polinom res = a * S1;

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