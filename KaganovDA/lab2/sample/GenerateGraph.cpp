#include "Graph.h"
#include "Dejkstra.h"
#include <cfloat>
#include <locale.h>
#include <fstream>
#include <cstring>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	setlocale(LC_ALL, "Russian");
	Graph* graph;
	int n;			//количество вершин
	int m;			//количество рЄбер
	int s;			//вершина от которой считаетс€ кратчайший путь


	int typeGenerate;
	cout << "¬ведите кол-во вершин: ";
	cin >> n;
	cout << "¬ведите кол-во ребер: ";
	cin >> m;
	try
	{
		graph = new Graph(n, m);
	}
	catch (const char ex)
	{
		cout << ex;
		return -1;
	}

	cout << "¬ведите способ задани€ графа:" << endl;
	cout << "1. —лучайный: " << endl;
	cout << "2. ќт руки: " << endl;


	cin >> typeGenerate;
	switch (typeGenerate)
	{
	case 1: {
		try
		{
			int minRange;								
			int maxRange;					
			cout << "¬ведите минимальный вес ребра: ";
			cin >> minRange;
			cout << "¬ведите максимальный вес ребра: ";
			cin >> maxRange;
			graph->Generate(minRange, maxRange);
		}
		catch (const char ex)
		{
			cout << ex;
			return -1;
		}
		break;
	}
	case 2: {
		int _nac_ver, _kon_ver;
		float _weight;

		try
		{
			for (int i = 0; i < m; i++) {
				cout << "¬ведите начальную вершину: " << endl;
				cin >> _nac_ver;
				cout << "¬ведите конечную вершину: " << endl;
				cin >> _kon_ver;
				cout << "¬ведите вес: " << endl;
				cin >> _weight;
				graph->AddEdge(_nac_ver, _kon_ver, _weight);
			}
		}
		catch (const char ex)
		{
			cout << ex;
			return -1;
		}
		break;
	}
	}
	cout << "Write start vertices for Dijkstra" << endl;
	cin >> s;

	graph->PrintList();
	cout << endl;

	float *dist;										
	int *up;
	try {
		Dejkstra::dejkstra(graph, s, dist, up);
	}
	catch (const char ex)
	{
		cout << ex;
		return -2;
	}

	cout << n << ' ' << m << endl;			
	cout << "start vertices = " << s << endl;

	m = graph->GetRealSize();
	Edge* edge;
	cout << " Matrix edges " << endl;
	for (int j = 0; j < m; j++) {
		edge = graph->GetEdge(j);
		cout << edge->Ne << ' ' << edge->Ke << ' ' << edge->W << endl;
	}

	cout << " Distances " << endl;
	for (int i = 0; i < n; i++)
		if (dist[i] != FLT_MAX)
			cout << dist[i] << ' ';
		else
			cout << "inf" << ' ';

	cout << endl << " Ways " << endl;
	for (int i = 0; i < n; i++) {
		cout << endl;
		cout << i;
		cout << " distance " << dist[i];	
		cout << " up " << up[i];
	}


	delete graph;
	delete[]dist;
	delete[]up;



	cout << endl;
	return 0;
}
