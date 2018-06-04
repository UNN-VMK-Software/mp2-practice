#pragma once
#define NULL 0
#include "node.h"
                                            /*СПИСОК С ГОЛОВОЙ*/
template <typename T>
class list {
private:
	node<T>* current;
   
	node<T>* Head; 
public:
	list();
	list(const list<T> &list2);     
	~list();   
	list<T>& operator = (const list<T> &list2); 
	bool IsEmpty() const;  
	void Insert_to_tail(const T con = 0); 
	void clear();
	bool operator == (const list<T> &list2) const; 
	bool operator != (const list<T> &list2) const;
	void Dellcurrent();
	void reset();
	void getnext();
	T getcurrentdate();
	T getnextcurrentdate();
	bool IsEnd();
	void Delete(const T date);
};
template <typename T>
T list<T>:: getnextcurrentdate() {
	return current->next->date;
}

template <typename T>
void list<T>:: Delete(const T date1) {
	if (!IsEmpty()) {
		int a = 1;
		node<T> * ptr = Head->next;
		if (ptr->date != date1) { 
			ptr = ptr->next;
		}
		else a = 0;
		while ((ptr->date != date1)&&(ptr!=Head->next)&&(a==1)) ptr = ptr->next;
		if (a == 1 && ptr == Head->next) throw "netu node with this date";
		//нашли адрес ноды которую нужно удалить
		if (a == 0) {
			//это первая нода надо переобозначить Head->next; и 
			node<T> * ptrend = Head->next;
			int flag = 0;
			while (ptrend->next != Head->next) {
				ptrend = ptrend->next;
				flag = 1;
			}
			if (flag == 1) {
				node<T> *p = ptr->next;
				delete ptr;
				Head->next = p;
				current = Head->next;
				ptrend->next = Head->next;
			}
			else {
				delete ptr;
				Head->next = Head;
				current = NULL;
			}
		}
		else
		{
			node<T> *pprev = Head->next;
			node<T> *pnext = ptr->next;
			while (pprev->next != ptr) pprev = pprev->next;
			delete ptr;
			pprev->next = pnext;
			current = pprev;
			
		}

	}
	else throw"cant delete empty list";
}


template <typename T>
bool list<T>::IsEnd() {
	if (current->next == Head->next) return true; else return false;
}
template <typename T>
void list<T>:: getnext() {
	current = current->next;
}

template <typename T>
T list<T>:: getcurrentdate() {
	return current->date;
}
template <typename T>
void list<T>:: reset() {
	if (!IsEmpty()) current = Head->next;
}
template <typename T>
list<T>::list() {
	Head = new node<T>;
	Head->next = Head;
	current = NULL;
}
template <typename T>
bool list<T>::IsEmpty() const {
	if (current == NULL)
		return true; 
	else
		return false;
}


template <typename T>
void list<T>::Insert_to_tail(const T con) {
	if (!IsEmpty()) {
		while (current->next != Head->next) current = current->next;
		current->next = new node<T>(con, Head->next);
	}
	else {
		Head->next = new node<T>(con);
		Head->next->next = Head->next;
		current = Head->next;
	}
}

template <typename T>
list<T>::list(const list<T> &list2) {
	Head = new node<T>;
	Head->next = Head;
	current = NULL;
	if (!list2.IsEmpty()) {
		node<T>* ptr2 = list2.Head;//указывает на фиктивную list2 ноду
		ptr2 = ptr2->next;//  нода с данными у того от куда копирую
		Head->next = new node<T>(ptr2);
		node<T>* ptrend = ptr2;
		current = Head->next; // current на ноду с данными у исходного
		while (ptrend->next!= ptr2) ptrend = ptrend->next;
		ptr2 = ptr2->next;
		while (ptr2 != list2.Head->next) {
			current->next = new node<T>(ptr2);
			current = current->next;
			ptr2 = ptr2->next;
		}
		//зациклить
		current->next = Head->next;
	}
	current = list2.current;
}
template <typename T>
list<T>::~list() {
	this->clear();
}
  template <typename T>
  void list<T>::clear(){
	  if (!IsEmpty()) {
		  reset();
		  node<T>* end;
		  while (!IsEnd()) getnext();
		  end = current;
		  reset();
		  while (!IsEnd()) {
			  node<T>* ptr = current->next;
			  delete current;
			  Head->next = ptr;
			  current = ptr;
			  end->next = ptr;
		  }
		  delete current;
		  current = NULL;
		  Head->next = Head;
	  }
}
      template <typename T>
	  list<T>& list<T>:: operator = (const list<T> &list2) {   //необходимо обходиться без итераторов
		  this->clear();
		  if (!list2.IsEmpty()) {
			  //найдём конец у list2
			  node<T>* ptr2 = list2.Head;//указывает на фиктивную list2 ноду
			  ptr2 = ptr2->next;//  нода с данными у того от куда копирую
			  Head->next = new node<T>(ptr2);
			  node<T>* ptrend = ptr2;
			  current = Head->next; // current на ноду с данными у исходного
			  while (ptrend->next != ptr2) ptrend = ptrend->next;
			  ptr2 = ptr2->next;
			  while (ptr2 != list2.Head->next) {
				  current->next = new node<T>(ptr2);
				  current = current->next;
				  ptr2 = ptr2->next;
			  }
			  //зациклить
			  current->next = Head->next;
		  }
		  return (*this);
		  }
	  

	template <typename T>
	bool  list<T> ::operator == (const list<T> &list2) const {
		bool res = true;
		if (list2.IsEmpty() && this->IsEmpty()) return true;
		else {
			node<T>* listc = Head->next; //Адрес первой носящей смысл ноды с даннными
			node<T>* list2c = list2.Head->next;  //Адрес первой носящей смысл ноды с даннными
			if (listc->date != list2c->date) res = false;
			listc = listc->next;
			list2c = list2c->next;
			while (listc != Head->next && list2c != list2.Head->next) {
				if (listc->date != list2c->date) res = false;
				listc = listc->next;
				list2c = list2c->next;
			}
			if (listc != Head->next || list2c != list2.Head->next) res = false;
		}
		return res;
	}
	template <typename T>
	bool  list<T> ::operator != (const list<T> &list2) const {
		if (*this == list2) return 0; else return 1;
	}

	template <typename T>
	void list<T> ::Dellcurrent()
	{
		if (!this->IsEmpty())
		{
			node<T> * Ptr = Head->next;
			node<T> * Ptrnext = current->next;
			node<T> * Ptr2 = Head->next;

			if ((current == Ptr) && (current->next == Ptr)) //надо сделать список пустым 
			{
				delete current;
				Head->next = Head;
				current = NULL;
			}
			else if ((current == Ptr) && (current->next != Ptr)) //удалить начальный 
			{
				while (Ptr2->next != Head->next) Ptr2 = Ptr2->next; // теперь Ptr2 - конец 
				delete current;
				Head->next = Ptrnext;
				current = Ptrnext;
				Ptr2->next = Head->next;

			}
			else if (current != Ptr) // удалить не начальный, но конечный или средний 
			{
				while (Ptr->next != current) Ptr = Ptr->next;
				Ptr->next = Ptrnext;
				delete current;
				current = Ptr;
			}
		}
	}

	