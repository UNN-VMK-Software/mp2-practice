#include "..//include/priorityqueue.h"
#include "..//include/Graph.h"
#include <iostream>
#include <cfloat>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, m;
	int	t = 0;
	std::cout << "Введите количество вершин графа" << endl;
	std::cin >> n;
	std::cout << "Введите количество вершин графа" << endl;
	std::cin >> m;
	Graph graph(n, m);
	graph.generateGraph(-10, 10);
	graph.printgraph();
	return 0;
}