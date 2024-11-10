#pragma once
#include "Sequence.h"

template <typename T>
void Swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
int cmp_up(const T& a, const T& b) {
	return (a - b >= 0) ? 1 : -1;
}

template <typename T>
int cmp_down(const T& a, const T& b) {
	return (a - b >= 0) ? -1 : 1;
}

template <typename T>
class ISorter {
public:
	virtual ~ISorter() {}
	virtual Sequence<T>* Sort(Sequence<T>* seq, int (*cmp)(const T&, const T&)) = 0;
};