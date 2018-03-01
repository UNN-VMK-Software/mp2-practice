#ifndef STACK_H
#define STACK_H


template <typename TKey>
class Stack
{
private:
	List<TKey>* List;
public:
	Stack();
	Stack(const Stack<TKey>&);
	~Stack;

	void Push(TKey);
	TKey Pop();
	TKey Take();
	bool IsEmpty() const;
	bool IsFull() const;
};
template <typename TKey>
Stack<TKey>::Stack()
{
	list = new List<TKey>;
};
template <typename TKey>
Stack<TKey>::Stack(const Stack&S)
{
	list = new List<TKey>(S.list);
};
template <typename TKey>
Stack<TKey>::~Stack()
{
	delete list;
};

template <typename TKey>
void Stack<TKey>::Push(TKey key)
{
	if (IsFull()) throw "Is Full";
	list->Add(key);
};

template <typename TKey>
TKey Stack<TKey>::Take()
{
	if (IsEmpty()) throw "Is Empty";
	TKey key = list->key;
	return key;
};

template <typename TKey>
TKey Stack<TKey>::Pop()
{
	if (IsEmpty()) throw "Is Empty";
	TKey key = list->key;
	try {
		list->Remove(key);
	}
	catch (const char* ex)
	{
		cout << ex << endl;
	}
	return key;
};

template <typename TKey>
bool Stack<TKey>::IsEmpty() const
{
	return(list->Size == 0);
};
template <typename TKey>
bool Stack<TKey>::IsFull() const
{
	TKey key = -1;
	try
	{
		list -> Add(key);
		try {
			list->Remove(key);
		}
		catch (const char* ex)
		{
			cout << ex << endl;
		}
	}
	catch (bool) {
		return true;
	};
	return false;
};

#endif