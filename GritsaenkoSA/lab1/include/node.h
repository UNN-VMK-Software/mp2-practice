#pragma once

//Шаблон класса Элемент списка
template<class T>
class node
{
public:
	T data;		//Данные в элементе
	node<T>* next;		//Указатель на следующий эл-т
	bool operator< (const node<T>& n) const;	//Оператор сравнения
	bool operator> (const node<T>& n) const;	//Оператор сравнения
	node(T in, node<T>* nxt = NULL);				//Конструктор с параметром
	node();					//Конструктор по умолчанию
	//node(T Data, node* NextPtr);// конструктор с двумя параметрами

};

template <class T>
node<T>::node(T in, node<T>* nxt = NULL)
{ 
	data = in;
	next = nxt;
}

template <class T> //Оператор сравнения
bool node<T>::operator< (const node<T>& n) const
{ 
	return (data<n.data); 
}

template <class T> //Оператор сравнения
bool node<T>::operator> (const node<T>& n) const
{ 
	return (data>n.data);
}

/*template <class T> //Конструктор с параметром
node<T>::node(T in) 
{ 
	data = in; 
	next = temp; 
}	*/

template <class T> //Конструктор по умолчанию
node<T>::node() 
{ 
	next = NULL; 
}	

/*template <class T> 
node<T>::node(T Data, node* NextPtr) 
{ 
	data = Data; 
	next = NextPtr;
}*/