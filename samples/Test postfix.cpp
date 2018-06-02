#include <iostream>
#include <algorithm>
#include <locale.h>
#include "TInfixToPolish.h"
#include <string>
#include <conio.h>
using namespace std;


void main(){
	setlocale(LC_CTYPE, "russian");
	string str;
	cout << " Введите арифметическое выражение: "<<endl;
	try {
		getline(cin, str);
		transform(str.begin(), str.end(), str.begin(), tolower);
		cout << " Запись исходной строки в нижнем регистре " << endl;
		cout << str << endl;
		while ((!TInfixToPolish::Brace(str))||(!TInfixToPolish::Protect(str)))
		{
			cout << " Повторите ввод ";
			getline(cin, str);
		}
		str = TInfixToPolish::InfixToPolish(str);
		cout << " Постфиксная форма: " << str << endl;
		TInfixToPolish::Calk(str);
	}
	catch (const char* exeption)
	{
		cerr << exeption << endl;
	}
	std::system("pause");
}