#ifndef TLINK_H
#define TLINK_H

template <typename T>
class TLink {
public:
	T data;
	TLink<T>* pNext;
	TLink() {};
	~TLink() {};
	TLink(const T datum, TLink<T>* link = nullptr) { data = datum; pNext = link; }
	TLink<T>& operator=(const TLink<T>& _TLink)
	{
		data = _TLink.data;
		pNext = _TLink.pNext;
		return *this;
	};
	bool operator == (const TLink<T>& link) const
	{
		return *this->pNext == link.pNext;
	};
};

#endif
