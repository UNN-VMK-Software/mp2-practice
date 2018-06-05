#pragma once
template <typename T>
class PriorityQueue
{
public:
	virtual bool IsFull() const = 0;
	virtual bool IsEmpty() const = 0;
	virtual void Push(T a) = 0;
	virtual T Pop() = 0;
};