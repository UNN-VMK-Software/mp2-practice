#include "DHeap.h"

DHeap::DHeap(int d)
{
	if (d <= 0)
		throw "DHeap: incorrect D-Arn";
	this->d = d;
	lastIdx = -1;
	keys = new Data*[maxSize];
}

DHeap::DHeap(const DHeap &heap)
{
	this->d = heap.d;
	keys = new Data*[maxSize];
	for (int i = 0; i <= heap.lastIdx; i++)
		keys[i] = heap.keys[i];
	this->lastIdx = heap.lastIdx;
}

DHeap::~DHeap()
{
	delete[] keys;
}

int DHeap::isFull()//Проверка на полноту
{
	return lastIdx >= maxSize - 1;
}

int DHeap::isEmpty()//Проверка на пустоту
{
	return lastIdx == -1;
}

void DHeap::add(Data *&key) // Вставка элемента в кучу
{
	if (isFull())
		throw "DHeap: No memory";
	lastIdx++;
	keys[lastIdx] = key;
	surfacing(lastIdx);
}

void DHeap::addSet(Data **key, int num)  // Вставка массива элементов в кучу
{
	if (lastIdx + num >= maxSize)
		throw "DHeap: Too large set!";
	for (int i = lastIdx + 1; i < lastIdx + num + 1; i++)
	{
		keys[i] = key[i - lastIdx - 1];
	}
	lastIdx += num;
	hilling();
}

Data* DHeap::erase() // Изъятие последнего элемента
{
	if (isEmpty())
		throw "DHeap: no data";
	Data* key = keys[lastIdx];
	lastIdx--;
	return key;
}

Data* DHeap::erase(int i) // Изъятие i-го элемента
{
	if (isEmpty())
		throw "DHeap: No data!";
	if ((i < 0) || (i > lastIdx))
		throw "DHeap: invalid index";

	Data* key = keys[i];
	if (i == lastIdx)
	{
		lastIdx--;
		return key;
	}
	transposition(i, lastIdx);
	lastIdx--;
	immersion(i);
	return key;
}

void DHeap::transposition(int i, int j)// Обмен значений
{
	if ((i < 0) || (j < 0) || (i > lastIdx) || (j > lastIdx))
		throw "DHeap:  invalid indexes";
	Data* tmp = keys[i];
	keys[i] = keys[j];
	keys[j] = tmp;
}

void DHeap::surfacing(int i)// Всплытие
{
	if ((i < 0) || (i > lastIdx))
		throw "DHeap: invalid index";

	int p = (i - 1) / d;
	while (i > 0) {
		if (keys[p]->priorities < keys[i]->priorities)
			break;
		transposition(p, i);
		i = p;
		p = (i - 1) / d;
	}
}

void DHeap::immersion(int i)// Погружение
{
	if ((i < 0) || (i > lastIdx))
		throw "DHeap: invalid index";

	int c = minChild(i);
	while ((c != -1) && (keys[c]->priorities < keys[i]->priorities)) {
		transposition(i, c);
		i = c;
		c = minChild(i);
	}
}

void DHeap::hilling()// Окучивание
{
	for (int i = lastIdx; i >= 0; i--)
		immersion(i);
}

int DHeap::minChild(int i)// Поиск минимального потомка
{
	int f = i * d + 1;
	if (f > lastIdx)
		return -1;

	int l = std::min(i*d + d, lastIdx);
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