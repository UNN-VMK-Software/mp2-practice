#include <iostream>
#include "kraskal.h"
#include "graph.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int n,m;
	
	cout << "Введите число вершин вашего графа" << endl;
	cin >> n;
	cout << "Введите число ребер вашего графа" << endl;
	cin >> m;
	Edge* E = new Edge[m];
	int l = 0;//ходилка по массиву ребер
	for (int i = 0; i < (n-1); i++)
	{
		cout << "Если между вершинами нет ребра, введите 0. Введите веса всех ребер, связывающих вершину "<< i << endl;
		for (int j = i+1; j < n; j++)
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
	PriorityQueue<Edge>* Q = new PriorityQueueBasedDHeap<Edge>(m);
    Edge* WE = new Edge[n - 1];
	AlgoritmKraskala AK;
	WE = AK.Kraskal(&G, Q);
	for (int i = 0;i < n-1;i++) {
		cout << "(" << WE[i].GetStart() << "," << WE[i].GetFinish() << ")" << ",";
	}
	return 0;
}