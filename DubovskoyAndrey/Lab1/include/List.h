#ifndef LIST_H
#define LIST_H

template <typename TKey>
class List
{
private:
	Node<TKey> *root;
public:
	List();
	List(const List<TKey>&);
	~List();

	void Add(TKey);
	void Remove(TKey);
	void InsertBefore(TKey, TKey);
	void InsertAfter(TKey, TKey);
	void InsertEnd(TKey);
	void print() const;
	int Size() const;
	Node<TKey> *Search(TKey);
};

template <typename TKey>
List<TKey>::List()
{};

template <typename TKey>
List<TKey>::List(const List<TKey>&L)
{
	 this->root = L;
};

template <typename TKey>
List<TKey>::~List()
{
	
	while (root != 0)
	{
		Node<TKey>* tmp = root;
		root = root->pNext;
		delete tmp;
	}
	delete root;
};

template <typename TKey>
void List<TKey>::Add(TKey K)
{
	Node<TKey> * a = new Node<TKey>;
	a->key = key;
	a->pNext = root;
	root = a;
};
template <typename TKey>
void List<TKey>::Remove(TKey K)
{
	if (root == 0)
		throw "Node is empty";
	if (root->key == K->key)
	{
		Node<TKey>*n = root;
		root = root->pNext;
		delete n;
		return;
	}
	Node<TKey>*tmp = root;
	while (tmp -> pNext != 0 && tmp->pNext->key != K)
	{
		tmp = tmp->pNext;
	}
	if (tmp->pNext == 0)
		throw "Key not found";
	Node<TKey>*n = tmp->pNext;
	tmp->pNext = n->pNext;
};
template <typename TKey>
void List<TKey>::InsertBefore(TKey K1, TKey K2)
{
	if (root == 0) throw "Is Empty";
	if (root->key == K1)
	{
		root = new Node<TKey>;
		root->key = K1;

	}
};
template <typename TKey>
void List<TKey>::InsertAfter(TKey K1, TKey K2)
{
	if (root == 0) throw "List is empty";
	while (root->pNext != 0 && root->key != K2)
	{
		root = root->pNext;
	}
	if (root->pNext == 0 && root->key != K2)
	{
		throw "Key not  found";
	}
	Node<Tkey>*a = new Node<TKey>;
	a->key = K1;
	a->pNext = root -> pNext;
	root->pNext = a;
};
template <typename TKey>
void List<TKey>::InsertEnd(TKey K)
{
	if (root == 0)
	{
		root = new Node<TKey>;
		root->key = K;
		root->pNext = 0;
		return;
	}
	while (root->pNext != 0)
	{
		root = root->pNext;
	}
	root->pNext = new Node<TKey>;
	root->pNext->key = K;
	root->pNext -> pNext = 0;
};
template <typename TKey>
int List<TKey>::Size() const
{
	Node<TKey>*a = root;
	int i = 0;
	while (a->pNext!=0)
	{
		i++;
		a = a->pNext;
	}
	return i;
};
template <typename TKey>
Node<TKey>* List<TKey>::Search(TKey K)
{
	Node<TKey>*a = root;
	while (a!= 0 && a->key!=K)
	{
		a = a->pNext;
	}
	if (a == 0) throw "Key not found";
	return a;
};

template <typename TKey>
void List<TKey>::print() const
{
	if (root == 0)
	{
		throw "Node is empty";
	}
	Node<TKey>* a = root;
	while (a != 0)
	{
		cout << a->key << " ";
		a = a->pNext;
	}
	cout << endl;
};

#endif