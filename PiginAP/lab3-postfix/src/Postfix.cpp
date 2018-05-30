#include "Postfix.h"
#include <string>

using namespace std;

bool Postfix::operand(const char str) 
{
    if((str>=65) && (str<=90))
	{
        return true;
    }
	else if(((str>=40)&&(str<=43))||(str == 45)||(str == 47) || (str == 61))
		 {
			return false;
		 }
    throw "Operation is not correct" + str;
}
//==========================================================||==========================================================
int Postfix::priority(char x) 
{
    if ((x =='*')||(x =='/'))
	{
        return 2;
    }
    if ((x =='+')||(x =='-'))
	{
        return 1;
    }
    if ((x =='(')||(x ==')'))
	{
        return 0;
    }
	return -1;
} 
//==========================================================||==========================================================
string Postfix::create_form(string inp_text)
{
	Stack<char> Stack_one;
	Stack<char> Stack_two;
	for (int i = 0; i < inp_text.length(); i++)
	{
		if (inp_text[i] == '(') Stack_two.push(inp_text[i]);
		else if ((inp_text[i] == '+') || (inp_text[i] == '-') || (inp_text[i] == '/') || (inp_text[i] == '*')) 
		{
			char stack_two_up = Stack_two.pop();
			while ((!Stack_two.IsEmpty()) && (Postfix::priority(stack_two_up) > Postfix::priority(inp_text[i]))) 
			{
				Stack_one.push(stack_two_up);
				stack_two_up = Stack_two.pop();
			}
			if(stack_two_up!='\0')
			{
				Stack_two.push(stack_two_up);
			}
				Stack_two.push(inp_text[i]);
		}
		else if (inp_text[i] == ')') 
		{
			char stack_two_up = Stack_two.pop();
			while ((Stack_two.IsEmpty()) && (stack_two_up != '(')); 
			{
				Stack_one.push(stack_two_up);
			}
			Stack_two.pop();
		}
		else { Stack_one.push(inp_text[i]); }
	}

	while (!Stack_two.IsEmpty()) { Stack_one.push(Stack_two.pop()); }
	string s = "";
	while (!Stack_one.IsEmpty()) { s = Stack_one.pop() + s; }
	
	return s;

}
//==========================================================||==========================================================
double Postfix::calc_form(string form)
{
	Stack<double> double_list;
	for (size_t i = form.size()-1; i < form.size(); i--) 
	{
		if (Postfix::operand(form[i])) 
		{
			std::cout << "input var " << form[i] << " : ";
			double var;
			

			std::cin >> var;
			double_list.push(var);
		}

	}
	Stack<double> end_list;
	for (int i = 0; i < form.size(); i++) 
	{
		char element = form[i];
		if (Postfix::operand(element)) 
		{
			end_list.push(double_list.pop());
		}
		else {
			double two = end_list.pop();
			double one = end_list.pop();
			try
			{
			const double st = calc_op(one, two, element);
			end_list.push(st); 
			}
			catch( const char* ex)
			{ 
			cout<<ex;
			}
			
			}
	}
	return end_list.pop();
}
//==========================================================||==========================================================
double Postfix::calc_op(double one, double two, char op)
{
		switch (op) 
		{
		case '+':
			return (one + two);
		case '-':
			return (one - two);
		case '*':
			return (one * two);
		case '/':
			if(two == 0)
			{
				throw " Error, x/0 is impossible";
			}
			else return (one / two);
		default:
			return -1;
		}
}
//==========================================================||==========================================================
