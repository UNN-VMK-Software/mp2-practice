#pragma once

#include <vector>
#include <string>
#include "Tables.h"
#include "Polinoms.h"


template <class data> 
class HashTable : public Table<std::string, data>
{
protected:
	std::vector<short unsigned int> signs;
	void ReHash();
public:
	HashTable() : Table <std::string, data>(7) { max_size = 7; records.resize(7); signs.resize(7); }
	HashTable(size_t ms) : Table <std::string, data>(ms) { max_size = current_size = ms; records.resize(ms); signs.resize(ms); }
	~HashTable() {};
	unsigned int murmurHash2(std::string &dat);
	data* Search(std::string &s) override;
	void Insert(std::string &s, data *d) override;
	void Delete(std::string &s) override;
	void GoNext() override;
	data* GetCurrent() const override;
	size_t GetSize() const { return records.size()-1; }
	bool Check_Overload1() const;
	bool Check_Overload2() const;

	template <class data>
	friend std::ostream& operator<< (ostream &out, const HashTable<data>& _table)
	{
		out << "[=================================]" << std::endl;
		for (auto rec : _table.records)
		{
			if (rec.second == nullptr)
				out << "[Empty record]" << endl;
			else
				out << "[Key]: " << rec.first << "[Record]: " << *(rec.second);
		}
		out << "[=================================]" << std::endl;
		return out;
	}
};

template <class data>
unsigned int HashTable<data>::murmurHash2(std::string &name)
{
	std::string st = name;
	unsigned int len = st.length();
	const unsigned int m = 0x5bd1e995;
	const unsigned int seed = 0;
	const int r = 24;

	unsigned int h = seed ^ len;

	unsigned int k;

	while (len >= 4)
	{
		k = st[0];
		k |= st[1] << 8;
		k |= st[2] << 16;
		k |= st[3] << 24;

		k *= m;
		k ^= k >> r;
		k *= m;

		h *= m;
		h ^= k;

		st += 4;
		len -= 4;
	}

	switch (len)
	{
	case 3:
		h ^= st[2] << 16;
	case 2:
		h ^= st[1] << 8;
	case 1:
		h ^= st[0];
		h *= m;
	};

	h ^= h >> 13;
	h *= m;
	h ^= h >> 15;

	return h;
}

template <class data>
data * HashTable<data>::Search(std::string &name)
{
	srand(murmurHash2(name));
	size_t i =0;
	current = rand() % records.size();
	while ((signs[current] == 1) && (i < (records.size()-1))) {
		if (records[current].first == name)
			return records[current].second;
		else
		{
			current = rand() % records.size();
			i++;
		}
	}
	if ((signs[i] == 0) || (signs[i] == 2) || i >= (records.size()-1))
		return nullptr;

}

template <class data>
void HashTable<data>::Insert(std::string &name, data *d)
{
	if (Check_Overload1())
		ReHash();
	auto res = std::make_pair(name, d);
	srand(murmurHash2(name));
	current = rand() % records.size();
	while (signs[current] == 1)
		current = rand() % records.size();
	if ((signs[current] == 0) || (signs[current] == 2))
	{
		records[current] = res;
		signs[current] = 1;
	}
}

template <class data>
void HashTable<data>::Delete(std::string &name)
{
	srand(murmurHash2(name));
	size_t i = 0;
	current = rand() % records.size();
	bool del = false;
	while ((signs[current] == 1) && (i < records.size() - 1)) {
		if (records[current].first == name)
		{
			signs[current] = 2;
			records[current].first = "";
			records[current].second = nullptr;
			del = true;
		}
		else
		{
			current = rand() % records.size();
			i++;
		}
	}
	if (signs[current] == 2 && !del)
		throw "Record is deleted";
	if (signs[current] == 0  || (i>=records.size()-1))
		throw "Record is empty";


}

template <class data>
void HashTable<data>::ReHash()
{
	
	current_size *= 1.5;
	auto records_new(records);
	auto signs_new(signs);
	/*records_new.resize(current_size);
	signs_new.resize(current_size);*/
	records.clear();
	signs.clear();
	records.resize(current_size);
	signs.resize(current_size);
	for (auto rec : records_new)
	{
		srand(murmurHash2(rec.first));
		current = rand() % current_size;
		while (signs[current] == 1)
			current = rand() % records_new.size();
		records[current] = rec;
		signs[current] = 1;
	}
}

template <class data>
void HashTable<data>::GoNext()
{
	++current;
}

template <class data>
data* HashTable<data>::GetCurrent() const
{
	return records[current].second;
}


template <class data>
bool HashTable<data>::Check_Overload1() const
{
	unsigned short int Rec_b = 0, Rec_e = (*this).signs.size();
	for (auto a : signs)
	{
		if (a == 1)
			Rec_b++;
	}
	return Rec_b / Rec_e >= 0.7;
}

template <class data>
bool HashTable<data>::Check_Overload2() const
{
	unsigned short int Rec_bd = 0, Rec_e = (*this).signs.size();
	for (auto a : signs)
	{
		if ((a == 1) || (a == 2))
			Rec_bd++;
	}
	return Rec_bd / Rec_e >= 0.7;
};


