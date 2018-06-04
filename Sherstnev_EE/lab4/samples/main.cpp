#include <iostream>
#include "graph.h"
#include "Algoritm.h"
#include <cfloat>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
	Graph *graph;
	int n;
	int m;
	int s;
	try {
		int N;
		int K;
		float weight;
		int flag;
		std::cout << "vvedite chislo vershin: ";
		std::cin >> n;
		std::cout << "vvedite chislo reber: ";
		std::cin >> m;
		std::cout << "vvedite startovuy vershinu: ";
		std::cin >> s;
		graph = new Graph(n, m);
		int cur = graph->GetCursor();
		std::cout << "\n 1 - Graph will fills automaticly. \n 2 - Graph will fill manually \n";
		std::cin >> flag;
		std::cout << "\n";
		switch (flag)
		{
		case 1: {
			graph->generateGraph(0, 50);
			break;
		}
		case 2: {
			while (cur < m) {
				std::cout << "vvedite pervuy tochku: ";
				std::cin >> N;
				if (N == -1) break;
				std::cout << "vvedite vtoruy tochku: ";
				std::cin >> K;
				if (K == -1) break;
				std::cout << "vvedite ves rebra: ";
				std::cin >> weight;
				std::cout << "\n";
				graph->Push(N, K, weight);
				cur = graph->GetCursor();
			}
			break;
		}
		}

	}


	catch (...) {
		return -1;
	}

	try {
		graph->ConnectCheck();
	}

	catch (...) {
		return -1;
	}
	graph->Print();
	std::cout << endl;

	float *dist;
	int *up;
	try {
		Algoritm::Dijkstra(graph, s, dist, up);
	}
	catch (...) {
		return -2;
	}

	remove("ways.txt");
	ofstream output("ways.txt");
	output.precision(2);

	output << n << ' ' << m << endl;
	output << s << endl;

	m = graph->GetCursor();
	WeightedEdge* edge;
	for (int j = 0; j < m; j++) {
		edge = graph->GetEdge(j);
		output << edge->ne << ' ' << edge->ke << ' ' << edge->we << endl;
	}

	std::cout << "Distanses : \n";

	for (int i = 0; i < n; i++)
		if (dist[i] != FLT_MAX)
			std::cout << dist[i] << ' ';
		else
			std::cout << "inf" << ' ';

	std::cout << "\nPassed Vertexes: \n";

	for (int i = 0; i < n; i++)
		std::cout << up[i] << ' ';


	getchar();
	output.close();
	delete graph;
	delete[]dist;
	delete[]up;
	getchar();
	return 0;
}