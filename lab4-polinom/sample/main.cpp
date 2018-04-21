#include "TPolinom.h"

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");

	TPolinom A;
	TPolinom B;
	TPolinom C;
	string s;
	string c;

	int i = 1;
	int j = 0;
	int k;
	while (i == 1)
	{
		cout << "Что хотите сделать с полиномами ?" << endl;
		cout << "1. Сумма полиномов." << endl;
		cout << "2. Разность полиномов." << endl;
		cout << "3. Произведение полиномов." << endl;
		cout << "4. Произведение полинома и числa." << endl;
		cout << "5. Произведение числа и полинома." << endl;
		cout << "Ваш выбор: ";
		cin >> j;
		cout << endl;

		if (j == 1)
		{
			cout << "Введите первый полином: ";
			cin.ignore();
			getline(cin, s);
			cout << endl;
			cout << "Введите второй полином: ";
			getline(cin, c);
			cout << endl;

			TPolinom A(s);
			TPolinom B(c);
			C = A + B;
			cout << C;
		}

		if (j == 2)
		{
			cout << "Введите первый полином: ";
			cin.ignore();
			getline(cin, s);
			cout << endl;
			cout << "Введите второй полином: ";
			getline(cin, c);
			cout << endl;

			TPolinom A(s);
			TPolinom B(c);
			C = A - B;
			cout << C;
		}

		if (j == 3)
		{
			cout << "Введите первый полином: ";
			cin.ignore();
			getline(cin, s);
			cout << endl;
			cout << "Введите второй полином: ";
			getline(cin, c);
			cout << endl;

			TPolinom A(s);
			TPolinom B(c);
			C = A * B;
			cout << C;
		}

		if (j == 4)
		{
			cout << "Введите полином: ";
			cin.ignore();
			getline(cin, s);
			cout << endl;
			cout << "Введите число: ";
			cin >> k;
			TPolinom A(s);
			C = A * k;
			cout << C;
		}
		
		if (j == 5)
		{
			cout << "Введите число: ";
			cin >> k;
			cout << endl;
			cout << "Введите полином: ";
			cin.ignore();
			getline(cin, s);
			cout << endl;
			TPolinom A(s);
			C = k * A;
			cout << C;
			cout << endl;
		}

		cout << endl;
		cout << "Повторить работу в программе ? " << endl;
		cout << "1. Да" << endl;
		cout << "2. Нет" << endl;
		cout << "Ваш выбор: ";
		cin >> i;
		cout << endl;
	}

	cin.get();
}