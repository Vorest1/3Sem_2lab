#include <cassert>
#include <iostream>
#include <time.h>
#include "Sorter.h"
#include "Sorts.h"
#include "Sequence.h"
#include "TestSorts.h"

using namespace std;

void Test_sort() {
	TestHeap();
	TestQuick();
	TestBubble();
	cout << endl;
	cout << "Test time sorting Seq with >10^5 elements: \n";
	for (int i = 100; i < 1000000; i *= 10) {
		cout << "For " << i << "elements: \n";
		TestTime(i);
	}
	for (int i = 100000; i < 400000; i += 100000) {
		cout << "For " << i << "elements: \n";
		TestTime(i);
	}
	cout << "\nFor more elements Seq sorting more 3sec :(((\n";
	cout << "\n/_________________________________________________________________/\n";
}

void TestTime(int length) {
	double Htime, Qtime, Btime;
	Uniqe_Ptr<Sequence<int>> Hseq = new ArraySequence<int>;
	Uniqe_Ptr<Sequence<int>> Qseq = new ArraySequence<int>;
	Uniqe_Ptr<Sequence<int>> Bseq = new ArraySequence<int>;
	int* data = new int[length];
	srand(time(nullptr));
	for (int i = 0; i < length; i++) {
		data[i] = rand() % 100;
	}
	Hseq = new ArraySequence<int>(data, length);
	Qseq = new ArraySequence<int>(data, length);
	Bseq = new ArraySequence<int>(data, length);
	delete[] data;
	Uniqe_Ptr<ISorter<int>> Hsorter = (new HeapSorter<int>);
	Uniqe_Ptr<ISorter<int>> Qsorter = (new QuickSorter<int>);
	Uniqe_Ptr<ISorter<int>> Bsorter = (new BubbleSorter<int>);


	clock_t Hstart = clock();
	Uniqe_Ptr<Sequence<int>> Hresult = Hsorter->Sort(Hseq.Get(), cmp_up);
	clock_t Hend = clock();
	Htime = Hend - Hstart;
	cout << "	 HeapSort: " << Htime << endl;

	clock_t Qstart = clock();
	Uniqe_Ptr<Sequence<int>> Qresult = Qsorter->Sort(Qseq.Get(), cmp_up);
	clock_t Qend = clock();
	Qtime = Qend - Qstart;
	cout << "	 QuickSort: " << Qtime << endl;

	if (length <= 10000) {
		clock_t Bstart = clock();
		Uniqe_Ptr<Sequence<int>> Bresult = Bsorter->Sort(Bseq.Get(), cmp_up);
		clock_t Bend = clock();
		Btime = Bend - Bstart;
		cout << "	 BubbleSort: " << Btime << endl;
	}
}


void TestHeap() {
	cout << "\n/_________________________________________________________________/\n";
	cout << "Test heap sort\n";
	int* data = new int[10];

	for (int i = 0; i < 10; i++) {
		data[i] = 10 - i;
	}
	Uniqe_Ptr<Sequence<int>> seq = new ArraySequence<int>(data, 10);
	delete[] data;
	Uniqe_Ptr<ISorter<int>> sorter = (new HeapSorter<int>);
	Uniqe_Ptr<Sequence<int>> res = sorter->Sort(seq.Get(), cmp_up);

	cout << "\nTest sort up: ";
	for (int i = 0; i < 10; i++) {
		assert(res->Get(i) == i + 1);
	}
	cout << "DONE\n";

	res = sorter->Sort(seq.Get(), cmp_down);
	cout << "Test sort down: ";
	for (int i = 0; i < 10; i++) {
		assert(res->Get(i) == 10 - i);
	}
	cout << "DONE\n";

	cout << "Test the correctness of sorting: ";
	int arr[7]{ 7, -6, 9, 5, 12, 0, -78 };
	Uniqe_Ptr<Sequence<int>> seq2 = new ArraySequence<int>(arr, 7);

	int correct[7]{ -78, -6, 0, 5, 7, 9, 12 };
	Uniqe_Ptr<Sequence<int>> cor = new ArraySequence<int>(correct, 7);

	Uniqe_Ptr<Sequence<int>> res2 = sorter->Sort(seq2.Get(), cmp_up);
	for (int i = 0; i < 7; ++i) {
		assert(res2->Get(i) == cor->Get(i));
	}
	cout << "DONE\n";

	cout << "Test the correctness of sorting with Double type data: ";
	Uniqe_Ptr<ISorter<double>> Dsorter = (new HeapSorter<double>);
	double darr[7]{ 9, -6, 9.001, 0.5, 12.256, 0.0, -78.55 };
	Uniqe_Ptr<Sequence<double>> dseq = new ArraySequence<double>(darr, 7);

	double dcorrect[7]{ -78.55, -6, 0.0, 0.5, 9, 9.001, 12.256 };
	Uniqe_Ptr<Sequence<double>> dcor = new ArraySequence<double>(dcorrect, 7);

	Uniqe_Ptr<Sequence<double>> dres = Dsorter->Sort(dseq.Get(), cmp_up);
	for (int i = 0; i < 7; ++i) {
		assert(dres->Get(i) == dcor->Get(i));
	}
	cout << "DONE\n";
	cout << "\n/_________________________________________________________________/\n";
}

void TestQuick() {
	cout << "Test quick sort\n";
	int* data = new int[10];

	for (int i = 0; i < 10; i++) {
		data[i] = 10 - i;
	}
	Uniqe_Ptr<Sequence<int>> seq = new ArraySequence<int>(data, 10);
	delete[] data;
	Uniqe_Ptr<ISorter<int>> sorter = (new QuickSorter<int>);
	Uniqe_Ptr<Sequence<int>> res = sorter->Sort(seq.Get(), cmp_up);

	cout << "\nTest sort up: ";
	for (int i = 0; i < 10; i++) {
		assert(res->Get(i) == i + 1);
	}
	cout << "DONE\n";

	res = sorter->Sort(seq.Get(), cmp_down);
	cout << "Test sort down: ";
	for (int i = 0; i < 10; i++) {
		assert(res->Get(i) == 10 - i);
	}
	cout << "DONE\n";

	cout << "Test the correctness of sorting: ";
	int arr[7]{ 7, -6, 9, 5, 12, 0, -78 };
	Uniqe_Ptr<Sequence<int>> seq2 = new ArraySequence<int>(arr, 7);

	int correct[7]{ -78, -6, 0, 5, 7, 9, 12 };
	Uniqe_Ptr<Sequence<int>> cor = new ArraySequence<int>(correct, 7);

	Uniqe_Ptr<Sequence<int>> res2 = sorter->Sort(seq2.Get(), cmp_up);
	for (int i = 0; i < 7; ++i) {
		assert(res2->Get(i) == cor->Get(i));
	}
	cout << "DONE\n";

	cout << "Test the correctness of sorting with Double type data: ";
	Uniqe_Ptr<ISorter<double>> Dsorter = (new QuickSorter<double>);
	double darr[7]{ 9, -6, 9.001, 0.5, 12.256, 0.0, -78.55 };
	Uniqe_Ptr<Sequence<double>> dseq = new ArraySequence<double>(darr, 7);

	double dcorrect[7]{ -78.55, -6, 0.0, 0.5, 9, 9.001, 12.256 };
	Uniqe_Ptr<Sequence<double>> dcor = new ArraySequence<double>(dcorrect, 7);

	Uniqe_Ptr<Sequence<double>> dres = Dsorter->Sort(dseq.Get(), cmp_up);
	for (int i = 0; i < 7; ++i) {
		assert(dres->Get(i) == dcor->Get(i));
	}
	cout << "DONE\n";
}

void TestBubble() {
	cout << "\n/_________________________________________________________________/\n";
	cout << "Test bubble sort\n";
	int* data = new int[10];

	for (int i = 0; i < 10; i++) {
		data[i] = 10 - i;
	}
	Uniqe_Ptr<Sequence<int>> seq = new ArraySequence<int>(data, 10);
	delete[] data;
	Uniqe_Ptr<ISorter<int>> sorter = (new BubbleSorter<int>);
	Uniqe_Ptr<Sequence<int>> res = sorter->Sort(seq.Get(), cmp_up);

	cout << "\nTest sort up: ";
	for (int i = 0; i < 10; i++) {
		assert(res->Get(i) == i + 1);
	}
	cout << "DONE\n";

	res = sorter->Sort(seq.Get(), cmp_down);
	cout << "Test sort down: ";
	for (int i = 0; i < 10; i++) {
		assert(res->Get(i) == 10 - i);
	}
	cout << "DONE\n";

	cout << "Test the correctness of sorting: ";
	int arr[7]{ 7, -6, 9, 5, 12, 0, -78 };
	Uniqe_Ptr<Sequence<int>> seq2 = new ArraySequence<int>(arr, 7);

	int correct[7]{ -78, -6, 0, 5, 7, 9, 12 };
	Uniqe_Ptr<Sequence<int>> cor = new ArraySequence<int>(correct, 7);

	Uniqe_Ptr<Sequence<int>> res2 = sorter->Sort(seq2.Get(), cmp_up);
	for (int i = 0; i < 7; ++i) {
		assert(res2->Get(i) == cor->Get(i));
	}
	cout << "DONE\n";

	cout << "Test the correctness of sorting with Double type data: ";
	Uniqe_Ptr<ISorter<double>> Dsorter = (new BubbleSorter<double>);
	double darr[7]{ 9, -6, 9.001, 0.5, 12.256, 0.0, -78.55 };
	Uniqe_Ptr<Sequence<double>> dseq = new ArraySequence<double>(darr, 7);

	double dcorrect[7]{ -78.55, -6, 0.0, 0.5, 9, 9.001, 12.256 };
	Uniqe_Ptr<Sequence<double>> dcor = new ArraySequence<double>(dcorrect, 7);

	Uniqe_Ptr<Sequence<double>> dres = Dsorter->Sort(dseq.Get(), cmp_up);
	for (int i = 0; i < 7; ++i) {
		assert(dres->Get(i) == dcor->Get(i));
	}
	cout << "DONE\n";
	cout << "\n/_________________________________________________________________/\n";
}