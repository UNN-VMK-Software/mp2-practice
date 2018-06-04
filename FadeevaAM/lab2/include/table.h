#pragma once
#include "line.h"
#include <iostream>
#include <iomanip>

using namespace std;

#define WIDTHFIRSTCOLUMN 30
#define DEFAULTSIZE 10

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
	virtual type* Search(const string k) = 0;	
	virtual void Reset() = 0;
	virtual bool IsTabEnded() const = 0;
	virtual void GetNext()=0;
	virtual line<type> GetCurrent() const = 0;
	bool IsEmpty() const { return size == 0; }
	bool IsFull() const { return size == maxsize; }
	int GetSize() const { return size; }
	
};


