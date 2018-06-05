#pragma once
#include "tlist.h"

using TElem = int;

class TStack
{
private:
	TList elems;
public:
	TStack() = default;
	void Push(TElem a);
	void Pop();
	TElem Top();
	bool IsFull() const;
	bool IsEmpty() const;
};
