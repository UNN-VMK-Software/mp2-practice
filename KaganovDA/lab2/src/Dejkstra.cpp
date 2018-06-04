#include "Dejkstra.h"


DataFloat::DataFloat(int s, float dist)
{
	this->s = s;
	priorities = dist;
}

void Dejkstra::dejkstra(Graph *&graph, int s, float *&distance, int *&up)
{
	int n = graph->GetVerticesNum();
	int m = graph->GetRealSize();
	if ((s < 0) || (s >= n))
		throw "Dejkstra: Invalid start vertex";

	Data** dist = new Data*[n];
	up = new int[n];

	PriorityQueue *queue = QueueFactory::createQueue(static_cast<QueueID>(0));

	for (int i = 0; i < n; i++) {
		up[i] = i;
		dist[i] = new DataFloat(i, FLT_MAX);
		if (i == s)
			dist[s]->priorities = 0;
		queue->Push(dist[i]);
	}

	Edge** edges = graph->GetEdgeSet();
	while (!queue->IsEmpty())
	{
		int vConsidered = ((DataFloat*)queue->Pop())->s;
		float delta;

		for (int i = 0; i < m; i++)
		{
			int vIncident = -1;
			if (edges[i]->Ke == vConsidered)
				vIncident = edges[i]->Ne;
			if (edges[i]->Ne == vConsidered)
				vIncident = edges[i]->Ke;
			if (vIncident == -1) continue;

			float way = dist[vConsidered]->priorities + graph->GetWeight(vConsidered, vIncident);
			delta = dist[vIncident]->priorities - way;
			if (delta > 0)
			{
				dist[vIncident]->priorities = way;		//поскольку в очереди лежат указатели на объекты dist[i],
				up[vIncident] = vConsidered;			//то значение в очереди автоматически измен€тс€
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
