#ifndef NODE_H
#define NODE_H

template <typename TKey>
class Node
{
public:
	TKey key;
	Node<TKey> *pNext;

};

#endif 
