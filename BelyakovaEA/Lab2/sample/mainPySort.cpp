#include "dheap.h"
#include "PySort.h"
#include <stdio.h>

const int SIZE = 10;

int main() {


	int d = 4;
	int nVertex = 4;
	int nEdges = 5;

	if (nEdges <= 0 || nVertex <= 0)
	{
		printf("ERROR: Number of edges and verteces must be positive!\n");
		return 1;
	}

	//printf("Sort\n");
	int *arr = new int[SIZE];

	for (int i = 0; i < SIZE; ++i)
	{
		arr[i] = i;
	}

	for (int i = 0; i < SIZE; ++i)
	{
		printf("%d; ", arr[i]);
	}
	printf("\n");

	DHeap<int> *heap = new DHeap<int>(arr, d, SIZE);
	printf("Sort\n");
	PyrSort(heap);

	for (int i = 0; i < SIZE; ++i)
	{
		printf("%d; ", arr[i]);
	}

	printf("\n");

	delete heap;
	delete[] arr;
	return 0;
}