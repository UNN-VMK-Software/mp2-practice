#include <conio.h>
#include "upor_table.h"
#include "prosm_table.h"
#include "hash_table.h"
#include "polynom.h"
#include "monom.h"



#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

int main()
{
	int c = 0;
	int k;
	int SIZE;
	cout << "Write size table" << endl;
	cin >> SIZE;
	ScanTable<string, polynom> A(SIZE);
	OrdTab<string, polynom> B(SIZE);
	HashTable<string, polynom> C(SIZE);

	while (c != 1)
	{
		system("cls");
		cout << "Chouse operation" << endl;
		cout << "1: Insert" << endl;
		cout << "2: Delete" << endl;
		cout << "3: Search" << endl;
		cin >> k;
		switch (k)
		{
	case 1:
		{
			string str;
			cout << "Write polynom" << endl;
			cin >> str;
			polynom a(str);
			A.Insert(str, a);
			B.Insert(str, a);
			C.Insert(str, a);
			cout << "ScanTable :" << endl;
			cout << A << endl;
			cout << "OrdTab :" << endl;
			cout << B << endl;
			cout << "Hash :" << endl;
			cout << C << endl;
			break;
		}
	case 2:
		{
			string str;
			cout << "Write polynom" << endl;
			cin >> str;
			polynom a(str);
			A.Delete(str);
			B.Delete(str);
			C.Delete(str);
			cout << "ScanTable :" << endl;
			cout << A << endl;
			cout << "OrdTab :" << endl;
			cout << B << endl;
			cout << "Hash :" << endl;
			cout << C << endl;
			break;
		}
		case 3:
		{
			string str;
			cout << "Write polynom" << endl;
			cin >> str;
			polynom a(str);
			if (A.Search(str) == NULL)
				cout << "error: ne found" << endl;
			else cout << " Found " << A.Search(str)->Data << endl;
			if (B.Search(str) == NULL)
				cout << "error: ne found" << endl;
			else cout << " Found " << B.Search(str)->Data << endl;
			if (C.Search(str) == NULL)
				cout << "error: ne found" << endl;
			else cout << " Found " << C.Search(str)->Data << endl;
			break;
		}
		default:
		{
			cout << "error, choose again" << endl;
			break;
		}
		}

		cout << "Exit: 1" << endl;
		cin >> c;
	}
return 0;
}


	