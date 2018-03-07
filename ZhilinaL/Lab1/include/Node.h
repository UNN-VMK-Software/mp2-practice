#pragma once

template <typename typediff>
class Node
{
private:
	Node* Next;
	typediff Data;
public:
	Node(typediff Data = 0, Node* NextPtr = NULL);
	Node(const Node<typediff> &NodaCopy);
	~Node();
};

template <typename typediff>
Node<typediff> ::Node(typediff data, Node* NextPtr)
{
	Data = data;
	Next = NextPtr;
}

template <typename typediff>
Node<typediff> ::Node(const Node<typediff> &NodaCopy)
{
	Data = NodaCopy<typediff>.Data;
	Next = NodaCopy<typediff>.Next;
}

template <typename typediff>
Node<typediff> :: ~Node()
{
	delete Next;
	Data = NULL;
}
