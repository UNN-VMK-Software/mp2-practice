#ifndef GRAPH_H
#define GRAPH_H

#include "Graph.h"

WeightedEdge::WeightedEdge(int nver, int kver, float weight)
{
	this->kver = kver;
	this->nver = nver;
	this->weight = weight;
}

Graph::Graph(int vershini)
{
	if ((vershini < 0) || (vershini > maxSizeVertices))
	{
		throw "Graph: Nepravilnoe chislo vershin";
	}
	else
	{
		this->vershini = vershini;
	}
	this->rebra = vershini * (vershini - 1) / 2;
	tek_rebro = 0;
	vertices = new int[vershini];
	edges = new WeightedEdge*[rebra];
}

Graph::Graph(int vershini, int rebra)
{
	if ((vershini < 0) || (vershini > maxSizeVertices))
	{
		throw "Graph: Nepravilnoe chislo vershin";
	}
	else
	{
		this->vershini = vershini;
	}
	if ((rebra < 0) || (rebra > vershini*(vershini - 1) / 2) || (rebra < vershini - 1))
	{
		throw "Graph: Nepravilnoe chislo reber";
	}
	else
	{
		this->rebra = rebra;
	}
	tek_rebro = 0;
	tek_vershina = 0;
	vertices = new int[vershini];
	for (int i = 0; i < vershini - 1; i++)
	{
		vertices[i] = -1;
	}
	edges = new WeightedEdge*[rebra];
}


Graph::~Graph()
{
	Cleaner();
	delete[] edges;
	delete[] vertices;
}


int Graph::SearchEdge(int nver, int kver)
{
	for (int i = 0; i < tek_rebro; i++)
	{
		if ((edges[i]->kver == kver) && (edges[i]->nver == nver) || (edges[i]->nver == kver) && (edges[i]->kver == nver))
		{
			return i;
		}
	}
	return -1;
}
bool Graph::SearchVershinu(int ver)
{
	for (int i = 0; i < tek_rebro; i++) 
	{
		if ((edges[i]->nver == ver) || edges[i]->kver == ver)
		{
			return true;
		}
	}
	return false;
}
void Graph::AddVershini(int nver, int kver)
{
	if (!SearchVershinu(nver)) 
	{
		vertices[tek_vershina] = nver;
		tek_vershina++;
	}
	if (!SearchVershinu(kver))
	{
		vertices[tek_vershina] = kver;
		tek_vershina++;
	}
}

void Graph::GenerateVertices(int & nver, int & kver)
{
	do {
		nver = rand() % vershini;
		kver = rand() % vershini;
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
	for (int i = 0; i < tek_rebro; i++)
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
		throw "Graph: Invalid ranges";
	}
	if (tek_rebro)// Если граф не пуст
	{
		Cleaner();
		tek_rebro = 0;
	}
	srand(time(NULL));
	for (int i = 0; i < rebra; i++)
	{
		GenerateVertices(nver, kver);
		weight = GenerateWeight(minRange, maxRange);
		edges[i] = new WeightedEdge(nver, kver, weight);
		AddVershini(nver, kver);
		tek_rebro++;
	}
}


void Graph::AddEdge(int nver, int kver, float weight)
{
	if (tek_rebro == rebra)
	{
		throw "Graph: Graph polniy";
	}
	if (nver == kver)
	{
		throw "Graph: Nelzya cikly";
	}
	if (SearchEdge(nver, kver) != -1)
	{
		throw "Graph: Ne dostupni neskolko re";
	}
	edges[tek_rebro] = new WeightedEdge(nver, kver, weight);
	AddVershini(nver, kver);
	tek_rebro++;
}

void Graph::RemoveEdge(int nver, int kver)
{
	int j = SearchEdge(nver, kver);
	if (j == -1)
	{
		throw "Graph: Popytka ydaleniya ne sush. rebra";
	}
	delete edges[j];
	edges[j] = edges[tek_rebro - 1];
	tek_rebro--;
}

int Graph::GetVerticesNum()
{
	return vershini;
}

int Graph::GetEdgeSize()
{
	return rebra;
}

int Graph::GetRealSize()
{
	return tek_rebro;
}
bool Graph::IsConnectivity()
{
	for (int i = 0; i < vershini; i++)
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
	if (tek_rebro == 0)
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
		throw "Graph: Nevernoe rebro";
	}
	return edges[j]->weight;
}

void Graph::PrintList()
{
	using namespace std;
	for (int i = 0; i < vershini; i++)
	{
		cout << i << " : ";
		for (int j = 0; j < tek_rebro; j++)
		{
			if (edges[j]->nver == i)
			{
				cout << edges[j]->kver << '(' << edges[j]->weight << ')' << ", ";
			}
			if (edges[j]->kver == i)
			{
				cout << edges[j]->nver << '(' << edges[j]->weight << ')' << ", ";
			}
		}
		cout << endl;
	}
}
#endif