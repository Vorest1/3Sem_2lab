#include<iostream>
#include<cassert>
#include<vector>
#include"Sequence.h"

void Equal(const Sequence<int>& seq, int* array) {
    for (size_t i = 0; i < seq.GetSize(); ++i) {
        assert(seq.Get(i) == array[i]);
    }
}

void TestDynamicArray();
void TestSequence();
void TestArraySequence();

void Test();

class Counter {
public:
    Counter();
    Counter(const Counter& other);
    ~Counter();
    static size_t GetCount();
private:
    static size_t _count;
};

size_t Counter::_count = 0;

Counter::Counter() {
    ++_count;
}

Counter::Counter(const Counter& other) {
    ++_count;
}


Counter::~Counter() {
    --_count;
}

size_t Counter::GetCount() {
    return _count;
}

bool operator<(const Counter& first, const Counter& second) {
    return &first < &second;
}


void Test() {
    TestDynamicArray();
    TestSequence();
    std::cout << "\n";
}

void TestSequence() {
    TestArraySequence();
}
void TestDynamicArray() {
    std::cout << "\n/_________________________________________________________________/\n";
    std::cout << "Dynamic array tests." << std::endl << std::endl;

    std::cout << "Test1. Array constructor/destructor memory test: ";
    {
        Counter static_array[5];
        DynamicArray<Counter> array(static_array, 5);
    }
    assert(Counter::GetCount() == 0);
    std::cout << "Done" << std::endl;

    std::cout << "Test2. Size constructor memory test: ";
    {
        DynamicArray<Counter> array(5);
    }
    assert(Counter::GetCount() == 0);
    std::cout << "Done" << std::endl;

    std::cout << "Test3. Copy constructor memory test: ";
    {
        DynamicArray<Counter> array(5);
        DynamicArray<Counter> copy(array);
    }
    assert(Counter::GetCount() == 0);
    std::cout << "Done" << std::endl;

    std::cout << "Test4. GetSize test: ";
    {
        DynamicArray<int> array(5);
        int static_array[6];
        DynamicArray<int> array_from_array(static_array, 6);
        DynamicArray<int> copy_array(array_from_array);
        assert(array.GetSize() == 5);
        assert(array_from_array.GetSize() == 6);
        assert(copy_array.GetSize() == 6);
    }
    std::cout << "Done" << std::endl;

    std::cout << "Test5. Set and Get test: ";
    {
        DynamicArray<int> array(5);
        array.Set(3, 2);
        bool had_exception = false;
        try {
            array.Set(5, 5);
        }
        catch (std::out_of_range) {
            had_exception = true;
        }
        assert(had_exception);
        assert(array.Get(2) == 3);
        had_exception = false;
        try {
            array.Get(5);
        }
        catch (std::out_of_range) {
            had_exception = true;
        }
        assert(had_exception);
    }
    std::cout << "Done" << std::endl;

    std::cout << "Test6. Operator[] test: ";
    {
        DynamicArray<int> array(5);
        array[2] = 3;
        assert(array[2] == 3);
    }
    std::cout << "Done" << std::endl;

    std::cout << "Test7. Resize test: ";
    {
        DynamicArray<int> array(5);
        array.Resize(7);
        assert(array.GetSize() == 7);
        array.Set(10, 6);
        assert(array.Get(6) == 10);
    }
    std::cout << "Done" << std::endl;
    std::cout << "/_________________________________________________________________/\n";
}
void TestArraySequence() {
    std::cout << "\n/_________________________________________________________________/\n";
    std::cout << "Array Sequence tests." << std::endl << std::endl;

    std::cout << "Test1. Array Sequence constructor/destructor memory test: ";
    {
        Counter static_array[5];
        ArraySequence<Counter> list(static_array, 5);
    }
    assert(Counter::GetCount() == 0);
    {
        int static_array[5] = { 1, 2, 3 ,4, 5 };
        ArraySequence<int> list(static_array, 5);
        Equal(list, static_array);
    }
    std::cout << "Done" << std::endl;

    std::cout << "Test2. Default constructor memory test: ";
    {
        ArraySequence<Counter> array();
    }
    assert(Counter::GetCount() == 0);
    std::cout << "Done" << std::endl;

    std::cout << "Test3. GetSize test: ";
    {
        ArraySequence<int> list;
        int static_array[6];
        ArraySequence<int> list_from_array(static_array, 6);
        ArraySequence<int> copy_list(list_from_array);
        assert(list.GetSize() == 0);
        assert(list_from_array.GetSize() == 6);
        assert(copy_list.GetSize() == 6);
    }
    std::cout << "Done" << std::endl;

    std::cout << "Test4. Get test: ";
    {
        int static_array[5] = { 1, 2, 3 ,4, 5 };
        ArraySequence<int> list(static_array, 5);
        bool had_exception = false;
        try {
            list.Get(5);
        }
        catch (std::out_of_range) {
            had_exception = true;
        }
        assert(had_exception);
        assert(list.Get(2) == 3);
        assert(list.GetFirst() == 1);
        assert(list.GetLast() == 5);
    }
    std::cout << "Done" << std::endl;

    std::cout << "Test5. Last and First test: ";
    {
        int static_array[5] = { 1, 2, 3 ,4, 5 };
        ArraySequence<int> array(static_array, 5);
        array[2] = 3;
        assert(array[2] == 3);
    }
    std::cout << "Done" << std::endl;

    std::cout << "Test6. Append and Prepend test: ";
    {
        int static_array[5] = { 1, 2, 3 ,4, 5 };
        int static_array_prep[6] = { 0, 1, 2, 3 ,4, 5 };
        int static_array_app[7] = { 0, 1, 2, 3 ,4, 5, 6 };
        ArraySequence<int> list(static_array, 5);
        list.Prepend(0);
        Equal(list, static_array_prep);
        list.Append(6);
        Equal(list, static_array_app);
    }
    std::cout << "Done" << std::endl;
    std::cout << "/_________________________________________________________________/\n";
}