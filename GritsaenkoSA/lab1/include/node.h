#pragma once

//Шаблон класса Элемент списка
template<class T>
class node
{
public:
	T data;		//Данные в элементе
	node* next;		//Указатель на следующий эл-т
	bool operator< (const node& n) { return (data<n.data); }	//Операторы 
	bool operator> (const node& n) { return (data>n.data); }	//сравнения
	node(T in) { data = in; next = NULL; }					//Конструктор с параметром
	node() { next = NULL; }										//Конструктор по умолчанию
	node(T Data, node* NextPtr) { data = Data; next = NextPtr;}// конструктор с двумя параметрами

};
