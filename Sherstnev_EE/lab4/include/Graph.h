#pragma once

class WeightedEdge
{
public:
	int ne; //nachalo
	int ke; //konec
	float we; //ves
	WeightedEdge(int ne, int ke, float we);
};

class Graph
{
private:
	int n; // vers
	int m; // rebra
	int current;
	WeightedEdge** edges;
	int* vertices;
private:
	void generateVertices(int &N, int &K);
	float generateWeight(float minRange, float maxRange);
	void cleaner();
	int findEdge(int N, int K);
public:
	Graph(int n, int m);
	void generateGraph(float minRange, float maxRange);

	void Push(int, int, float);
	void ConnectCheck();
	int GetNumberofVertex();
	int GetNumberofEdges();
	int GetCursor();
	WeightedEdge* GetEdge(int);
	WeightedEdge** GetEdgeSet();
	float GetWeight(int, int);
	void Print();
	~Graph();
};

