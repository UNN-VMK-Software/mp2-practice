#pragma once

#include "graph.h"
#include "priority_queue.h"
#include <iostream>

using namespace std;

template <typename T>
class DHeap
{
	int d = 2;// d-куча
	T* keys; // массив ключей
	int n; // максимальное число ключей
	int k;// текущее число ключей 
public:
	DHeap() {};
	DHeap(int MaxSize);
	DHeap(T* edges, int size);
	DHeap(Graph graph);
	~DHeap();

	// методы работы с кучей
	void transpose(int i, int j);
	void emerge(int i); //всплытие
	void sinking(int i); //погружение
	int minchild(int id);
	T deleteminkey();
	void insert(const T& key);
	void makeitheap(); //окучивание

	// вспомогательные методы для работы с кучей
	int GetMaxSize() { return n; };
	int GetCurrSize() { return k; };
	void ChangeCurrSize(int curr) { k = curr; };

	//вывод
	void Print();

};

template <typename T>
DHeap<T>::DHeap(T* edges, int size)
{
	n = size;
	keys = new T[n];
	for (int i = 0;i < n;i++)
	{
		keys[i] = edges[i];
	}
	k = n;
};

template <typename T>
DHeap<T>::~DHeap()
{
	delete[] keys;
}

template <typename T>
DHeap<T>::DHeap(int MaxSize)
{
	n = MaxSize;
	k = 0;
	keys = new T[n];
};

template <typename T>
DHeap<T>::DHeap(Graph graph)
{

};

template <typename T>
void DHeap<T>::transpose(int i, int j)
{
	T tmp = keys[i];
	keys[i] = keys[j];
	keys[j] = tmp;
}

template<typename T>
void DHeap<T>::insert(const T& key)
{
	if (k >= n) throw("Error insert");
	keys[k] = key;
	emerge(k);
	k++;
}

template<typename T>
void DHeap<T>::emerge(int i)
{
	int p = (i - 1) / d;
	while (i>0)
	{
		if (keys[p] > keys[i])
		{
			transpose(p, i);
			i = p;
			p = (i - 1) / d;
		}
		else break;
	}
}

template<typename T>
void DHeap<T>::sinking(int i)
{
	int c = minchild(i);
	while ((c != -1) && (keys[c] < keys[i]))
	{
		transpose(i, c);
		i = c;
		c = minchild(i);
	}

}

template<typename T>
int DHeap<T>::minchild(int id)
{
	int f = id*d + 1;
	if (f > k-1)
		return -1;

	int l = (id*d + d < k-1)? id*d + d : k-1;
	int c;

	T minKey = keys[f];
	c = f;
	for (int j = f + 1; j <= l; j++) {
		if (minKey > keys[j]) {
			minKey = keys[j];
			c = j;
		}
	}
	return c;
}

template<typename T>
T DHeap<T>::deleteminkey()
{
	T tmp = keys[0];
	transpose(0,k-1);
	k--;
	sinking(0);
	return tmp;
}

template<typename T>
void DHeap<T>::makeitheap()
{
	for (int i = (k - 1); i >= 0; i--)
	{
		sinking(i);
	}
}

template<typename T>
void DHeap<T>::Print()
{
	for (int i = 0;i < n;i++)
	{
		cout << keys[i]<<" ";
	}
}

