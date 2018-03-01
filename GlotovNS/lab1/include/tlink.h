#ifndef TLINK_H
#define TLINK_H

template <class TData>
class TLink
{
public:
	TLink(TData data, TLink<TData> *pNext);
	
	TData data;
	TLink<TData> *pNext;
};

template <class TData>
TLink<TData>::TLink(TData data, TLink<TData> *pNext)
{
	this->data = data;
	this->pNext = pNext;
};

#endif 
