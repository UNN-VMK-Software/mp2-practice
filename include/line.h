#pragma once
#include <string>

using namespace std;

template <class type>
struct line {
	type data;
	string key;
	line() { key = string(); data = type(); }			
	line(string k, type d) { key = k; data = d; }

};

