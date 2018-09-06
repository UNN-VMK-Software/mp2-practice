#include <iostream>
#include "Graph.h"
#include "Priority_Queue.h"
#include "Algorithm.h"


typedef float KeyType;

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите количество вершин:" << endl;
	int n;
	cin >> n;
	cout << "Введите количество рёбер" << endl;
	int m;
	cin >> m;
	Graph<KeyType> *graph = new Graph<KeyType>(n, m);
	KeyType *P = new KeyType[n];

	for (int i = 0; i<m; i++)
	{
		cout << "Введите начальную вершину ребра, затем конечную, а потом его вес " << endl;
		int f, t;
		KeyType w;
		cin >> f;
		cin >> t;
		cin >> w;
		graph->Push(f - 1, t - 1, w);
	}

	system("cls");
	cout << "Граф: " << endl << endl;
	graph->Print();
	cout << "Задайте начальную вершину:" << endl;
	int a;
	cin >> a;
	for (int i = 0; i <= n; i++)
		P[i] = a - 1;
	KeyType *dist = Algorithm<KeyType>::Dijkstra(a - 1, P, graph);
	cout << "Итог: " << endl << endl;
	for (int i = 1; i<n + 1; i++)
		cout << i << ' ';
	cout << "Вершины " << endl << endl;
	for (int i = 0; i < n; i++)
		if (dist[i] == max_heap)
			cout << 0 << ' ';
		else
			cout << dist[i] << ' ';
	cout << "Кратчайшие пути " << endl << endl;
	for (int i = 0; i<n; i++)
		cout << P[i] + 1 << ' ';
	cout << "Предыдущие вершины " << endl << endl;
	system("pause");
	return 0;
}