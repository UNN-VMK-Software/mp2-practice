#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <iostream>

#include "List.h"
#include "Node.h"
#include "Stack.h"
#include "NameVal.h"

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