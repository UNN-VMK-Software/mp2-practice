#pragma once
#
template<typename T>
class Node
{
public:
	T key;
	Node* pLeft;
	Node* pRight;
	Node* pParent;
	Node() {};
	Node(T k) { key = k; };
	~Node() {};
};