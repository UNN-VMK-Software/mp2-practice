#pragma once
#include "Polynom.h"
#include "HashTable.h"
#include "SortTable.h"
#include <iostream>
#include <sstream>

char main_menu()
{
	system("cls");
	char f;

	cout << "1.View Tables." << endl;
	cout << "2. Add polynom in Tables." << endl;
	cout << "3. Delete polynom from Tables." << endl;
	cout << "4. Find polynom in Tables." << endl;
	cout << endl;
	cout << "What do with polynoms: " << endl;
	cout << "5. Add." << endl;
	cout << "6. Sub." << endl;
	cout << "7. Mult." << endl;
	cout << endl;
	cout << "8. Exit." << endl;
	cin >> f;
	return f;
}

void main() {
	char pmenu;
	ScanTable<Polynom> scantable;
	SortTable<Polynom> sorttable;
	HashTable<Polynom> hashtable;
	Polynom p, res;
	string polynom, pol;
	string k, k1;
	stringstream b;
	do {
		pol = "";
		pmenu = main_menu();
		switch (pmenu)
		{
		case '1':
		{
			system("cls");
			cout << endl;
			cout << "Scantable:" << endl << scantable << endl;
			cout << "Sorttable:" << endl << sorttable << endl;
			cout << "Hashtable:" << endl << hashtable << endl;
			system("pause");
			break;
		}
		case '2':
		{
			system("cls");
			cout << "Add polynom." << endl << "Enter the polynom: ";
			cin >> polynom;
			cout << endl;
			p = polynom;
			k = polynom;
			try
			{
				scantable.Insert(k, p);
				sorttable.Insert(k, p);
				hashtable.Insert(k, p);
			}
			catch (...)
			{
				cout << "Repeat key." << endl << endl;
			}
			system("pause");
			break;
		}
		case '3':
		{
			system("cls");
			cout << "Delete polynom." << endl << "Enter the key: ";
			cin >> k;
			try
			{
				scantable.Delete(k);
				sorttable.Delete(k);
				hashtable.Delete(k);
			}
			catch (...)
			{
				cout << endl << "Key not found." << endl << endl;
			}
			system("pause");
			break;
		}
		case '4':
		{
			system("cls");
			cout << "Find polynom." << endl << "Enter the key: ";
			cin >> k;

			if(scantable.Search(k)!=NULL)
			{
				cout << *(scantable.Search(k)) << endl;
				cout << *(sorttable.Search(k)) << endl;
				cout << *(hashtable.Search(k)) << endl;
			}
			else
			{
				cout << endl << "Key not found." << endl << endl;
			}
			system("pause");
			break;
		}
		case '5':
		{
			system("cls");
			cout << "Enter the key one polynom: ";
			cin >> k;
			cout << "Enter the key second polynom: ";
			cin >> k1;
			if((sorttable.Search(k)!=NULL)&&(sorttable.Search(k1)!=NULL))
			{
				res = *(sorttable.Search(k)) + *(sorttable.Search(k1));
				cout << endl << *(sorttable.Search(k)) << '+' << *(sorttable.Search(k1)) << '=' << res << endl;

				cout << endl << "Save polynom?" << endl << " 1) Yes." << endl << " 2) No." << endl;
				cin >> pol;
			}
			else
			{
				cout << endl << "Key not found" << endl;
			}
			system("pause");
			break;
		}
		case '6':
		{
			system("cls");
			cout << "Enter the key one polynom: ";
			cin >> k;
			cout << "Enter the key second polynom: ";
			cin >> k1;
			if ((sorttable.Search(k) != NULL) && (sorttable.Search(k1) != NULL))
			{
				res = *(sorttable.Search(k)) - *(sorttable.Search(k1));
				cout << *(sorttable.Search(k)) << '-' << *(sorttable.Search(k1)) << '=' << res << endl;
				cout << endl << "Save polynom?" << endl << " 1) Yes." << endl << " 2) No." << endl;
				cin >> pol;
			}
			else
			{
				cout << endl << "Key not found." << endl << endl;
			}
			system("pause");
			break;
		}
		case '7':
		{
			system("cls");
			cout << "Enter the key one polynom: ";
			cin >> k;
			cout << "Enter the key second polynom: ";
			cin >> k1;
			if ((sorttable.Search(k) != NULL) && (sorttable.Search(k1) != NULL))
			{
				res = *(sorttable.Search(k)) * *(sorttable.Search(k1));
				cout << endl << *(sorttable.Search(k)) << '*' << *(sorttable.Search(k1)) << '=' << res << endl;

				cout << endl << "Save polynom?" << endl << " 1) Yes." << endl << " 2) No." << endl;
				cin >> pol;
			}
			else
			{
				cout << endl << "Key not found." << endl << endl;
			}
			system("pause");
			break;
		}
		case '8': break;
		}
		if (pol == "1")
		{
			system("cls");
			b << res;
			k = b.str();
			try
			{
				scantable.Insert(k, res);
				sorttable.Insert(k, res);
				hashtable.Insert(k, res);
			}
			catch (...)
			{
				cout << "Repeat key." << endl << endl;
				system("pause");
			}
		}
		b.str("");
	} while (pmenu != '8');
}