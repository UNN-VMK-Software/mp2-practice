#include "separated_sets.h"
#include <iostream>

using namespace std;

SeparatedSets::SeparatedSets(int m)
{
	n = m;
	M = new int[n];
	for (int i = 0; i < n; i++)
	{
		M[i] = i;
	}
}
void SeparatedSets::Create(int singl)
{
	if (singl > n) 
		cout << "Error";
	else 
		M[singl] = singl;
}
void SeparatedSets::Unite(int i, int j)
{
	for (int k = 0; k < n; k++)
	{
		if (M[k] == i) M[k] = j;
	}
}
int SeparatedSets::DefineSubset(int i)
{
	return M[i];
}