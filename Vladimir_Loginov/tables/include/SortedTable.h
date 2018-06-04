#pragma once

#include <vector>
#include <cstdlib>
#include <iostream>
#include "Polinoms.h"
#include "Tables.h"
#include "ScanTable.h"

template <class key, class data> 
class SortedTable : public Table <key, data>
{
public:
	SortedTable() : Table <key, data>(7) { max_size = 7; records.resize(7); };
	SortedTable(size_t ms) : Table <key, data>(ms) { max_size = ms; records.resize(ms);  };
	SortedTable(const ScanTable<key, data> &b);
	~SortedTable() {};
	data* Search(key& k) override;
	void Insert(key& k, data* d) override;
	void Delete(key& k) override;
	void GoNext() override;
	data* GetCurrent() const override;
	size_t GetSize() const { return records.size(); }

	template <class key, class data>
	friend std::ostream& operator<< (ostream &out, const SortedTable<key, data>& _table)
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

template<class key, class data>
SortedTable<key, data>::SortedTable(const ScanTable<key, data> &b)
{
	size_t ms = b.GetSize();
	records.resize(ms);
	signs.resize(ms);
	b.Reset();
	for (b.GetCurrent(); !b.IsEnded(); b.GoNext())
	{
		(*this).Insert(b.GetCurrent().first, b.GetCurrent().second);
	}
	current = 0;
}

template <class key, class data>
data * SortedTable<key, data>::Search(key& k)
{
	size_t j = GetSize()-1, i = 0;
	size_t mid = j - i;
	while (mid > 0) 
	{
		mid = (j - i) >> 1;
		if (records[mid].first == k)
		{
			current = mid;
			return records[current].second;
		}
		else if (records[mid].first < k)
			i += mid;
		else j -= mid+1;
	}
	return nullptr;
}

template <class key, class data>
void SortedTable<key, data>::Insert(key& k, data* d)
{
	Search(k);
	records.insert(records.begin() + current, std::make_pair(k, d));
}

template <class key, class data>
void SortedTable<key, data>::Delete(key &k)
{
	Search(k);
	records.erase(records.begin() + current);
}

template <class key, class data>
void SortedTable<key, data>::GoNext()
{
	++current;
}

template <class key, class data>
data* SortedTable<key, data>::GetCurrent() const
{
	return records[current].second;
}

