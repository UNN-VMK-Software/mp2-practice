#include "dejkstra.h"
#include <iostream>

using namespace std;

//#define MAX 1000;

void AlgoritmDejkstri::Dejkstra(Graph* g, PriorityQueue<Vertex>* q)
{
	
	int n = g->GetN();
	int m = g->GetM();

	Vertex* dist = new Vertex[n];

	int* up = new int[n];
	
	for (int i = 0; i < n; i++) {
	    Vertex tmp(i,100000);
		up[i] = i;
		dist[i] = tmp;
		q->push(dist[i]);
	}
	dist[0].SetMark(0);

	Edge** edges = new Edge*[m];
	for (int i = 0;i < m;i++)
	{
		edges[i] = new Edge(g->GetEdge(i));
	}

	while (!q->IsEmpty())
	{
		int vConsidered = q->pop().GetId(); //vConsidered - currid
		float delta;

		for (int i = 0; i < m; i++)
		{
			int vIncident = -1;
			if (edges[i]->GetFinish() == vConsidered)
				vIncident = edges[i]->GetStart();
			if (edges[i]->GetStart() == vConsidered)
				vIncident = edges[i]->GetFinish();
			if (vIncident == -1) continue;

			float way = dist[vConsidered].GetMark() + g->GetEdgeWeight(vConsidered, vIncident);
			delta = dist[vIncident].GetMark() - way;
			if (delta > 0)
			{
				dist[vIncident].SetMark(way);  
				up[vIncident] = vConsidered;		
			}
		}
	}
	float* Distance = new float[n];
	for (int i = 0; i < n; i++)
	Distance[i] = dist[i].GetMark();

	//вывод
	for (int i = 0;i < n;i++)
	{
		cout << Distance[i] << " ";
	}
	cout << endl;
	for (int i = 0;i < n;i++)
	{
		cout << up[i] << " ";
	}
    // удаление выделенной памяти
	for (int i = 0;i < m;i++)
	{
		delete edges[i];
	}
	delete[]edges;

	    delete[]up;

	delete[]dist;

}