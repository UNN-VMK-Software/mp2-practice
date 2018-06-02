#ifndef TINFIXTOPOLISH
#define TINFIXTOPOLISH
#include <iostream>
#include "TStack.h"
#include "TList.h"
#include <string>
#include  <map>
using namespace std;


class TInfixToPolish{
	private:
		static int GetOperation(char); //Получить приоритет операции
		static map<char, float> ReadValue(string); //Формирование контейнера типа map,где ключ-символ операнда,a значение-значение операнда
	public:
		static void Calk(string); // Вычисление арифметического выражения
		static string InfixToPolish(string); //Перевод арифметического выражения в постфиксную форму
		static bool Brace(string); //Совпадает ли количество открывающихся и закрывающихся скобок?!
		static bool Protect(string); // Правильно ли введена строка?!
};

#endif