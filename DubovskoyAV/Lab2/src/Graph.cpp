
#include "graph.h"

WeightedEdge::WeightedEdge(int Ne, int Ke, float W)
{
	this->Ne = Ne;// Начальная вершина
	this->Ke = Ke;// Конечная вершина
	this->W = W;  // Вес ребра из N в K
}

void Graph::generateVertices(int & Ne, int & Ke)
{
	do {
		Ne = rand() % n;
		Ke = rand() % n;
	} while ((Ne == Ke) || (searchEdge(Ne, Ke) != -1));
}

float Graph::generateW(float minRange, float maxRange)
{
	double i = minRange;
	double j = (double)(maxRange - minRange) / RAND_MAX;
	double result = j * rand() + i;
	return result;
}

void Graph::cleaner()
{
	for (int i = 0; i < m_cur; i++)
		delete edges[i];
}

int Graph::searchEdge(int Ne, int Ke)
{
	for (int i = 0; i < m_cur; i++) {
		if ((edges[i]->Ke == Ke) &&
			(edges[i]->Ne == Ne) ||
			(edges[i]->Ne == Ke) &&
			(edges[i]->Ke == Ne))
			return i;
	}
	return -1;
}

Graph::Graph(int n)
{
	if ((n < 0) || (n > maxVerticesSize))
		throw "Graph: invalid number of vertexes";
	else
		this->n = n;
	this->m = n * (n - 1) / 2;
	m_cur = 0;
	vertices = new int[n];
	edges = new WeightedEdge*[m];
}

Graph::Graph(int n, int m)
{
	if ((n < 0) || (n > maxVerticesSize))
		throw "Graph: invalid number of vertexes";
	else
		this->n = n;

	if ((m < 0) || (m > n*(n - 1) / 2) || (m < n - 1))
		throw "Graph: invalid number of edges";
	else
		this->m = m;

	m_cur = 0;

	vertices = new int[n];
	edges = new WeightedEdge*[m];
}

Graph::~Graph() {
	cleaner();
	delete[] edges;
	delete[] vertices;
}

void Graph::generateGraph(float minRange, float maxRange)
{
	int Ne;
	int Ke;
	float W;

	if (minRange > maxRange)
		throw "Graph: Invalid ranges";

	if (m_cur) {		// Если граф не пуст
		cleaner();
		m_cur = 0;
	}

	srand(time(NULL));
	for (int i = 0; i < m; i++) {
		generateVertices(Ne, Ke);
		W = generateW(minRange, maxRange);
		edges[i] = new WeightedEdge(Ne, Ke, W);
		m_cur++;
	}
}

void Graph::addEdge(int Ne, int Ke, float _W)
{
	if (m_cur == m)
		throw "Graph: Graph is full";
	if (Ne == Ke)
		throw "Graph: Ne!=Ke";
	if (searchEdge(Ne, Ke) != -1)
		throw "Graph: edge already being";
	edges[m_cur] = new WeightedEdge(Ne, Ke, _W);
	m_cur++;
}

void Graph::removeEdge(int Ne, int Ke)
{
	int j = searchEdge(Ne, Ke);
	if (j == -1)
		throw "Graph: edge not found";
	delete edges[j];
	edges[j] = edges[m_cur - 1];
	m_cur--;
}

int Graph::getVerticesNum()
{
	return n;
}

int Graph::getEdgeSize()
{
	return m;
}

int Graph::getRealSize()
{
	return m_cur;
}

WeightedEdge** Graph::getEdgeSet()
{
	if (m_cur == 0)
		return 0;
	return edges;
}

WeightedEdge* Graph::getEdge(int j)
{
	return edges[j];
}

float Graph::getW(int Ne, int Ke)
{
	int j = searchEdge(Ne, Ke);
	if (j == -1)
		throw "Graph: edge not found";
	return edges[j]->W;
}

void Graph::printList()
{
	using namespace std;
	for (int i = 0; i < n; i++)
	{
		cout << i << " : ";
		for (int j = 0; j < m_cur; j++)
		{
			if (edges[j]->Ne == i)
				cout << edges[j]->Ke << '(' << edges[j]->W << ')' << ", ";
			if (edges[j]->Ke == i)
				cout << edges[j]->Ne << '(' << edges[j]->W << ')' << ", ";
		}
		cout << endl;
	}
}

