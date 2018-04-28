#pragma once
#include <string>

using namespace std;

template <class type>
struct line {
	type data;
	string key;
	line() { key = ""; data = type(); }
	line(string k, type d) { key = k; data = d; }
	line<type>& operator=(const line<type>& l);
};

template <class type> line<type>& line<type>::operator=(const line<type>& l) {
	key = l.key;
	data = l.data;
	return *this;
}

