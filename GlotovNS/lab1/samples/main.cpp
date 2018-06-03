#include <iostream>
#include <string>
#include <locale.h>
#include "Postfix.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Перевод символьного арифметического выражения из инфиксной формы в постфиксную" << endl;
	cout << "Введите инфиксионнную форму выражения: " << endl;
	string expression;
	cin >> expression;
	string notation;
	float result;
	try {
		notation = Postfix::postfix_notation(expression);
		result = Postfix::postfix_calculation(notation);
	}
	catch (...)
	{
		cout << "Ошибка! Неверно введенное значение!" << endl;
		return 1;
	}
	cout << endl;
	cout << "Постфиксная форма: " << notation << endl;
	cout << "Результат: " << result << endl;
	system("pause");
}
