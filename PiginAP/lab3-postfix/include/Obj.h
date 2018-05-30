#ifndef OBJ_H
#define OBJ_H

#include <iostream>
template <typename L>

class Obj
{
public:
	Obj() :pNext(NULL) {};
	Obj(const L& value) :pNext(NULL), val(value) {};
	Obj* pNext;
	L val;
};
#endif

// A-(B-A)*C/(D-A)+E
// Не переспрашивать одинаковые