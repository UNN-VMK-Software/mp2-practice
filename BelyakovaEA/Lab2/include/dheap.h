#ifndef DHEAP_H
#define DHEAP_H

#include "edge.h"
#include "Dijkstra.h"


template <class T> class DHeap
{
private:
	int d;
	int n; // число ребер 
	T* keys; // множество ребер
	int min(int a, int b);

public:
	DHeap(T* keys, int d, int n);
	DHeap(const DHeap &H); //  онструктор копировани€
	~DHeap(); // ƒеструктор

	virtual bool isEmpty() const { return n == 0; }

	void transpose(int i, int j);
	void surfacing(int i);
	void sinking(int i); //погружение 
	void hilling(); //окучивание
	void remove(int i);
	void insert(T k);
	int minchild(int i);

	T getmin();

	int GetSize() { return n; }
	void SetSize(int new_size) { n = new_size; }
	T& GetElement(int idx) { return keys[idx]; }
};

template <class T>
DHeap<T> ::DHeap(T* keys, int d, int n)
{
	this->keys = keys;
	this->d = d;
	this->n = n;
}

template <class T>
DHeap<T>::DHeap(const DHeap&H)
{
	d = H.d;
	n = H.n;
	keys = new T[n];
	for (int i = 0; i < n; i++)
	{
		keys[i] = H.keys[i];
	}
}

template <class T>
DHeap<T>::~DHeap() {
	//Do not delete keys as we do not own it;
}

template <class T>
int DHeap<T>::min(int a, int b)
{
	if (a <= b) return a;
	else return b;
}

template <class T>
void DHeap<T> ::transpose(int i, int j) {
	T tmp = keys[i];
	keys[i] = keys[j];
	keys[j] = tmp;
}

template <class T>
void DHeap<T>::surfacing(int i) {
	int p = (i - 1) / d;
	while (p > 0) {  
		if (keys[p] > keys[i])
		{
			transpose(p, i);
			i = p;
			p = (i - 1) / d;
		}

		else
		{
			break;
		}
	}
}


template <class T>
void DHeap<T>::sinking(int i) {
	int c = minchild(i);
	while (c != -1 && keys[c] < keys[i]) {
		transpose(c, i);
		i = c;
		c = minchild(i);
	}
}

template <class T>
int DHeap<T>::minchild(int i) {
	if (i * d + 1 > n - 1) return -1;

	int minidx = i * d + 1;
	int i1 = i * d + 1;
	int i2 = min(i * d + d, n - 1);
	T minkey = keys[i1];
	for (int i = i1; i <= i2; i++) {
		if (keys[minidx] > keys[i]) {
			minidx = i;
			minkey = keys[i];
		}
	}
	return minidx;
}

template <class T>
T DHeap<T> ::getmin() {

	T tmp = keys[0];
	transpose(0, n - 1);
	n--;
	sinking(0);
	return tmp;
}

template <class T>
void DHeap<T>::hilling() {
	for (int i = n - 1; i >= 0; i--)
		sinking(i);
}

template <class T>
void DHeap<T>::remove(int i) {
	if (i == n - 1)
	{
		n--;
		return;
	}

	keys[i] = keys[n - 1];
	n--;
	sinking(i);
}

template <class T>
void DHeap<T>::insert(T k) {
	keys[n] = k;
	surfacing(n);
	++n;
}


template class DHeap<int>;
template class DHeap<VertexDist>;

#endif