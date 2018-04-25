#include "gtest.h"
#include "scantable.h"
#include <iostream>

TEST(aa, aa)
{
	scantable<int> a(3);
	a.Insert("Sasha2", 5);
	a.Insert("Sasha", 0);
	a.Insert("Sasha1", 1);
	a.Delete("Sasha");

	for (int i = 0; i < a.size; i++)
		cout << a.stab[i].key << ' ' << a.stab[i].data<< endl;

}
