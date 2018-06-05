#pragma once
#include <iostream>

using namespace std;

class Edge
{
	int N; // начало
	int K; // конец
	float W; // вес
public:
	Edge() {};
	~Edge() {};
	Edge(int i, int j, float k);
	Edge(const Edge& e);

	int GetStart() { return N; };
	int GetFinish() { return K; };
	float GetWeight() { return W; };

	bool operator<(const Edge& e);
	bool operator>(const Edge& e) { return !(*this < e); };
	Edge& operator=(const Edge& e);
	friend ostream& operator<<(ostream& os, const Edge& e);
};

class Vertex
{
	int id;
	float mark;
public:
	Vertex() { id = -1; mark = 1000000.0; };
	~Vertex() {};
	Vertex(int i, float k);

	int GetId() { return id; };
	float GetMark() { return mark; };
	void SetMark(float v) { mark = v; }

	bool operator<(const Vertex& e);
	bool operator>(const Vertex& e) { return !(*this < e);};
	Vertex& operator=(const Vertex& e);

};


class Graph // неориентированный граф, не содержащий петель
{
	int n; // число вершин
	int m; // число ребер
	Edge* edges; 
public:
	Graph(int k, int l);
	Graph(int k, int l, Edge* edg);
	~Graph();
	float GetEdgeWeight(int n, int k);
	int GetN() { return n; };
	int GetM() { return m; };
	Edge GetEdge(int i) { return edges[i]; };
};



