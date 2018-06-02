#ifndef TLIST_H
#define TLIST_H                                                                                       
#include <locale.h>
#include "TLink.h"


template <typename Type>
class TList {
	private:
	   TLink<Type> *begin;
	public:
	   TList(); //Конструктор
	   TList(const TList<Type>&L); //Конструктор копирования
	   ~TList(); //Деструктор
	   void Insert_Begin(Type key); //Добавление элемента в начало
	   void Insert_End(Type key); //Добавление элемента в конец
	   void Insert_Before(Type key, Type nextkey); // Добавление эл-та ДО другого эл-та
	   void Insert_After(Type key, Type prevkey); // Добавление эл-та ПОСЛЕ другого эл-та
	   TLink<Type>* Search(Type key); // Поиск элемента с заданным ключом
	   void Delete(Type key); //Удаление
	   TLink<Type>* Getroot() const; // Получить элемент списка
	   int Size() const; //Подсчёт количества элементов
	   void Print(); //Вывод элементов списка на экран
       };  

template <typename Type>
TList<Type>::TList(){
	begin = NULL;
}
template <typename Type>
TList<Type>::TList(const TList<Type>&L){
	if (L.begin == 0) return 0;
	TLink<Type>*second = L.begin;
	begin->Key = second->key;
	begin->pNext = 0;
	second = second->pNext;
	TLink<Type>*tmp = begin;
	while (begin != 0)
	{
		tmp->pNext = new TLink<Type>;
		tmp->pNext->pNext = 0;
		tmp = tmp->pNext;
		second = second->pNext;
	}

}

template <typename Type>
TList<Type>::~TList(){
	delete begin;

}
template <typename Type>
void TList<Type>::Insert_Begin(Type key) //Добавление эл-та  в начало списка
{
	TLink<Type> *n = new TLink<Type>();
	n->key = key;
	n->pNext = begin;
	begin = n;
}

template <typename Type>
void TList<Type>::Insert_End(Type key) //Добавление эл-та в конец списка
{
	if (begin == 0)
	{
		begin = new TLink<Type>();
		begin->key = key;
		begin->pNext = NULL;
		return;
	}

	while (begin->pNext != 0)
	{
		begin = begin->pNext;
	}
	begin->pNext = new TLink<Type>();
	begin->pNext->key = key;
	begin->pNext->pNext = 0;
}

template <typename Type>
void TList<Type>::Insert_Before(Type key, Type nextkey)  //Добавление эл-та ДО другого эл-та с заданным ключом
{
	setlocale(LC_CTYPE, "russian");
	if (begin == 0)
	{
		throw "Список пуст";
	}
	if (begin->key == nextkey)
	{
		TLink<TYPE>* ptr = new TLink<Type>();
		ptr->key = key;
		ptr->pNext = begin;
		begin = ptr;
		return;
	}
	TLink<Type> *tmp = begin;
	while ((tmp->pNext != 0) && (tmp->pNext->key != nextkey))
	{
		tmp = tmp->pNext;
	}
	if (tmp->pNext == 0)
	{
		throw "Элемент с указанным ключом не найден";
	}
	TLink<Type> *n = new TLink<Type>();
	n->key = key;
	n->pNext = tmp->pNext;
	tmp->pNext = n;
}
template <typename Type> //Добавление эл - та ПОСЛЕ другого эл - та с заданным ключом
void TList<Type>::Insert_After(Type key, Type prevkey)  
{
	setlocale(LC_CTYPE, "russian");
	if (begin == 0)
	{
		throw "Список пуст";
	}
	TLink<Type> *tmp = begin;
	while ((tmp->pNext != 0) && (tmp->key != prevkey))
	{
		tmp = tmp->pNext;
	}

	if ((tmp->pNext == 0) && (tmp->key != prevkey))
	{
		throw "Элемент с указанным ключом не найден";
	}
	TLink<Type> *n = new TLink<Type>();
	n->key = key;
	n->pNext = tmp->pNext;
	tmp->pNext = n;
}

 template <typename Type>
 TLink<Type>* TList<Type>::Getroot() const{
	 return begin;

}
 template <typename Type>
 int TList<Type>::Size() const{
	 int amount = 0;
	 TLink<Type>*ptr = begin;
	 while (ptr != 0){
		 amount++;
		 ptr = ptr->pNext;
	 
	 }
	 return amount;
 }
 template <typename Type>
 TLink<Type>* TList<Type>::Search(Type key){
	 setlocale(LC_CTYPE, "russian");
	 TLink<Type>*tmp = begin;
	 while (tmp != 0)
	 {
		 if (tmp->key == key)
		 {
			 return tmp;
		 }
		 tmp = tmp->pNext;
	 }
	 throw " Элемент с указанным ключом не найден";
 }

 template <typename Type>
 void TList<Type>::Delete(Type key){
	 setlocale(LC_CTYPE, "russian");
	 if (begin == 0) return;
	 TLink<Type>*tmp = begin;
	 if (begin->key = key)
	 {
		 begin = begin->pNext;
		 delete tmp;
		 return;
	 }
	 while ((tmp->pNext != 0) && (tmp->pNext->key != key))
		 tmp = tmp->pNext;
	 if (tmp->pNext == 0)
	 {
		 throw " Ошибка!";
	 }
	 TLink<Type>*ptr = tmp->pNext;
	 tmp->pNext = ptr->pNext;
	 delete ptr;
 }
 template <typename Type>
 void TList<Type>:: Print(){
		 TLink<Type> *tmp = begin;
	 while (tmp != 0){
		 cout << tmp->key << "->";
		 tmp = tmp->pNext;

	 }

 }
#endif