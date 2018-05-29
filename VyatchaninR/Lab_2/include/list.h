#pragma once

template <typename DataType>
class List
{
public:
	DataType data;
	List* next;
	List();
	List(const List& l);
	List(DataType d, List* l = NULL);
	~List() {}
	List& operator = (const List& l);
	bool operator == (const List& l) const;
	bool operator != (const List& l) const;
};

template <typename DataType>
List<DataType>::List()
{
	next = NULL;
}

template <typename DataType>
List<DataType>::List(const List& l)
{
	data = l.data;
	next = l.next;
}

template <typename DataType>
List<DataType>::List(DataType d, List* l)
{
	data = d;
	next = l;
}

template <typename DataType>
List<DataType>& List<DataType>::operator=(const List& l)
{
	data = l.data;
	next = l.next;
	return *this;
}

template <typename DataType>
bool List<DataType>::operator== (const List& l) const
{
	int k = 0;

	if (data != l.data)
		k++;

	if (next != l.next)
		k++;

	if (k == 0)
		return true;
	else
		return false;
}

template <typename DataType>
bool List<DataType>::operator!= (const List& l) const
{
	int k = 0;

	if (data == l.data)
		k++;

	if (next == l.next)
		k++;
	if (k != 0)
		return true;
	else
		return false;
}