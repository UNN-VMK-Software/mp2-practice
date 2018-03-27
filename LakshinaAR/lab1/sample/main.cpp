#include "polinom.h"
#include <iostream>
#include <string>

using namespace std;

const string sym = "+-*^xyz0123456789";

int main()
{
	string s1,s2;
	polynom p1, p2;
	double c;
	int counter;

	cout<<"Choose a operation"<<endl;
	cout<<"1. p1 + p2"<<endl;
	cout<<"2. p1 - p2"<<endl; 
	cout<<"3. c*p2"<<endl;
	cout<<"4. p1*p2"<<endl;

	cout << "Your choice: ";
	cin >> counter;
	
	if (counter>0 && counter<5)
	{
		if (counter == 1 || counter == 2  || counter == 4)
		{
			cout << "Enter polinom p1: ";
			cin >> s1;
			p1 = s1;
			cout << "Enter polinom p2: ";
			cin >> s2;
			p2 = s2;
			switch (counter)
			{
			case 1:
				{
					cout << "Result of operation: " << p1 + p2 << endl;
					break;
				}
			case 2:
				{
					cout << "Result of operation: " << p1 - p2 << endl;
					break;
				}
			case 4:
				{
					cout << "Result of operation: " << p1*p2 << endl;
					break;
				}
			 }
		  }


		if (counter == 3)
		{
			cout << "Enter polinom p: ";
			cin >> s1;
			p1 = s1;
			cout << "Enter const: ";
			cin >> c;
			cout << "Result of operation: " << c*p1 << endl;
		}
	}
	else
		cout << "Incorrect input "<< endl;

	return 0;
}