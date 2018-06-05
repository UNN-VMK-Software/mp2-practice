#include "Function.h"
#include <iostream>
#include <string>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	string s, a;
	float Result;
	cout << "Введите выражение: " << endl;
	getline(cin, s);
	try
	{
		s = st::correct(s);
	}
	catch (const char*ex)
	{
		cout << endl << ex << endl;
		return;
	}
	a = st::postfix_form(s);
	try
	{
		Result = st::calculations(a);
	}
	catch (const char*ex)
	{
		cout << endl << ex << endl;
		return;
	}
	cout << endl << "Результат: " << s <<" = " << Result << endl;
}