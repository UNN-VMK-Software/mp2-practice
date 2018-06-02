#ifndef TSTACK_H
#define TSTACK_H
#include "TList.h"
#include <locale.h>

template <typename Type>
class TStack{
	private:
		TList<Type> *pFirst; //Указатель на первое звено
	public:
		TStack(); //Конструктор
		TStack(const TStack<Type>& St); //Конструктор копирования
		~TStack(); //Деструктор
		Type Getroot(); //Получить элемент списка
		bool Is_Full() const; //Проверка на полноту
		bool Is_Empty() const; //Проверка на пустоту
		void Push(Type key); //Добавление элемента в стек
		Type Pop(); //Изъятие элемента из стека
		void Print(); // Вывод на экран

};

template <typename Type> //Конструктор для стека
TStack <Type> ::TStack() {
	pFirst = new TList<Type>;
}

template <typename Type>   //Получить элемент списка
Type TStack<Type>::Getroot() {
	return pFirst;
}
template <typename Type >   //Конструктор копирования
TStack <Type> ::TStack(const TStack & St ) {
	pFirst = new TList<Type>(*(St.pFirst));
}

template <typename Type>  //Деструктор
TStack<Type>::~TStack(){
	pFirst->~TList();
}


template <typename Type>
bool TStack<Type>::Is_Empty() const{   //Контроль пустоты
	return (pFirst->Getroot() == 0);
}

template <typename Type>
bool TStack<Type>::Is_Full() const {  //Контроль полноты
	TLink<Type> *ptr;
	try{
		ptr = new TLink<Type>;
	}
	catch (...){
		return true;
	}
	   delete ptr;
		return false;
}

 template <typename Type>  //Добавление элемента в стек
 void TStack<Type>::Push(Type key){   
 setlocale(LC_CTYPE, "russian");
 if (Is_Full()) throw " Стек полон";
 pFirst->Insert_Begin(key);
 }

 template <typename TYPE>
 void TStack<TYPE>::Print()
 {
	 TStack<TYPE>* tmp = new TStack<TYPE>(*this);
	 while (!tmp->Is_Empty())
		 cout << tmp->Pop() << endl;

 }

 template <typename Type>
 Type TStack <Type>::Pop(){ //Изъятие элемента из стека
 setlocale(LC_CTYPE, "russian");
 if (Is_Empty()) throw " Стек пуст";
 Type ptr = pFirst->Getroot()->key;
 pFirst->Delete(ptr);
 return ptr;
 }
#endif