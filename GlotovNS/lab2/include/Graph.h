#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

#define maxSizeVertices 1000


class WeightedEdge
{
public:
	int nver;			    // Начальная вершина
	int kver;			    // Конечная вершина
	float weight;	        // Вес ребра из N в K
	WeightedEdge(int nver, int kver, float weight);
};

class Graph
{
private:
	int vershini;			// Количество вершин
	int rebra;				// Количество ребер
	int tek_rebro;			// Текущее количество ребер
	int tek_vershina;		// Текущее количество вершин
	WeightedEdge** edges;   // Массив взвешенных ребер
	int* vertices;			// Массив вершин
public:
	// Конструкторы
	Graph(int n);
	Graph(int n, int m);
	~Graph();
	void GenerateGraph(float minRange, float maxRange);     // Генерация графа в рандомном режиме
	void AddEdge(int N, int K, float weight);				// Добавление ребра
	void RemoveEdge(int N, int K);							// Удаление ребра
	int GetVerticesNum();					// Число вершин
	int GetEdgeSize();						// Максимальное число ребер
	int GetRealSize();						// Реальное число ребер
	bool IsConnectivity();					// Проверка на связность графа
	WeightedEdge** GetEdgeSet();			// Массив взвешенных ребер
	WeightedEdge*  GetEdge(int j);			// Возвращает заданное ребро
	float GetWeight(int N, int K);			// Вес ребра с заданными вершинами
	void PrintList();                       // Отрисовка

											
private:
	void GenerateVertices(int &N, int &K);					// Генерация вершин
	float GenerateWeight(float minRange, float maxRange);	// Генерация рандомных весов
	void Cleaner();											// Удаление всех взвешенных ребер в графе
	int SearchEdge(int nver, int kver);				        // Поиск ребра по заданным вершинам
	bool SearchVershinu(int ver);							// Поиск заданной вершины (Существует ли она в массиве взвешенных ребер)
	void AddVershini(int nver, int kver);			        // Добавление вершин в массив вершин
};


