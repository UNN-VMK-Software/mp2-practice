#ifndef  PYR_SORT_H
#define PYR_SORT_H

#include "dheap.h"

/*
template <class T> void PyrSort(DHeap<T>* heap)
{
heap->hilling();
int size = heap->GetSize();
while (size > 0)
{
heap->transpose(0, size - 1);
heap->remove(size - 1);
size--;
heap->sinking(0);
//size--;
}
}*/

template <class T> void PyrSort(DHeap<T>* heap)
{
	heap->hilling();
	int cur_size = heap->GetSize();
	int old_size = cur_size;
	while (cur_size > 0)
	{
		heap->transpose(0, cur_size - 1);
		cur_size--;
		heap->SetSize(cur_size);
		heap->sinking(0);
	}

	heap->SetSize(old_size);
}

template void PyrSort<int>(DHeap<int>*);

#endif 


