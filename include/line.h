#pragma once
#include <string>

using namespace std;

template <class type>
struct line {
	type* data;
	string key;
	line() { key = ""; data = NULL; }
	line(string k, type d) { key = k; data =new type(d); }
	line<type>& operator=(const line<type>& l);
	~line() { delete data; }
	line (const line<type>& l);
	bool operator==(const line<type>&) const;
	bool operator!=(const line<type>& l) const { return !(*this == l); }
};

template <class type> line<type>::line(const line<type>& l) {
	key = l.key;
	data = new type(*(l.data));
}

template <class type> line<type>& line<type>::operator=(const line<type>& l) {
	delete data;
	key = l.key;
	data = new type(*(l.data));
	return *this;
}

template <class type> bool line<type>::operator==(const line<type>& l) const {
	return (key == l.key);
}