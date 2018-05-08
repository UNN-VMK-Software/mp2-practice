#include "gtest.h"
#include "scantable.h"
#include "sortedtable.h"
//#include "hashtable.h"
#include <iostream>

class Ttab : public testing::Test
{
protected:
	scantable<int> et1;
	scantable<int> t1;
	sortedtable<int> et2;
	sortedtable<int> t2;
	//hashtable<int> et3;
	//hashtable<int> t3;
	
public:
	Ttab() : et1(0), t1(2), et2(0), t2(2)
	{		
		t1.Insert("b", 2);
		t1.Insert("d", 4);
		t2.Insert("b", 2);
		t2.Insert("d", 4);
		//t3.Insert("b", 2);
	}
	~Ttab() {}
};

