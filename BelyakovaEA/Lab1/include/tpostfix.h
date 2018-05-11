#ifndef TPOSTFIX_H
#define TPOSTFIX_H
#include "TLink.h"
#include "TList.h"
#include "TStack.h"
#include <iostream>
#include <string>
using namespace std;

class VariableValues
{
public:
	VariableValues() : nValues(0), ops(NULL), value(NULL) {}

	int nValues;
	char* ops;
	float* value;
};

class st {
private:
	static int prioretet(char a);
	static VariableValues readvalues(const string& s);
public:
	static string correct(string s);
	static string postfixform(string s);
	static float calculations(string s);
};


#endif
