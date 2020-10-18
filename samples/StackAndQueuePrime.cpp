
#include <iomanip>
#include "Stack.h"
#include "Queue.h"
#include <stack>

#ifndef USE_QUEUE
#define USE_QUEUE

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "—имул€ци€ работы стека на примере массива из size чисел" << "\n";
	
	int size;
	cin >> size;
	int* ptr = new int[size];
	for (int i = 0; i < size; i++)
	{
		ptr[i] = (i + rand() % 100)*rand() % 12;
	}
	Stack<int>stack1(size);
	stack<int>stack2;

	for (int i = 0; i < size; i++)
	{
		cout << ptr[i] << " ";
		stack2.push(ptr[i]);
		stack1.push(ptr[i]);
	}
	cout << "\n";
	for (int i = stack1.GetFirst(); i < stack1.GetSize(); i++)
	{
		cout << stack1.pop() << " ";
	}
	cout << "\n";
	for (int i = 0; i < size; i++)
	{
		cout << stack2.top()<<" ";
		stack2.pop();
	}
	
}

/*int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "—имул€ци€ работы очереди на примере массива из 10 чисел" << "\n";
	int a1[10];
	Queue<int>queue(10);
	for (int i = 0; i < 10; i++)
	{
		a1[i] = i;
		queue.push(a1[i]);
	}
	for (int i = queue.GetFirst(); i < queue.GetSize(); i++)
	{
		cout << queue.pop() << "\n";
	}
}*/
#endif