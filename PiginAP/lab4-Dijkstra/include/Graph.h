#pragma once
#include <ctime>
#include <cstdlib>
#include <iostream>

#define maxVerticesSize 1000
//=======================================================||=======================================================
class Edge {
public:
	int N;
	int K;
	float weight;

	Edge(int N, int K, float weight);
};
//=======================================================||=======================================================
class Graph {
private:
	int n;
	int m;
	int m_cur;
	Edge** edges;
	int* vertices;
public:
	Graph(int n);
	Graph(int n, int m);
	~Graph();

	void generateGraph(float minRange, float maxRange);
	void addEdge(int N, int K, float weight);
	void delEdge(int N, int K);

	int getVerticesNum();
	int getEdgeSize();
	int getRealSize();
	Edge** getEdgeSet();
	Edge*  getEdge(int j); 
	float getWeight(int N, int K);

	void printList();

private:
	void generateVertices(int &N, int &K);
	float generateWeight(float minRange, float maxRange);
	void cleaner();
	int findEdge(int N, int K);
};