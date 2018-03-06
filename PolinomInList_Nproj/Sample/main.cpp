#include "polinom.h"
#include "ringlist.h"

int main()
{
	string s;
	cout << "Enter your polinom, using only letters x,y,z, without spaces and multiplication signs:\n";
	getline(cin, s);	
	Polinom P(s);
	return 0;
}