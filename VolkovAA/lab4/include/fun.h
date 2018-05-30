#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <iostream>

#include "list.h"
#include "nods.h"
#include "Stack.h"
#include "val.h"

using namespace std;

class functions
{
private:
	static int Priority(char x);
public:
	static NameValue* NVmas(string op);
	static string postfix(string line);
	static string operands(string line);
	static float Result(string line, int sizeOfTotalExpression, NameValue* NV);
	
};


#endif