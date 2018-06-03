#include "Graph.h"
#include "Dejkstra.h"
#include <cfloat>
#include <fstream>
#include <cstring>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	Graph *graph;
	int n;
	int m;
	int s;
	if (argc == 6) {
		try {
			n = atoi(argv[1]);					//количество вершин
			m = atoi(argv[2]);					//количество рёбер
			int minRange = atoi(argv[3]);		//минимальный вес
			int maxRange = atoi(argv[4]);		//максимальный вес			
			s = atoi(argv[5]);					//вершина от которой считается кратчайший путь
			graph = new Graph(n, m);
			graph->Generate(minRange, maxRange);
		}
		catch (const char* error) {
			return -1;
		}
	}
	else if (argc == 3) {
		string filename(argv[1]);
		ifstream input(filename);
		if (!input) {
			cout << "Error";
			return 2;
		}
		try {
			input >> n;
			input >> m;
			s = atoi(argv[2]);
			graph = new Graph(n);
			int Ne, Ke;
			float weight;
			while (!input.eof()) {
				input >> Ne;
				input >> Ke;
				input >> weight;
				graph->AddEdge(Ne, Ke, weight);
			}
		}
		catch (const char* error) {
			return -1;
		}
		input.close();
	}
	else return 1;

	graph->PrintList();
	cout << endl;

	float *dist;
	int *up;
	try {
		Dejkstra::dejkstra(graph, s, dist, up);
	}
	catch (const char* error) {
		return -2;
	}

	remove("previous_ways.txt");
	ofstream output("previous_ways.txt");
	output.precision(2);

	output << n << ' ' << m << endl;
	output << s << endl;

	m = graph->GetRealSize();
	Edge* edge;
	for (int j = 0; j < m; j++) {
		edge = graph->GetEdge(j);
		output << edge->Ne << ' ' << edge->Ke << ' ' << edge->W << endl;
	}

	for (int i = 0; i < n; i++)
		if (dist[i] != FLT_MAX)
			cout << dist[i] << ' ';
		else
			cout << "inf" << ' ';

	cout << "Печать всех путей" << endl;
	for (int i = 0; i < n; i++) {
		output << endl;
		output << i;							//номер вершины
		output << " distance: " << dist[i];		//растояние до вершины s
		output << " up: " << up[i];				//предшествующая вершина
	}

	output.close();
	delete graph;
	delete[]dist;
	delete[]up;
	return 0;
}
