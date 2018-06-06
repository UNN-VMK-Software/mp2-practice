#include "Deijkstra.h"

DataFloat::DataFloat(int v, float dist)
{
	this->v = v;
	priorities = dist;
}

void Dijkstra::dijkstra(Graph *&graph, int s, float *&distance, int *&up)
{
	int n = graph->getVerticesNum();
	int m = graph->getRealSize();
	if ((s < 0) || (s >= n))
		throw "Dijkstra: Invalid start vertex!";

	Data** dist = new Data*[n];
	up = new int[n];

	PriorityQueue *queue = QueueFactory::createQueue(static_cast<QueueID>(0));

	for (int i = 0; i < n; i++) {
		up[i] = i;
		dist[i] = new DataFloat(i, FLT_MAX);
		if (i == s)
			dist[s]->priorities = 0;
		queue->push(dist[i]);
	}

	Edge** edges = graph->getEdgeSet();
	while (!queue->isEmpty())
	{
		int vConsidered = ((DataFloat*)queue->pop())->v;
		float delta;

		for (int i = 0; i < m; i++)
		{
			int vIncident = -1;
			if (edges[i]->K == vConsidered)
				vIncident = edges[i]->N;
			if (edges[i]->N == vConsidered)
				vIncident = edges[i]->K;
			if (vIncident == -1) continue;

			float way = dist[vConsidered]->priorities + graph->getWeight(vConsidered, vIncident);
			delta = dist[vIncident]->priorities - way;
			if (delta > 0)
			{
				dist[vIncident]->priorities = way;  //поскольку в очереди лежат указатели на объекты dist[i],
				up[vIncident] = vConsidered;		//то значени€ в очереди автоматически измен€тс€.
				queue->refresh();
			}
		}
	}

	distance = new float[n];
	for (int i = 0; i < n; i++)
		distance[i] = dist[i]->priorities;

	for (int i = 0; i < n; i++)
		delete dist[i];
	delete[]dist;
	delete queue;
}