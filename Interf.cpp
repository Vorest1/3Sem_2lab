#pragma once
#include <iostream>
#include "Sorts.h"
#include "Sorter.h"
#include "Sequence.h"
#include "TestSeq.h"
#include "TestSorts.h"
#include "SmartPtr.h"

using namespace std;

int ProgInt() {
	Uniqe_Ptr<Sequence<int>> seq = new ArraySequence<int>;
	int type;
	while (true) {
		cout << "Choose option:\n"
			"1. Insert in back\n"
			"2. Insert in front\n"
			"3. Insert at pos\n"
			"4. Random values\n"
			"5. Show array\n"
			"6. Sort\n"
			"7. Test sequence\n"
			"8. Test sorts\n"
			"9. Exit\n";
		cin >> type;
		if (type == 1) {
			cout << "insert value\n";
			int number;
			cin >> number;
			seq->Append(number);
			continue;
		}
		if (type == 2) {
			cout << "insert value\n";
			int number;
			cin >> number;
			seq->Prepend(number);
			continue;
		}
		if (type == 3) {
			cout << "insert index\n";
			size_t index;
			cin >> index;
			cout << "insert value\n";
			int number;
			cin >> number;
			seq->InsertAt(number, index);
			continue;
		}
		if (type == 4) {
			int length = 0;
			while (length <= 0) {
				cout << "Length (>0): ";
				cin >> length;
			}

			int* data = new int[length];
			srand(time(nullptr));
			for (int i = 0; i < length; i++) {
				data[i] = rand() % 100;
			}
			seq = new ArraySequence<int>(data, length);
			delete[] data;
			continue;
		}
		if (type == 5) {
			for (size_t i = 0; i < seq->GetSize(); ++i) {
				cout << seq->Get(i) << " ";
			}
			cout << "\n";
			continue;
		}
		if (type == 6) {
			Uniqe_Ptr<ISorter<int>> sorter;
			int comp_type, sort_type;
			cout << "\nSelect sorting type: "; //выбор сортировки
			cout << "\n1)Heap\n2)Quick\n3)Bubble\n";
			cin >> sort_type;

			switch (sort_type) {
			case 1:
				sorter = (new HeapSorter<int>);
				break;
			case 2:
				sorter = (new QuickSorter<int>);
				break;
			case 3:
				sorter = (new BubbleSorter<int>);
				break;
			default:
				sorter = (new QuickSorter<int>);
				break;
			}

			Uniqe_Ptr<Sequence<int>> result;

			cout << "Select sort direction: \n"; //выбор направления сортировки
			cout << "1)Sorting Up\n2)Sorting Down\n";
			cin >> comp_type;
			switch (comp_type) {
			case 1:
				result = sorter->Sort(seq.Get(), cmp_up);
				break;
			case 2:
				result = sorter->Sort(seq.Get(), cmp_down);
				break;
			default:
				result = sorter->Sort(seq.Get(), cmp_up);
				break;
			}
			for (int i = 0; i < result->GetSize(); i++) {   //вывод сортировки
				cout << result->Get(i) << " ";
			}
			continue;
		}
		if (type == 7) {
			Test();
			continue;
		}
		if (type == 8) {
			Test_sort();
			continue;
		}
		if (type == 9) {
			return 0;
		}
	}
}

int ProgDouble() {
	Uniqe_Ptr<Sequence<double>> seq = new ArraySequence<double>;
	int type;
	while (true) {
		cout << "Choose option:\n"
			"1. Insert in back\n"
			"2. Insert in front\n"
			"3. Insert at pos\n"
			"4. Random values\n"
			"5. Show array\n"
			"6. Sort\n"
			"7. Test sequence\n"
			"8. Test sorts\n"
			"9. Exit\n";
		cin >> type;
		if (type == 1) {
			cout << "insert value\n";
			double number;
			cin >> number;
			seq->Append(number);
			continue;
		}
		if (type == 2) {
			cout << "insert value\n";
			double number;
			cin >> number;
			seq->Prepend(number);
			continue;
		}
		if (type == 3) {
			cout << "insert index\n";
			size_t index;
			cin >> index;
			cout << "insert value\n";
			double number;
			cin >> number;
			seq->InsertAt(number, index);
			continue;
		}
		if (type == 4) {
			int length = 0;
			while (length <= 0) {
				cout << "Length (>0): ";
				cin >> length;
			}

			double* data = new double[length];
			srand(time(nullptr));
			for (int i = 0; i < length; i++) {
				data[i] = (rand() % 10000);
				data[i] = data[i] / 100;
			}
			seq = new ArraySequence<double>(data, length);
			delete[] data;
			continue;
		}
		if (type == 5) {
			for (size_t i = 0; i < seq->GetSize(); ++i) {
				cout << seq->Get(i) << " ";
			}
			cout << "\n";
			continue;
		}
		if (type == 6) {
			Uniqe_Ptr<ISorter<double>> sorter;
			int comp_type, sort_type;
			cout << "\nSelect sorting type: "; //выбор сортировки
			cout << "\n1)Heap\n2)Quick\n3)Bubble\n";
			cin >> sort_type;

			switch (sort_type) {
			case 1:
				sorter = (new HeapSorter<double>);
				break;
			case 2:
				sorter = (new QuickSorter<double>);
				break;
			case 3:
				sorter = (new BubbleSorter<double>);
				break;
			default:
				sorter = (new QuickSorter<double>);
				break;
			}

			Uniqe_Ptr<Sequence<double>> result;

			cout << "Select sort direction: \n"; //выбор направления сортировки
			cout << "1)Sorting Up\n2)Sorting Down\n";
			cin >> comp_type;
			switch (comp_type) {
			case 1:
				result = sorter->Sort(seq.Get(), cmp_up);
				break;
			case 2:
				result = sorter->Sort(seq.Get(), cmp_down);
				break;
			default:
				result = sorter->Sort(seq.Get(), cmp_up);
				break;
			}
			for (int i = 0; i < result->GetSize(); i++) {   //вывод сортировки
				cout << result->Get(i) << " ";
			}
			cout << "\n";
			continue;
		}
		if (type == 7) {
			Test();
			continue;
		}
		if (type == 8) {
			Test_sort();
			continue;
		}
		if (type == 9) {
			return 0;
		}
	}
}

void BaseProg() {
	int type_el;
	cout << "\nEnter type elements : \n";
	cout << "1)Int \n2)Double\n";
	cin >> type_el;
	if (type_el == 2) {
		ProgDouble();
	}
	else {
		ProgInt();
	}
}


/*
int SortSteps() {
	int start_d, steps;
	cout << "Do you want see started data? (1 - yes, 2 - no)\n";
	cin >> start_d;
	if (start_d != 1) start_d = 0;
	cout << "Do you want to see steps for sorted? (1 - yes, 2 - no)\n";
	cin >> steps;
	if (steps != 1) steps = 0;
}

void BaseProgInt() {
	Uniqe_Ptr<ISorter<int>> sorter;
	int var_seq, length, sort_type, comp_type;
	length = 0;

	cout << "\nEnter sequence : \n" << endl;

	while (length <= 0) {
		cout << "Length (>0): ";
		cin >> length;
	}

	cout << "\nEnter elements : \n";
	cout << "1)My values\n2)Random values\n";
	cin >> var_seq;

	int* data = new int[length];
	srand(time(nullptr));
	switch (var_seq) {
		case 1:
			for (int i = 0; i < length; ++i) {
				cin >> data[i];
			}
			break;
		case 2:
			for (int i = 0; i < length; i++) {
				data[i] = rand() % 100;
			}
			break;
		default:
			for (int i = 0; i < length; i++) {
				data[i] = rand() % 100;
			}
	}
	Uniqe_Ptr<Sequence<int>> seq = new ArraySequence<int>(data, length);
	delete[] data;


	cout << "\nSelect sorting type: ";
	cout << "\n1)Heap\n2)Quick\n3)Bubble\n";
	cin >> sort_type;
	switch (sort_type) {
		case 1:
			sorter = (new HeapSorter<int>);
			break;
		case 2:
			sorter = (new QuickSorter<int>);
			break;
		case 3:
			sorter = (new BubbleSorter<int>);
			break;
		default:
			sorter = (new QuickSorter<int>);
			break;
	}


	Uniqe_Ptr<Sequence<int>> result;

	cout << "Select sort direction: \n";
	cout << "1)Sorting Up\n2)Sorting Down\n";
	cin >> comp_type;
	switch (comp_type) {
		case 1:
			result = sorter->Sort(seq._get(), cmp_up);
			break;
		case 2:
			result = sorter->Sort(seq._get(), cmp_down);
			break;
		default:
			result = sorter->Sort(seq._get(), cmp_up);
			break;
	}
	//for (int i = 0; i < length; i++) {
	//	cout << seq->Get(i) << " ";
	//}
	//cout << endl;
	for (int i = 0; i < length; i++) {
		cout << result->Get(i) << " ";
	}
}

void BaseProgDouble() {
	Uniqe_Ptr<ISorter<double>> sorter;
	int var_seq, length, sort_type, comp_type;
	length = 0;

	cout << "\nEnter sequence : \n" << endl;

	while (length <= 0) {
		cout << "Length (>0): ";
		cin >> length;
	}

	cout << "\nEnter elements : \n";
	cout << "1)My values\n2)Random values\n";
	cin >> var_seq;

	double* data = new double[length];
	srand(time(nullptr));
	switch (var_seq) {
	case 1:
		for (int i = 0; i < length; ++i) {
			cin >> data[i];
		}
		break;
	case 2:
		for (int i = 0; i < length; i++) {
			data[i] = (double)(rand()) / RAND_MAX*100;
		}
		break;
	default:
		for (int i = 0; i < length; i++) {
			data[i] = (double)(rand()) / RAND_MAX*100;
		}
	}
	Uniqe_Ptr<Sequence<double>> seq = new ArraySequence<double>(data, length);
	delete[] data;


	cout << "\nSelect sorting type: ";
	cout << "\n1)Heap\n2)Quick\n3)Bubble\n";
	cin >> sort_type;
	switch (sort_type) {
	case 1:
		sorter = (new HeapSorter<double>);
		break;
	case 2:
		sorter = (new QuickSorter<double>);
		break;
	case 3:
		sorter = (new BubbleSorter<double>);
		break;
	default:
		sorter = (new QuickSorter<double>);
		break;
	}


	Uniqe_Ptr<Sequence<double>> result;

	cout << "Select sort direction: \n";
	cout << "1)Sorting Up\n2)Sorting Down\n";
	cin >> comp_type;
	switch (comp_type) {
	case 1:
		result = sorter->Sort(seq._get(), cmp_up);
		break;
	case 2:
		result = sorter->Sort(seq._get(), cmp_down);
		break;
	default:
		result = sorter->Sort(seq._get(), cmp_up);
		break;
	}

	for (int i = 0; i < length; i++) {
		cout << result->Get(i) << " ";
	}
}*/