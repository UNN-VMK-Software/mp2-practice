#pragma once
#include <iostream>
using namespace std;
struct Edge
{
	int P1;
	int P2;
	double W;

	bool operator < (const Edge &A)
	{
		return W < A.W;
	}

	Edge() = default;

	Edge(int p1, int p2, double w) 
	{
		P1 = p1;
		P2 = p2;
		W = w;
	}
	friend ostream& operator<< (ostream& o, const Edge& e) {
		o << "start = " << e.P1 << ", weight = " << e.W << ", finish = " << e.P2 << endl;
		return o;
	}
	bool operator ==(const Edge& a) const
	{
		return (P1 ==a.P1 && P2 == a.P2 || P2 == a.P1 && P1 == a.P2);
	}
};
