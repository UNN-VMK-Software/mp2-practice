#include "polinom.h"
#include <conio.h>
#include "scan_table.h"
#include "sorted_table.h"
#include "hash_table.h"
void main()
{
	cout << "Input correct polinoms" << endl;
	cout << "You can insert/delete and find in tables" << endl;
	char c = 0, str;
	ScanTable<Polinom> Tab1;
	SortedTable<Polinom> Tab2;
	HashTable<Polinom> Tab3;
	string key;
	Polinom P;

	while (c != ' ')
	{/*
		cout << "ScanTable: " << endl << Tab1 << endl;
		cout << "-------------------------" << endl;
		cout << "SortedTable:" << endl << Tab2 << endl;
		cout << "-------------------------" << endl;
		cout << "HashTable:" << endl << Tab3 << endl << endl;
		cout << "-------------------------" << endl;*/
		cout << "1. Insert   2. Delete   3. Search   4.Show" << endl;
		cin >> str;
		switch (str)
		{
			case '1':
			{
				cout << "Enter polinom:" << endl;
				getline(cin, key);
				if (key == "")
					getline(cin, key);
				P = Polinom(key);
				try
				{
					Tab1.Insert(key, P);
					Tab2.Insert(key, P);
					Tab3.Insert(key, P);
				}
				catch (...)
				{
					cout << "Error" << endl;
				}/*
				cout << "ScanTable: " << endl << Tab1 << endl;
				cout << "-------------------------" << endl;
				cout << "SortedTable:" << endl << Tab2 << endl;
				cout << "-------------------------" << endl;
				cout << "HashTable:" << endl << Tab3 << endl << endl;
				cout << "-------------------------" << endl;*/
				break;
			}
			
			case '2':
			{
				cout << "Enter polinom:" << endl;
				getline(cin, key);
				if (key == "")
					getline(cin, key);
				try
				{
					Tab1.Delete(key);
					Tab2.Delete(key);
					Tab3.Delete(key);
				}
				catch (...)
				{
					cout << "Error" << endl;
				}/*
				cout << "ScanTable: " << endl << Tab1 << endl;
				cout << "-------------------------" << endl;
				cout << "SortedTable:" << endl << Tab2 << endl;
				cout << "-------------------------" << endl;
				cout << "HashTable:" << endl << Tab3 << endl << endl;
				cout << "-------------------------" << endl;*/
				break;
			}
			case '3':
			{
				cout << "Enter polinom:" << endl;
				getline(cin, key);
				if (key == "")
					getline(cin, key);
				try
				{
					cout << "ScanTable: " << endl << Tab1 << endl;
					cout << "-------------------------" << endl;
					cout << "Search in ScanTable: " << Tab1.Search(key) << endl;
					cout << "-------------------------" << endl;
					cout << "SortedTable:" << endl << Tab2 << endl;
					cout << "-------------------------" << endl;
					cout << "Search in SortedTable: " << Tab2.Search(key) << endl;
					cout << "-------------------------" << endl;
					cout << "HashTable:" << endl << Tab3 << endl << endl;
					cout << "-------------------------" << endl;
					cout << "Search in HashTable: " << Tab3.Search(key) << endl;
					cout << "-------------------------" << endl;
				}
				catch (...)
				{
					cout << "Error" << endl;
				}
				break;
			}
			case '4':
			{
				cout << "ScanTable: " << endl << Tab1 << endl;
				cout << "-------------------------" << endl;
				cout << "SortedTable:" << endl << Tab2 << endl;
				cout << "-------------------------" << endl;
				cout << "HashTable:" << endl << Tab3 << endl << endl;
				cout << "-------------------------" << endl;
			}
			default:
				cout << "try again" << endl;
		}
		cout << "Press SPACE to exit" << endl;
		cout << "Press any key to enter" << endl;
		c = _getch();
	}
}