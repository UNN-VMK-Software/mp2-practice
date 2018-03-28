#pragma once

template <typename T>
class TLink {
public:
	T data;
	TLink<T>* pNext;
	TLink() {};
	~TLink() {};
	TLink(const T datum, TLink<T>* link = NULL) { data = datum; pNext = link; }
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