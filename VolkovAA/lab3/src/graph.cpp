#include "Graph.h"

Edge::Edge(int N, int K, float weight)
{
	this->N = N;
	this->K = K;
	this->weight = weight;
}

Graph::Graph(int n)
{
	if ((n < 0) || (n > maxVerticesSize))
		throw "Graph: Invalid namber of vertices";
	else
		this->n = n;
	this->m = n*(n - 1) / 2;
	m_cur = 0;
	vertices = new int[n];
	edges = new Edge*[m];
}

Graph::Graph(int n, int m)
{
	if ((n < 0) || (n > maxVerticesSize))
		throw "Graph: Invalid namber of vertices";
	else
		this->n = n;

	if ((m < 0) || (m > n*(n - 1) / 2))
		throw "Graph: Invalid namber of edges";
	else
		this->m = m;

	m_cur = 0;

	vertices = new int[n];
	edges = new Edge*[m];
}

Graph::~Graph()
{
	cleaner();
	delete[] edges;
	delete[]vertices;
}

int Graph::findEdge(int N, int K)
{
	for (int j = 0; j < m_cur; j++)
		if ((edges[j]->K == K) &&
			(edges[j]->N == N) ||
			(edges[j]->N == K) &&
			(edges[j]->K == N))
			return j;
	return -1;
}

void Graph::generateVertices(int &N, int &K)
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
	for (int i = 0; i < m_cur; i++)
		delete edges[i];
}

void Graph::generateGraph(float minRange, float maxRange)
{
	int N;
	int K;
	float weight;

	if (minRange > maxRange)
		throw "Graph: Invalid ranges";

	if (m_cur) {
		cleaner();
		m_cur = 0;
	}

	srand(time(NULL));
	for (int i = 0; i < m; i++) {
		generateVertices(N, K);
		weight = generateWeight(minRange, maxRange);
		edges[i] = new Edge(N, K, weight);
		m_cur++;
	}
}

void Graph::addEdge(int N, int K, float weight)
{
	if (m_cur == m)
		throw "Graph: Graph is full";
	if (N == K)
		throw "Graph: Loops are disabled";
	if (findEdge(N, K) != -1)
		throw "Graph: multiple edges arent allowed!";
	edges[m_cur] = new Edge(N, K, weight);
	m_cur++;
}

void Graph::delEdge(int N, int K)
{
	int j = findEdge(N, K);
	if (j == -1)
		throw "Graph: try delete non-existent edge";
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

Edge** Graph::getEdgeSet()
{
	if (m_cur == 0)
		return 0;
	return edges;
}

Edge* Graph::getEdge(int j)
{
	return edges[j];
}

float Graph::getWeight(int N, int K)
{
	int j = findEdge(N, K);
	if (j == -1)
		throw "Graph: Invalid edge!";
	return edges[j]->weight;
}

void Graph::printList()
{
	using namespace std;
	for (int i = 0; i < n; i++)
	{
		cout << i << " : ";
		for (int j = 0; j < m_cur; j++)
		{
			if (edges[j]->N == i)
				cout << edges[j]->K << '(' << edges[j]->weight << ')' << ", ";
			if (edges[j]->K == i)
				cout << edges[j]->N << '(' << edges[j]->weight << ')' << ", ";
		}
		cout << endl;
	}
}