#include <string>
#include "TInfixToPolish.h"
#include <locale.h>
using namespace std;

int TInfixToPolish::GetOperation(char op) //Получение приоритета операций
{   
	setlocale(LC_CTYPE, "russian");
	if (op == '!') return 0;
	if (((op >= 'A') && (op <= 'Z')) || ((op>= 'a') && (op <= 'z'))) return 5;
	if ((op == '/') || (op == '*')) return 3;
	if ((op == '+') || (op == '-')) return 2;
	if (op == '(') return 0;
	if (op == ')') return 4;
	throw" Ошибка!";
};


void TInfixToPolish::Calk(string string) //Вычисление арифметического выражения
{
	float op, op1, op2;
	TStack<float> Tstack;
	map<char, float> Vmap = ReadValue(string);
	float result;
	for (size_t i = 0; i < string.length(); i++)
	{
		if (((string[i] >= 'A') && (string[i] <= 'Z')) || ((string[i] >= 'a') && (string[i] <= 'z')))
		{
			op = Vmap[string[i]];
			Tstack.Push(op);
		}

		switch (string[i])
		{
		case'-':
		{
			op1 = Tstack.Pop();
			op2 = Tstack.Pop();
			result = op2 - op1;
			Tstack.Push(result);
			break;
		}
		case'+':
		{
			op1 = Tstack.Pop();
			op2 = Tstack.Pop();
			result = op2 + op1;
			Tstack.Push(result);
			break;
		}
		case'*':
		{
			op1 = Tstack.Pop();
			op2 = Tstack.Pop();
			result = op2*op1;
			Tstack.Push(result);
			break;
		}
		case'/':
		{
			op1 = Tstack.Pop();
			op2 = Tstack.Pop();
			result = op2 / op1;
			Tstack.Push(result);
			break;
		}
		}
	}
	cout << "Результат: " << Tstack.Pop() << endl;
}


string TInfixToPolish::InfixToPolish(string string) //Перевод в постфиксную форму
{
	TStack<char> result;
	TStack<char> Operation;
	char top;
	for (int i = 0; i < string.length(); i++)
	{
		if (((string[i] >= 'A') && (string[i] <= 'Z')) || ((string[i] >= 'a') && (string[i] <= 'z')))
		{
			result.Push(string[i]);
			continue;
		}
		if (string[i] == '(')
		{
			Operation.Push(string[i]);
			continue;
		}
		if (string[i] == ')')
		{
			while ((top = Operation.Pop()) != '(')
			{
				result.Push(top);
			}
			continue;
		}
		if (!Operation.Is_Empty())
		{
			top = Operation.Pop();
			if (GetOperation(string[i]) > GetOperation(top))
			{
				Operation.Push(top);
				Operation.Push(string[i]);
				continue;
			}
			else
			{
				Operation.Push(top);
				top = Operation.Pop();
				Operation.Push(top);
				while ((GetOperation(top) >= GetOperation(string[i])) && (!Operation.Is_Empty()))
				{
					Operation.Pop();
					result.Push(top);
					if (Operation.Is_Empty()) break;
					top = Operation.Pop();
					Operation.Push(top);
				}
				Operation.Push(string[i]);
				continue;
			}
		}
		else
		{
			Operation.Push(string[i]);
			continue;
		}
	}
	while (!Operation.Is_Empty())
	{
		char a = Operation.Pop();
		result.Push(a);
	}
	string = "";
	while (!result.Is_Empty())
	{
		char a = result.Pop();
		string = a + string;
	}
	
	return string;

};

bool TInfixToPolish::Brace(string a) //Совпадает ли количество открывающихся и закрывающихся скобок?!
{
	int	count = 0;
	bool flag = false;
	for (size_t i = 0; i < a.length(); i++)
	{
		if (a[i] == '(')
			count++;

		if (a[i] == ')')
			count--;
	}	

	return (count == 0);

};

bool TInfixToPolish::Protect(string st){ //Корректно ли введена строка?!
	if (st.length() == 0) return false;
	TInfixToPolish inf;
	if (st.length() == 1){
		if (inf.GetOperation(st[0])) return false;
	}
	char left;
	char right;
	int ptr = 0;
	for (int i, j = 1; j < st.length(); j++){
		i = ptr;
		left = st[i];
		right = st[j];
		if ((!inf.GetOperation(left)) && (!inf.GetOperation(right))) return false;
		if ((left == '(') && ((right == '+') || (right == '-') || (right == '*') || (right == '/'))) return false;
		if (((left == '+') || (left == '-') || (left == '*') || (left == '/')) && (right == ')')) return false;
		if ((left == ')') && (right == '(')) return false;
		if (((inf.GetOperation(left) != '(') || (inf.GetOperation(left) != ')')) && (inf.GetOperation(left) == inf.GetOperation(right))) return false;
		if ((left == '*') && ((right == '+') || (right == '-') || (right == '/') || (right == ')') || (right == '+'))) return false;
		if ((left == '/') && ((right == '+') || (right == '-') || (right == '*') || (right == ')') || (right == '+'))) return false;
		if ((left == '+') && ((right == '*') || (right == '-') || (right == '/') || (right == ')') || (right == '+'))) return false;
		if ((left == '-') && ((right == '+') || (right == '-') || (right == '/') || (right == ')') || (right == '+'))) return false;
		ptr = j;

	}
	return true;
}

map<char, float> TInfixToPolish::ReadValue(string str) 
{
	map<char, float> res;
	float value;
	for (const char& c : str)
	{
		if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z'))) {
			if (res.count(c) == 0)
			{
				cout << "Введите: " << c << endl;
				cin >> value;
				res[c] = value;
			}
		}
	}
	return res;
}