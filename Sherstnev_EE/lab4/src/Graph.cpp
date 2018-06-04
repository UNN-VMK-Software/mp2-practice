#include "..\include\Graph.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <cstdlib>
#include <ctime>

using namespace std;


WeightedEdge::WeightedEdge(int ne, int ke, float we)
{
	this->ne = ne;
	this->ke = ke;
	this->we = we;
}



void Graph::generateVertices(int & N, int & K)
{
	do {
		N = rand() % n;
		K = rand() % n;
	} while ((N == K) || (findEdge(N, K) != -1));
}

float Graph::generateWeight(float minRange, float maxRange)
{
	double d = minRange;
	double c = (double)(maxRange - minRange) / RAND_MAX;
	double result = c * rand() + d;
	return result;
}

void Graph::cleaner()
{
	for (int i = 0; i < current; i++)
		delete edges[i];
}

int Graph::findEdge(int N, int K)
{
	for (int j = 0; j < current; j++)
		if ((edges[j]->ke == K) &&
			(edges[j]->ne == N) ||
			(edges[j]->ne == K) &&
			(edges[j]->ke == N))
			return j;
	return -1;
}

Graph::Graph(int versh, int rebr)
{
	if (versh < 0)
		throw
		exception("incorrect data");
	else
		this->n = versh;
	if ((rebr < 0) || rebr > n*(n - 1) / 2)
		throw
		exception("incorrect data");
	else
		this->m = rebr;
	current = 0;
	edges = new WeightedEdge*[m];
	vertices = new int[n];
}

void Graph::generateGraph(float minRange, float maxRange)
{
	int N;
	int K;
	float weight;

	if (minRange > maxRange)
		throw "Graph: Invalid ranges";

	if (current) {
		cleaner();
		current = 0;
	}

	srand(time(NULL));
	for (int i = 0; i < m; i++) {
		generateVertices(N, K);
		weight = generateWeight(minRange, maxRange);
		edges[i] = new WeightedEdge(N, K, weight);
		current++;
	}
}

void Graph::Push(int beg, int end, float fatness)
{
	if (current == m)
		throw
		exception("Graph is full!");
	if (beg == end)
		throw
		exception("Loops are not allowed!");
	if ((beg > n) || (end > n))
		throw
		exception("There are no such vertexs");
	edges[current] = new WeightedEdge(beg, end, fatness);
	current++;
}

void Graph::ConnectCheck()
{
	bool* check = new bool[n];
	int curVertex = -1;
	for (int i = 0; i < n; i++)
	{
		check[i] = false;
	}

	for (int i = 0; i < m; i++)
	{
		curVertex = edges[i]->ne;
		check[curVertex] = true;
		curVertex = edges[i]->ke;
		check[curVertex] = true;
		curVertex = -1;
	}
	for (int i = 0; i < n; i++)
	{
		if (check[i] == false)
		{
			throw
				exception("Nesvyaznij graf");
			return;

		}
	}
	return;
}


int Graph::GetNumberofVertex()
{
	return n;
}

int Graph::GetNumberofEdges()
{
	return m;
}

int Graph::GetCursor()
{
	return current;
}

WeightedEdge * Graph::GetEdge(int x)
{
	return edges[x];
}

WeightedEdge ** Graph::GetEdgeSet()
{
	if (current == 0)
		return 0;
	return edges;
}

float Graph::GetWeight(int beg, int end)
{
	if ((beg < 0) || (end > n) || (beg < 0) || (end > n))
		throw
		exception("Incorrect vertexes");
	for (int i = 0; i < current; i++)
		if ((edges[i]->ne == beg) && (edges[i]->ke == end) || (edges[i]->ne == end) && (edges[i]->ke == beg))
			return edges[i]->we;
}

void Graph::Print()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < current; j++)
			if (edges[j]->ne == i)
				cout << edges[j]->ne << " " << edges[j]->ke << "(" << edges[j]->we << ")" << endl;
}

Graph::~Graph()
{
	for (int i = 0; i < current; i++)
		delete edges[i];
	delete[] edges;
	delete[]vertices;
}
