#pragma once
#include "Tables.h" 
#include <string>
#include <cstdlib> // ��� ��������
#include <cmath>
using namespace std;
#define Mark0 0
#define Mark1 1
#define Markminus1 -1 
//0 - ��������; 1 - ����� ������; -1 - ��� �����;
//��������� ����� ��� �������;
template <class KeyType, class DataType>
class HashTable : public Table <KeyType, DataType>
{
public:
	HashTable(int SIZE = 20) : Table<KeyType, DataType>(SIZE)
	{
		DM = new int[SIZE];
		for (int i = 0; i < SIZE; i++)
			DM[i] = Mark0;
	};
	~HashTable() {};
	void Insert(const KeyType &KT_T, const DataType &DT_D); // ������� � ��������������� �������
	void Dell(const KeyType &KT_T);					// �������� �������� 
	DataTable<KeyType, DataType>* Search(const KeyType &KT_T) const;		// ����� ������� �� ����� 
private:
	void Reallocate(); //�����������������, � ������ ������ - ���������������
	int Hashfunc(const KeyType &k) const;
	int *DM; // DM like DataMarker
};

template<class KeyType>
int GetDigKey(const KeyType& k) { return 0; }

template<>
int GetDigKey<string>(const string &k)  // ���� ���������� ��� ������� �� string
{
	int g = 31; //13
	int hash = 0;
	for (int i = 0; i < k.length(); i++)
		hash = g * hash + k[i];
	return hash;
}

template <class KeyType, class DataType>  // ��� ������� ������ ������ (�����)
int HashTable<KeyType, DataType>::Hashfunc(const KeyType& k) const
{
	int temp = abs(GetDigKey(k));
	return (temp % (this->MaxSize));
}

template <class KeyType, class DataType>
void HashTable<KeyType, DataType>::Reallocate()
{
	int i = 0;
	int NextSize = (int)(this->MaxSize + 20)*1.65;
	DataTable<KeyType, DataType> ** NewDT = new DataTable<KeyType, DataType> *[NextSize];
	int * DM1 = new int[NextSize];
	for (int i = 0; i < this->MaxSize; i++)
		DM1[i] = DM[i];
	for (int i = this->MaxSize; i < NextSize; i++)
		DM1[i] = Mark0;
	delete[]DM;
	DM = DM1;
	//
	for (int i = 0; i<this->MaxSize; i++)
		NewDT[i] = this->DT[i];
	for (int i = this->MaxSize; i < NextSize; i++)
		NewDT[i] = NULL;
	delete[] this->DT;
	this->DT = NewDT;
	this->MaxSize = NextSize;
}

template <class KeyType, class DataType>
void HashTable<KeyType, DataType>::Insert(const KeyType &KT_T, const DataType &DT_D)
{
	if ((double)this->curindex / (double)this->MaxSize > 0.7) // ���������������� ���� �� ���������� �������� 30 ��������� 
		Reallocate();
	int place = Hashfunc(KT_T);
	if (DM[place] == Mark0) //������ ��������
	{
		this->DT[place] = new DataTable<KeyType, DataType>(KT_T, DT_D); DM[place] = Mark1; this->curindex++;
	}
	else if (DM[place] == Markminus1)
	{
		this->DT[place] = new DataTable<KeyType, DataType>(KT_T, DT_D); DM[place] = Mark1;
	}
	else
	{
		if ((*(this->DT[place])).Key == KT_T)
		{
			throw "duplicated key";
		}
		srand(place);
		int laker = rand() % (this->MaxSize);
		while (DM[laker] == Mark1) //���� ������� ����� 
		{
			laker = rand() % (this->MaxSize);
			if ((this->DT[laker] != NULL) && ((*(this->DT[laker])).Key == KT_T))
			{
				throw "duplicated key";
			}
		}
		this->DT[laker] = new DataTable<KeyType, DataType>(KT_T, DT_D);
		if (DM[laker] == 0)
			this->curindex++;
		DM[laker] = Mark1;
	}
}

template <class KeyType, class DataType>
void HashTable<KeyType, DataType>::Dell(const KeyType &KT_T)
{
	int place = Hashfunc(KT_T);
	if (DM[place] == 0) //�������� ���
		throw "element doesn't exist";
	if ((this->DT[place] != NULL) && ((*(this->DT[place])).Key == KT_T))
	{
		delete this->DT[place];
		this->DT[place] = NULL;
		DM[place] = Markminus1;
	}
	else
	{
		srand(place);
		while ((DM[place] == -1) || ((DM[place] == 1) && ((*(this->DT[place])).Key != KT_T))) //���� ������� ��� �����, ��� �� �����, �� �� ��������� ����� - �������� �����
			place = rand() % (this->MaxSize);
		if (DM[place] == 1) // ��������� �����
		{
			delete this->DT[place];
			this->DT[place] = NULL;
			DM[place] = Markminus1;
		}
		else throw "element doesn't exist";
	}
}

//��������� ����� (���������)
template <class KeyType, class DataType>
DataTable<KeyType, DataType>* HashTable<KeyType, DataType>::Search(const KeyType &KT_T) const
{
	int place = Hashfunc(KT_T);
	if (DM[place] == 0) //�������� ���
		throw "element doesn't exist";
	if ((this->DT[place] != NULL) && ((*(this->DT[place])).Key) == KT_T)
	{
		return this->DT[place];
	}
	else
	{
		srand(place);
		while ((DM[place] == -1) || ((DM[place] == 1) && ((*(this->DT[place])).Key != KT_T))) //���� ������� ��� �����, ��� �� �����, �� �� ��������� ����� - �������� �����
			place = rand() % (this->MaxSize);
		if (DM[place] == 1) // ��������� �����
		{
			return this->DT[place];
		}
		else
			throw "element doesn't exist";
	}

}
