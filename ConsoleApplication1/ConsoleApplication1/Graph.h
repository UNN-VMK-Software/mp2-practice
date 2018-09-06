#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;


template <class KeyType>
class Edge
{
public:
	Edge(int, int, KeyType);
	int from;
	int to;
	KeyType weight;
};

template <class KeyType>
class Graph
{
private:
	int n; //вершины
	int m; //ребра
	Edge<KeyType>** edges;
	int current; //текущее ребро
public:
	Graph(int, int);
	~Graph();
	void Push(int, int, KeyType);
	void Remove(int, int);
	int GetCount();
	int GetEdgeSize();
	Edge<KeyType>*  GetEdge(int);
	KeyType GetWeight(int, int);
	void Print();
	bool Scan(int, int*);
};

template <class KeyType>
Edge<KeyType>::Edge(int f, int t, KeyType w)
{
	from = f;
	to = t;
	weight = w;
}

template <class KeyType>
Graph<KeyType>::Graph(int v, int e)
{
	if (v < 0)
		return; //некорректная вершина
	else
		n = v;
	if ((e < 0) || (e > n * (n - 1) / 2))
		return; //некорректное ребро
	else
		m = e;
	current = 0;
	edges = new Edge<KeyType>*[m];
}

template <class KeyType>
Graph<KeyType>::~Graph()
{
	for (int i = 0; i < current; i++)
		delete edges[i];
	delete[] edges;
}

template <class KeyType>
void Graph<KeyType>::Push(int f, int t, KeyType w)
{
	if (current == m)
		return; // граф полон
	if (f == t)
		return; //граф не должен содержать петлей
	if ((f > n) || (t > n))
		return;//таких вершин не существует
	edges[current] = new Edge<KeyType>(f, t, w);
	current++;
}

template <class KeyType>
int Graph<KeyType>::GetCount()
{
	return n;
}

template <class KeyType>
int Graph<KeyType>::GetEdgeSize()
{
	return m;
}

template <class KeyType>
KeyType Graph<KeyType>::GetWeight(int f, int t)
{
	if ((f < 0) || (f > n) || (t < 0) || (t > n))
		return;// некорректные вершины
	for (int i = 0; i < current; i++)
		if ((edges[i]->from == f) && (edges[i]->to == t) || (edges[i]->from == t) && (edges[i]->to == f))
			return edges[i]->weight;
	return 0;
}

template <class KeyType>
void Graph<KeyType>::Print()
{
	cout << "От  до " << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < current; j++)
			if (edges[j]->from == i)
				cout << edges[j]->from + 1 << " " << edges[j]->to + 1 << "(" << edges[j]->weight << ")" << endl;
}

template <class KeyType>
Edge<KeyType>* Graph<KeyType>::GetEdge(int x)
{
	return edges[x];
}

template <class KeyType>
void Graph<KeyType>::Remove(int f, int t)
{
	int tmp = FindEdge(f, t);
	if (tmp == -1)
		return; // такого ребра нет
	delete edges[tmp];
	edges[tmp] = edges[current - 1];
	current--;
}

template <class KeyType>
bool Graph<KeyType>::Scan(int f, int* b)
{
	bool res = false;
	for (int i = 0; i < n; i++)
		if (b[i] == f)
			res = true;
	return res;
}

#endif 