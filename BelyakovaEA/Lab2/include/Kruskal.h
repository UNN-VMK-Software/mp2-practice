#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "dheap.h"
#include "Graph.h"
#include "SeparatedSet.h"
#include "PriorituQueue.h"

template<typename T>
class Algorithms {
public:
	static Graph* Kruskal(const Graph& graph, PriorityQueue<T>* queue); //?
};

template<typename T>
Graph* Algorithms<T>::Kruskal(const Graph& graph, PriorityQueue<T>* queue)
{
	int n = graph.GetVertexNum();
	int m = graph.GetEdgesNum();
	Graph *tree = new Graph(n, m, false);

	SeparatedSet *set = new SeparatedSet(n);
	/*for (int i = 0; i < n; ++i)
	{
	set->makesets(i);
	}*/

	for (int i = 0; i < m; ++i)
	{
		queue->Push(T(graph.GetEdge(i)));
	}

	int treeEdgeSize = 0;
	T tmp;

	while ((treeEdgeSize < n - 1) && (!queue->isEmpty()))
	{
		tmp = queue->Pop();

		int u = tmp.vertex;
		int v = tmp.upVertex;
		double weight = tmp.dist;

		int An = set->findsets(u);
		int Ak = set->findsets(v);

		if (An != Ak)
		{
			set->unionsets(An, Ak);
			printf("After union\n");
			tree->AddEdge(u, v, weight);
			printf("After add\n");
			++treeEdgeSize;
		}
	}

	//tree->Print();
	return tree;
}

template class Algorithms<VertexDist>;

#endif
