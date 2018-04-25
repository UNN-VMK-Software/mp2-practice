#pragma once
#include "line.h"


template <class type>
class table {
protected:
	int maxsize;
	
	int ind;
public:	int size;
	table(int sizeT = 5) { maxsize = sizeT; size = 0; ind = 0; }		//	
	virtual void Insert(const string k, const type d)=0;
	virtual void Delete(const string k) = 0;
	virtual type Search(const string k) = 0;	
	virtual void Reset() = 0;
	virtual bool IsTabEnded() = 0;
	virtual void GetNext()=0;
	virtual type GetCurrent() = 0;
};


