#include "..\include\Algoritm.h"

CompleteVertex::CompleteVertex(int v, float dist)
{
	this->v = v;
	label = dist;
}



void Algoritm::Dijkstra(Graph*&graf, int s, float *&distance, int *&up)
{
	int n = graf->GetNumberofVertex();
	int m = graf->GetCursor();
	if ((s < 0) || (s >= n))
		throw
		exception("Element doesn't exist");

	VertexLabel** dist = new VertexLabel*[n];
	up = new int[n];

	priority_queue *queue = new DheapBasedPriorityQueue();

	for (int i = 0; i < n; i++) {
		up[i] = i;
		dist[i] = new CompleteVertex(i, FLT_MAX);
		if (i == s)
			dist[s]->label = 0;
		queue->push(dist[i]);
	}

	WeightedEdge** edges = graf->GetEdgeSet();
	while (!queue->isEmpty())
	{
		int vConsidered = ((CompleteVertex*)queue->pop())->v;
		float delta;

		for (int i = 0; i < m; i++)
		{
			int vIncident = -1;
			if (edges[i]->ke == vConsidered)
				vIncident = edges[i]->ne;
			if (edges[i]->ne == vConsidered)
				vIncident = edges[i]->ke;
			if (vIncident == -1) continue;

			float way = dist[vConsidered]->label + graf->GetWeight(vConsidered, vIncident);
			delta = dist[vIncident]->label - way;
			if (delta > 0)
			{
				dist[vIncident]->label = way;  
				up[vIncident] = vConsidered;		
				queue->refresh();
			}
		}
	}

	distance = new float[n];
	for (int i = 0; i < n; i++)
		distance[i] = dist[i]->label;

	

	for (int i = 0; i < n; i++)
		delete dist[i];
	delete[]dist;
	delete queue;
}



