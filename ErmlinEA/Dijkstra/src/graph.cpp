#ifndef GRAPH_H
#define GRAPH_H

#include "..//include/Graph.h"

WeightedEdge::WeightedEdge(int n, int k, float weight)
{
	this->k = k;
	this->n = n;
	this->weight = weight;
}

Graph::Graph(int ver)
{
	if ((ver < 0) || (ver > maxSizeVertices))
	{
		throw "Err";
	}
	else
	{
		this->ver = ver;
	}
	this->reb = ver * (ver - 1) / 2;
	current_reb = 0;
	vertices = new int[ver];
	edges = new WeightedEdge*[reb];
}

Graph::Graph(int ver, int reb)
{
	if ((ver < 0) || (ver > maxSizeVertices))
	{
		throw "Err";
	}
	else
	{
		this->ver = ver;
	}
	if ((reb < 0) || (reb > ver*(ver - 1) / 2) || (reb < ver - 1))
	{
		throw "Err";
	}
	else
	{
		this->reb = reb;
	}
	current_reb = 0;
	current_ver = 0;
	vertices = new int[ver];
	for (int i = 0; i < ver - 1; i++)
	{
		vertices[i] = -1;
	}
	edges = new WeightedEdge*[reb];
}


Graph::~Graph()
{
	Cleaner();
	delete[] edges;
	delete[] vertices;
}


int Graph::SearchEdge(int n, int k)
{
	for (int i = 0; i < current_reb; i++)
	{
		if ((edges[i]->k == k) && (edges[i]->n == n) || (edges[i]->n == k) && (edges[i]->k == n))
		{
			return i;
		}
	}
	return -1;
}
bool Graph::SearchVershinu(int ver)
{
	for (int i = 0; i < current_reb; i++)
	{
		if ((edges[i]->n == ver) || edges[i]->k == ver)
		{
			return true;
		}
	}
	return false;
}
void Graph::AddVershini(int n, int k)
{
	if (!SearchVershinu(n))
	{
		vertices[current_ver] = n;
		current_ver++;
	}
	if (!SearchVershinu(k))
	{
		vertices[current_ver] = k;
		current_ver++;
	}
}

void Graph::GenerateVertices(int & nver, int & kver)
{
	do {
		nver = rand() % ver;
		kver = rand() % ver;
	} while ((nver == kver) || (SearchEdge(nver, kver) != -1));
}

float Graph::GenerateWeight(float minRange, float maxRange)
{
	double d = minRange;
	double c = (double)(maxRange - minRange) / RAND_MAX;
	double result = c * rand() + d;
	return result;
}

void Graph::Cleaner()
{
	for (int i = 0; i < current_reb; i++)
	{
		delete edges[i];
	}
}

void Graph::GenerateGraph(float minRange, float maxRange)
{
	int nver;
	int kver;
	float weight;
	if (minRange > maxRange)
	{
		throw "Err";
	}
	if (current_ver)// Если граф не пуст
	{
		Cleaner();
		current_ver = 0;
	}
	srand(time(NULL));
	for (int i = 0; i < reb; i++)
	{
		GenerateVertices(nver, kver);
		weight = GenerateWeight(minRange, maxRange);
		edges[i] = new WeightedEdge(nver, kver, weight);
		AddVershini(nver, kver);
		current_reb++;
	}
}


void Graph::AddEdge(int nver, int kver, float weight)
{
	if (current_reb == reb)
	{
		throw "Err";
	}
	if (nver == kver)
	{
		throw "Err";
	}
	if (SearchEdge(nver, kver) != -1)
	{
		throw "Err";
	}
	edges[current_reb] = new WeightedEdge(nver, kver, weight);
	AddVershini(nver, kver);
	current_reb++;
}

void Graph::RemoveEdge(int nver, int kver)
{
	int j = SearchEdge(nver, kver);
	if (j == -1)
	{
		throw "Err";
	}
	delete edges[j];
	edges[j] = edges[current_reb - 1];
	current_reb--;
}

int Graph::GetVerticesNum()
{
	return ver;
}

int Graph::GetEdgeSize()
{
	return reb;
}

int Graph::GetRealSize()
{
	return current_reb;
}
bool Graph::IsConnectivity()
{
	for (int i = 0; i < ver; i++)
	{
		if (vertices[i] < 0)
		{
			return false;
		}
	}
	return true;
}

WeightedEdge** Graph::GetEdgeSet()
{
	if (current_reb == 0)
	{
		return 0;
	}
	return edges;
}

WeightedEdge* Graph::GetEdge(int j)
{
	return edges[j];
}

float Graph::GetWeight(int nver, int kver)
{
	int j = SearchEdge(nver, kver);
	if (j == -1)
	{
		throw "Err";
	}
	return edges[j]->weight;
}

void Graph::PrintList()
{
	using namespace std;
	for (int i = 0; i < ver; i++)
	{
		cout << i << " : ";
		for (int j = 0; j < current_reb; j++)
		{
			if (edges[j]->n == i)
			{
				cout << edges[j]->k << '(' << edges[j]->weight << ')' << ", ";
			}
			if (edges[j]->k == i)
			{
				cout << edges[j]->n << '(' << edges[j]->weight << ')' << ", ";
			}
		}
		cout << endl;
	}
}
#endif