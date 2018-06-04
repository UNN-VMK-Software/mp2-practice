#include "polinom.h"
#include <conio.h>
#include "unsorted_table.h"
#include "sorted_table.h"
#include "hash_table.h"
void main()
{
	cout << "Select:" << endl<<endl;
	char c = 0, str;
	UnsortedTable<Polinom> T1;
	SortedTable<Polinom> T2;
	HashTable<Polinom> T3;
	string k;
	Polinom P;

	while (c != 27)
	{
		cout << "1. Insert   2. Delete   3. Search   4.Show" << endl;
		cin >> str;
		switch (str)
		{
		case '1':
		{
			cout << "Enter polinom:" << endl;
			getline(cin, k);
			if (k == "")
				getline(cin, k);
			P = Polinom(k);
			try
			{
				T1.Insert(P, k);
				T3.Insert(P, k);
				T2.Insert(P, k);
			}
			catch (...)
			{
				cout << "error" << endl;
			}
			break;
		}

		case '2':
		{
			cout << "Enter polinom:" << endl;
			getline(cin, k);
			if (k == "")
				getline(cin, k);
			try
			{
				T1.Delete(k);
				T2.Delete(k);
				T3.Delete(k);
			}
			catch (...)
			{
				cout << "not found" << endl;
			}
			break;
		}
		case '3':
		{
			cout << "Enter polinom:" << endl;
			getline(cin, k);
			if (k == "")
				getline(cin, k);
			try
			{
				cout << "UnsortedTable: " << endl << T1 << endl;
				cout << "-------------------------" << endl;
				cout << "Search in UnsortedTable: " << *(T1.Search(k)) << endl;
				cout << "-------------------------" << endl;
				cout << "SortedTable:" << endl << T2 << endl;
				cout << "-------------------------" << endl;
				cout << "Search in SortedTable: " << *(T2.Search(k)) << endl;
				cout << "-------------------------" << endl;
				cout << "HashTable:" << endl << T3 << endl << endl;
				cout << "-------------------------" << endl;
				cout << "Search in HashTable: " << *(T3.Search(k)) << endl;
				cout << "-------------------------" << endl;
			}
			catch (...)
			{
				cout << "not found" << endl;
			}
			break;
		}
		case '4':
		{
			cout << "UnsortedTable: " << endl << T1 << endl;
			cout << "-------------------------" << endl;
			cout << "SortedTable:" << endl << T2 << endl;
			cout << "-------------------------" << endl;
			cout << "HashTable:" << endl << T3 << endl << endl;
			cout << "-------------------------" << endl;
		}
		default:
			cout << "try again" << endl;
		}
		cout << "press esc to exit and any key to continue" << endl;
		c = _getch();
	}
}