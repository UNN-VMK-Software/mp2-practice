#pragma once
#include <map>
#include <string>
using namespace std;

class funcs
{
	static int priority(const char&);
	static bool is_variable(const char&);
	static bool is_operation(const char&);
	static map<char, double> readvalue(const string&);
	static int correct(const string& s);
public:
	static string postfix_form(string);
	static double compute(string);
};

inline string funcs::postfix_form(string)
{
	return "0";
}

inline double funcs::compute(string)
{
	return 0.0;
}
