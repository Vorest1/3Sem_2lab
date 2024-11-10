#pragma once

int ProgInt();
int ProgDouble();
void BaseProg();

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