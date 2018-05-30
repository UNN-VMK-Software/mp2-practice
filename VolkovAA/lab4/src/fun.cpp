#include "fun.h"
#include <string>
#include <iostream>

#include "List.h"
#include "nods.h"
#include "stack.h"
#include "val.h"

using namespace std;

int functions::Priority(char sym)
{
	if ((sym == '*') || (sym == '/')) {
		return 3;
	}
	if ((sym == '+') || (sym == '-')) {
		return 2;
	}
	if (sym == ')') {
		return 1;
	}
	if (sym == '(') {
		return 0;
	}
	return -1;
}
string functions::postfix(string line)
{
	Stack<char> S1;
	Stack<char> S2;
	
	for (int i = 0; i < (int)line.length(); i++)
	{
		if (((line[i] >= 'a') && (line[i] <= 'z')) || ((line[i] >= 'A') && (line[i] <= 'Z')))
			S1.Push(line[i]);
		else if (line[i] == ')')
		{
			while ((!S2.IsEmpty()) && (S2.Take() != '('))
			{
				S1.Push(S2.Pop());

			}
			if (!S2.IsEmpty() && (S2.Take() == '('))
				S2.Pop();
			else 
				throw "S2 is empty";
		}
		else if (line[i] == '(')
			S2.Push(line[i]);
		else if ((line[i] == '+') || (line[i] == '-') || (line[i] == '/') || (line[i] == '*'))
		{
			if (Priority(S2.Take()) <= Priority(line[i]) || S2.Take() == '(')
				S2.Push(line[i]);
			else
			{
				while ((!S2.IsEmpty()) && (Priority(S2.Take()) >= Priority(line[i])))
				{
					S1.Push(S2.Pop());
				}
				S2.Push(line[i]);
			}
		}		
	}
	while (!S2.IsEmpty())
	{
		if((S2.Take()!=')')&&(S2.Take()!='('))
			S1.Push(S2.Pop());
		else
			S2.Pop();
	}
	
	string postfix = "";
	while (!S1.IsEmpty())
	{
		postfix = S1.Pop() + postfix;
	}
	return postfix;
}
		
string functions::operands(string line)
{
	int n=0;
	for(int i=0;i<(int)line.length();i++)
	{
		if(((line[i]>='A')&&(line[i]<='Z'))|| ((line[i] >= 'a') && (line[i] <= 'z')))
			n++;
	}
	char* arr=new char[n];
	int j=0;
	for(int i=0;i<(int)line.length();i++)
	{
		if(((line[i]>='A')&&(line[i]<='Z'))|| ((line[i] >= 'a') && (line[i] <= 'z')))
		{
			arr[j]=line[i];
			j++;
		}
	}
	int k=1;
	for( int i=1;i<n;i++)
	{
		bool flag=true;
		for(int j=0;j<i;j++)
			if (arr[i]==arr[j])
				flag=false;
		if (flag) k++;
	}
	char* arr1=new char[k+1];
	arr1[0]=arr[0];
	int g=1;
	for( int i=1;i<n;i++)
	{
		bool flag=true;
		for(int j=0;j<i;j++)
			if (arr1[j]==arr[i])
				flag=false;
		if (flag) arr1[g++]=arr[i];
	}
	arr1[g] = '\0';
	
	string op(arr1);
	delete [] arr;
	delete [] arr1;
	return op;

}
NameValue * functions::NVmas( string op)
{
	NameValue *NV = new NameValue[op.length()];
	for (int i = 0; i < (int)op.length(); i++)
	{
		cout << "Enter the " << i+1 << " val: ";
		cin >> NV[i].Value;
		NV[i].Operand = op[i];
		cout << endl;
	}
	return NV;
}
float functions::Result(string line, int sizeOfTotalExpression, NameValue* NV)
{
	Stack<float> S1;
	
	for (int i = 0; i < sizeOfTotalExpression; i++)
	{
		
		int j = 0;
		if (((line[i] >= 'A') && (line[i] <= 'Z')) || ((line[i] >= 'a') && (line[i] <= 'z')))
		{
			while (NV[j].Operand != line[i])
				j++;
			S1.Push(NV[j].Value);
		}
		float a, b;
		if (line[i] == '+')
		{
			a = S1.Pop();
			b = S1.Pop();
			S1.Push(b + a);
		}
		if (line[i] == '-')
		{
			a = S1.Pop();
			b = S1.Pop();
			S1.Push(b - a);
		}
		if (line[i] == '*')
		{
			a = S1.Pop();
			b = S1.Pop();
			S1.Push(b * a);
		}
		if (line[i] == '/')
		{
			a = S1.Pop();
			b = S1.Pop();
			if(a!=0)
				S1.Push(b / a);
			else
				throw "Error!\nYou can not divide by zero.";
		}
		
	}
	return S1.Pop();
}