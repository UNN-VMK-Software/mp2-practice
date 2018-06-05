#pragma once
#include"Edge.h"
#include <vector>
using namespace std;

struct vertex
{
	int point_index = 0;
	double distance = 0;
	int from = -1;

	vertex(int point_index, double distance, int from)
		: point_index(point_index), distance(distance), from(from)
	{
	}

	bool operator<(const vertex& p) const { return distance < p.distance; }
};


class Graph
{
	void Generate(int n, int m);
	vector<Edge> edges;
	vector<int> points;
public:
	Graph(int n, int m);	
	Graph(vector<Edge> edges);
	int PointsSize()const;
	int EdgesSize()const;
	vector<Edge> GetEdges() const;
	vector<int> GetPoints() const;
	void print();
};
