#include "dijkstra.h"
#include <cfloat>
#include <iostream>

using namespace std;

int main() {
	Graph* graph;
	int n;			// вершины
	int m;			// ребера
	int s;			// Start vertices


	int typeGenerate;
		cout << "Write number vertices" << endl;
		cin >> n;
		cout << "Write number edges" << endl;
		cin >> m;
	
	
		if ((m < 0) || (m > n*(n - 1) / 2) || (m < n - 1))
		{
			cout<<"Graph isn't svyazny"<<endl;
			return -1;
		}
		else{
			graph = new Graph(n, m);}
	
	
		
		
			
		

	cout << "Write type of generate graph:" << endl;
	cout << "1. Random" << endl;
	cout << "2. Manual" << endl;
	
	
	cin >> typeGenerate;
	switch (typeGenerate)
	{
	// Рандомная генерация графа
	case 1: {
		try
		{
			int minRange;								// Минимальное значение веса ребра
			int maxRange;								// Максимальное значение веса ребра
			cout << "Write min Range" << endl;
			cin >> minRange;
			cout << "Write max Range" << endl;
			cin >> maxRange;
			graph->generateGraph(minRange, maxRange);
		}
		catch (const char ex) 
		{
			cout<<ex;
			return -1;
		}
		break;
	}
	// Ручная генерация графа
	case 2: {
		int nac_ver, kon_ver;
		float weight;
	
		try
		{
			for (int i = 0; i < m; i++) {
				cout << "Write start vertices" << endl;
				cin >> nac_ver;
				cout << "Write finish vertices" << endl;
				cin >> kon_ver;
				cout << "Write weight" << endl;
				cin >> weight;
				graph->addEdge(nac_ver, kon_ver, weight);
			}
		}
		catch (const char ex) 
		{
			cout<<ex;
			return -1;
		}
		break;
	}
	}
	cout << "Write start vertices for Dijkstra" << endl;
	cin >> s;
	
	graph->printList();
	cout << endl;

	float *dist;										// Массив расстояний между S и i-той вершиной
	int *up;											// Массив вершин, предшествующих в кратчайшем пути
	try {
		Dijkstra::dijkstra(graph, s, dist, up);
	}
	catch (const char ex) 
		{
			cout<<ex;
			return -2;
		}

	cout << n << ' ' << m << endl;										// Печать количество вершин
	cout << "start vertices = " << s << endl;							 // Печать стартовой вершины

	m = graph->getRealSize();
	WeightedEdge* edge;
	cout << "// Matrix edges //" << endl;								// Печать матрицы взвешенный вершин
	for (int j = 0; j < m; j++) {
		edge = graph->getEdge(j);
		cout << edge->nac_ver<< ' ' << edge->kon_ver << ' ' << edge->weight << endl;
	}

	cout << "// Distances //" << endl;			 // Печать расстояний от заданной вершины S до i-той вершины
	for (int i = 0; i < n; i++)
		if (dist[i] != FLT_MAX)
			cout << dist[i] << ' ';
		else
			cout << "inf" << ' ';
	
	cout << endl << "// Ways //" << endl;			// Печать путей всех вершин  
	for (int i = 0; i < n; i++) {
		cout << endl;
		cout << i;									// - i-я вершина
		cout << ' ' << dist[i];						// - расстояние до S от этой вершины
		cout << ' ' << up[i];						// - предшествующая вершина i-ой
	}

	
	delete graph;				// Освобождение памяти
	delete[]dist;
	delete[]up;



	cout << endl;
	return 0;
}