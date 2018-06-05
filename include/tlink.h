#pragma once

template <typename T>
struct TLink
{
	T key = 0;
	TLink *pNext = nullptr;

	TLink(T value):key(value){}
	TLink() = default;
};