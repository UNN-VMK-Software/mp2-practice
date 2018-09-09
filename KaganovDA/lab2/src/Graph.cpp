#include "Graph.h"


Edge::Edge(int Ne, int Ke, float W)
{
	this->Ne = Ne;
	this->Ke = Ke;
	this->W = W;
}

Graph::Graph(int n)
{
	if ((n < 0) || (n > maxVerticesSize))
		throw "Graph: Invalid namber of vertices";
	else
		this->n = n;
	this->m = n * (n - 1) / 2;
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
	Clean();
	delete[] edges;
	delete[] vertices;
}

void Graph::Generate(float minRange, float maxRange)
{
	int Ne;
	int Ke;
	float W;

	if (minRange > maxRange)
		throw "Graph: Invalid ranges";

	if (m_cur) {
		Clean();
		m_cur = 0;
	}

	srand(time(NULL));
	for (int i = 0; i < m; i++) {
		GenerateVertices(Ne, Ke);
		W = GenerateWeight(minRange, maxRange);
		edges[i] = new Edge(Ne, Ke, W);
		m_cur++;
	}
}

void Graph::AddEdge(int Ne, int Ke, float W)
{
	if (m_cur == m)
		throw "Graph: Graph is full";
	if (Ne == Ke)
		throw "Graph: Loops are disabled";
	if (FindEdge(Ne, Ke) != -1)
		throw "Graph: multiple edges arent allowed!";
	edges[m_cur] = new Edge(Ne, Ke, W);
	m_cur++;
}

void Graph::DelEdge(int Ne, int Ke)
{
	int i = FindEdge(Ne, Ke);
	if (i == -1)
		throw "Graph: try delete non-existent edge";
	delete edges[i];
	edges[i] = edges[m_cur - 1];
	m_cur--;
}

int Graph::GetVerticesNum()
{
	return n;
}

int Graph::GetEdgeSize()
{
	return m;
}

int Graph::GetRealSize()
{
	return m_cur;
}

Edge** Graph::GetEdgeSet()
{
	if (m_cur == 0)
		return 0;
	return edges;
}

Edge* Graph::GetEdge(int i)
{
	return edges[i];
}

float Graph::GetWeight(int Ne, int Ke)
{
	int i = FindEdge(Ne, Ke);
	if (i == -1)
		throw "Graph: Invalid edge!";
	return edges[i]->W;
}

void Graph::PrintList()
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

void Graph::GenerateVertices(int &Ne, int &Ke)
{
	do {
		Ne = rand() % n;
		Ke = rand() % n;
	} while ((Ne == Ke) || (FindEdge(Ne, Ke) != -1));
}

float Graph::GenerateWeight(float minRange, float maxRange)
{
	double a = minRange;
	double b = (double)(maxRange - minRange) / RAND_MAX;
	double result = b * rand() + a;
	return result;
}

void Graph::Clean()
{
	for (int i = 0; i < m_cur; i++)
		delete edges[i];
}

int Graph::FindEdge(int Ne, int Ke)
{
	for (int i = 0; i < m_cur; i++)
		if ((edges[i]->Ke == Ke) &&
			(edges[i]->Ne == Ne) ||
			(edges[i]->Ne == Ke) &&
			(edges[i]->Ke == Ne))
			return i;
	return -1;
}
