#include "postfix.h"
#include "Stack.h"
#include <string>
#include <iostream>

using namespace std;

int postfix::GetOperationPtr(char op) {
	int Ptr;
	switch (op) {
	case '*':
	case '/': Ptr = 3; break;
	case '+':
	case '-': Ptr = 2; break;
	case '(': Ptr = 1; break;
	case '=': Ptr = 0; break;
	default: Ptr = -1;
	}
	return Ptr;
}

int postfix::IsOperation(char op) {
	if (op == '+' || op == '-' || op == '*' || op == '/' || op == '=') return 1;
	else return 0;
}

bool postfix::Operand(const char Exp) {
	if ((Exp >= 65) && (Exp <= 90)) {
		return true;
	}
	else if (((Exp >= 40) && (Exp <= 43)) || (Exp == 45) || (Exp == 47) || (Exp == 61)) {
		return false;
	}
	throw "Wrong operation " + Exp;
}

float postfix::calc_op(float one, float two, char op) {
	switch (op) {
	case '+':
		return (one + two);
	case '-':
		return (one - two);
	case '*':
		return (one * two);
	case '/':
		if (two == 0)
		{
			throw "Ошибка! Деление на ноль!\n";
		}
		else return (one / two);
	default:
		return -1;
	}
}

char* postfix::ConvertToPolish(char *InfixExp, int len) {
	char ch, t, *PolishExp = new char[strlen(InfixExp) + 1];
	int pos = 0;	//индекс текущего символа в выражении
	Stack<char> PolishStack, OperationStack;
	bool key;
	do {
		ch = InfixExp[pos++];
		if (isalpha(ch)) PolishStack.Push(ch);
		else if (ch == '(') OperationStack.Push(ch);
		else if (ch == ')') {
			while (1) {
				t = OperationStack.Pop();
				if (t == '(') break;
				PolishStack.Push(t);
			}
		}
		else if (IsOperation(ch)) {
			while (!OperationStack.IsEmpty()) {
				t = OperationStack.Pop();
				if (GetOperationPtr(ch) <= GetOperationPtr(t)) PolishStack.Push(t);
				else { OperationStack.Push(t); break; }
			}
			OperationStack.Push(ch);
		}
	} while ((ch != '=') && (pos < len));
	pos = 0;
	for (int i = 0; i < len; i++)
		if ((InfixExp[i] != '(') && (InfixExp[i] != ')')) pos++;
	PolishExp[pos] = '\0';
	PolishExp[--pos] = '=';
	while (!PolishStack.IsEmpty()) PolishExp[--pos] = PolishStack.Pop();
	return PolishExp;
}

float postfix::ConvertToInfix(char *Exp, int l) {
	Exp[l - 1] = '\0';
	l--;
	map<char, float> nums;
	for (size_t i = 0; i < l; i++) {
		if (postfix::Operand(Exp[i]) && nums.count(Exp[i]) == 0) {
			float var;
			cout << "Введите значение переменной: " << Exp[i] << " = ";
			cin >> var;
			nums.insert(pair<char, float>(Exp[i], var));
		}

	}
	Stack<float> end_list;
	for (int i = 0; i < l; i++) {
		char element = Exp[i];
		if (postfix::Operand(element)) {
			end_list.Push(nums[element]);
		}
		else {
			double two = end_list.Pop();
			double one = end_list.Pop();
			/* try {
				//float a = calc_op(one, two, element);
				end_list.Push(calc_op(one, two, element));
			}
			catch(const char* error) {
				cout << error << endl;
			} */
			end_list.Push(calc_op(one, two, element));
		}
	}
	return end_list.Pop();
}
