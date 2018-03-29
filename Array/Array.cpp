// Array.cpp
#include <iostream>

using namespace std;

template <class T>
class Array{
	private:
		int size_;
		T* startptr;
		Array();
	public:
		~Array();
		Array(const int size);
		T& operator[](int index) const;
		int Size() const;
};

template<class T>
Array<T>::Array(int capacity)
{
	if (capacity <= 0)
		throw runtime_error("invalid init size");
	size_ = capacity;
	startptr = new T[capacity];
	while (--capacity)
		startptr[capacity] = T();
	if (startptr == NULL)
		throw runtime_error("Could not allocate memory");
}

template<class T>
int Array<T>::Size() const{ return size_; }

template<class T>
Array<T>::Array()
{
	throw runtime_error("Trying to init empty array");
	exit(1);
}

template<class T>
T& Array<T>::operator[](const int index) const
{
	if (index >= size_ || index < 0)
		throw runtime_error("Index out of range");
	return startptr[index];
}

template<class T>
Array<T>::~Array()
{
	delete[] startptr;
	startptr = nullptr;
}
