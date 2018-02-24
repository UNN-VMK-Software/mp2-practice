#pragma once
template <typename T>
class list;
template <typename Type1>
class node {
private:
	Type1 date;
	node* next;
public:
	~node();
	node(const Type1 date = 0, node* next = 0); // Date - это ссылка на объект типа Type1 это же monom
	node(const node<Type1> &con);
	node(const node* con);
	friend class list <Type1>;
};
template <typename Type1>
node<Type1>::node(const Type1 date, node* next) {
	this->next = next;
	this->date = date;
}
template <typename Type1>
node<Type1>::node(const node<Type1> &con) {
	next = con.next;
	date = con.date;
}
template <typename Type1>
node<Type1>:: node(const node* con) {
	next = con->next;
	date = con->date;
}
// шаблонная нода
template <typename Type1>
node<Type1>:: ~node() {
	delete next;
}