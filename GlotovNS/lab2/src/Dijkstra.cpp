#include "Dijkstra.h"

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
	PriorityQueue *queue = new DHeapBasedPriorityQueue();
	for (int i = 0; i < n; i++)
	{
		up[i] = i;
		dist[i] = new DataFloat(i, FLT_MAX);
		if (i == s)
		{
			dist[s]->priorities = 0;
		}
		queue->Push(dist[i]);
	}
	WeightedEdge** edges = graph->GetEdgeSet();
	while (!queue->IsEmpty())
	{
		int vConsidered = ((DataFloat*)queue->Pop())->v;
		float delta;
		for (int i = 0; i < m; i++)
		{
			int vIncident = -1;
			if (edges[i]->kver == vConsidered)
			{
				vIncident = edges[i]->nver;
			}
			if (edges[i]->nver == vConsidered)
			{
				vIncident = edges[i]->kver;
			}
			if (vIncident == -1) continue;
			float way = dist[vConsidered]->priorities + graph->GetWeight(vConsidered, vIncident);
			delta = dist[vIncident]->priorities - way;
			if (delta > 0)
			{
				dist[vIncident]->priorities = way;  //поскольку в очереди лежат указатели на объекты dist[i],
				up[vIncident] = vConsidered;		//то значени€ в очереди автоматически измен€тс€.
				queue->Refresh();
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