#include "binary_search_tree.h"
#include "priority_queue.h"
#include "graph.h"
#include "binary_search_tree_based_priority_queue.h"
#include "kraskal.h"
#include <iostream>

using namespace std;

int main(void)
{
	setlocale(LC_ALL, "Russian");

	int n, m;

	cout << "¬ведите число вершин вашего графа" << endl;
	cin >> n;
	cout << "¬ведите число ребер вашего графа" << endl;
	cin >> m;
	Edge* E = new Edge[m];
	int l = 0;//ходилка по массиву ребер
	for (int i = 0; i < n; i++)
	{
		cout << "¬ведите веса всех ребер, св€зывающих вершину " << i << endl;
		for (int j = i + 1; j < n; j++)
		{
			float w;
			cout << " с вершиной " << j << ": ";
			cin >> w;
			cout << endl;
			if (w != 0) {
				Edge tmp(i, j, w);
				E[l] = tmp;
				l++;
			}
			if (l > m) cout << "Error!" << endl;
		}
	}

	Graph G(n, m, E);
	PriorityQueue<Edge>* Q = new BinarySearchTreeBasedPriorityQueue<Edge>;
	Edge* WE = new Edge[n - 1];
	AlgoritmKraskala AK;
	WE = AK.Kraskal(&G, Q);
	return 0;
}

	