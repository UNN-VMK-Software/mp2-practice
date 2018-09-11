#include <vector>
#include <Graph.h>
#include <DHeapBasePriorityQueue.h>

using namespace std;

vector<Edge> alg_kruscal(Graph g)
{
	vector<int> groups = vector<int>();
	groups.reserve(g.PointsSize());
	for (int i = 0; i < g.PointsSize(); i++)
	{
		groups.push_back(i);
	}
	vector<Edge> T;
	DHeapBasePriorityQueue<Edge> queue(g.GetEdges(), 2);
	int n = g.PointsSize();
	while (!queue.IsEmpty() && T.size() < n - 1)
	{
		Edge edge = queue.Pop();
		if (groups[edge.P1] != groups[edge.P2])
		{
			for (int i = 0; i < n; i++)
			{
				if (groups[i] == groups[edge.P2])
				{
					groups[i] = groups[edge.P1];
				}
			}
			T.push_back(edge);
		}
	}
	return T;
}


int main() {
	Graph test = Graph(8, 11);
	test.print();
	vector<Edge> test1 = alg_kruscal(test);
	for (int i = 0; i < test1.size(); i++) {
		cout << test1[i] << endl;
	}

	return 0;
}
