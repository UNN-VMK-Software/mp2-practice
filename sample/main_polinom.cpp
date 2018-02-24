#include <iostream>
#include "monom.h"
#include "list.h"
using namespace std;
void   main() 
{
	Monom a(11, 521);
	Monom b(12, 344);
	list<Monom> c;
	c.Insert_to_tail(a);
	if (!c.IsEmpty()) {
		cout << "EbANAYA HUETA NOT EMPTY LIST FUCK YEACH!" << endl;
	}
	system("pause");
	
}