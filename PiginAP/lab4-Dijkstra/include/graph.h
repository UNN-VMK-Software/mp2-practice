#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <cstdlib>
#include <ctime>

#define maxVerticesSize 1000


class WeightedEdge {
public:
	int nac_ver;			// Начальная вершина
	int kon_ver;			// Конечная вершина
	float weight;	// Вес ребра из N в K

	WeightedEdge(int _nac_ver, int _kon_ver, float _weight);
};
//============================================================||============================================================
class Graph {
private:
	int vershini;			// Количество вершин
	int rebra;				// Количество ребер
	int tek_rebro;			// Текущее количество ребер
	WeightedEdge** edges;   // Массив взвешенных ребер
	int* vertices;			// Массив вершин
public:
	// Конструкторы
	Graph(int vershini);
	Graph(int vershini, int rebra);
	~Graph();

	void generateGraph(float minRange, float maxRange);					// Генерация графа в случайном порядке
	void addEdge(int nac_ver, int kon_ver, float weight);				// Добавление ребра
	void removeEdge(int nac_ver, int kon_ver);							// Удаление ребра

	int getVerticesNum();								// Число вершин
	int getEdgeSize();									// Максимальное число ребер
	int getRealSize();									// Реальное число ребер
	WeightedEdge** getEdgeSet();						// Массив взвешенных ребер
	WeightedEdge*  getEdge(int j);						// Возвращает заданное ребро
	float getWeight(int nac_ver, int kon_ver);			// Вес ребра с заданными вершинами

	void printList();



private:
	void generateVertices(int &nac_ver, int &kon_ver);					// Генерация вершин
	float generateWeight(float minRange, float maxRange);				// Генерация рандомных весов
	void cleaner();														// Удаление всех взвешенных ребер в графе
	int searchEdge(int _nac_ver, int _kon_ver);							// Поиск ребра по заданным вершинам

};
#endif;