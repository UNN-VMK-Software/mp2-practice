#pragma once
#include "node.h"

//Шаблон класса Циклический список с головой
template<class T>
class list
{
private:
	node<T>* head;	//голова
	node<T>* Current;//Указатель на голову
	node<T>* tail;//хвост
	void Clean();									//Служебный метод, очистка списка
public:
	list();											//Конструктор по умолчанию
	~list();										//Деструктор
	list(const list<T>& src);						//Конструктор копирования
	list<T>& operator=(const list<T>& temp);		//Перегрузка оператора присваивания
	void InsertInOrder(T elem);						//Вставка в упорядоченный список
	void InsertAfter(const node<T>* A, T data);		//вставка после
	node<T>* GetHead() const { return head; }		//Получить указатель на голову
	bool IsEmpty() const;							//проверка на пустоту
	void reset(); //current = head
	void gonext();//переход на следующее звено
	void insertup(const T &d);//вставка
	bool operator==(const list<T>& var) const;								//Оператор сравнения ==
	bool operator!=(const list<T>& temp) const { return !(*this == temp); }	//Оператор сравнения не равно
};



template <class T>//Очистка списка
void list<T>::Clean()
{
	node<T>* curr = head->next;
		while (curr != head)
		{
			node<T>* temp = curr->next;
			delete curr;
			curr = temp;
		}
		head->next = head;//?
}


template <class T>//Конструктор по умолчанию
list<T>::list()
{
	head = new node<T>;
	head->next = head;
}



template <class T>//Деструктор
list<T>::~list()
{
	Clean();
	delete head;
}

template<class T>//переход на следующий
 void list<T>::gonext()
{
	current = current->next;
}


template <class T>//Конструктор копирования
list<T>::list(const list<T>& src) //: list()
{	
	node<T>* psrc = src.head;
	node<T>* pcur = head;
	while (psrc->next != src.head)
	{
		psrc = psrc->next;
		pcur->next = new node<T>(psrc->data);
		pcur = pcur->next;
	} 
	pcur->next = head;



	/*head = new node<T>();
	node<T>* temp = head;
	node<T>* temp1 = src.head->next;
	while (temp1 != src.head)
	{
		temp->next = new node<T>(temp1->data);
		temp = temp->next;
		temp1 = temp1->next;
	}
	tail = temp;
	tail->next = head;*/



	/*if (src.IsEmpty())
		head = NULL;
	else
	{
		//head =
		Current = new node<T>(src.head->data); //head;
		node<T>* a =src.head->next;
		while (a != src.Current)
		{
			Current->next = new node<T>(a->data);
			Current = Current->next;
			a = a->next;
		}
		Current->next = new node<T>(a->data, head);
		Current = Current->next;
	}*/

		
}

template <class T>// проверка на пустоту
bool list<T>::IsEmpty() const
{
	if (head == NULL)
		return true;
	else return false;
}

template<class T>//current = head;
void list<T>::reset()
{
	current = head;
}


 template<class T>
 void list<T>::insertup(const T & d)
{
	node<T>* t = new node<T>(d);
	node<T>* tt = head->next;
	node<T>* pred = head;
	while ((tt != head) && (tt->data > t->data))
	{
		pred = tt;
		tt = tt->next;
	}
	pred->next = t;
	t->next = tt;
	if (tt == head)
	{
		tail = t;
	}
}

template <class T>//Оператор присваивания
list<T>& list<T>::operator=(const list<T>& temp) 
{
	Clean();
	node<T>* ptemp = temp.head;
	node<T>* pcurr = head;
	while (ptemp->next != temp.head)
	{
		ptemp = ptemp->next;
		pcurr->next = new node<T>(ptemp->data);
		pcurr = pcurr->next;
	}
	pcurr->next = head;
	return *this;
}


template <class T>//Вставка в упорядоченный список
void list<T>::InsertInOrder(T elem)
{
	node<T>* temp = new node<T>(elem);
	node<T>* curr = head;

	while ((*(curr->next) < *temp) && curr->next != head)
		curr = curr->next;
	node<T>* temp1 = curr->next;
	curr->next = temp;
	curr->next->next = temp1;
}

template <class T>//вставка звена после
void list<T> :: InsertAfter(const node<T>* A, T data)
{
	if (head == NULL)
		throw "list is empty";
	else 
	{
		node<T>* temp = head;
		while ((temp != A)&&(temp->next!=head))
			temp = temp->next;
		if (temp == A)
		{
			node<T>* temp1 = temp->next;
			temp->next = new node<T>(data, temp1);
		}
		else
			throw "net";
	}
	
}


template<class T>//Оператор сравнения
bool list<T>::operator==(const list<T>& var) const
{
	bool res = true;
	if (this != &var)
	{
		node<T>* temp1 = var.head->next;
		node<T>* temp2 = head->next;
		while (temp1->data == temp2->data && temp2 != head && temp1 != var.head)
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		if (temp2 != head || temp1 != var.head)
			res = false;
	}
	return res;
}
