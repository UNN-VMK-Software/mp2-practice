#include "..//include/Deijkstra.h"

DataFloat::DataFloat(int v, float dist)
{
	this->v = v;
	priorities = dist;
}

void Dijkstra::dijkstra(Graph *&graph, int s, float *&distance, int *&up)
{
	int n = graph->GetVerticesNum();
	int m = graph->GetRealSize();
	if ((s < 0) || (s >= n))
	{
		throw "Dijkstra: Invalid start vertex!";
	}
	Data** dist = new Data*[n];
	up = new int[n];
	PriorityQueue *queue = new PriorityQueueHeap();
	for (int i = 0; i < n; i++)
	{
		up[i] = i;
		dist[i] = new DataFloat(i, FLT_MAX);
		if (i == s)
		{
			dist[s]->priorities = 0;
		}
		queue->push(dist[i]);
	}
	WeightedEdge** edges = graph->GetEdgeSet();
	while (!queue->isEmpty())
	{
		int vConsidered = ((DataFloat*)queue->pop())->v;
		float delta;
		for (int i = 0; i < m; i++)
		{
			int vIncident = -1;
			if (edges[i]->k == vConsidered)
			{
				vIncident = edges[i]->n;
			}
			if (edges[i]->n == vConsidered)
			{
				vIncident = edges[i]->k;
			}
			if (vIncident == -1) continue;
			float way = dist[vConsidered]->priorities + graph->GetWeight(vConsidered, vIncident);
			delta = dist[vIncident]->priorities - way;
			if (delta > 0)
			{
				dist[vIncident]->priorities = way; 
				up[vIncident] = vConsidered;		
				queue->refresh();
			}
		}
	}
	distance = new float[n];
	for (int i = 0; i < n; i++)
	{
		distance[i] = dist[i]->priorities;
	}
	for (int i = 0; i < n; i++)
	{
		delete dist[i];
	}
	delete[]dist;
	delete queue;
}