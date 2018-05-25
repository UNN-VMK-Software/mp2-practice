#pragma once
#include <cstdlib>
#include <cstdio>
#include <vector>
#include "Tables.h"
#include "Polinoms.h"

template <class key, class data>
class ScanTable : public Table <key, data>
{

public:
	ScanTable() : Table<key, data>(7) { max_size = 7; records.resize(7); current = 0; }
	ScanTable(size_t ms) : Table<key, data>(ms) { max_size = ms; records.resize(ms); current = 0; }
	~ScanTable() {};
	data* Search(key &k) override;
	void Insert(key &k, data* d) override;
	void Delete(key& k) override;
	void GoNext() override;;
	data* GetCurrent() const override;
	size_t GetSize() const { return records.size(); }

	template <class key, class data>
	friend std::ostream& operator<< (ostream &out, const ScanTable<key, data>& _table)
	{
		out << "[=================================]" << std::endl;
		for (auto rec : _table.records)
		{
			if (rec.second == nullptr)
				out << "[Empty record]" << endl;
			else
				out <<"[Key]: " << rec.first << "[Record]: " << *(rec.second);
		}
		out << "[=================================]" << std::endl;
		return out;
	}
};

template<class key, class data>
data * ScanTable<key, data>::Search(key& k)
{
	Reset();
	while ((current < (records.size()-1)) && (records[current].first != k))
		GoNext();
	if (records[current].first == k)
		return records[current].second;
	else
		return nullptr;
}

template<class key, class data>
void ScanTable<key, data>:: Insert(key &k, data* d)
{
	if (current_size < max_size)
	{
		records[current++] = std::make_pair(k, d); 
		current_size++;
	}
	else
	{
		max_size *= 1.5;
		records.resize(max_size);
		records[current++] = std::make_pair(k, d); 
		current_size++;
	}
}

template<class key, class data>
void ScanTable<key, data>::Delete(key& k)
{
	Search(k);
	if (records[current].first == k)
	{
		records[current] = records[records.size()-1];
		records.pop_back();
	}
}
template<class key, class data>
void ScanTable<key, data>::GoNext()
{
	++current;
}

template<class key, class data>
data* ScanTable<key, data>::GetCurrent() const
{
	return records[current].second;
}

