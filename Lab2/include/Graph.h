#include <iostream>
#include <cstdlib>
#include <ctime>

#define maxVerticesSize 1000


class WeightedEdge {
public:
	int Ne;			// Начальная вершина
	int Ke;			// Конечная вершина
	float W;	// Вес ребра из N в K

	WeightedEdge(int Ne, int _Ke, float W);
};

class Graph {
private:
	int n;			// Количество вершин
	int m;				// Количество ребер
	int m_cur;			// Текущее количество ребер
	WeightedEdge** edges;   // Массив взвешенных ребер
	int* vertices;			// Массив вершин


	void generateVertices(int &Ne, int &Ke);					// Генерация вершин
	float generateW(float minRange, float maxRange);	// Генерация рандомных весов
	void cleaner();											// Удаление всех взвешенных ребер в графе
	int searchEdge(int Ne, int Ke);				// Поиск ребра по заданным вершинам

public:
	// Конструкторы
	Graph(int n);
	Graph(int n, int m);
	~Graph();

	void generateGraph(float minRange, float maxRange);     // Генерация графа в рандомном режиме
	void addEdge(int N, int K, float W);				// Добавление ребра
	void removeEdge(int N, int K);							// Удаление ребра

	int getVerticesNum();					// Число вершин
	int getEdgeSize();						// Длинна ребер
	int getRealSize();						// Реальное число ребер
	WeightedEdge** getEdgeSet();			// Массив взвешенных ребер
	WeightedEdge*  getEdge(int j);			// Возвращает заданное ребро
	float getW(int N, int K);			// Вес ребра с заданными вершинами

	void printList();                       //Вывод
};