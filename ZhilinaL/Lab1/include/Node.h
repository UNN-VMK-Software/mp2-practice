#pragma once
using namespace std;
template<typename T>
class Node
{
public:
	T data;	//данные в звене	                                                    
	Node* next;//указатель на следущее звено	                                                        
	Node() { next = nullptr; }//конструктор по умолчанию-создает пустое звено								   
	Node(T Data) { data = Data; next = nullptr; }//конструктор с параметром-данные звена					    
	bool operator< (const Node& z) const { return (data < z.data); }//перегрезка операции меньше, сравнивает данные звеньев
	bool operator> (const Node& z) const { return (data > z.data); }//перегрузка операции больше, сравнивает данные звеньев
};



