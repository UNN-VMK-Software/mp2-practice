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

class Graph {
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

	void generateGraph(float minRange, float maxRange);     // Генерация графа в рандомном режиме
	void addEdge(int N, int K, float weight);				// Добавление ребра
	void removeEdge(int N, int K);							// Удаление ребра

	int getVerticesNum();					// Число вершин
	int getEdgeSize();						// Максимальное число ребер
	int getRealSize();						// Реальное число ребер
	bool isConnectivity();					// Проверка на связность графа
	WeightedEdge** getEdgeSet();			// Массив взвешенных ребер
	WeightedEdge*  getEdge(int j);			// Возвращает заданное ребро
	float getWeight(int N, int K);			// Вес ребра с заданными вершинами
	void printList();						// Печать графа
	void printVertices();					// Печать массива вершин


	/* Вспомогательные функции */
private:
	void generateVertices(int &N, int &K);					// Генерация вершин
	float generateWeight(float minRange, float maxRange);	// Генерация рандомных весов
	void cleaner();											// Удаление всех взвешенных ребер в графе
	int searchEdge(int _nac_ver, int _kon_ver);				// Поиск ребра по заданным вершинам
	bool searchVershinu(int _ver);							// Поиск заданной вершины (Существует ли она в массиве взвешенных ребер)
	void addVershini(int _nac_ver, int _kon_ver);			// Добавление вершин в массив вершин


};