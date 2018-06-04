#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <Windows.h>
#include "HashTable.h"
#include "ScanTable.h"
#include "SortedTable.h"
#include "Polinoms.h"
#include "TMonom.h"



//int main() {
//	system("color 0F");
//	std::string s;
//	TPolinom zero("");
//	std::vector<TPolinom> Vector_of_Polinoms;
//	TPolinom temp1("-50xy^3+xyz+4zxy-5y+y+z");
//	Vector_of_Polinoms.push_back(temp1);
//	TPolinom temp2("25x^2-34y^2z^6x^4");
//	Vector_of_Polinoms.push_back(temp2);
//	TPolinom temp3("58x^1y^2z^3");
//	Vector_of_Polinoms.push_back(temp3);
//	int menu = 1;
//	int nPolinoms = 1;
//	int a, b, c;
//	std::cout << "Menu:" << endl;
//	std::cout << "1. Add new polinom" << endl;
//	std::cout << "2. Delete existing polinom" << endl;
//	std::cout << "3. Sum two polinoms" << endl;
//	std::cout << "4. Multiple two polinoms" << endl;
//	std::cout << "5. Multiple polinom on number" << endl;
//	std::cout << "6. Print polinom" << endl;
//	std::cout << "7. Sum two polinoms (+=)" << endl;
//	std::cout << "8. Substract two polinoms" << endl;
//	std::cin >> menu;
//	while (menu < 9 && menu > 0)
//	{
//		switch (menu)
//		{
//		case 1: 
//		{
//			std::cout << "Enter your polinom. It must be like '25x^2+34x^2y^8z^4' " << std::endl;
//			std::cin >> s;
//			TPolinom temp1(s);
//			Vector_of_Polinoms.push_back(temp1);
//			nPolinoms++;
//			std::cout << "Menu:" << endl;
//			std::cout << "1. Add new polinom" << endl;
//			std::cout << "2. Delete existing polinom" << endl;
//			std::cout << "3. Sum two polinoms" << endl;
//			std::cout << "4. Multiple two polinoms" << endl;
//			std::cout << "5. Multiple polinom on number" << endl;
//			std::cout << "6. Print polinom" << endl;
//			std::cout << "7. Sum two polinoms (+=)" << endl;
//			std::cout << "8. Substract two polinoms" << endl;
//			std::cin >> menu;
//			break; 
//		}
//		case 2:
//			do {
//				std::cout << "Enter number of the polinom you want to delete " << std::endl;
//				std::cin >> a;
//			} while (a < 0 || a > Vector_of_Polinoms.size());
//			Vector_of_Polinoms[a]=zero;
//			std::cout << "Menu:" << endl;
//			std::cout << "1. Add new polinom" << endl;
//			std::cout << "2. Delete existing polinom" << endl;
//			std::cout << "3. Sum two polinoms" << endl;
//			std::cout << "4. Multiple two polinoms" << endl;
//			std::cout << "5. Multiple polinom on number" << endl;
//			std::cout << "6. Print polinom" << endl;
//			std::cout << "7. Sum two polinoms (+=)" << endl;
//			std::cout << "8. Substract two polinoms" << endl;
//			std::cin >> menu;
//			break;
//		case 3:
//			do {
//				std::cout << "Enter number of the first polinom you want to sum " << std::endl;
//				std::cin >> a;
//			} while (a < 0 || a > Vector_of_Polinoms.size());
//			do {
//				std::cout << "Enter number of the second polinom you want to sum " << std::endl;
//				std::cin >> b;
//			} while (b < 0 || b > Vector_of_Polinoms.size());
//			do {
//				std::cout << "Enter number of the polinom you want to save the result. If you dont want to save, enter '-1' " << std::endl;
//				std::cin >> c;
//			} while (c < -1 || c > (int)Vector_of_Polinoms.size());
//			if (c == -1)
//			{
//				TPolinom res;
//				res = Vector_of_Polinoms[a] + Vector_of_Polinoms[b];
//				std::cout << res;
//			}
//			else if (c > -1)
//				Vector_of_Polinoms[c] = Vector_of_Polinoms[a] + Vector_of_Polinoms[b];
//			std::cout << "Menu:" << endl;
//			std::cout << "1. Add new polinom" << endl;
//			std::cout << "2. Delete existing polinom" << endl;
//			std::cout << "3. Sum two polinoms" << endl;
//			std::cout << "4. Multiple two polinoms" << endl;
//			std::cout << "5. Multiple polinom on number" << endl;
//			std::cout << "6. Print polinom" << endl;
//			std::cout << "7. Sum two polinoms (+=)" << endl;
//			std::cout << "8. Substract two polinoms" << endl;
//			std::cin >> menu;
//			break;
//		case 4:
//			do {
//				std::cout << "Enter number of the first polinom you want to multiple " << std::endl;
//				std::cin >> a;
//			} while (a < 0 || a > Vector_of_Polinoms.size());
//			do {
//				std::cout << "Enter number of the second polinom you want to multiple " << std::endl;
//				std::cin >> b;
//			} while (b < 0 || b > Vector_of_Polinoms.size());
//			do {
//				std::cout << "Enter number of the polinom you want to save the result. If you dont want to save, enter '-1' " << std::endl;
//				std::cin >> c;
//			} while (c < -1 || c > (int)Vector_of_Polinoms.size());
//			if (c == -1)
//			{
//				TPolinom res;
//				res = Vector_of_Polinoms[a] * Vector_of_Polinoms[b];
//				std::cout << res;
//			}
//			else if (c > -1)
//				Vector_of_Polinoms[c] = Vector_of_Polinoms[a] * Vector_of_Polinoms[b];
//			std::cout << "Menu:" << endl;
//			std::cout << "1. Add new polinom" << endl;
//			std::cout << "2. Delete existing polinom" << endl;
//			std::cout << "3. Sum two polinoms" << endl;
//			std::cout << "4. Multiple two polinoms" << endl;
//			std::cout << "5. Multiple polinom on number" << endl;
//			std::cout << "6. Print polinom" << endl;
//			std::cout << "7. Sum two polinoms (+=)" << endl;
//			std::cout << "8. Substract two polinoms" << endl;
//			std::cin >> menu;
//			break;
//		case 5:
//			double d;
//			do {
//				std::cout << "Enter number of the first polinom you want to multiple " << std::endl;
//				std::cin >> a;
//			} while (a < 0 || a > Vector_of_Polinoms.size());
//			std::cout << "Enter number you want your polinom to multiple" << std::endl;
//			std::cin >> d;
//			do {
//				std::cout << "Enter number of the polinom you want to save the result. If you dont want to save, enter '-1' " << std::endl;
//				std::cin >> c;
//			} while (c < -1 || c > (int)Vector_of_Polinoms.size());
//			if (c == -1)
//			{
//				TPolinom res;
//				res = Vector_of_Polinoms[a] * d;
//				std::cout << res;
//			}
//			else if (c > -1)
//				Vector_of_Polinoms[c] = Vector_of_Polinoms[a] * d;
//			std::cout << "Menu:" << endl;
//			std::cout << "1. Add new polinom" << endl;
//			std::cout << "2. Delete existing polinom" << endl;
//			std::cout << "3. Sum two polinoms" << endl;
//			std::cout << "4. Multiple two polinoms" << endl;
//			std::cout << "5. Multiple polinom on number" << endl;
//			std::cout << "6. Print polinom" << endl;
//			std::cout << "7. Sum two polinoms (+=)" << endl;
//			std::cout << "8. Substract two polinoms" << endl;
//			std::cin >> menu;
//			break;
//		case 6:
//			for(auto polinom : Vector_of_Polinoms)
//				std::cout << "Polinom = " << polinom;
//			std::cout << "Menu:" << endl;
//			std::cout << "1. Add new polinom" << endl;
//			std::cout << "2. Delete existing polinom" << endl;
//			std::cout << "3. Sum two polinoms" << endl;
//			std::cout << "4. Multiple two polinoms" << endl;
//			std::cout << "5. Multiple polinom on number" << endl;
//			std::cout << "6. Print polinom" << endl;
//			std::cout << "7. Sum two polinoms (+=)" << endl;
//			std::cout << "8. Substract two polinoms" << endl;
//			std::cin >> menu;
//			break;
//		case 7:
//			do {
//				std::cout << "Enter number of the first polinom you want to sum from 0 to" << Vector_of_Polinoms.size() << std::endl;
//				std::cin >> a;
//			} while (a < 0 || a > Vector_of_Polinoms.size());
//			do {
//				std::cout << "Enter number of the second polinom you want to sum from 0 to" << Vector_of_Polinoms.size() << std::endl;
//				std::cin >> b;
//			} while (b < 0 || b > Vector_of_Polinoms.size());
//			Vector_of_Polinoms[a] += Vector_of_Polinoms[b];
//			std::cout << "Menu:" << endl;
//			std::cout << "1. Add new polinom" << endl;
//			std::cout << "2. Delete existing polinom" << endl;
//			std::cout << "3. Sum two polinoms" << endl;
//			std::cout << "4. Multiple two polinoms" << endl;
//			std::cout << "5. Multiple polinom on number" << endl;
//			std::cout << "6. Print polinom" << endl;
//			std::cout << "7. Sum two polinoms (+=)" << endl;
//			std::cout << "8. Substract two polinoms" << endl;
//			std::cin >> menu;
//			break;
//		case 8:
//			do {
//				std::cout << "Enter number of the first polinom you want to sum " << std::endl;
//				std::cin >> a;
//			} while (a < 0 || a > Vector_of_Polinoms.size());
//			do {
//				std::cout << "Enter number of the second polinom you want to sum " << std::endl;
//				std::cin >> b;
//			} while (b < 0 || b > Vector_of_Polinoms.size());
//			do {
//				std::cout << "Enter number of the polinom you want to save the result. If you dont want to save, enter '-1' " << std::endl;
//				std::cin >> c;
//			} while (c < -1 || c >(int)Vector_of_Polinoms.size());
//			if (c == -1)
//			{
//				TPolinom res;
//				res = Vector_of_Polinoms[a] - Vector_of_Polinoms[b];
//				std::cout << res;
//			}
//			else if (c > -1)
//				Vector_of_Polinoms[c] = Vector_of_Polinoms[a] - Vector_of_Polinoms[b];
//			std::cout << "Menu:" << endl;
//			std::cout << "1. Add new polinom" << endl;
//			std::cout << "2. Delete existing polinom" << endl;
//			std::cout << "3. Sum two polinoms" << endl;
//			std::cout << "4. Multiple two polinoms" << endl;
//			std::cout << "5. Multiple polinom on number" << endl;
//			std::cout << "6. Print polinom" << endl;
//			std::cout << "7. Sum two polinoms (+=)" << endl;
//			std::cout << "8. Substract two polinoms" << endl;
//			std::cin >> menu;
//			break;
//		default:exit(1);
//		}
//	}
//	return 0;
//}

int main()
{
	system("color 0F");
	ScanTable<std::string, TPolinom> Table1(2);
	SortedTable<std::string, TPolinom> Table2(2);
	HashTable<TPolinom> Table3(2);
	int menu;
	std::cout << "Menu:" << endl;
	std::cout << "1. Search" << endl;
	std::cout << "2. Insert" << endl;
	std::cout << "3. Delete" << endl;
	std::cin >> menu;
	while (menu >= 1 && menu <= 3)
	{
		switch (menu)
		{
		case 1:
		{
			std::cout << "Scan Table: " << endl;
			std::cout << Table1;
			std::cout << endl;
			std::cout << "Sorted Table: " << endl;
			std::cout << Table2;
			std::cout << endl;
			std::cout << "Hash Table: " << endl;
			std::cout << Table3;
			std::cout << endl;
			std::cout << "Type polinom you want to search" << endl;
			std::string s;
			cin >> s;
			TPolinom *res = Table1.Search(s);
			if (res != nullptr)
				std::cout << "Polinom was found in Scan Table" << endl;
			else std:cout << "There is no such polinom in Scan Table" << endl;
			res = Table2.Search(s);
			if (res != nullptr)
				std::cout << "Polinom was found in Sorted Table" << endl;
			else std::cout << "There is no such polinom in Sorted Table" << endl;
			res = Table3.Search(s);
			if (res != nullptr)
				std::cout << "Polinom was found in Hash Table" << endl;
			else std::cout << "There is no such polinom in Hash Table" << endl;
			std::cout << "Menu:" << endl;
			std::cout << "1. Search" << endl;
			std::cout << "2. Insert" << endl;
			std::cout << "3. Delete" << endl;
			cin >> menu;
			break;
		}
		case 2: {
			std::cout << "Type polinom you want to insert" << endl;
			std::string s;
			cin >> s;
			TPolinom *rec = new TPolinom(s);
			Table1.Insert(s, rec);
			Table2.Insert(s, rec);
			Table3.Insert(s, rec);
			std::cout << "Scan Table: " << endl;
			std::cout << Table1;
			std::cout << endl;
			std::cout << "Sorted Table: " << endl;
			std::cout << Table2;
			std::cout << endl;
			std::cout << "Hash Table: " << endl;
			std::cout << Table3;
			std::cout << endl;
			std::cout << "Menu:" << endl;
			std::cout << "1. Search" << endl;
			std::cout << "2. Insert" << endl;
			std::cout << "3. Delete" << endl;
			cin >> menu;
			break;
		}
		case 3: {
			std::cout << "Type polinom you want to delete" << endl;
			std::string s;
			cin >> s;
			TPolinom *res = Table1.Search(s);
			if (res == nullptr)
				std::cout << "There is no such polinom in Scan Table" << endl;
			else 
				Table1.Delete(s);
			res = Table2.Search(s);
			if (res == nullptr)
				std::cout << "There is no such polinom in Sorted Table" << endl;
			else 
			Table2.Delete(s);
			try {
				Table3.Delete(s);
			}
			catch (const char* ex)
			{
				std::cout << "Trying to delete nonexisting or already deleted record" << std::endl;
			}
			std::cout << "Scan Table: " << endl;
			std::cout << Table1;
			std::cout << endl;
			std::cout << "Sorted Table: " << endl;
			std::cout << Table2;
			std::cout << endl;
			std::cout << "Hash Table: " << endl;
			std::cout << Table3;
			std::cout << endl;
			std::cout << "Menu:" << endl;
			std::cout << "1. Search" << endl;
			std::cout << "2. Insert" << endl;
			std::cout << "3. Delete" << endl;
			cin >> menu;
			break;
		}
		}

	}
}