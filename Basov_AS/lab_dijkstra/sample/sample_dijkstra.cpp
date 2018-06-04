#include "dijkstra.h"
#include <cfloat>
#include <iostream>

using namespace std;

int main() {
	Graph* graph;
	int n; // Количество вершин
	int m; // Количество ребер
	int s; // Стартовая вершина


	int typeGenerate;
	try
	{
		cout << "Write number vertices" << endl;
		cin >> n;
		cout << "Write number edges" << endl;
		cin >> m;
		graph = new Graph(n, m);
	}
	catch (...)
	{
		return -1;
	}

	cout << "Write type generate graph:" << endl;
	cout << "1. Random" << endl;
	cout << "2. Manual" << endl;


	cin >> typeGenerate;
	switch (typeGenerate)
	{
		/* Рандомная генерация графа*/
	case 1: {
		try
		{
			int minRange; // Минимальное значение веса ребра
			int maxRange; // Максимальное значение веса ребра
			cout << "Write minRange" << endl;
			cin >> minRange;
			cout << "Write maxRange" << endl;
			cin >> maxRange;
			graph->generateGraph(minRange, maxRange);
		}
		catch (...) {
			return -1;
		}
		break;
	}
			/* Ручная генерация графа*/
	case 2: {
		int _nac_ver, _kon_ver;
		float _weight;

		try
		{
			for (int i = 0; i < m; i++) {
				cout << "Write start vershinu" << endl;
				cin >> _nac_ver;
				cout << "Write finish vershinu" << endl;
				cin >> _kon_ver;
				cout << "Write weight" << endl;
				cin >> _weight;
				graph->addEdge(_nac_ver, _kon_ver, _weight);
			}
		}
		catch (...)
		{
			return -1;
		}
		break;
	}
	}
	if (!graph->isConnectivity()) // Проверка на связность
		return -3;
	graph->printVertices();
	cout << "Write start vertices for Dijkstra" << endl;
	cin >> s;

	graph->printList();
	cout << endl;

	float *dist;    // Массив расстояний между S и i-той вершиной
	int *up;		// Массив вершин, предшествующих в кратчайшем пути
	try {
		Dijkstra::dijkstra(graph, s, dist, up);
	}
	catch (...) {
		return -2;
	}

	cout << n << ' ' << m << endl;	      // Печать количество вершин
	cout << s << endl;					  // Печать стартовой вершины

	m = graph->getRealSize();
	WeightedEdge* edge;
	cout << "// Matrix edges //" << endl; // Печать матрицы взвешенный вершин
	for (int j = 0; j < m; j++) {
		edge = graph->getEdge(j);
		cout << edge->nac_ver << ' ' << edge->kon_ver << ' ' << edge->weight << endl;
	}

	cout << endl << "// Distances //" << endl;	   // Печать расстояний от заданной вершины S до i-той вершины
	for (int i = 0; i < n; i++) {
		if (dist[i] == FLT_MAX) return -4;
		cout << s << " -> " << i << " distance = " << dist[i] << endl;
	}


	cout << endl << "// Ways //" << endl;   // Печать путей всех вершин  
	for (int i = 0; i < n; i++) {
		int j = i;
		cout << j << " <- ";
		while (up[j] != s) {
			cout << up[j] << " <- ";
			j = up[j];
		}
		cout << s << endl;
	}

	// Освобождение памяти
	delete graph;
	delete[]dist;
	delete[]up;


	// Задержка консоли
	cout << endl;
	system("pause");
	return 0;
}