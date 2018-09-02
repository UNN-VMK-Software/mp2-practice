#ifndef EDGE_H
#define EDGE_H

class Edge {
public:
	int Ne; // начало ребра
	int Ke; //конец ребра
	double W; // вес ребра

	Edge(int N, int K, double _W)
	{
		Ne = N;
		Ke = K;
		W = _W;
	}
};


class VertexDist
{
public:
	VertexDist() : vertex(0), dist(0.0), upVertex(0) {}
	VertexDist(const Edge& edge) : vertex(edge.Ne), upVertex(edge.Ke), dist(edge.W) {}


	int vertex;

	double dist;
	int upVertex;

	bool operator<(const VertexDist& vd)
	{
		return dist < vd.dist;
	}

	bool operator>(const VertexDist& vd)
	{
		return dist > vd.dist;
	}

	bool operator==(const VertexDist& vd)
	{
		return dist == vd.dist;
	}
};

#endif
