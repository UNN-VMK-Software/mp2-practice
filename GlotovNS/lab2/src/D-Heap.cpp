#include "D-Heap.h"

DHeap::DHeap(int d)
{
	if (d <= 0)
	{
		throw "DAryHeap: Nevernaya D-Arnost";
	}
	this->d = d;
	lastIdx = -1;
	keys = new Data*[maxSize];
}

DHeap::DHeap(const DHeap &heap)
{
	this->d = heap.d;
	keys = new Data*[maxSize];
	for (int i = 0; i <= heap.lastIdx; i++)
	{
		keys[i] = heap.keys[i];
	}
	this->lastIdx = heap.lastIdx;
}

DHeap::~DHeap()
{
	delete[] keys;
}

int DHeap::IsFull()
{
	return lastIdx >= maxSize - 1;
}

int DHeap::IsEmpty()
{
	return lastIdx == -1;
}

void DHeap::Add(Data *&key)
{
	if (IsFull())
	{
		throw "DAryHeap: No memory";
	}
	lastIdx++;
	keys[lastIdx] = key;
	Surfacing(lastIdx);
}

void DHeap::AddSet(Data **key, int num)
{
	if (lastIdx + num >= maxSize)
	{
		throw "DAryHeap: Too large set!";
	}
	for (int i = lastIdx + 1; i < lastIdx + num + 1; i++)
	{
		keys[i] = key[i - lastIdx - 1];
	}
	lastIdx += num;
	Hilling();
}

Data* DHeap::Erase()
{
	if (IsEmpty())
	{
		throw "DAryHeap: No data!";
	}
	Data* key = keys[lastIdx];
	lastIdx--;
	return key;
}

Data* DHeap::Erase(int i)
{
	if (IsEmpty())
	{
		throw "DAryHeap: No data!";
	}
	if ((i < 0) || (i > lastIdx))
	{
		throw "DAryHeap: Invalid index";
	}
	Data* key = keys[i];
	if (i == lastIdx)
	{
		lastIdx--;
		return key;
	}
	Transposition(i, lastIdx);
	lastIdx--;
	Immersion(i);
	return key;
}

void DHeap::Transposition(int i, int j)
{
	if ((i < 0) || (j < 0) || (i > lastIdx) || (j > lastIdx))
	{
		throw "DAryHeap: Invalid indexes";
	}
	Data* tmp = keys[i];
	keys[i] = keys[j];
	keys[j] = tmp;
}

void DHeap::Surfacing(int i)
{
	if ((i < 0) || (i > lastIdx))
	{
		throw "DAryHeap: Invalid index";
	}
	int p = (i - 1) / d;
	while (i > 0) {
		if (keys[p]->priorities < keys[i]->priorities)
		{
			break;
		}
		Transposition(p, i);
		i = p;
		p = (i - 1) / d;
	}
}

void DHeap::Immersion(int i)
{
	if ((i < 0) || (i > lastIdx))
	{
		throw "DAryHeap: Invalid index";
	}
	int c = MinChild(i);
	while ((c != -1) && (keys[c]->priorities < keys[i]->priorities))
	{
		Transposition(i, c);
		i = c;
		c = MinChild(i);
	}
}

void DHeap::Hilling()
{
	for (int i = lastIdx; i >= 0; i--)
	{
		Immersion(i);
	}
}

int DHeap::MinChild(int i)
{
	int f = i * d + 1;
	if (f > lastIdx)
	{
		return -1;
	}
	int l = std::min(i*d + d, lastIdx);
	int c;
	Data* minKey = keys[f];
	c = f;
	for (int k = f + 1; k <= l; k++)
	{
		if (minKey->priorities > keys[k]->priorities)
		{
			minKey = keys[k];
			c = k;
		}
	}
	return c;
}