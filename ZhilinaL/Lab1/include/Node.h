#pragma once
using namespace std;
template<typename T>
class Node
{
public:
	T data;		                                                    
	Node* next;	                                                        
	Node() { next = nullptr; }										   
	Node(T Data) { data = Data; next = nullptr; }					    
	bool operator< (const Node& z) const { return (data < z.data); }
	bool operator> (const Node& z) const { return (data > z.data); }
};



