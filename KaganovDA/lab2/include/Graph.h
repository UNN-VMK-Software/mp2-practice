#pragma once
#include <ctime>
#include <cstdlib>
#include <iostream>

#define maxVerticesSize 1000

class Edge {
public:
	int Ne;			//начало
	int Ke;			//конец
	float W;		//вес ребра

	Edge(int Ne, int Ke, float W);
};

class Graph
{
private:
	int n;				//число вершин
	int m;				//число рёбер
	int m_cur;
	Edge** edges;		//массив указателей на рёбра
	int* vertices;
public:
	Graph(int n);
	Graph(int n, int m);
	~Graph();

	void Generate(float minRange, float maxRange);		//стройка графа
	void AddEdge(int Ne, int Ke, float weight);
	void DelEdge(int Ne, int Ke);
	int GetVerticesNum();
	int GetEdgeSize();
	int GetRealSize();
	Edge** GetEdgeSet();
	Edge*  GetEdge(int i);
	float GetWeight(int Ne, int Ke);
	void PrintList();
private:
	void GenerateVertices(int &Ne, int &Ke);
	float GenerateWeight(float minRange, float maxRange);
	void Clean();
	int FindEdge(int Ne, int Ke);
};
