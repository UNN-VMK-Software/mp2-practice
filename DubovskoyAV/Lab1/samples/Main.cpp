#include <iostream>
#include <string>

#include "List.h"
#include "Node.h"
#include "Stack.h"
#include "NameVal.h"
#include "Functions.h"

using namespace std;

void main()
{
	cout <<"Enter  term"<< endl;
	string line;
	cin >> line;
	
	string postfix;
	try
	{
		postfix=functions::postfix(line);
	}
	catch( const char* ex)
	{ 
		cout<<ex<<endl;
		return;
	}

		

	cout<<postfix<<endl;
	string op=functions::operands(postfix);

	NameValue *NV = new NameValue[op.length()];

	cout << "Enter the values"<<endl;
	NV = functions::NVmas(op);

	try
	{
		cout<<functions::Result(postfix,postfix.length(),NV)<<endl;
	}
	catch( const char* ex)
	{ 
		cout<<ex<<endl;
		return;
	}


}
	