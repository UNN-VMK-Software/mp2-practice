#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

#define maxSizeVertices 1000


class WeightedEdge
{
public:
	int n;			   
	int k;			   
	float weight;	       
	WeightedEdge(int n, int k, float weight);
};

class Graph
{
private:
	int ver;			
	int reb;				
	int current_reb;			
	int current_ver;		
	WeightedEdge** edges;   
	int* vertices;	
	void GenerateVertices(int &N, int &K);
	float GenerateWeight(float minRange, float maxRange);
	void Cleaner();
	int SearchEdge(int n, int k);
	bool SearchVershinu(int ver);
	void AddVershini(int n, int k);
public:
	// Конструкторы
	Graph(int n);
	Graph(int n, int m);
	~Graph();
	void GenerateGraph(float minRange, float maxRange);     
	void AddEdge(int N, int K, float weight);				
	void RemoveEdge(int N, int K);							
	int GetVerticesNum();					
	int GetEdgeSize();						
	int GetRealSize();						
	bool IsConnectivity();					
	WeightedEdge** GetEdgeSet();			
	WeightedEdge*  GetEdge(int j);			
	float GetWeight(int N, int K);		
	void PrintList();                       		      
};


