#ifndef LIST_H
#define LIST_H

#include "nods.h"

template <typename T>
class List
{
private:
	Node<T> *root;
public:
	List();
	List(const List<T>&);
	~List();

	void Add(T);
	void Remove(T);
	void InsertBefore(T, T);
	void InsertAfter(T, T);
	void InsertEnd(T);
	void print() const;
	int Size() const;
	T GetRoot()const;
	Node<T> *Search(T);
};

template <typename T>
List<T>::List()
{
	root = 0;
};

template <typename T>
List<T>::List(const List<T>&L)
{
	L->pNext=this->root;
	this->root = L;
};

template <typename T>
List<T>::~List()
{
	
	while (root != 0)
	{
		Node<T>* tmp = root;
		root = root->pNext;
		delete tmp;
	}
	delete root;
};

template <typename T>
void List<T>::Add(T key)
{
	Node<T> * a = new Node<T>;
	a->key = key;
	a->pNext = root;
	root = a;
};

template <typename T>
void List<T>::Remove(T K)
{
	if (root == 0)
		throw "List is empty";
	if (this->root->key == K)
	{
		Node<T>*n = root;
		root = root->pNext;
		delete n;
		return;
	}
	Node<T>*tmp = root;
	while (tmp -> pNext != 0 && tmp->pNext->key != K)
	{
		tmp = tmp->pNext;
	}
	if (tmp->pNext == 0)
		throw "Key not found";
	Node<T>*n = tmp->pNext;
	tmp->pNext = n->pNext;
};

template <typename T>
void List<T>::InsertBefore(T K1, T K2)
{
	if (root == 0) throw "Is Empty";
	if (root->key == K1)
	{
		root = new Node<T>;
		root->key = K1;

	}
};

template <typename T>
void List<T>::InsertAfter(T K1, T K2)
{
	if (root == 0) throw "List is empty";
	while (root->pNext != 0 && root->key != K2)
	{
		root = root->pNext;
	}
	if (root->pNext == 0 && root->key != K2)
	{
		throw "Key not  found";
	}
	Node<T>*a = new Node<T>;
	a->key = K1;
	a->pNext = root -> pNext;
	root->pNext = a;
};

template <typename T>
void List<T>::InsertEnd(T K)
{
	if (root == 0)
	{
		root = new Node<T>;
		root->key = K;
		root->pNext = 0;
		return;
	}
	while (root->pNext != 0)
	{
		root = root->pNext;
	}
	root->pNext = new Node<T>;
	root->pNext->key = K;
	root->pNext -> pNext = 0;
};

template <typename T>
int List<T>::Size() const
{
	Node<T>* a = root;
	int i = 0;	
	while (a != 0)
	{
		i++;
		a = a->pNext;
	}
	return i;
};

template <typename T>
Node<T>* List<T>::Search(T K)
{
	Node<T>* a = root;
	while (a!= 0 && a->key!=K)
	{
		a = a->pNext;
	}
	if (a == 0) throw "Key not found";
	return a;
};

template <typename T>
T  List<T>::GetRoot()const
{
	if (root!=0)
		return root->key;
	else
		return '!';
	
}

template <typename T>
void List<T>::print() const
{
	if (root == 0)
	{
		throw "Node is empty";
	}
	Node<T>* a = root;
	while (a != 0)
	{
		cout << a->key << " ";
		a = a->pNext;
	}
	cout << endl;
};

#endif