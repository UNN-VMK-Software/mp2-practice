#pragma once
#include "binary_search_tree.h"
#include "priority_queue.h"

#define NULL nullptr

template<typename T>
class BinarySearchTreeBasedPriorityQueue: public PriorityQueue<T>
{
public:
	BinarySearchTree<T>* tree;
	BinarySearchTreeBasedPriorityQueue();
	~BinarySearchTreeBasedPriorityQueue();
	void push(T val);
	T pop();
	bool IsEmpty();
};

template <typename T>
BinarySearchTreeBasedPriorityQueue<T>::BinarySearchTreeBasedPriorityQueue()
{
}

template <typename T>
BinarySearchTreeBasedPriorityQueue<T>::~BinarySearchTreeBasedPriorityQueue()
{
}

template <typename T>
void BinarySearchTreeBasedPriorityQueue<T>::push(T val)
{
	Node<T>* tmp;
	tmp->key = val;
	tree->Insert(tmp);
}

template <typename T>
T BinarySearchTreeBasedPriorityQueue<T>::pop()
{
	Node<T>* node = tree->Searchmin(tree->GetRoot());
	tree->Remove(node);
	return node->key;
}

template <typename T>
bool BinarySearchTreeBasedPriorityQueue<T>::IsEmpty()
{
	if (tree->GetRoot()==NULL) return true;
	else return false;
}
