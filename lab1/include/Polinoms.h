#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

struct Tmonom {
	int cf;
	unsigned int abc;
	Tmonom(const double d = 0, const unsigned int m = 0) { cf = d; abc = m; };
	Tmonom(const Tmonom& _Tmonom) {
		cf = _Tmonom.cf;
		abc = _Tmonom.abc;
	};
	const Tmonom& operator = (const Tmonom& _Tmonom)
	{
		cf = _Tmonom.cf;
		abc = _Tmonom.abc;
		return *this;
	};
	bool operator < (const Tmonom& _tmonom) const
	{
		return abc < _tmonom.abc;
	};
	bool operator != (const Tmonom& _tmonom) const
	{
		return abc !=  _tmonom.abc;
	};
	bool operator == (const Tmonom& _tmonom) const
	{
		return abc == _tmonom.abc;
	};
};

template <typename T>
class TLink {
public:
	T data;
	TLink<T>* pNext;
	TLink() {};
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
template <typename T>
class TRingList {
private:
	TLink <T> *head;
public:
	TLink <T> *current;
	TRingList();
	TRingList(const TRingList <T> &);
	~TRingList();
	void Insert(const T _data);
	void InsertInEnd(const T datum);
	void Reset();
	void Clean();
	bool IsEnded();
	TRingList<T>& operator=(const TRingList<T>& _TRingList);
	bool operator==(const TRingList<T>& list2) const;
	TLink<T>* GetNext();
	TLink<T>* Search(const TLink<T>& d);
};

template <typename T>
TRingList<T>::TRingList()
{
	head = new TLink<T>();
	head->pNext = head;
	current = head;
}

template <typename T>
TLink<T>* TRingList<T>::Search(const TLink<T> & d)
{
	TLink<T>* tmp = head;
	if (tmp->pNext != head)
	{
		while ((tmp->pNext != head) && (tmp->data != d.data))
		{
			tmp = tmp->pNext;
		}
		if (tmp->data == d.data)
			return tmp;
		else
			return NULL;
	}
	else
		return NULL;
}
template <typename T>
TRingList<T>::TRingList(const TRingList <T> & Ring)
{
	if (Ring.head->pNext != head)
	{
		head = new TLink<T>(Ring.head->data, Ring.head);
		TLink<T> *temp = head;
		TLink<T> *temp2 = Ring.head->pNext;
		while (temp2 != head)
		{
			temp->pNext = new TLink<T>(temp2->data, Ring.head);
			temp = temp->pNext;
			temp2 = temp2->pNext;
		}
	}
	else {
		head = new TLink<T>(Ring.head->data);
		current = head;
		head->pNext = head;
	}
}
template<typename T>
TRingList<T>::~TRingList()
{
	TLink<T> *temp;
	temp = head;
	TLink<T> *temp2;
	temp2 = head;
	while (temp->pNext != head)
	{
		temp2 = temp->pNext;
		delete temp;
		temp = temp2;
	}
	delete temp;
}

template <typename T>
void TRingList<T>::Insert(const T datum)
{
	if (head->pNext == head) // проблема с доступом к голове
	{
		TLink<T>* tmp = new TLink<T>(datum, head);
		head->pNext = tmp;
	}
	else
	{
		TLink<T>* prev = new TLink<T>(datum);
		TLink<T>* tmp = prev;
		tmp = tmp->pNext;
		while ((tmp != head) && (datum < tmp->data))
		{
			prev = tmp;
			tmp = tmp->pNext;
		}
		prev->pNext = new TLink<T>(datum, tmp);
	}
}
template <typename T>
void TRingList<T>::InsertInEnd(const T datum)
{
	TLink<T>* tmp = head;
	if (head->pNext != head)
	{
		while (tmp->pNext != head)
			tmp = tmp->pNext;
		tmp = new TLink<T>(datum);
		tmp->pNext = head;
	}
	else
	{
		tmp = new TLink<T>(datum, head);
		head->pNext = tmp;
	}
}

template <typename T>
void TRingList<T>::Reset()
{
	current = head->pNext;
}

template<typename T>
inline void TRingList<T>::Clean()
{
	TLink<T> *temp = head;
	TLink<T> *temp2 = head;
	if (temp->pNext != head)
	{
		while (temp->pNext != head)
		{
			temp2 = temp->pNext;
			delete temp;
			temp = temp2;
		}
		head->pNext = head;
	}
}

template<typename T>
bool TRingList<T>::IsEnded()
{
	return (current->pNext == head);
}

template<typename T>
TRingList<T>& TRingList<T>::operator=(const TRingList<T> & _TRingList)
{
	TLink<T>* tmp = head;
	if (this != &_TRingList)
	{
		Clean();
		if (_TRingList.head->pNext != _TRingList.head)
		{
			head = new TLink<T>(_TRingList.head->data);
			TLink<T> *temp = head;
			TLink<T> *temp2 = _TRingList.head->pNext;
			while (temp2 != head)
			{
				temp->pNext = new TLink<T>(temp2->data);
				temp = temp->pNext;
				temp2 = temp2->pNext;
			}
		}
	}
	return *this;
}

template<typename T>
bool TRingList<T>::operator==(const TRingList<T> & list2) const
{
	TLink<T> *temp = head;
	TLink<T> *temp2 = list2.head;
	bool f = true;
	while ((temp->pNext != head) && (temp2->pNext != list2.head) && (f))
	{
		if (temp->data != temp2->data)
			f = false;
		temp = temp->pNext;
		temp2 = temp2->pNext;
	}
	if ((temp->pNext != head) || (temp2->pNext != list2.head))
		f = false;
	return f;
}



template <typename T>
TLink<T>* TRingList<T>::GetNext()
{
	return current->pNext;
};


class TPolinom {
private:
	TRingList<Tmonom> *monoms;
public:
	TPolinom();
	TPolinom(const string & s);
	TPolinom(const TPolinom &);
	~TPolinom();
	TPolinom operator+ (const TPolinom & _polinom);
	TPolinom operator* (const TPolinom & _polinom);
	TPolinom operator* (double d);
	const TPolinom& operator = (const TPolinom& _polinom);
	friend ostream& operator<< (ostream &out, const TPolinom& _polinom)
	{
		_polinom.monoms->Reset();
		for (_polinom.monoms->current; _polinom.monoms->IsEnded(); _polinom.monoms->GetNext())
		{
			out << _polinom.monoms->current->data.cf 
				<< "x^" << (_polinom.monoms->current->data.abc / 100) 
				<< "y^" << (_polinom.monoms->current->data.abc / 10) % 10 
				<< "z^" << (_polinom.monoms->current->data.abc) % 100;
		}
		return out;
	}
};

TPolinom::TPolinom()
{
	TRingList<Tmonom> tmp;
	*(*this).monoms = tmp;
}

TPolinom::TPolinom(const string& s)
{
	string str = s;
	string num = "";
	int number = 0;
	int i = 0;
	int nMonoms = 0;
	bool flag;
	while (i < str.length() - 2)
	{
		flag = false;
		if ((str[i] == '-' || str[i] == '+'))
		{
			if (isalpha(s[i + 1]))
			{
				number = 1;
			}
			if (str[i] == '-')
			{
				flag = true;
				i++;
			}
			else if (str[i] == '+')
			{
				flag = false;
				i++;
			}
		}
		while (isdigit(str[i]) || (str[i] == '.'))
		{
			num += str[i];
			i++;
		}// не обрабатывается моном нулевой степени + моном, который начинается с букв.
		number = atof(num.c_str());
		if (number != 0) {
			Tmonom temp;
			if (flag)
				number *= (-1);
			temp.cf = number;
			if ((str[i] == 'x') && (!(str[i + 1] == '^')))
			{
				temp.abc += 1 * 100;
				i += 1;
			}
			else if ((str[i] == 'x') && (str[i + 1] == '^'))
			{
				temp.abc += atoi(&str[i + 2]) * 100;
				i += 3;
			}
			if ((str[i] == 'y') && (!(str[i + 1] == '^')))
			{
				temp.abc += 1 * 10;
				i += 1;
			}
			else if ((str[i] == 'y') && (str[i + 1] == '^'))
			{
				temp.abc += atoi(&str[i + 2]) * 10;
				i += 3;
			}
			if ((str[i] == 'z') && (!(str[i + 1] == '^')))
			{
				temp.abc += 1;
				i += 1;
			}
			else if ((str[i] == 'z') && (str[i + 1] == '^'))
			{
				temp.abc += atoi(&str[i + 2]);
				i += 3;
			}
			monoms->Insert(temp);
		}
	}
}


TPolinom::TPolinom(const TPolinom & _polinom)
{
	monoms = _polinom.monoms;
}

TPolinom::~TPolinom()
{
	delete monoms;
}

TPolinom TPolinom::operator+ (const TPolinom & _polinom)
{
	(*this).monoms->Reset();
	_polinom.monoms->Reset();
	TPolinom res = (*this);
	for (this->monoms->current; this->monoms->IsEnded(); this->monoms->GetNext())
	{
		for (_polinom.monoms->current; _polinom.monoms->IsEnded(); _polinom.monoms->GetNext())
		{
			TLink<Tmonom>* link = res.monoms->Search(_polinom.monoms->current->data);
			if (link != NULL)
				link->data.cf += _polinom.monoms->current->data.cf;
			else
				res.monoms->Insert(_polinom.monoms->current->data);
		}
	}
	return res;
}

TPolinom TPolinom::operator* (const TPolinom & _polinom)
{
	(*this).monoms->Reset();
	_polinom.monoms->Reset();
	TPolinom res = (*this);
	res.monoms->Clean();
	for (this->monoms->current; this->monoms->IsEnded(); this->monoms->GetNext())
	{
		for (_polinom.monoms->current; _polinom.monoms->IsEnded(); _polinom.monoms->GetNext())
		{
			unsigned int tmpabc = (*this).monoms->current->data.abc + _polinom.monoms->current->data.abc;
			if (tmpabc < 1000)
			{
				Tmonom tmp((*this).monoms->current->data.cf + _polinom.monoms->current->data.cf, tmpabc);
				TLink<Tmonom>* tmp2 = res.monoms->Search(tmp);
				if (tmp2 != NULL)
					tmp2->data.cf += (*this).monoms->current->data.cf + _polinom.monoms->current->data.cf;
				else
					res.monoms->Insert(tmp);
			}
			else throw "Power is more then expected";
		}
	}
	return *this;
}

TPolinom TPolinom::operator* (double d)
{
	(*this).monoms->Reset();
	TPolinom res = (*this);
	if (d == 0)
		res.monoms->Clean();
	else {
		while (!(monoms->IsEnded()))
		{
			res.monoms->current->data.cf *= d;
			res.monoms->GetNext();
		}
	}
	return res;
}
const TPolinom& TPolinom::operator =(const TPolinom& _polinom)
{
	monoms = _polinom.monoms;
	return *this;
};
