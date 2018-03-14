#pragma once
template <class val>
class node
{
public:
	val data;
	node<val>* next;
	node() { next = NULL; }
	node(const node<val> &n);
	~node() {}
	const node<val>& operator=(const node<val> &n);
	friend ostream & operator<<(ostream &out, const node<val> &n)
	{
		out << n.data;
		return out;
	}
};

template<class val>
inline node<val>::node(const node<val>& n)
{
	data = n.data;
	next = n.next;
}

template<class val>
inline const node<val>& node<val>::operator=(const node<val>& n)
{
	data = n.data;
	next = n.next;
	return *this;
}
