#pragma once
#include "tree_node.h"

#define NULL nullptr

template<typename T>
class BinarySearchTree 
{
	Node<T>* root; // указатель на корневой узел
public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree& tree);
	~BinarySearchTree();
	//методы:
	Node<T>* Search(T key);
	Node<T>* Searchmin(Node<T>* x);
	Node<T>* Searchmax(Node<T>* x);
	Node<T>* Searchnext(Node<T>* curr);
	Node<T>* Searchprev(Node<T>* curr);
	void Insert(Node<T>* x);
	void Remove(Node<T>* z);
	Node<T>* GetRoot() { return root; };
};

template<typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	root = NULL;
}

template<typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& tree)
{
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	while (root != NULL)
	{
		Node<T>* tmp = Searchmax(root);
		Remove(tmp);
	}

}

//методы:
template<typename T>
Node<T>* BinarySearchTree<T>::Search(T data)
{
	Node<T> *curr = root;
	while (curr != NULL && curr->key != data)
	{
		if (data < curr->key) curr = curr->pLeft;
		else curr = curr->pRight;
	}
	return curr;
}

template<typename T>
Node<T>* BinarySearchTree<T>::Searchmin(Node<T>* x)
{
	Node<T>* curr = x;
	while (curr->pLeft != NULL)
	{
		curr = curr->pLeft;
	}
	return curr;
}

template<typename T>
Node<T>* BinarySearchTree<T>::Searchmax(Node<T>* x)
{
	Node<T>* curr = x;
	while (curr->pRight != NULL)
	{
		curr = curr->pRight;
	}
	return curr;

}

template<typename T>
Node<T>* BinarySearchTree<T>::Searchnext(Node<T>* curr)
{
	Node<T> *res = NULL;
	if (curr->pRight != NULL)
	{
		res = Searchmin(curr);
		return res;
	}
	res = curr->pParent;
	Node<T> *tmp = curr;
	while (res != NULL && tmp == res->pRight)
	{
		tmp = res;
		res = res->pParent;
	}
	return res;

}

template<typename T>
Node<T>* BinarySearchTree<T>::Searchprev(Node<T>* curr)
{
	Node<T> *res = NULL;
	if (curr->pLeft != NULL)
	{
		res = Searchmax(curr);
		return res;
	}
	res = curr->pParent;
	Node<T> *tmp = curr;
	while (res != NULL && tmp == res->pLeft)
	{
		tmp = res;
		res = res->pParent;
	}
	return res;

}

template<typename T>
void BinarySearchTree<T>::Insert(Node<T>*x)
{
	if (root == NULL)
	{
		root = x;
		return;
	}
	Node<T> *node = root, *y;
	while (node != NULL)
	{
		y = node;
		if (x->key < node->key) node = node->pLeft;
		else node = node->pRight;
	}
	x->pParent = y;
	if (x->key < y->key) y->pLeft = x;
	else y->pRight = x;
}

template<typename T>
void BinarySearchTree<T>::Remove(Node<T>*z)
{
	Node<T> *y = NULL, *x = NULL;
	if (z->pLeft != NULL && z->pRight != NULL)
	{
		y = Searchnext(z);
	}
	else y = z;
	if (y->pLeft != NULL) x = y->pLeft;
	else x = y->pRight;
	if (x != NULL) x->pParent = y->pParent;
	if (y->pParent != NULL)
	{
		if (y = y->pParent->pLeft) y->pParent->pLeft = x;
		else y->pParent->pRight = x;
	}
	if (y != z)
	{
		z->key = y->key;
	}
}