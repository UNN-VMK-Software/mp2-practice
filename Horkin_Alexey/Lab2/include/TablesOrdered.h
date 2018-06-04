#pragma once
#include "Tables.h"

template <class KeyType, class DataType>
class TableOrdered : public Table<KeyType, DataType>
{
public:
	TableOrdered(int SIZE = MIN_SIZE) : Table<KeyType, DataType>(SIZE) {};
	virtual ~TableOrdered() {};
	virtual void Insert(const KeyType &KT_T, const DataType &DT_D); // ������� � ������������� ������� �������
	virtual void Dell(const KeyType &KT_T);					// �������� �������� 
	virtual DataTable<KeyType, DataType>* Search(const KeyType &KT_T) const;		// ����� ������� �� ����� 
private:
	virtual void Reallocate(); //����������������� 
	int BinarSearch(const KeyType &Key) const; //�������� �����
};

template <class KeyType, class DataType>
void TableOrdered <KeyType, DataType> ::Reallocate()
{
	int NextSize = (int)(this->MaxSize + 20)*1.65;
	DataTable <KeyType, DataType> ** NewDT = new DataTable <KeyType, DataType>*[NextSize];
	for (int i = 0; i<this->MaxSize; i++)
		NewDT[i] = this->DT[i];
	for (int i = this->MaxSize; i<NextSize; i++)
		NewDT[i] = NULL;
	delete[] this->DT;
	this->DT = NewDT;
	this->MaxSize = NextSize;
}

template <class KeyType, class DataType>
int TableOrdered <KeyType, DataType> ::BinarSearch(const KeyType &Key) const  //���������� ������ (����� ������ � �������)
{
	int tail = this->Top - 1;
	int mid = 0;
	int start = 0;
	while (start <= tail)
	{
		mid = (tail + start) / 2;
		if ((*(this->DT[mid])).Key < Key)
			start = mid + 1;
		else if ((*(this->DT[mid])).Key > Key)
			tail = mid - 1;
		else return mid; //new disicion
	}
	if (start > tail)
		mid = start;
	return mid;

}

template <class KeyType, class DataType>
void TableOrdered <KeyType, DataType> ::Insert(const KeyType &KT_T, const DataType &DT_D)
{
	int area = BinarSearch(KT_T);
	int j;
	if ((this->DT[area] == NULL) || ((*(this->DT[area])).Key != KT_T))
	{
		if ((double)this->Top / (double)this->MaxSize > 0.7) // ���������������� ���� �� ���������� �������� 30 ��������� 
			Reallocate();
		for (j = this->Top; j > area; j--)
			this->DT[j] = this->DT[j - 1];
		this->DT[j] = new DataTable<KeyType, DataType>(KT_T, DT_D);
		this->Top++;
	}
	else throw "duplicate key";
}

template <class KeyType, class DataType>
void  TableOrdered <KeyType, DataType> ::Dell(const KeyType &KT_T)
{
	int area = BinarSearch(KT_T);

	if ((this->DT[area] != NULL) && ((*(this->DT[area])).Key == KT_T))
	{
		delete this->DT[area];
		for (int i = area; i < this->Top; i++)
			this->DT[i] = this->DT[i + 1];
		this->Top -= 1;
	}
	else
		throw "element doesn't exist";
}

template <class KeyType, class DataType>
DataTable<KeyType, DataType>* TableOrdered <KeyType, DataType> ::Search(const KeyType &KT_T) const
{
	int area = BinarSearch(KT_T);
	if ((this->DT[area]!=NULL) && ((*(this->DT[area])).Key == KT_T))
		return this->DT[area];
	else throw "element doesn't exist";
}
