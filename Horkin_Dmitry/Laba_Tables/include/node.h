#pragma once
#include <string>
template <typename Type1>
class node {
public:
	Type1 date;
	node* next;
	node() { next = NULL; }; //гениально
	node(const Type1 date, node* next = NULL); 
	node(const node<Type1> &con);
	node(const node* con);
};
template <typename Type1>
node<Type1>::node(const Type1 date, node* next) {
	this->next = next;
	this->date = date;
}
template <typename Type1>
node<Type1>::node(const node<Type1> &con) {
	date = con.date;
}
template <typename Type1>
node<Type1>::node(const node* con) {
	date = con->date;
}
