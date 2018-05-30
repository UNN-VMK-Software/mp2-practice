#include "polinom.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	{
		int f;
		do
		{
			cout << "Выберите действие с полиномами:" << endl;
			cout << "1 - сложить полиномы" << endl;
			cout << "2 - умножить полиномы" << endl;
			cout << "3 - умножить полином на константу" << endl;
			cin >> f;
			cin.ignore();
			if (f == 1)
			{
				string s;
				cout << "Введиет первый полином" << endl;
				getline(cin, s);
				polinom p1(s);
				cout << "Введите второй полином" << endl;
				getline(cin, s);
				polinom p2(s);
				polinom p3 = p1 + p2;
				cout << "Результат: " << p3 << endl;
			}
			else
				if (f == 2)
				{
					string s;
					cout << "Введите первый полином" << endl;
					getline(cin, s);
					polinom p1(s);
					cout << "Введите второй полином" << endl;
					getline(cin, s);
					polinom p2(s);
					polinom p3 = p1 * p2;
					cout << "Результат: " << p3 << endl;
				}
				else
					if (f == 3)
					{
						string s;
						cout << "Введите полином" << endl;
						getline(cin, s);
						polinom p(s);
						cout << "Введите число" << endl;
						double d;
						cin >> d;
						p = p * d;
						cout << "Результат: " << p << endl;
					}
					else
						cout << "Выберите еще раз" << endl;
			cout << "Хотите продолжить?" << endl;
			cout << "1 - да" << endl;
			cout << "2 - нет" << endl;
			cin >> f;
		} while (f == 1);
		return 0;
	}
}




