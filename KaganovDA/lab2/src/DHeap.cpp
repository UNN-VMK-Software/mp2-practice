#include "DHeap.h"


DHeap::DHeap(int d)
{
	if (d <= 0)
		throw "DHeap: Invalid element";
	this->d = d;
	idx = -1;
	keys = new Data*[maxSize];
}

DHeap::DHeap(const DHeap &heap)
{
	this->d = heap.d;
	keys = new Data*[maxSize];
	for (int i = 0; i <= heap.idx; i++)
		keys[i] = heap.keys[i];
	this->idx = heap.idx;
}

DHeap::~DHeap()
{
	delete[] keys;
}

void DHeap::Add(Data *&key)
{
	if (IsFull())
		throw "DHeap: No Memory";
	idx++;
	keys[idx] = key;
	Surfacing(idx);
}

void DHeap::AddSet(Data **key, int num)
{
	if (idx + num >= maxSize)
		throw "DAryHeap: Too large set!";
	for (int i = idx + 1; i < idx + num + 1; i++)
	{
		keys[i] = key[i - idx - 1];
	}
	idx += num;
	Hilling();
}

Data* DHeap::Delete()
{
	if (IsEmpty())
		throw "DHeap: No data";
	Data* key = keys[idx];
	idx--;
	return key;
}

Data* DHeap::Remove(int i)
{
	if (IsEmpty())
		throw "DHeap: No data";
	if ((i < 0) || (i > idx))
		throw "DHeap: Invalid index";

	Data* key = keys[i];
	if (i == idx)
	{
		idx--;
		return key;
	}
	Transpose(i, idx);
	idx--;
	Sinking(i);
	return key;
}

void DHeap::Transpose(int i, int j)
{
	if ((i < 0) || (j < 0) || (i > idx) || (j > idx))
		throw "DHeap: Invalid indexes";
	Data* tmp = keys[i];
	keys[i] = keys[j];
	keys[j] = tmp;
}

void DHeap::Surfacing(int i)
{
	if ((i < 0) || (i > idx))
		throw "DHeap: Invalid index";

	int p = (i - 1) / d;
	while (p > 0 && keys[p]->priorities > keys[i]->priorities) {
		Transpose(i, p);
		i = p;
		p = (i - 1) / d;
	}
}

void DHeap::Sinking(int i)
{
	if ((i < 0) || (i > idx))
		throw "DHeap: Invalid index";

	int c = MinChild(i);
	while ((c != -1) && (keys[c]->priorities < keys[i]->priorities)) {
		Transpose(i, c);
		i = c;
		c = MinChild(i);
	}
}

void DHeap::Hilling()
{
	for (int i = idx; i >= 0; i--)
		Sinking(i);
}

const int DHeap::IsFull()
{
	return idx >= maxSize - 1;
}

const int DHeap::IsEmpty()
{
	return idx == -1;
}

int DHeap::MinChild(int i)
{
	int f = i * d + 1;
	if (f > idx)
		return -1;

	int l = std::min(i*d + d, idx);
	int c;

	Data* minKey = keys[f];
	c = f;
	for (int k = f + 1; k <= l; k++) {
		if (minKey->priorities > keys[k]->priorities) {
			minKey = keys[k];
			c = k;
		}
	}
	return c;
}