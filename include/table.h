#pragma once
#include "line.h"
#include <iostream>

using namespace std;

#define DEFAULTSIZE 5

template <class type>
class table {
protected:
	int maxsize;
	int size;
	int ind;
	virtual void Realloc() = 0;
public:	
	table(int sizeT) { maxsize = sizeT; size = 0; ind = 0; }		
	virtual ~table() {};
	virtual void Insert(const string k, const type& d)=0;
	virtual void Delete(const string k) = 0;
	virtual type Search(const string k) = 0;	
	virtual void Reset() = 0;
	virtual bool IsTabEnded() = 0;
	virtual void GetNext()=0;
	virtual line<type> GetCurrent() = 0;
	bool IsEmpty() { return size == 0; }
	int GetSize() { return size; }
	
};


