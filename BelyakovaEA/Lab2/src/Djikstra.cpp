#include "Dijkstra.h"
#include "dheap.h"
#include "PriorituQueue.h"

VertexDist* Dijkstra::DijkstraSearch(const Graph& graph /*,TODO: arnost*/)
{
	VertexDist *result = new VertexDist[graph.GetVertexNum()];

	//Fill values for root
	result[0].vertex = 0;
	result[0].dist = 0.0;
	result[0].upVertex = 0;

	//Fill values for other verteces
	//Infinity == (Sum of all weights + 1)
	for (int i = 1; i < graph.GetVertexNum(); ++i)
	{
		result[i].vertex = i;
		result[i].dist = graph.GetSumOfWeights();
		result[i].upVertex = i;
	}

	PriorityQueueDHeap<VertexDist> dheap(result, 4 , graph.GetVertexNum());

	while (!dheap.isEmpty())
	{
		VertexDist vd = dheap.Pop();
		NeighboorVector neighboors = graph.GetNeigboors(vd.vertex);

		for (int i = 0; i < neighboors.size(); ++i) //cocedi
		{
			for (int j = 0; j < dheap.GetSize(); ++j) //cocedi ostavshiesya v kuche
			{
				if (dheap.GetElement(j).vertex == neighboors[i].vertex)
				{
					if (dheap.GetElement(j).dist > vd.dist + neighboors[i].edgeWeight)
					{
						dheap.GetElement(j).dist = vd.dist + neighboors[i].edgeWeight;
						dheap.GetElement(j).upVertex = vd.vertex;
					}
				}
			}
		}

		dheap.RepairQueue();
	}

	dheap.SetSize(graph.GetVertexNum());
	return result;
}