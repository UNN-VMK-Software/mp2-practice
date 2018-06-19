#ifndef POSTFIX_H
#define POSTFIX_H

#include "Stack.h"
#include <iostream>

using namespace std;

class Postfix
{
private:
    static bool operand(const char str); //+
    static int priority(char x);	//+
	static double calc_op(double one, double two, char op);
public:
	static string create_form(string inp_text);	//+
	static double calc_form(string form);	//+
};
#endif