#include "monom.h" 
#include "polinom.h" 
#include <iostream> 
#include <ostream> 
#include "TablesUnord.h" 
#include "TablesOrdered.h" 
#include "TablesHash.h" 
using namespace std;

int main()
{
	int c = 0;
	int k;
	int SIZE;

	cout << "Create table, please enter size of table" << endl;
	cin >> SIZE;
	TableUnord<string, polinom> A(SIZE);
	string a;
	TableOrdered<string, polinom> B(SIZE);
	HashTable<string, polinom> C(SIZE);

	while (c != 1)
	{
		system("cls");
		cout << "Chouse operation" << endl;
		cout << "1 - Insert" << endl;
		cout << "2 - Dell" << endl;
		cout << "3 - Search" << endl;
		cout << "4 - Print" << endl;
		cin >> k;
		switch (k)
		{
		case 1:
		{
			string str;
			cout << "Write your polinom" << endl;
			cin >> str;
			polinom a(str);
			try { A.Insert(str, a); }
			catch (...) { cout << "duplicated key" << endl; }
			try { B.Insert(str, a); }
			catch (...) { cout << "duplicated key" << endl; }
			try { C.Insert(str, a); }
			catch (...) { cout << "duplicated key" << endl; }
			cout << "Unordered :" << endl;
			cout << A << endl;
			cout << "Ordered :" << endl;
			cout << B << endl;
			cout << "Hash :" << endl;
			cout << C << endl;
			break;
		}
		case 2:
		{
			string str;
			cout << "Write your polinom" << endl;
			cin >> str;
			polinom a(str);
			try { A.Dell(str); }
			catch (...) { cout << "element doesn't exist" << endl; }
			try { B.Dell(str); }
			catch (...) { cout << "element doesn't exist" << endl; }
			try { C.Dell(str); }
			catch (...) { cout << "element doesn't exist" << endl; }
			cout << "Unordered :" << endl;
			cout << A << endl;
			cout << "Ordered :" << endl;
			cout << B << endl;
			cout << "Hash :" << endl;
			cout << C << endl;
			break;
		}
		case 3:
		{
			string str;
			cout << "Write your polinom" << endl;
			cin >> str;
			polinom a(str);
			try { cout << "finded: " << A.Search(str)->Data; }
			catch (...) { cout << "element doesn't exist" << endl; }
			try { cout << "finded: " << B.Search(str)->Data; }
			catch (...) { cout << "element doesn't exist" << endl; }
			try { cout << "finded: " << C.Search(str)->Data; }
			catch (...) { cout << "element doesn't exist" << endl; }
			break;
		}
		case 4:
		{
			cout << "Unordered :" << endl;
			cout << A << endl;
			cout << "Ordered :" << endl;
			cout << B << endl;
			cout << "Hash :" << endl;
			cout << C << endl;
			break;
		}
		default:
		{
			cout << "ERROR, choose again" << endl;
			break;
		}
		}

		cout << "Exit - 1" << endl;
		cin >> c;
	}
	return 0;
}


