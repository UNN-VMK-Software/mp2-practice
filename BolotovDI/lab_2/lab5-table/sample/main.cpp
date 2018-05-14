#include "ScanTable.h"
#include "SortedTable.h"

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	int i = 0;
	string s;
	SortedTable A;

	while (i<5)
	{
		getline(cin, s);

		TPolinom B(s);
		A.Insert(s, B);
		i++;
	}
	string c;
	getline(cin, c);
	A.Delete(c);

	getline(cin, s);

	TPolinom B(s);
	A.Insert(s, B);

	/*string c;
	getline(cin, c);
	A.Search(c);*/

	cout << "Hello" << endl;
	cin.get();
}