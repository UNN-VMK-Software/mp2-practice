#pragma once
#include <string>

using namespace std;


template <class type>
struct record 
{
	type* data;
	string key;
	record() {key = ""; data = nullptr;}                                            //Конструктор без параметров
	
	record(string k) { key = k; data = nullptr; }
	
	record(string s, type t)  {key = s; data = new type(t);}                        //Конструктор с парметрами
	record(const record<type>& r) { key = r.key; data = new type(*(r.data)); }      //Конструктор копирования
	record<type>& operator=(const record<type>& r);                                 //Присваивание
	~record() { delete data; };
	bool operator==(const record<type>& r) const { return key == r.key; }
	bool operator!=(const record<type>& r) const { return !(*this == r); }

};


template <class type> record<type>& record<type>::operator=(const record<type>& r)
{
	key = r.key;
	delete data;
	data = new type(*(r.data));
	return *this;
}