#include "graph.h"
#include <iostream>

using namespace std;

Vertex::Vertex(int i, float k)
{
	id = i;
	mark = k;
}
bool Vertex::operator<(const Vertex& e)
{
	if (id < e.id)
		return true;
	else 
		return false;
}
Vertex& Vertex::operator=(const Vertex& e)
{
	id = e.id;
	mark = e.mark;
	return *this;
}
 ostream& operator<<(ostream& os, const Edge& e)
 {
	 cout << e.W <<" ";
	 return os;
 }

 bool Edge::operator<(const Edge& e)
 {
	 if (W < e.W) return true;
	 else return false;
 }

Edge::Edge(int i, int j, float k)
{
	N = i;
	K = j;
	W = k;
}

Edge& Edge::operator=(const Edge& e)
{
	W = e.W;
	K = e.K;
	N = e.N;
	return *this;
}
Edge::Edge(const Edge& e) 
{
	W = e.W;
	K = e.K;
	N = e.N;
}

Graph::Graph(int k, int l)
{
	n = k;
	m = l;
	edges = new Edge[m];
}


Graph::Graph(int k, int l, Edge* edg)
{
	n = k;
	m = l;
	edges = new Edge[m];
	for (int i = 0; i < m; i++)
	{
		edges[i] = edg[i];
	}
}

Graph::~Graph()
{
	delete[] edges;
}

float Graph::GetEdgeWeight(int n, int k)
{
	for (int i = 0; i < m;i++)
	{
		if ((edges[i].GetStart() == n) && (edges[i].GetFinish() == k))
			return edges[i].GetWeight();
	}
	return -1;
}
