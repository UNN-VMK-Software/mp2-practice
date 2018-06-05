#include "dheap_sort.h"

void PiramidSortBasedDHeap::PiramidSort(int* keys, int n) 
{
	DHeap<int> heap(keys,n);
	heap.makeitheap();
	while (heap.GetCurrSize() > 1)
	{
		heap.transpose(0, heap.GetCurrSize() - 1);
		heap.ChangeCurrSize(heap.GetCurrSize()-1);
		heap.sinking(0);
	}
	heap.Print();
}