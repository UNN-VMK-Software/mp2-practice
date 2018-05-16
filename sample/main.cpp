#include "polynom.h"
#include "hashtable.h"
#include "sortedtable.h"
#include <iostream>
#include <sstream>

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
	string k, k1;
	stringstream b;


	do {

		if (yn == "1")
		{
			system("cls");

			b << res;
			k = b.str();  

			try
			{
				scant.Insert(k, res);
				sortt.Insert(k, res);
				hasht.Insert(k, res);
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

			cout << "Add polynom" << endl << "Enter the polynom: ";					
			cin >> polynom;
			cout << endl;
			p = polynom;
			k = polynom; 

			try
			{
				scant.Insert(k, p);
				sortt.Insert(k, p);
				hasht.Insert(k, p);
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
			cin >> k;
			
			try
			{
				scant.Delete(k);
				sortt.Delete(k);
				hasht.Delete(k);
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
			cin >> k;

			try
			{
				cout << *(scant.Search(k)) << endl;
				cout << *(sortt.Search(k)) << endl;
				cout << *(hasht.Search(k)) << endl;
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
			cin >> k;
			cout << "Enter the key of the second polynom: ";
			cin >> k1;

			try
			{
				res = *(sortt.Search(k)) + *(sortt.Search(k1));
				cout << endl << *(sortt.Search(k)) << '+' << *(sortt.Search(k1)) << '=' << res << endl;

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
			cin >> k;
			cout << "Enter the key of the second polynom: ";
			cin >> k1;

			try
			{
				res = *(sortt.Search(k)) - *(sortt.Search(k1));
				cout << *(sortt.Search(k)) << '-' << *(sortt.Search(k1)) << '=' << res << endl;

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
			cin >> k;
			cout << "Enter the key of the second polynom: ";
			cin >> k1;

			try
			{
				res = *(sortt.Search(k)) * *(sortt.Search(k1));
				cout << endl << *(sortt.Search(k)) << '*' << *(sortt.Search(k1)) << '=' << res << endl;

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