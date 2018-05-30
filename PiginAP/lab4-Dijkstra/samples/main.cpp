#include "priority_queue.h"
#include "Graph.h"
#include <iostream>

int main()
{
	Graph graph(7, 10);
	graph.generateGraph(-100, 100);
	graph.printList();
	return 0;
}