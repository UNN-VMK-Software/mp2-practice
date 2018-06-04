#include "ScanTable.h"
#include "HashTable.h"
#include "SortedTable.h"
#include "Polinom.h"
#include <conio.h>
using namespace std;
int main()
{
	ScanTable<Polinom> A(10);
	SortedTable<Polinom> B;
	HashTable<Polinom> C;
	string Key, Str;
	Polinom P;
	int i = 0;
	while (i != 5)
	{
		cout << "Choose your action: " << endl;
		cout << "1.Input " << endl;
		cout << "2.Delete" << endl;
		cout << "3.Search" << endl;
		cout << "4.Print tables" << endl;
		cout << "5.End" << endl;
		cin >> i;
		switch (i)
		{
		case 1:
		{
			system("cls");
			cout << "Enter your polinom" << endl;
			cin >> Key;
			P = Polinom(Key);
			try { A.Insert(P, Key); }
			catch (...) { cout << "not unique key" << endl; }
			try { B.Insert(P, Key); }
			catch (...) { cout << "not unique key" << endl; }
			try { C.Insert(P, Key); }
			catch (...) { cout << "not unique key" << endl; }
			cout << "ScanTable: " << endl << A << endl;
			cout << "SortedTable :" << endl << B << endl;
			cout << "HashTable :" << endl << C << endl << endl;
			break;
		}

		case 2:
		{
			system("cls");
			cout << "Enter your polinom:" << endl;
			cin >> Key;

			try { A.Delete(Key); }
			catch (...) { cout << "element doesn't exist" << endl; }
			try { B.Delete(Key); }
			catch (...) { cout << "element doesn't exist" << endl; }
			try { C.Delete(Key); }
			catch (...) { cout << "element doesn't exist" << endl; }
			cout << "ScandTable: " << endl << A << endl;
			cout << "Sortedable :" << endl << B << endl;
			cout << "HashTable :" << endl << C << endl << endl;
			break;
		}

		case 3:
		{
			system("cls");
			cout << "Enter your polinom:" << endl;
			cin >> Key;
			try { cout << "find: " << *(A.Search(Key)) << endl; }
			catch (...) { cout << "element doesn't exist" << endl; }
			try { cout << "find: " << *(B.Search(Key)) << endl; }
			catch (...) { cout << "element doesn't exist" << endl; }
			try { cout << "find: " << *(C.Search(Key)) << endl; }
			catch (...) { cout << "element doesn't exist" << endl; }
			break;
		}
		break;
		case 4:
		{
			system("cls");
			cout << "ScanTable : " << A << endl;
			cout << "SortedTable : " << B << endl;
			cout << "HashTable : " << C << endl;
			break;
		}

		default:
		{
			cout << "try again" << endl;
			break;
		}
		}
	}
	return 0;
}