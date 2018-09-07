#pragma once
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
class DHeap
{
	vector<T> keys;
	int d = 3;
public:
	DHeap() = default;
	DHeap(vector<T> keys, int d);
	DHeap(const DHeap& heap) = default;
	void Sink(int idx);		//Погружение
	void Rise(int idx);		//Всплытие
	void Transpose(int idx1, int idx2);		//Транспонирование
	void Hilling();		//Окучивание
	void Insert(T keys);
	void Remove(int idx);
	T GetMinValue();
	int Minchild(int idx);
	bool IsEmpty() const;
};

template <typename T>
DHeap<T>::DHeap<T>(vector<T> keys, int d)
{
	this->d = d;
	this->keys = keys;
	Hilling();
}

template <typename T>
void DHeap<T>::Sink(int idx)
{
	int c = Minchild(idx);
	while (c != -1 && keys[c] < keys[idx])
	{
		Transpose(c, idx);
		idx = c;
		c = Minchild(idx);
	}
}

template <typename T>
void DHeap<T>::Rise(int idx)
{
	int p = (idx - 1) / d;
	while (p > 0)
	{
		if (keys[idx] < keys[p])
		{
			Transpose(p, idx);
		}
		idx = p;
		p = (idx - 1) / d;
	}
}

template <typename T>
void DHeap<T>::Transpose(int idx1, int idx2)
{
	swap(keys[idx1], keys[idx2]);
}

template <typename T>
void DHeap<T>::Hilling()
{
	for (int i = keys.size() - 1; i >= 0; i--)
	{
		Sink(i);
	}
}

template <typename T>
void DHeap<T>::Insert(T key)
{
	keys.push_back(key);
	Rise(keys.size() - 1);
}

template <typename T>
void DHeap<T>::Remove(int idx)
{
	if (idx < 0 || idx >= keys.size()) throw "Index error";
	
	swap(keys.back(), keys[idx]);
	keys.pop_back();
	Sink(idx);
}

template <typename T>
T DHeap<T>::GetMinValue()
{
	T tmp = keys.front();
	swap(keys.front(), keys.back());
	keys.pop_back();
	Sink(0);
	return tmp;
}

template <typename T>
inline int DHeap<T>::Minchild(int idx)
{
	if (idx*d + 1 >= keys.size()) return -1;
	int minidx = idx*d + 1;
	int idx1 = idx*d + 1;
	int idx2 = min(idx*d + d, (int)keys.size() - 1);
	for (int i = idx1; i <= idx2; i++)
	{
		if (keys[i] < keys[minidx])
			minidx = i;
	}
	return minidx;
}

template<typename T>
inline bool DHeap<T>::IsEmpty() const
{
	return keys.empty();
}