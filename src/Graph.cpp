#include "Graph.h"
#include "DHeapBasePriorityQueue.h"
#include <ostream>
#include <iostream>
#include <ctime>
using namespace std;

bool Tut(vector<int> points, int P)
{
	for (double point : points)
	{
		if (P == point)
		{
			return true;
		}
	}
	return false;
}

void Graph::Generate(int n, int m)
{
	if (n <= -1 || m <= 0 || n*(n - 1) / 2 < m || n - 1 > m)
	{
		throw exception("Can not generete graph");
	}
	points = vector<int>();
	points.reserve(n);
	for (int i = 0; i < n; i++)
	{
		points.push_back(i);
	}
	srand(time(nullptr));
	edges.reserve(m);
	for (int i = 0; i < n - 1; i++)
	{
		edges.push_back(Edge(i, i + 1, rand() % 45 + 1));
		m--;
	}
	while (m > 0)
	{
		const Edge e = Edge(rand() % n, rand() % n, rand() % 45 + 1);
		if (e.P1 == e.P2)
		{
			continue;
		}
		int i;
		for (i = 0; i < edges.size(); i++)
		{
			if (e == edges[i])
			{
				break;
			}
		}
		if (i == edges.size())
		{
			edges.push_back(e);
			m--;
		}
	}
}


Graph::Graph(int n, int m)
{
	Generate(n, m);
}

Graph::Graph(vector<Edge> edges)
{
	points.reserve(2 * edges.size());
	for (int i = 0; i < edges.size(); i++)
	{
		if (!Tut(points, edges[i].P1))
		{
			points.push_back(edges[i].P1);
		}
		if (!Tut(points, edges[i].P2))
		{
			points.push_back(edges[i].P2);
		}
	}

	this->edges = edges;
}



int Graph::PointsSize() const
{
	return points.size();
}

int Graph::EdgesSize() const
{
	return edges.size();
}

vector<Edge> Graph::GetEdges() const
{
	return edges;
}

vector<int> Graph::GetPoints() const
{
	return points;
}

void Graph::print()
{
	cout << "points" << endl;
	for (int i = 0; i < points.size(); i++) {
		cout.width(4);
		cout << points[i];
	}
	cout << endl << "edges" << endl;
	for (Edge e : edges) {
		cout.width(4);
		cout << e.P1;
		cout.width(4);
		cout << e.P2;
		cout.width(4);
		cout << e.W << endl;
	}
}
