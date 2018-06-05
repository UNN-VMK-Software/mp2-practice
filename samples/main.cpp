#include <tstack.h>
#include <iostream>
using namespace std;

void print1(int& x) {
	x = 10;
	cout << x;
}
void print2(int* x) {
	*x = 20;
	cout << *x;
}

int main() {
	TStack stack;

	int*z = new int(1);
	int x;
	print1(x);
	print2(z);

}
