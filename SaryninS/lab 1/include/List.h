#pragma once
#include "node.h"

template<typename T>
class List
{
protected:
	Node<T> *head;
	Node<T> *current;
public:
	List();// конструктор
	List(const List<T> &lst);//констр копировани
	~List();// деструктор

	void Clean(); // удалить все звенья
    List<T>& operator=(const List<T>& lst);//оператор присваивания
	Node<T>* GetCurr() const { return current; } // получить указатель на текущий
	void InsertAfter(Node<T>* n, T d);// вставка после выбраннго элемента
	void InsertOrdered(T d);//всавка в упорядоченный 

	void GetNext() { current = current->next; } //current сдвигаем на 1 вправо
	void Reset() { current = head->next;  } // возращение указателя на начало
	bool IsEnded() const { return current == head; } //проверка не конец ли списка
    
	bool operator==(const List<T>& lst) const;							
	bool operator!=(const List<T>& lst) const;
};

template <typename T>
List<T>::List()
{
	head = new Node<T>;
		head->next = head;
	current = head->next;
}

template <typename T>
List<T>::List(const List<T>& lst) 
{
	Node<T>* tmp = lst.head;
	head = new Node<T>(tmp->data);
	head->next = head;
	current = head;
	while (tmp->next != lst.head)
	{
		tmp = tmp->next;
		current->next = new Node<T>(tmp->data);
		GetNext();
	}
	current->next = head;

}

template <class T>
List<T>::~List()
{
	Clean();
	delete head;
}

template <class T>
List<T>& List<T>::operator=(const List<T>& lst)
{
	Clean();
	Node<T>* tmp = lst.head;
	Node<T>* tmp2 = head;
	while (tmp->next != lst.head)
	{
		tmp = tmp->next;
		tmp2->next = new Node<T>(tmp->data);
		tmp2 = tmp2->next;
	}
	tmp2->next = head;
	current = head->next;
	return *this;
}

template <class T>
void List<T>::InsertAfter(Node<T>* n, T d)
{
	Node<T>* tmp = n->next;
	n->next = new Node<T>(d);
	n->next->next = tmp;
}

template <class T>
void List<T>::InsertOrdered(T d)
{
	Node<T>* tmp;
	current = head;
	while ((current->next->data > d) && current->next != head)
	{
		GetNext();
	}
	tmp = current->next; 
	current->next = new Node<T>(d);
	current->next->next = tmp;
}

template <class T>
void List<T>::Clean()
{
	Node<T>* tmp = head->next;
	Node<T>* tmp2;
	while (tmp != head)
	{
	    tmp2 = tmp->next;
		delete tmp;
		tmp = tmp2;
	}
	head->next = head;
}

template<class T>
bool List<T>::operator==(const List<T>& lst) const
{
	bool res = true;
	if (this != &lst)
	{
		Node<T>* tmp1 = head->next;
		Node<T>*  tmp2 = lst.head->next;
		while (tmp1->data == tmp2->data && tmp1 != head && tmp2 != lst.head)
		{
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
		if (tmp1 != head || tmp2 != lst.head)
			res = false;
	}
	return res;
}

template<class T>
bool List<T>::operator!=(const List<T>& lst)const
{
	return !(*this == lst); 
}