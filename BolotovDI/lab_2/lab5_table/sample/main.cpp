#include "ScanTable.h"
#include "SortedTable.h"
#include "HashTable.h"

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	
	int c = 0;
	int k;
	int SIZE;

	cout << "Пожалуйста, введите размер таблицы: ";
	cin >> SIZE;
	cout << endl;
	
	ScanTable A(SIZE);
	SortedTable B(SIZE);
	HashTable C(SIZE);

	while (c != 2)
	{
		system("cls");
		cout << "Выберите операцию." << endl;
		cout << "1. Вставка" << endl;
		cout << "2. Удаление" << endl;
		cout << "3. Поиск" << endl;
		cout << "Ваш выбор: ";
		cin >> k;
		cout << endl;
		switch (k)
		{
			case 1:
			{
				string c;
				cout << "Введите строку: ";
				cin.ignore();
				getline(cin, c);
				TPolinom F(c);
				try
				{
					A.Insert(c, &F);
				}
				catch (const char *ex)
				{
					cout << ex << endl;
				}
				try
				{
					B.Insert(c, &F);
				}
				catch (const char *ex)
				{
					cout << ex << endl;
				}
				try
				{
					C.Insert(c, &F);
				}
				catch (const char *ex)
				{
					cout << ex << endl;
				}
				cout << endl << "Просматриваемая таблица:" << endl;
				A.PrintTable();
				cout << endl << "Сортированная таблица: " << endl;
				B.PrintTable();
				cout << endl << "Хэш-таблица: " << endl;
				C.PrintTable();
				cout << endl;
				break;
			}
			case 2:
			{
				string c;
				cout << "Введите строку: ";
				cin.ignore();
				getline(cin, c);
				TPolinom F(c);
				try
				{
					A.Delete(c);
				}
				catch (const char *ex)
				{
					cout << ex << endl;
				}
				try
				{
					B.Delete(c);
				}
				catch (const char *ex)
				{
					cout << ex << endl;
				}
				try
				{
					C.Delete(c);
				}
				catch (const char *ex)
				{
					cout << ex << endl;
				}
				cout << endl << "Просматриваемая таблица:" << endl;
				A.PrintTable();
				cout << endl << "Сортированная таблица: " << endl;
				B.PrintTable();
				cout << endl << "Хэш-таблица: " << endl;
				C.PrintTable();
				cout << endl;
				break;
			}
			case 3:
			{
				string c;
				cout << "Введите строку: ";
				cin.ignore();
				getline(cin, c);
				TPolinom F(c);
				cout << endl;
				A.PrintTable();
				cout << endl;
				B.PrintTable();
				cout << endl;
				C.PrintTable();
				cout << endl;
				if (A.Search(c) != nullptr)
				{
					cout << endl << "Позиция в просматриваемой таблице: " << A.GetIndex() << endl;
				}
				else
				{
					cout << "Элемент не найден. " << endl;
				}
				if (B.Search(c) != nullptr)
				{
					cout << endl << "Позиция в сортированной таблице: " << B.GetIndex() << endl;
				}
				else
				{
					cout << "Элемент не найден. " << endl;
				}
				if (C.Search(c) != nullptr)
				{
					cout << endl << "Позиция в хэш-таблице: " << C.GetIndex() << endl;
				}
				else
				{
					cout << "Элемент не найден. " << endl;
				}
				break;
			}
		}

		cout << endl << "Продолжить работу в программе? " << endl;
		cout << "1. Да" << endl;
		cout << "2. Нет" << endl;
		cout << "Ваш выбор: ";
		cin >> c;
	}

	cin.get();
}