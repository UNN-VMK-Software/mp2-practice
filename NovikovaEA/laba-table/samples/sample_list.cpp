#include "monom.h"
#include "polinom.h"
#include <iostream>
#include <ostream>
#include "TablesUnordered.h"
#include "TablesOrdered.h"
#include "TablesHash.h"
using namespace std;

int main()
{

	polinom aff("1+x");
	setlocale(LC_ALL, "Russian");
	int c = 0;
	int k;
	int size;

	cout << "Введите размер таблицы" << endl;
	cin >> size;
	unordtable<string, polinom> A(size);
	string a;
	ordertable<string, polinom> B(size);
	hashtable<string, polinom> C(size);

	while (c != 1)
	{
		system("cls");
		cout << "Выберете операцию" << endl;
		cout << "1 - Вставка" << endl;
		cout << "2 - Удаление" << endl;
		cout << "3 - Поиск" << endl;
		cout << "4 - Открыть таблицу" << endl;
		cin >> k;
		switch (k)
		{
		case 1:
		{
			string str;
			cout << "Введите полином" << endl;
			cin >> str;
			polinom a(str);
			try { A.insert(str, a); }
			catch (...) { cout << "Дублирующийся ключ" << endl; }
			try { B.insert(str, a); }
			catch (...) { cout << "Дублирующийся ключ" << endl; }
			try { C.insert(str, a); }
			catch (...) { cout << "Дублирующийся ключ" << endl; }
			cout << "Неупорядоченная :" << endl;
			cout << A << endl;
			cout << "Упорядоченная :" << endl;
			cout << B << endl;
			cout << "Hash :" << endl;
			cout << C << endl;
			break;
		}
		case 2:
		{
			string str;
			cout << "Введите полином" << endl;
			cin >> str;
			polinom a(str);
			try { A.delet(str); }
			catch (...) { cout << "элемент не существует" << endl; }
			try { B.delet(str); }
			catch (...) { cout << "элемент не существует" << endl; }
			try { C.delet(str); }
			catch (...) { cout << "элемент не существует" << endl; }
			cout << "Неупорядоченная :" << endl;
			cout << A << endl;
			cout << "Упорядоченная :" << endl;
			cout << B << endl;
			cout << "Hash :" << endl;
			cout << C << endl;
			break;
		}
		case 3:
		{
			string str;
			cout << "Введите полином" << endl;
			cin >> str;
			polinom a(str);
			try { cout << "Найдено: " << A.search(str)->data; }
			catch (...) { cout << "элемент не существует" << endl; }
			try { cout << "Найдено: " << B.search(str)->data; }
			catch (...) { cout << "элемент не существует" << endl; }
			try { cout << "Найдено: " << C.search(str)->data; }
			catch (...) { cout << "элемент не существует" << endl; }
			break;
		}
		case 4:
		{
			cout << "Неупорядоченные :" << endl;
			cout << A << endl;
			cout << "Упорядоченные :" << endl;
			cout << B << endl;
			cout << "Hash :" << endl;
			cout << C << endl;
			break;
		}
		default:
		{
			cout << "Ошибка" << endl;
			break;
		}
		}

		cout << "Если хотите выйти, нажмите 1" << endl;
		cin >> c;
	}
	return 0;
}


