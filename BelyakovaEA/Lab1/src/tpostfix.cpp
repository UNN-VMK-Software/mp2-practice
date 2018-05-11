#include "tlink.h"
#include "tlist.h"
#include "tstack.h"
#include "tpostfix.h"
#include <iostream>
#include <string>

using namespace std;

int st::prioretet(char a)
{
	switch (a)
	{
	case '(':
		return 1;
		break;
	case '+':
		return 2;
		break;
	case '-':
		return 2;
		break;
	case '*':
		return 3;
		break;
	case '/':
		return 3;
		break;
	}
	return 0;
}


string st::correct(string s)
{
	int count = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			s.erase(i, 1);
		}
		if (islower(s[i]))
		{
			s[i] = toupper(s[i]);
		}
		if (s[i] == '(')
			++count;
		if (s[i] == ')')
		{
			--count;

			if (count < 0)
				throw "Check the number of parentheses";
		}
	}
	if (count > 0)
	{
		throw "Check the number of parentheses";
	}
	return s;
}


string st::postfixform(string s)
{
	TStack<char> stack1;
	TStack<char> stack2;
	char top;
	int m = s.length();
	std::cout << s << endl;
	for (int i = 0; i < m; i++)
	{
		if (isalpha(s[i]))
		{
			stack1.Push(s[i]);
			continue;
		}
		if (s[i] == '(')
		{
			stack2.Push(s[i]);
			continue;
		}
		if (s[i] == ')')
		{
			while ((top = stack2.Pop()) != '(')
			{
				stack1.Push(top);
			}
			continue;
		}
		if (!stack2.IsEmpty())
		{
			top = stack2.Pop();
			if (prioretet(s[i]) > prioretet(top))
			{
				stack2.Push(top);
				stack2.Push(s[i]);
				continue;
			}
			else
			{
				stack2.Push(top);
				top = stack2.Pop();
				stack2.Push(top);
				while ((prioretet(top) >= prioretet(s[i])) && (!stack2.IsEmpty()))
				{
					stack2.Pop();
					stack1.Push(top);
					if (stack2.IsEmpty()) break;
					top = stack2.Pop();
					stack2.Push(top);
				}
				stack2.Push(s[i]);
				continue;
			}
		}
		else
		{
			stack2.Push(s[i]);
			continue;
		}
	}

	while (!stack2.IsEmpty())
	{
		char a = stack2.Pop();
		stack1.Push(a);
	}
	s = "";
	while (!stack1.IsEmpty())
	{
		char a = stack1.Pop();
		s = a + s;
	}
	std::cout << "Postfix form:" << endl;
	std::cout << s << endl;
	return s;
}


float st::calculations(string s)
{
	VariableValues values = readvalues(s);
	TStack<float> stack;
	int m = s.length();
	float x, y, Result;

	for (int i = 0; i < m; i++)
	{
		if (isalpha(s[i]))
		{
			for (int j = 0; j < values.nValues; j++) {
				if (s[i] == values.ops[j])
					stack.Push(values.value[j]);
			}
		}
		if (s[i] == '+')
		{
			x = stack.Pop();
			y = stack.Pop();
			Result = y + x;
			stack.Push(Result);
		}
		if (s[i] == '-')
		{
			x = stack.Pop();
			y = stack.Pop();
			Result = y - x;
			stack.Push(Result);
		}
		if (s[i] == '*')
		{
			x = stack.Pop();
			y = stack.Pop();
			Result = y * x;
			stack.Push(Result);
		}
		if (s[i] == '/')
		{
			x = stack.Pop();
			y = stack.Pop();
			if (x == 0)
			{
				throw "Devision by zero";
			}
			Result = y / x;
			stack.Push(Result);
		}
	}
	Result = stack.Pop();

	delete [] values.ops;
	delete [] values.value;

	return Result;
}

VariableValues st::readvalues(const string& s) {  
	int k = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (isalpha(s[i]))
			k++;

	}

	VariableValues variables;
	char* arr = new char[k]; //массив с повторениями
	int idx = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (isalpha(s[i])) {
			arr[idx] = s[i];
			idx++;
		}
	}

	variables.nValues = 0;
	bool flag = true;

	for (int i = 0; i < k; i++) {
		flag = true;
		for (int j = 0; j < i; j++) {
			if (arr[j] == arr[i])
				flag = false;
		}

		if (flag == true)
			variables.nValues++;
	}

	variables.ops = new char[variables.nValues];
	idx = 0;

	for (int i = 0; i < k; i++)
	{
		flag = true;
		for (int j = 0; j < i; j++) {
			if (arr[i] == arr[j]) {
				flag = false;
			}
		}
		if (flag == true) {
			variables.ops[idx] = arr[i];
			idx++;
		}
		
 	}

	delete[] arr;

	variables.value = new float[variables.nValues];

	for (int i = 0; i < variables.nValues; i++)
	{
		std::cout << "Input: " << variables.ops[i] << endl;
		cin >> variables.value[i];
	}
	return variables;
}