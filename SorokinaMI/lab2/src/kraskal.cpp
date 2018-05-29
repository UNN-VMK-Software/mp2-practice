#include "kraskal.h"
#include "separated_sets.h"


Edge* AlgoritmKraskala::Kraskal(Graph*g, PriorityQueue<Edge>* queue)
{
	SeparatedSets U(g->GetN());
	int nE = g->GetN() - 1; //число ребер в составе минимального остовного дерева
	int kE = 0; // число ребер в оставном дереве сейчас
	Edge* E = new Edge[nE];
	for (int i = 0;i < g->GetM();i++)
	{
		queue->push(g->GetEdge(i));
	}
	while ((!queue->IsEmpty()) &&(kE < nE))
	{
		Edge Tmp = queue->pop();
		int A = Tmp.GetStart(), B = Tmp.GetFinish();
		if (U.DefineSubset(A) != U.DefineSubset(B)) 
		{
			U.Unite(B, A);
			E[kE] = Tmp;
			kE++;
		}
	}

	return E;
}