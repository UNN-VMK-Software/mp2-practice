#pragma once



//Звено списка
template<typename type>
class unit
{
public:
	type data;		                                                    //Данные в элементе
	unit* next;	                                                        //Указатель на следующий элемент
	unit() { next = nullptr; }										    //Конструктор по умолчанию
	unit(type dz) { data = dz; next = nullptr; }					    //Конструктор с параметром
	bool operator< (const unit& z) { return (data<z.data); }	 
	bool operator> (const unit& z) { return (data>z.data); }	
};