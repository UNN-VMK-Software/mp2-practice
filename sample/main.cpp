#include "polynom.h"
#include "hashtable.h"
#include "sortedtable.h"
#include <iostream>

char main_menu()
{
	system("cls");
	char res;
	
	cout << "1. Display tables" << endl;
	cout << "2. Add polynom" << endl;
	cout << "3. Delete polynom" << endl;
	cout << "4. Find polynom" << endl;
	cout << endl;
	cout << "Operations with polynoms: "<< endl;
	cout << "5. Addition" << endl;
	cout << "6. Substraction" << endl;
	cout << "7. Multiplication" << endl;
	cout << endl;
	cout << "8. Exit" << endl;
	cout << endl;
	cout << "Choose menu item: ";
	cin >> res;
	return res;
}

void main() {
	char pmenu;
	scantable<polynom> scant;
	sortedtable<polynom> sortt;
	hashtable<polynom>hasht;
	polynom p, res;
	string polynom, yn;
	string k1, k2;

	do {

		if (yn == "1")
		{
			system("cls");

			cout << "Polynom: " << res << endl << "Enter the key: ";
			cin >> k1;
			 
			try
			{
				scant.Insert(k1, res);
				sortt.Insert(k1, res);
				hasht.Insert(k1, res);
			}
			catch (...)
			{
				cout << "Repeated key" << endl << endl;
			}
		}

		yn = "";

		pmenu = main_menu();
		
		switch (pmenu)
		{
		case '1':
		{
			system("cls");

			cout << endl;
			cout << "Scantable" << endl << scant << endl;
			cout << "Sortedtable" << endl << sortt << endl;
			cout << "Hashtable" << endl << hasht << endl;

			system("pause");
			break;
		}
		case '2':
		{
			system("cls");

			cout << "Add polynom" << endl << "Enter the key: ";			
			cin >> k1;
			cout << "Enter the polynom: ";
			cin >> polynom;
			cout << endl;
			p = polynom;

			try
			{
				scant.Insert(k1, p);
				sortt.Insert(k1, p);
				hasht.Insert(k1, p);
			}
			catch (...)
			{
				cout << "Repeated key" << endl << endl;
			}

			system("pause");
			break;
		}
		case '3':
		{
			system("cls");

			cout << "Delete polynom" << endl << "Enter the key: ";
			cin >> k1;
			
			try
			{
				cout <<"Polynom: "<< sortt.Search(k1) << endl;

				scant.Delete(k1);
				sortt.Delete(k1);
				hasht.Delete(k1);
			}
			catch (...)
			{
				cout << endl << "Key not found" << endl << endl;
			}

			system("pause");
			break;
		}
		case '4':
		{
			system("cls");

			cout << "Find polynom" << endl<< "Enter the key: ";
			cin >> k1;

			try
			{
				cout << sortt.Search(k1) << endl;
			}
			catch (...)
			{
				cout << endl << "Key not found" << endl << endl;
			}

			system("pause");
			break;
		}
		case '5':
		{
			system("cls");

			cout << "Enter the key of the first polynom: ";
			cin >> k1;
			cout << "Enter the key of the second polynom: ";
			cin >> k2;

			try
			{
				res = sortt.Search(k1) + sortt.Search(k2);
				cout << endl << sortt.Search(k1) << '+' << sortt.Search(k2) << '=' << res << endl;

				cout << endl << "Save polynom?" << endl << " 1) Yes" << endl << " 2) No" << endl << "Your choice: " << endl;
				cin >> yn;
			}
			catch (...)
			{
				cout << endl << "Key not found" << endl << endl;
			}
			
			system("pause");
			break;
		}

		case '6':
		{
			system("cls");

			cout << "Enter the key of the first polynom: ";
			cin >> k1;
			cout << "Enter the key of the second polynom: ";
			cin >> k2;

			try
			{
				res = sortt.Search(k1) - sortt.Search(k2);
				cout << sortt.Search(k1) << '-' << sortt.Search(k2) << '=' << res << endl;

				cout << endl << "Save polynom?" << endl << " 1) Yes" << endl << " 2) No" << endl << "Your choice: " << endl;
				cin >> yn;
			}
			catch (...)
			{
				cout << endl << "Key not found" << endl << endl;
			}

			system("pause");
			break;
		}
		case '7':
		{
			system("cls");

			cout << "Enter the key of the first polynom: ";
			cin >> k1;
			cout << "Enter the key of the second polynom: ";
			cin >> k2;

			try
			{
				res = sortt.Search(k1) * sortt.Search(k2);
				cout << endl << sortt.Search(k1) << '*' << sortt.Search(k2) << '=' << res << endl;

				cout << endl << "Save polynom?" << endl << " 1) Yes" << endl << " 2) No" << endl << "Your choice: " << endl;
				cin >> yn;
			}
			catch (...)
			{
				cout << endl << "Key not found" << endl << endl;
			}

			system("pause");
			break;
		}
		case '8': break;			
		}
	} while (pmenu != '8');
}