#include "scan_table.h"
#include "sorted_table.h"
#include "hash_table.h"
#include <iostream>
#include "polinom.h"



char main_menu()
{
	system("cls");

	char str;

	cout << "What will you do with tables?" << endl;
	cout << "1. Show tables" << endl;
	cout << "2. Insert" << endl;
	cout << "3. Delete" << endl;
	cout << "4. Search" << endl;
	cout << "5. Exit" << endl;
	cout << endl;
	cout << "Your choice: ";
	cin >> str;
	return str;
}

void main()
{	
	char pmenu;
	scantable<polynom> ScT;
	sortedtable<polynom> SrT;
	hashtable<polynom> HsT;

	polynom pol;
	string inp_pol;

	do {

		pmenu = main_menu();

		switch (pmenu)
		{
		case '1':
		{
			system("cls");
			cout << "ScanTable: " << endl << ScT << endl;
			cout << "SortTable: " << endl << SrT << endl;
			cout << "HashTable: " << endl << HsT << endl;
			cout << endl << endl;
			system("pause");
			break;
		}
		case '2':
		{
			system("cls");
			cout << "Input polynom: ";
			cin >> inp_pol;
			cout << endl;
			pol = inp_pol;
			try
			{
				ScT.Insert(inp_pol, pol);
				SrT.Insert(inp_pol, pol);
				HsT.Insert(inp_pol, pol);
			}
			catch (...)
			{
				cout << "This key has already been entered earlier" << endl << endl; 
			}
			system("pause");
			break;
		}
		case '3':
		{
			system("cls");

			cout << "Enter key: ";
			cin >> inp_pol;
			try
			{
				ScT.Delete(inp_pol);
				SrT.Delete(inp_pol);
				HsT.Delete(inp_pol);
			}
			catch (...)
			{
				cout << endl << "Key was not found" << endl << endl;
			}
			system("pause");
			break;
		}
		case '4':
		{
			system("cls");
			cout << "Enter key: ";
			cin >> inp_pol;
			try
			{
				cout << "Polynom with such key was found in scantable:    " << *(ScT.Search(inp_pol)) << endl;
				cout << "Polynom with such key was found in sortedtable:  " << *(SrT.Search(inp_pol)) << endl;
				cout << "Polynom with such key was found in hashtable:    " << *(HsT.Search(inp_pol)) << endl;
			}
			catch (...)
			{
				cout << endl << "Polynom with such key was not found" << endl;
			}
			system("pause");
			break;
		}
		}
	} while (pmenu != '5');
}