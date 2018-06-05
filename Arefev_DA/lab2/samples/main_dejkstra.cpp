#include <iostream>
#include "graph.h"
#include "priority_queue.h"
#include "priority_queue_based_dheap.h"
#include "dejkstra.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, m;

	cout << "Введите число вершин вашего графа" << endl;
	cin >> n;
	cout << "Введите число ребер вашего графа" << endl;
	cin >> m;
	Edge* E = new Edge[m];
	int l = 0;//ходилка по массиву ребер
	for (int i = 0; i < n-1; i++)
	{
		cout << "Если между вершинами нет ребра, введите 0. Введите веса всех ребер, связывающих вершину " << i << endl;
		for (int j = i + 1; j < n; j++)
		{
			float w;
			cout << " с вершиной " << j << ": ";
			cin >> w;
			cout << endl;
			if (w != 0) {
				Edge tmp(i, j, w);
				E[l] = tmp;
				l++;
			}
			if (l > m) cout << "Error!" << endl;
		}
	}

	Graph G(n, m, E);
	PriorityQueue<Vertex>* Q = new PriorityQueueBasedDHeap<Vertex>(n);
	AlgoritmDejkstri AD;
	AD.Dejkstra(&G, Q);
	return 0;
}