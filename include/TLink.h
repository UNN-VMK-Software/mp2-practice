#ifndef TLINK_H
#define TLINK_H

template <typename Type>
class TLink{
	public:
		Type key;
		TLink<Type> *pNext;
};

#endif 