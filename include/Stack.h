#pragma once
#include <iostream>

using namespace std;
template<class A1>
class Stack
{
public:

	Stack()
	{
		Array = 0;
		size = 0;
		first =0;
		last = -1;
		DataCount = 0;
		
	}
	Stack(int _size)
	{
		if (_size < 0)throw logic_error("negative size");
		Array = new const A1*[_size];
		size = _size;
		first = 0;
		last = -1;
		DataCount = 0;
		
	}
	Stack(Stack& lhs)
	{
		Array = new const A1*[lhs.size];
		size = lhs.size;
		first = lhs.first;
		last = lhs.last;
		DataCount = lhs.DataCount;
		
	}

	virtual ~Stack()
	{
		delete[] Array;
	}
	bool IsEmpty()
	{
		return(DataCount==0);
	}
	bool IsFull()
	{
		return(DataCount==size);
	}
	const A1** GetMemory()
	{
		return Array;
	}
	 void push (const A1& lhs)
	{
		if ((*this).IsFull()) throw logic_error("Container is overflow");
		if (Array == 0) throw logic_error("memory error");
		last++;
		Array[last] = &lhs;
		DataCount++;
	}
	 bool find(const A1& lhs)
	 {
		 if ((*this).IsEmpty()) throw logic_error("Container is empty");
		 if (Array == 0) throw logic_error("memory error");
		 for (int i = first; i < DataCount; i++)
		 {
			 if (lhs == (*Array[i]))return 1;
		 }
		 return 0;
	 }
	 const A1& min()
	 {
		 if ((*this).IsEmpty()) throw logic_error("Container is empty");
		 if (Array == 0) throw logic_error("memory error");
		const A1* tmp = Array[first];
		 for (int i = first+1; i < DataCount; i++)
		 {
			 if ((*tmp) > (*Array[i])) tmp=Array[i];
		 }
		 return (*tmp);
	 }
	virtual const A1& pop()
	{
		if (this->IsEmpty()) throw logic_error("Stack is empty");
		if (Array == 0) throw logic_error("memory error");
		const A1* tmp = Array[last];
		Array[last] = 0;
		last--;
		DataCount--;
		return (*tmp);
	}
	int GetSize()
	{
		return size;
	}
	int GetFirst()
	{
		return first;
	}
protected:

const A1** Array;
int size;
int first;
int last;
int DataCount;
};