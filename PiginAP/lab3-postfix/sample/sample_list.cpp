#include <iostream>
#include <string>
#include "Postfix.h"

using namespace std;


int main() 
{
	Stack<char> Stack_one;
	Stack<char> Stack_two;
	string inp_text;

	cout << "Expression: ";
	cin >> inp_text;

	string form = Postfix::create_form(inp_text);
	cout << "Post. form: " << form << endl;
	double calc_form = Postfix::calc_form(form);
	cout << calc_form << endl;
	
	return 0;
}