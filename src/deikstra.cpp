#include <vector>
#include <Graph.h>
#include <DHeapBasePriorityQueue.h>
using namespace std;

vector<vertex> alg_deikstra(const Graph& g, const int start)
{
	vector<int> points = g.GetPoints();
	int n = points.size();
	vector<vector<double>> matrix = vector<vector<double>>(n);
	for (int i = 0; i < n; i++) {
		matrix[i] = vector<double>(n, 0);
	}

	vector<Edge> edges = g.GetEdges();
	int m = edges.size();
	for (int i = 0; i < m; i++) {
		matrix[edges[i].P1][edges[i].P2] = edges[i].W;
		matrix[edges[i].P2][edges[i].P1] = edges[i].W;
	}

	vector<double> distance = vector<double>(g.PointsSize(), numeric_limits<double>::infinity());
	vector<int> from = vector<int>(g.PointsSize(), -1);

	distance[start] = 0;

	DHeapBasePriorityQueue<vertex> queue = DHeapBasePriorityQueue<vertex>();
	queue.Push(vertex(start, distance[start], from[start]));

	while (!queue.IsEmpty())
	{
		const vertex p = queue.Pop();
		vector<double>& weight = matrix[p.point_index];
		for (unsigned int i = 0; i < weight.size(); i++)
		{
			if (weight[i] == 0)
				continue;

			const double newDist = distance[p.point_index] + weight[i];
			if (newDist < distance[i])
			{
				distance[i] = newDist;
				from[i] = p.point_index;
				queue.Push(vertex(i, distance[i], from[i]));
			}
		}
	}

	vector<vertex> result = vector<vertex>();
	result.reserve(n);
	for (int i = 0; i < n; i++)
	{
		result.push_back(vertex(points[i], distance[i], from[i]));
	}
	return result;
}


int main() {
	vector<Edge> edges = vector<Edge>();
	/*edges.push_back(Edge(0, 3, 11));
	edges.push_back(Edge(0, 1, 5));
	edges.push_back(Edge(1, 2, 2));
	edges.push_back(Edge(0, 2, 8));
	edges.push_back(Edge(2, 3, 3));*/
	Graph g = Graph(6,8);
	g.print();
	vector<vertex> v = alg_deikstra(g, 0);

	cout << "Point:    ";
	for (int i = 0; i < v.size(); i++)
	{
		cout.width(4);
		cout << v[i].point_index;
	}
	cout << endl << "Distance: ";
	for (int i = 0; i < v.size(); i++)
	{
		cout.width(4);
		cout << v[i].distance;
	}
	cout << endl << "From:     ";
	for (int i = 0; i < v.size(); i++)
	{
		cout.width(4);
		cout << v[i].from;
	}
	cout << endl;

	return 0;
}
