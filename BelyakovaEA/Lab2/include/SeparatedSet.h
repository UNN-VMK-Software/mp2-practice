#ifndef SEPARATEDSET
#define SEPARATEDSET

class SeparatedSet
{
public:
	SeparatedSet(int size);
	~SeparatedSet() { delete[] harVec; }

	void makesets(int idx);
	int findsets(int idx);
	void unionsets(int x, int y);

private:
	int* harVec;
	int size;
};
#endif 
