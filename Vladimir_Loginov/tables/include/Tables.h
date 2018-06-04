#ifndef TABLE_H
#define TABLE_H
#include <vector>


template <class key, class data>
class Table
{
protected:
	std::vector<std::pair<key, data*> > records;
	size_t max_size;
	size_t current_size;
	size_t current;
public:
	Table(size_t ms) { max_size = ms; current = current_size = 0; };
	virtual ~Table() {};
	virtual void GoNext() = 0;
	virtual data* GetCurrent() const = 0;
	virtual data* Search(key &k) = 0;
	virtual void Insert(key &k, data *d) = 0;
	virtual void Delete(key &k) = 0;
	virtual void Reset() { current = 0;  }
	virtual bool IsEnded() const { return current == current_size; }
	virtual bool IsEmpty() const { return current == 0; }
};

#endif