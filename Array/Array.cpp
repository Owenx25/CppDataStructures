// Array.cpp
#include <iostream>

using namespace std;

template <class T>
class Array{
	private:
		int capacity;
		T* startptr;
		Array();
	public:
		~Array();
		Array(int capacity);
		T& operator[](const int index) const;
		int Get_capacity() const;
};

template<class T>
Array<T>::Array(int capacity)
{
	if (capacity <= 0)
		throw runtime_error("invalid init size");
	this->capacity = capacity;
	startptr = new T[capacity];
	while (--capacity)
		startptr[capacity] = T();
	if (startptr == NULL)
		throw runtime_error("Could not allocate memory");
}

template<class T>
int Array<T>::Get_capacity() const{ return capacity; }

template<class T>
Array<T>::Array()
{
	throw runtime_error("Trying to init empty array");
	exit(1);
}

template<class T>
T& Array<T>::operator[](const int index) const
{
	if (index >= capacity || index < 0)
		throw runtime_error("Index out of range");

	return startptr[index];
}

template<class T>
Array<T>::~Array()
{
	delete[] startptr;
	startptr = 0;
}
