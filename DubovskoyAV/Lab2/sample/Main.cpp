#include "Dijkstra.h"
#include <cfloat>
#include <iostream>

using namespace std;

int main() {
	Graph* graph;
	int n; // Количество вершин
	int m; // Количество ребер
	int s; // Стартовая вершина

	try
	{
		cout << "Enter number vertices" << endl;
		cin >> n;
		cout << "Enter number edges" << endl;
		cin >> m;
		graph = new Graph(n, m);
	}
	catch (...)
	{
		return -1;
	}

	cout << "Enter type generate graph:"<<endl<< "1. Random" << endl << "2. Manual" << endl;

	int typeEnter;
	cin >> typeEnter;
	switch (typeEnter)
	{
	//Random
	case 1: {
		try
		{
			float minRange; // Минимальный вес ребра
			float maxRange; // Максимальный вес ребра
			cout << "Enter minRange" << endl;
			cin >> minRange;
			cout << "Enter maxRange" << endl;
			cin >> maxRange;
			graph->generateGraph(minRange, maxRange);
		}
		catch (...)
		{
			return -1;
		}
		break;
	}
	//Manual
	case 2: {
		int Ne, Ke;
		float W;

		try
		{
			for (int i = 0; i < m; i++) {
				cout << "Enter start vershinu" << endl;
				cin >> Ne;
				cout << "Enter finish vershinu" << endl;
				cin >> Ke;
				cout << "Enter W" << endl;
				cin >> W;
				graph->addEdge(Ne, Ke, W);
			}
		}
		catch (...)
		{
			return -1;
		}
		break;
	}
	}
	
	graph->printList(); //Вывод графа
	cout << endl;

	cout << "Enter start vertex for Dijkstra" << endl;
	cin >> s;

	float *dist;    // Массив расстояний между стартовой вершиной и i-той вершиной
	int *up;		// Массив вершин, предшествующих в кратчайшем пути
	try {
		Dijkstra::dijkstra(graph, s, dist, up);
	}
	catch (...) {
		return -2;
	}

	cout << n << ' ' << m << endl;	      // Печать количества вершин
	cout << s << endl;					  // Печать стартовой вершины

	m = graph->getRealSize();
	WeightedEdge* edge;
	cout << "// Matrix edges //" << endl; // Печать матрицы взвешенных вершин
	for (int j = 0; j < m; j++) {
		edge = graph->getEdge(j);
		cout << edge->Ne << ' ' << edge->Ke << ' ' << edge->W << endl;
	}

	cout << "// Distances //" << endl;	   // Печать расстояний от заданной стартовой вершины до i-той вершины
	for (int i = 0; i < n; i++)
		if (dist[i] != FLT_MAX)
			cout << dist[i] << ' ';
		else
			cout << "inf" << ' ';

	cout << endl << "// Ways //" << endl;   // Печать путей всех вершин  
	for (int i = 0; i < n; i++) {
		cout << endl;
		cout << i;							// - i-я вершина
		cout << ' ' << dist[i];				// - расстояние до стартовой вершины от этой вершины
		cout << ' ' << up[i];				// - предшествующая вершина i-ой
		cout << endl;
	}

	/* Освобождение памяти */
	delete graph;
	delete[]dist;
	delete[]up;
		
	system("pause");// Задержка консоли
	return 0;
}