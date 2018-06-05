#include <vector>
#include <DHeapBasePriorityQueue.h>
#include <iostream>
#include <ctime>

using namespace std;

template <typename T>
vector<T> alg_pirsort(vector<T> m)
{
	DHeapBasePriorityQueue<T> queue = DHeapBasePriorityQueue<T>(m, 2);
	vector<T> sorted;
	while (!queue.IsEmpty())
	{
		sorted.push_back(queue.Pop());
	}
	return sorted;
}


int main() {
	srand(time(NULL));

	for (int arr = 1; arr <= 8 ; arr++)
	{
		int length = rand() % 10 + 5;
		vector<int> v = vector<int>();
		for (int i = 0; i < length; i++)
		{
			v.push_back(rand() % 30 - 10);
		}
		cout << "Array #" << arr << ": ";
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl << "Sorted: ";
		v = alg_pirsort(v);
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << "\n\n";
	}
	
	return 0;
}
