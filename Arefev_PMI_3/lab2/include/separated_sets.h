#pragma once

class SeparatedSets {
	int n;
	int* M;
public:
	SeparatedSets(int m); // создаем юниверс
	~SeparatedSets() { delete[] M; };
	void Create (int singl);
	void Unite(int i, int j);
	int DefineSubset(int i);
};