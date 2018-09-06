#ifndef ALGORITHM_H 
#define ALGORITHM_H



#include "Priority_Queue.h"
#include "D_Heap.h"
#include "Graph.h"

using namespace std;

template <class KeyType>
class Algorithm
{
public:
	static KeyType* Dijkstra(int, KeyType *&, Graph<KeyType>*&);
};



template <class KeyType>
KeyType* Algorithm<KeyType>::Dijkstra(int s, KeyType *&P, Graph<KeyType>*& gr)
{
	int n = gr->GetCount();
	int m = gr->GetEdgeSize();
	KeyType **graph = new KeyType*[n];
	for (int i = 0; i < n; i++)
		graph[i] = new KeyType[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			graph[i][j] = -1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (gr->GetEdge(j)->from == i)
				graph[gr->GetEdge(j)->to][gr->GetEdge(j)->from] = gr->GetEdge(j)->weight;
			if (gr->GetEdge(j)->to == i)
				graph[gr->GetEdge(j)->from][gr->GetEdge(j)->to] = gr->GetEdge(j)->weight;

		}

	KeyType *distance = new KeyType[n];
	int *vis = new int[n];
	for (int i = 0; i < n; i++)
		vis[i] = -1;
	vis[0] = s;
	int w, min;
	for (int i = 0; i < n; i++)
	{
		if (graph[s][i] == -1)
			distance[i] = max_heap;
		else distance[i] = graph[s][i];
	}
	for (int i = 1; i < n - 1; i++)
	{
		min = max_heap;
		for (int k = 0; k < n; k++) {
			if (distance[k] < min && k != s && !gr->Scan(k, vis))
			{
				w = k;
				min = distance[k];
			}
		}
		if (min == max_heap)
			break;
		vis[i] = w;
		for (int j = 1; j < n + 1; j++)
		{
			if (!gr->Scan(j, vis) && graph[w][j] != -1 && (distance[w] + graph[w][j]) <= distance[j])
			{
				P[j] = w;
				distance[j] = distance[w] + graph[w][j];
			}
		}
	}

	distance[s] = 0;
	return distance;
}
#endif 