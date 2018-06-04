#include "..\include\Dheap.h"





Dheap::Dheap(int ar)
{
	if (ar <= 0)
		throw
		exception("Arity must be positive");
	this->d = ar;
	labels = new VertexLabel*[max_heap];
	lastidx = -1;
}


Dheap::~Dheap()
{
	delete[]labels;
}


void Dheap::transpose(int i, int j)
{
	if ((i < 0) || (j < 0) || (i > lastidx) || (j > lastidx))
		throw "Invalid indexes";
	VertexLabel* tmp = labels[i];
	labels[i] = labels[j];
	labels[j] = tmp;
}


void Dheap::add(VertexLabel* &key)
{
	if (isFull())
		throw "No memory";
	lastidx++;
	labels[lastidx] = key;
	surfacing(lastidx);
}


void Dheap::addSet(VertexLabel** key, int num)
{
	if (lastidx + num >= max_heap)
		throw "DAryHeap: Too large set!";
	for (int i = lastidx + 1; i < lastidx + num + 1; i++)
	{
		labels[i] = key[i - lastidx - 1];
	}
	lastidx += num;
	spudding();
}


VertexLabel* Dheap::erase(int i)
{
	if (isEmpty())
		throw "No data!";
	if ((i < 0) || (i > lastidx))
		throw "Invalid index";

	VertexLabel* key = labels[i];
	if (i == lastidx)
	{
		lastidx--;
		return key;
	}
	transpose(i, lastidx);
	lastidx--;
	sinking(i);
	return key;
}



void Dheap::surfacing(int i)
{
	if ((i < 0) || (i > lastidx))
		throw "Invalid index";

	int p = (i - 1) / d;
	while (i > 0) {
		if (labels[p]->label < labels[i]->label)
			break;
		transpose(p, i);
		i = p;
		p = (i - 1) / d;
	}
}


void Dheap::sinking(int i)
{
	if ((i < 0) || (i > lastidx))
		throw "Invalid index";

	int c = minChild(i);
	while ((c != -1) && (labels[c]->label < labels[i]->label)) {
		transpose(i, c);
		i = c;
		c = minChild(i);
	}
}


void Dheap::spudding()
{
	for (int i = lastidx; i >= 0; i--)
		sinking(i);
}


int Dheap::isFull()
{
	return lastidx >= max_heap - 1;
}


int Dheap::isEmpty()
{
	return lastidx == -1;;
}


int Dheap::minChild(int i)
{
	int f = i * d + 1;
	if (f > lastidx)
		return -1;

	int l = std::fmin(i*d + d, lastidx);
	int c;

	VertexLabel* minKey = labels[f];
	c = f;
	for (int k = f + 1; k <= l; k++) {
		if (minKey->label > labels[k]->label) {
			minKey = labels[k];
			c = k;
		}
	}
	return c;
}


