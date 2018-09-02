#include "SeparatedSet.h"

#include <stdio.h>

SeparatedSet::SeparatedSet(int _size)
{
	this->size = _size;
	harVec = new int[size];

	for (int i = 0; i < size; ++i)
	{
		harVec[i] = i;
	}
}


void SeparatedSet::makesets(int idx)
{
	//printf("makeset %d\n", idx);
	if ((idx > size - 1) || (idx < 0))
		throw ("out of range");

	harVec[idx] = idx;
}

int SeparatedSet::findsets(int idx)
{
	//printf("findset %d\n", idx);
	if ((idx > size - 1) || (idx < 0))
		throw ("out of range");

	return harVec[idx];
}

void SeparatedSet::unionsets(int x, int y)
{
	//printf("x %d y %d\n", x, y);
	if ((x > size - 1) || (x < 0) || (y > size - 1) || (y < 0))
		throw ("out of range");

	for (int i = 0; i < size; ++i)
	{
		if (harVec[i] == y)
		{
			harVec[i] = x;
		}
	}
}