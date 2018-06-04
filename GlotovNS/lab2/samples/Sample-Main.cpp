#include "Dijkstra.h"
#include <cfloat>
#include <iostream>
#include "locale.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	Graph* graph;
	int n; // Количество вершин
	int m; // Количество ребер
	int s; // Стартовая вершина
	int typeGenerate;
	try
	{
		cout << "Введите количество вершин:" << endl;
		cin >> n;
		cout << "Введите количество ребер:" << endl;
		cin >> m;
		graph = new Graph(n, m);
	}
	catch (...)
	{
		return -1;
	}
	cout << "Выберите способ генерации графа:" << endl;
	cout << "1. Рандомный" << endl;
	cout << "2. Ручной" << endl;
	cin >> typeGenerate;
	switch (typeGenerate)
	{
		/* Рандомная генерация графа*/
	case 1: {
		try
		{
			int minRange; // Минимальное значение веса ребра
			int maxRange; // Максимальное значение веса ребра
			cout << "Введите минимальное значение веса ребра:" << endl;
			cin >> minRange;
			cout << "Введите максимальное значение веса ребра:" << endl;
			cin >> maxRange;
			graph->GenerateGraph(minRange, maxRange);
		}
		catch (...) {
			return -1;
		}
		break;
	}
			/* Ручная генерация графа*/
	case 2: {
		int nac_ver, kon_ver;
		float weight;
		try
		{
			for (int i = 0; i < m; i++)
			{
				cout << "Введите начальную вершину:" << endl;
				cin >> nac_ver;
				cout << "Введите конечную вершину:" << endl;
				cin >> kon_ver;
				cout << "Введите вес:" << endl;
				cin >> weight;
				graph->AddEdge(nac_ver, kon_ver, weight);
			}
		}
		catch (...)
		{
			return -1;
		}
		break;
	}
	}
	if (!graph->IsConnectivity())// Проверка на связность
	{
		return -3;
	}
	cout << "Введите начальную вершину для алгоритма Дейкстры:" << endl;
	cin >> s;
	graph->PrintList();
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
	m = graph->GetRealSize();
	WeightedEdge* edge;
	cout << "Матрица взвешенных вершин." << endl; // Печать матрицы взвешенный вершин
	for (int j = 0; j < m; j++) 
	{
		edge = graph->GetEdge(j);
		cout << edge->nver << ' ' << edge->kver << ' ' << edge->weight << endl;
	}
	cout << "Расстояние от заданной вершины до i-ой вершины:" << endl;	   // Печать расстояний от заданной вершины S до i-той вершины
	for (int i = 0; i < n; i++) 
	{
		if (dist[i] == FLT_MAX)
		{
			return -4;
		}
		cout << s << " -> " << i << " Дистанция = " << dist[i] << endl;
	}
	cout << endl << "Пути всех вершин:" << endl;   // Печать путей всех вершин  
	for (int i = 0; i < n; i++) 
	{
		int temp = i;
		cout << temp << " <- ";
		while (up[temp] != s) 
		{
			cout << up[temp] << " <- ";
			temp = up[temp];
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