#pragma once
#include <iostream>
#include "DynamicArray.h"
#include "Sequence.h"
#include "SmartPtr.h"
#include "Sorter.h"

template <typename T>
class HeapSorter : public ISorter<T> {
private:
    void Heapify(Sequence<T>* seq, int (*cmp)(const T&, const T&), int len, int i) {
        int largest = i;
        int _left = 2 * i + 1;
        int _right = 2 * i + 2;

        if (_left < len && cmp((*seq)[_left], (*seq)[largest]) > 0) {
            largest = _left;
        }

        if (_right < len && cmp((*seq)[_right], (*seq)[largest]) > 0) {
            largest = _right;
        }

        if (largest != i) {
            Swap((*seq)[i], (*seq)[largest]);
            Heapify(seq, cmp, len, largest);
        }
    }

    void HeapSort(Sequence<T>* seq, int (*cmp)(const T&, const T&), int len) {
        for (int i = len / 2 - 1; i >= 0; i--) {
            Heapify(seq, cmp, len, i);
        }
        for (int i = len - 1; i >= 0; i--) {
            Swap((*seq)[0], (*seq)[i]);
            Heapify(seq, cmp, i, 0);
        }
    }
public:
    Sequence<T>* Sort(Sequence<T>* seq, int (*cmp)(const T&, const T&)) {
        Sequence<T>* result = seq->GetSubSequence(0, seq->GetSize() - 1);
        HeapSort(result, cmp, result->GetSize());
        return result;
    }
};


template <typename T>
class QuickSorter : public ISorter<T> {
private:
    int Partition(Sequence<T>* seq, int (*cmp)(const T&, const T&), int start, int end) {
        int pivot = (*seq)[end];
        int pIndex = start;
        for (int i = start; i < end; i++) {
            if (cmp((*seq)[i], pivot) <= 0) {
                Swap((*seq)[i], (*seq)[pIndex]);
                pIndex++;
            }
        }
        Swap((*seq)[pIndex], (*seq)[end]);
        return pIndex;
    }

    void QuickSort(Sequence<T>* seq, int (*cmp)(const T&, const T&), int start, int end) {
        if (start >= end) {
            return;
        }
        int pivot = Partition(seq, cmp, start, end);
        QuickSort(seq, cmp, start, pivot - 1);
        QuickSort(seq, cmp, pivot + 1, end);
    }
public:
    Sequence<T>* Sort(Sequence<T>* seq, int (*cmp)(const T&, const T&)) {
        Sequence<T>* result = seq->GetSubSequence(0, seq->GetSize() - 1);
        QuickSort(result, cmp, 0, result->GetSize() - 1);
        return result;
    }

};


template<typename T>
class BubbleSorter : public ISorter<T> {
private:
    void BubbleSort(Sequence<T>* seq, int (*cmp)(const T&, const T&), int len) {
        for (int i = 0; i < len-1; ++i){
            for (int j = 0; j < len - i - 1; ++j){
                if (cmp((*seq)[j], (*seq)[j+1]) > 0) {
                    Swap((*seq)[j], (*seq)[j+1]);
                }
            }
        }
    }
public:
    Sequence<T>* Sort(Sequence<T>* seq, int (*cmp)(const T&, const T&)) {
        Sequence<T>* result = seq->GetSubSequence(0, seq->GetSize() - 1);
        BubbleSort(result, cmp, result->GetSize());
        return result;
    }
};