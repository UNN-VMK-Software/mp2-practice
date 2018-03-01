#include "List.h"
#include "Node.h"
#include "Stack.h"
#include "NameVal.h"
#include <iostream>

using namespace std;

void main()
{

	
	
	Stack<char> S1;
	Stack<char> S2;
	char *line = new char;
	int i = 0,sizeOfTotalExpression =0, numberOperands=0;
	cout << "Enter enter the expression:" <<endl;
	while (cin >> line[i])
		{
			cin >> line[i];
			
			if (line[i] == '*')  //Замена умножения
				line[i] = '.';
			if (line[i] == '-')  //Замена минуса
				line[i] = ',';
			if (line[i] = 41)                    //пришла скобка )
				while (S2.Take != 40)
					S1.Push(S2.Pop);
			if ((line[i] >= 65) && (line[i] <= 90))//пришел операнд
			{
				numberOperands++;
				S1.Push(line[i]);
			}
			if (S2.IsEmpty = true)                    //Вставка в пустой стек 2
				S2.Push(line[i]);
			else
			{
				if ((S2.Take() <= line[i]) || (S2.Take() == line[i] - 1) || (S2.Take() == line[i] + 1))
					S2.Push(line[i]);
				if ((S2.Take() > line[i]))
					while ((S2.Take() >= line[i]) || (S2.Take() == line[i] - 1) || (S2.Take() == line[i] + 1))
						S1.Push(S2.Pop);
			}
			if (line[i] = 40)                    //пришла скобка (
				S2.Push(line[i]);
			sizeOfTotalExpression++;
		}
	while (S2.IsEmpty != false)
	{
		S1.Push(S2.Pop);
	}

	cout << endl;
	cout << endl;
	

	NameValue *NV = new NameValue[numberOperands];

	cout << "Enter the values"<<endl;
	for (int i = 0; i < numberOperands; i++)
	{
		cout << "Enter the" << i << " value: ";
		cin >> NV[i].Value;
		cout << endl;
	}

	
	for (int i = 0; i < sizeOfTotalExpression; i++) //Вывод до постфиксной формы
	{
		if (line[i] == '.')  //Замена умножения
			line[i] = '*';
		if (line[i] == ',')  //Замена минуса
			line[i] = '-';
		
		cout << line[i];
	}

	i = 0;
	while( i < numberOperands)
	{
		int j = 0;
		while(j < sizeOfTotalExpression)
			if ((line[i] >= 65) && (line[i] <= 90))
			{
				NV[j].Operand = line[i];
				i++;
				j =+ 2;
			}
	}

	cout << "Postfix form";
	for (int i = sizeOfTotalExpression; i >= 0; i--)
	{
		line[i] = S1.Pop;

	for (int i = 0; i < sizeOfTotalExpression; i++)  //Вывод постфиксной формы
	{
		if (line[i] == '.')  //Замена точки на умножение
			line[i] = '*';
		if (line[i] == ',')  //Замена запятой на минус
			line[i] = '-';
		cout << line[i];
	}
	
	for (int i = 0; i < sizeOfTotalExpression; i++)
	{
		int j = 0;
		if ((line[i] >= 65) && (line[i] <= 90))
			while (NV[j].Operand != line[i])
				j++;
		S2.Push(NV[j].Value);
		float a, b;
		if ((line[i] > 41) && (line[i] < 48))
		{
			if (line[i] == '+')
			{
				a = S2.Pop;
				b = S2.Pop;
				S2.Push(b + a);
			}
			if (line[i] == '-')
			{
				a = S2.Pop;
				b = S2.Pop;
				S2.Push(b - a);
			}
			if (line[i] == '*')
			{
				a = S2.Pop;
				b = S2.Pop;
				S2.Push(b * a);
			}
			if (line[i] == '/')
			{
				a = S2.Pop;
				b = S2.Pop;
				S2.Push(b / a);
			}
		}
	}
	cout << "The value of the expression: " << S2.Pop;


}
	