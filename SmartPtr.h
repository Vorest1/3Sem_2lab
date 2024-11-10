#pragma once
#include <iostream>
#include "Sequence.h"

using namespace std;

template<typename T>
class Shared_Ptr {
private:
	T* _ptr;
	size_t* _count;
public:
	//конструктор
	explicit Shared_Ptr(T* new_ptr = nullptr) : _ptr(new_ptr), _count(new size_t(1)) {}

	//конструктор копирования
	Shared_Ptr(const Shared_Ptr& other) : _ptr(other._ptr), _count(other._count) {
		if (_count) {
			(*_count)++;
		}
	}

	//деструктор
	~Shared_Ptr() { Del(); }

	//перегруз операторов
	Shared_Ptr& operator=(const Shared_Ptr& other) {
		if (this != &other) {
			if (_count && (*_count) - 1 == 0) {
				delete _ptr;
				delete _count;
			}
			else if (_count) {
				delete _ptr;
				--(*_count);
			}
			_ptr = other._ptr;
			_count = other._count;
			if (_count) {
				(*_count)++;
			}
		}
		return *this;
	}

	Shared_Ptr<T>& operator=(T* other) {
		if (_count) {
			(*_count)--;
			if (*_count <= 0) {
				delete _ptr;
				delete _count;
			}
		}
		this->_ptr = other;
		this->_count = new int(1);
		return *this;
	}

	T& operator*() const noexcept {
		if (_ptr == nullptr) {
			throw runtime_error("ERROR: Dereferencing a null pointer");
		}
		return *_ptr;
	}

	T* operator->() const noexcept { return _ptr; }

	T& operator[](int Index) {
		if (Index < 0) {
			throw std::out_of_range("Out of range");
		}
		return *_ptr[Index];
	}

	//методы
	T& Get() const noexcept { return *_ptr; }
	size_t Get_Count() const noexcept { return *_count; }
	void Swap(Shared_Ptr<T>& other) {
		T* temp = this->_ptr;
		size_t* temp_count = this->_count;
		this->_ptr = other._ptr;
		other._ptr = temp;
		this->_count = other._count;
		other._count = temp_count;
	}

	void Del() {
		if (*_count && --(*_count) == 0) {
			//cout << "Delete original\n";
			//cout << "count = " << *_count << endl;
			delete _ptr;
			delete _count;
		}
		else if (_count) {
			//cout << "Delete copy\n";
			//cout << "count = " << *_count << endl;
			_ptr = nullptr;
			*this->_count = 0;
		}
	}

	bool Uniq() {
		return *this->_count == 1;
	}
};

template<typename T>
class Uniqe_Ptr {
private:
	T* _ptr;
public:
	//конструктор
	Uniqe_Ptr() noexcept : _ptr(nullptr) {}
	Uniqe_Ptr(T* new_ptr) noexcept : _ptr(new_ptr) {}

	Uniqe_Ptr(Uniqe_Ptr<T>&& other) {
		this->_ptr = other._ptr;
		other._ptr = nullptr;
	}

	Uniqe_Ptr(Uniqe_Ptr<T>& other) {
		this->_ptr = other._ptr;
		other._ptr = nullptr;
	}

	Uniqe_Ptr(const Uniqe_Ptr&) = delete;
	Uniqe_Ptr& operator=(const Uniqe_Ptr&) = delete;

	//деструктор
	~Uniqe_Ptr() noexcept { Del(); }

	//перегруз операторов
	T& operator*() const noexcept {
		if (_ptr == nullptr) {
			throw runtime_error("ERROR: Dereferencing a null pointer");
		}
		return *_ptr;
	}

	T* operator->() const noexcept { return _ptr; }

	Uniqe_Ptr& operator=(Uniqe_Ptr&& other) noexcept {
		if (this != &other) {
			Del();
			_ptr = other._release();
		}
		return *this;
	}

	Uniqe_Ptr<T>& operator=(T* other) {
		delete _ptr;
		this->_ptr = other;
		return *this;
	}

	bool operator==(const Uniqe_Ptr& other) const noexcept {
		if (_ptr != nullptr && other._ptr != nullptr) {
			return *_ptr == *other._ptr;
		}
		else {
			return _ptr == other._ptr;
		}
	}

	bool operator!=(const Uniqe_Ptr& other) const noexcept {
		return !(*this == other);
	}

	//методы
	void Del() noexcept { delete _ptr;  _ptr = nullptr; }

	void Swap(Uniqe_Ptr& other) noexcept {
		T* temp = _ptr;
		_ptr = other._ptr;
		other._ptr = temp;
	}

	T* Release() noexcept {
		T* n_ptr = _ptr;
		_ptr = nullptr;
		return n_ptr;
	}

	T* Get() const noexcept { return _ptr; }
};



/*
template <typename T>
class WeakPtr {
private:
	T* _ptr;
	size_t* _count;
public:
	WeakPtr() {
		_ptr = nullptr;
		_count = 1;
	}

	WeakPtr(const Shared_Ptr<T>& other) {
		this->_ptr = other._ptr;
		_count = other._count;
		++(*_count);
	}

	~WeakPtr() = default;

	void del() {
		delete _ptr;
	}

	void Swap(WeakPtr<T>& other) {
		T* tmp = this->_ptr;
		this->_ptr = other._ptr;
		other._ptr = tmp;
	}

	int get_Count() {
		return *_count;
	}

	bool Expired() {
		return get_Count() == 0;
	}

	Shared_Ptr<T> Lock() {
		if (Expired()) {
			return Shared_Ptr<T>(nullptr);
		}
		Shared_Ptr<T> pointer = nullptr;
		pointer._ptr = this->_ptr;
		pointer._count = this->_count;
		(*_count)++;
		return pointer;
	}

	WeakPtr<T>& operator=(const Shared_Ptr<T>& other) {
		this->ptr = other._ptr;
		this->_count = other._count;
		return *this;
	}

	WeakPtr<T>& operator=(const WeakPtr<T>& other) {
		this->_ptr = other._ptr;
		this->_count = other._count;
		return *this;
	}
};

template <typename T>
class MsPtr {
private:
	ArraySequence<T>* _ptr;
	int* _count;
public:
	MsPtr() {
		this->_ptr = new ArraySequence<T>();
		this->_count = new int(0);
	}

	MsPtr(std::nullptr_t) {
		this->_ptr = nullptr;
		this->_count = new int(0);
	}

	MsPtr(const MsPtr<T>& other) {
		this->_ptr = other._ptr;
		this->_count = other._count;
		(*this->_count)++;
	}

	MsPtr(T* other, int count) {
		this->_ptr = new ArraySequence<T>(other, count);
		this->_count = new int(1);
	}

	MsPtr(const ArraySequence<T>& other) {
		this->_ptr = new ArraySequence<T>(other);
		this->_count = new int(1);
	}

	~MsPtr() {
		if (_count) {
			(*_count)--;
			if (*_count <= 0) {
				delete _ptr;
				delete _count;
			}
		}
	}

	int get_Count() {
		return *this->_count;
	}

	bool Unique() {
		return *this->_count == 1;
	}

	void del() {
		if (_count) {
			(*_count)--;
			if (*_count <= 0) {
				delete _ptr;
				delete _count;
			}
		}
		this->_ptr = nullptr;
		this->_count = nullptr;
	}

	void Swap(MsPtr<T>& other) {
		T* tmp = this->_ptr;
		int* tmp_counter = this->_count;
		this->_ptr = other._ptr;
		other._ptr = tmp;
		this->_count = other._count;
		other._count = tmp_counter;
	}

	ArraySequence<T>* _get() {
		return this->_ptr;
	}

	MsPtr<T>& operator=(const MsPtr<T>& other) {
		if (_count) {
			(*_count)--;
			if (*_count <= 0) {
				delete _ptr;
				delete _count;
			}
		}
		this->_ptr = other._ptr;
		this->_count = other._count;
		(*this->_count)++;
		return *this;
	}

	MsPtr<T>& operator=(T* other) {
		if (_count) {
			(*_count)--;
			if (*_count <= 0) {
				delete _ptr;
				delete _count;
			}
		}
		this->_ptr = other;
		this->_count = new int(1);
		return *this;
	}

	operator bool() {
		return this->_ptr;
	}

	T& operator*() {
		return *(this->_ptr);
	}

	T* operator->() {
		return this->_ptr;
	}

	T& operator[](int index) {
		if (index < 0) {
			throw std::out_of_range("Out of range");
		}
		return (*(this->_ptr))[index];
	}
};

template<typename T>
class MemorySpan {
private:
	MsPtr<T> _ptr;
public:
	MemorySpan() {
		this->_ptr = MsPtr<T>();
	}

	MemorySpan(T* other, int count) {
		this->_ptr = MsPtr<T>(other, count);
	}

	MemorySpan(const ArraySequence<T>& other) {
		this->_ptr = MsPtr<T>(other);
	}

	MemorySpan(const MemorySpan<T>& other) {
		this->_ptr = MsPtr<T>(other._ptr);
	}

	~MemorySpan() = default;

	T& operator[](int index) {
		if (index < 0) {
			throw std::out_of_range("Out of range");
		}
		return (this->_ptr)[index];
	}

	T& _get(int index) {
		if (index < 0) {
			throw std::out_of_range("Out of range");
		}
		return this->_ptr[index];
	}

	MsPtr<T> _get() {
		return this->_ptr;
	}
};
*/