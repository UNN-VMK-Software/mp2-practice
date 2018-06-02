#ifndef POLISH_LIST_H
#define POLISH_LIST_H

#include "Node.h"

template <typename TKey>

class List {
private:
	Node<TKey>* root;
public:
	List();
	List(const List&);
	~List();
	void Add(TKey);							//вставка ключа в начало
	void Remove(TKey);						//удаление заданного ключа
	void InsertBefore(TKey, TKey);			//вставка до элемента с заданным ключом
	void InsertAfter(TKey, TKey);			//вставка после элемента с заданным ключом
	void InsertEnd(TKey);					//вставка ключа в конец
	void Print()const;						//вывод списка
	int Size()const;						//определение длинны списка
	TKey GetRoot()const;
	Node<TKey>* Search(TKey);				//указатель на начало списка
};

template <typename TKey>
List<TKey>::List() {
	root = 0;
};

template <typename TKey>
List<TKey>::List(const List& L) {
	L->pNext = this->root;
	this->root = L;
};

template <typename TKey>
List<TKey>::~List() {
	while (root != 0) {
		Node<TKey>* tmp = root;
		root = root->pNext;
		delete tmp;
	}
	delete root;
};

template <typename TKey>
void List<TKey>::Add(TKey key) {
	Node<TKey>* a = new Node<TKey>;
	a->key = key;
	a->pNext = root;
	root = a;
};

template <typename TKey>
void List<TKey>::Remove(TKey key) {
	if (root == 0)
		throw "List Is Empty";
	if (this->root->key == key) {
		Node<TKey>* a = root;
		root = root->pNext;
		delete a;
		return;
	}
	Node<TKey>* tmp = root;
	while (tmp->pNext != 0 && tmp->pNext->key != key)
		tmp = tmp->pNext;
	if (tmp->pNext == 0)
		throw "Key Not Found";
	Node<TKey>* a = tmp->pNext;
	tmp->pNext = a->pNext;
};

template <typename TKey>
void List<TKey>::InsertBefore(TKey key, TKey KeyNext) {
	if (root == 0)
		throw "List Is Empty";
	if (root->key == key) {
		root = new Node<Tke>;
		root->key = key;
	}
};

template <typename TKey>
void List<TKey>::InsertAfter(TKey key, TKey KeyPrev) {
	if (root == 0)
		throw "List Is Empty";
	while (root->pNext != 0 && root->key != KeyPrev)
		root = root->pNext;
	if (root->pNext == 0 && root->key != KeyPrev)
		throw "Key Not Found";
	Node<TKey>* a = new Node<TKey>;
	a->key = key;
	a->pNext = root->pNext;
	root->pNext = a;
};

template <typename TKey>
void List<TKey>::InsertEnd(TKey key) {
	if (root == 0) {
		root = new Node<TKey>;
		root->key = key;
		root->pNext = 0;
		return;
	}
	while (root->pNext != 0)
		root = root->pNext;
	root->pNext = new Node<TKey>;
	root->pNext->key = key;
	root->pNext->pNext = 0;
};

template <typename TKey>
void List<TKey>::Print()const {
	if (root == 0)
		throw "Stack Is Empty";
	Node<TKey>* a = root;
	while (a != 0) {
		cout << a->key << " ";
		a = a->pNext;
	}
	cout << endl;
};

template <typename TKey>
int List<TKey>::Size()const {
	Node<TKey>* a = root;
	int i = 0;
	while (a != 0) {
		i++;
		a = a->pNext;
	}
	return i;
};

template <typename TKey>
TKey List<TKey>::GetRoot()const {
	if (root != 0)
		return root->key;
	else
		return 1;
}

template <typename TKey>
Node<TKey>* List<TKey>::Search(TKey key) {
	Node<TKey>* a = root;
	while (a != 0 && a->key != key)
		a = a->pNext;
	if (a == 0)
		throw "Key Not Found";
	return a;
};

#endif