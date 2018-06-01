#pragma once
#include "list.h"
#include "tab_record.h"
#define S 10


template <class type>
class table 
{
protected:
	unsigned int maxsize;
	unsigned int cursize;
	int idx; 
	virtual void Realloc() = 0;      
public:
	table(int any_size = S) { maxsize = any_size; cursize = 0; idx = -1; }		//Конструктор
	virtual ~table() {};
		 
	virtual type* Search(const string& k) = 0;         
	virtual void Insert(const string& k, const type& d) = 0;  
	virtual void Delete(const string& k) = 0;                                     
	
	virtual void Reset();
	virtual bool IsTabEnded() const;
	virtual void GetNext();
	virtual record<type> GetCurrent() const = 0;             
	virtual bool IsEmpty() { return cursize == 0; }

	template<class type> friend ostream& operator<<(ostream& os, const table<type>& tab) = 0;
};


template<class type> void table<type>::Reset()
{
	if (!IsEmpty())
		idx = 0;
	else
		throw "Table is empty";
}


template<class type> bool table<type>::IsTabEnded() const
{
	return (idx >= cursize - 1 );                                             //нулевая запись
}


template <class type> void table<type>::GetNext()
{
	if (!IsTabEnded())
		idx++;
	else
		//
		Reset();
		//throw "Next record is not found";
}


