#pragma once

#include <iostream>

template <class valtype>

class NODE
{
public:
	valtype key;
	NODE *pNext;
};

template <class valtype>
class List 
{
private:
	NODE<valtype>* pFirst;
public:
	List();
	List(const List &list);
	~List();

	void print();
	NODE<valtype>* search(valtype key);
private:
	NODE<valtype>* searchPrev(valtype key, NODE<valtype> *&point);
	void erase(NODE<valtype> *elem);
public:
	void erase(valtype key);

	void insertFirst(valtype key);
	void insertLast(valtype key);
	void insertBefore(valtype key, NODE<valtype> *elem);
	void insertAfter(valtype key, NODE<valtype> *elem);

	NODE<valtype>* getFirst();
};

template <class valtype>
List<valtype>::List()
{
	pFirst = 0;
}

template <class valtype>
List<valtype>::List(const List<valtype> &list)
{
	pFirst = 0;
	NODE<valtype>* tmp = list.pFirst;
	while (tmp != 0) {
		insertLast(tmp->key);
		tmp = tmp->pNext;
	}
}

template <class valtype>
List<valtype>::~List()
{
	NODE<valtype> *tmp = pFirst;
	while (pFirst) {
		pFirst = pFirst->pNext;
		delete tmp;
		tmp = pFirst;
	}
}

template <class valtype>
void List<valtype>::print()
{
	if (!pFirst) {
		std::cout << "��� ����������" << std::endl;
		return;
	}

	NODE<valtype> *tmp = pFirst;
	while (tmp != 0) {
		std::cout << tmp->key << " ";
		tmp = tmp->pNext;
	}
	std::cout << std::endl;
}

template <class valtype>
NODE<valtype>* List<valtype>::search(valtype key)
{
	if (!pFirst) throw "������ ����!";

	NODE<valtype> *tmp = pFirst;
	while ((tmp != 0) && (tmp->key != key))
		tmp = tmp->pNext;

	if ((!tmp) || (tmp->key != key)) return 0;

	return tmp;
}

template <class valtype>
NODE<valtype>* List<valtype>::searchPrev(valtype key, NODE<valtype> *&elem)
{
	if (!pFirst) return 0;

	NODE<valtype> *pPrev = 0;
	elem = pFirst;
	while ((elem != 0) && (elem->key != key)) {
		pPrev = elem;
		elem = elem->pNext;
	}
	if ((!elem) || (elem->key != key)) {
		elem = 0;
		pPrev = 0;
		return 0;
	}

	return pPrev;
}

template <class valtype>
void List<valtype>::erase(NODE<valtype> *elem)
{
	if (!pFirst) throw "������ ����!";
	NODE<valtype> *point = pFirst;
	NODE<valtype> *pPrev = 0;
	while ((point != 0) && (point != elem)) {
		pPrev = point;
		point = point->pNext;
	}
	if (point != elem) return;

	if (!pPrev) {
		pFirst = pFirst->pNext;
		delete point;
		return;
	}
	pPrev->pNext = point->pNext;
	delete point;
	return;
}

template <class valtype>
void List<valtype>::erase(valtype key)
{
	if (!pFirst) throw "������ ����!";
	NODE<valtype> *point;
	NODE<valtype> *pPrev = searchPrev(key, point);
	if ((!pPrev) && (pFirst->key != key))
		throw "�� ������� ����� �������";
	if (!pPrev) {
		pFirst = pFirst->pNext;
		delete point;
		return;
	}
	pPrev->pNext = point->pNext;
	delete point;
	return;
}

template <class valtype>
void List<valtype>::insertFirst(valtype key)
{
	NODE<valtype> *tmp = new NODE<valtype>();
	tmp->key = key;
	tmp->pNext = pFirst;
	pFirst = tmp;
}

template <class valtype>
void List<valtype>::insertLast(valtype key)
{
	NODE<valtype> *tmp = pFirst;
	if (!pFirst) {
		insertFirst(key);
		return;
	}
	while (tmp->pNext != 0)
		tmp = tmp->pNext;
	tmp->pNext = new NODE<valtype>;
	tmp = tmp->pNext;
	tmp->key = key;
	tmp->pNext = 0;
}

template <class valtype>
void List<valtype>::insertBefore(valtype key, NODE<valtype> *elem)
{
	if (!pFirst) throw "������ ����!";
	NODE<valtype> *point;
	NODE<valtype> *pPrev = searchPrev(key, point);
	if ((!pPrev) && (pFirst->key != key))
		throw "��� ����� � �������� ������ ��� �������";

	elem->pNext = point;
	if (!pPrev) {
		pFirst = elem;
		return;
	}
	pPrev->pNext = elem;
}

template <class valtype>
void List<valtype>::insertAfter(valtype key, NODE<valtype> *elem)
{
	if (!pFirst) throw "������ ����!";
	NODE<valtype> *point = search(key);
	if (!point)
		throw "��� ����� � �������� ������ ��� �������";
	elem->pNext = point->pNext;
	point->pNext = elem;
}

template <class valtype>
NODE<valtype>* List<valtype>::getFirst()
{
	return pFirst;
}