#pragma once

#include <iostream>
#include "node.h"
using namespace std;

struct Monom
{
	double coeff;
	unsigned int abc;
	Monom(double c = 0, unsigned int a = 0) { coeff = c; abc = a; }
	Monom(const Monom &a) { coeff = a.coeff; abc = a.abc; }
};

class Ringlist
{
	Node<Monom> *head;
	Node<Monom> *curr;
public:
	Ringlist();
	Ringlist(const Ringlist &l);
	~Ringlist();

	void InsertToTail(const Monom &a);
	void InsertToOrdered(const Monom &a);
	void Ordering();

	void reset();
	Monom& GetNext();
	int isended();
};