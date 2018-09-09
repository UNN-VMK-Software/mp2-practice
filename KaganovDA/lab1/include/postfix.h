#ifndef POLISH_POSTFIX_H
#define POLISH_POSTFIX_H

#include <iostream>
#include <string>
#include <map>

#include "Stack.h"
using namespace std;

class postfix
{
private:
	static int GetOperationPtr(char op);				//получить приоретет операции
	static int IsOperation(char op);					//проверка на знак операции
	static bool Operand(const char Exp);
	static float calc_op(float one, float two, char op);
public:
	/* static bool Operand(const char Exp);
	static float calc_op(float one, float two, char op); */
	static char* ConvertToPolish(char *Exp, int len);				//преобразование в польскую форму
	static float ConvertToInfix(char* Exp, int len);				//перевод из постфиксной формы и подсчёт выражения
};

#endif