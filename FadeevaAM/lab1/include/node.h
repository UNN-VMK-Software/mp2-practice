#pragma once

template <class type>
struct node {
	node* next;
	type data;
	node() { next = nullptr; }
	node(type a) { data = a; next = nullptr; }	
	bool operator== (const node& a) const { return (data==a.data); }
	bool operator!= (const node& a) const { return !(*this==a); }
};