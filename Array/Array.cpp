// Array.cpp
#include <iostream>

using namespace std;

template <class ArrayType>
class Array{
	private:
		int size;
		ArrayType* startptr;
		Array();
	public:
		~Array();
		ArrayType& operator[](int index);
		void operator=(const ArrayType& other);
		Array(int size);
		int get_size();
		ArrayType element_at(int index);
};

//Implementation Portion
template<class ArrayType>
int Array<ArrayType>::get_size() {
	return size;
}

template<class ArrayType>
Array<ArrayType>::Array()
{
	throw runtime_error("Trying to init empty array");
	exit(1);
}

template<class ArrayType>
Array<ArrayType>::Array(int size)
{
	this->size = size;
	startptr = new ArrayType[size];
	if (startptr == NULL)
		throw runtime_error("Could not allocate memory");
}

template<class ArrayType>
ArrayType& Array<ArrayType>::operator[](int index)
{
	if (index >= size || index < 0)
		throw runtime_error("Index out of range");

	return startptr[index];
}

template<class ArrayType>
void Array<ArrayType>::operator=(const ArrayType& other)
{
	if (other == null)
		throw runtime_error("Assigning to null value");
	startptr + sizeof(ArrayType) = other;
}

template<class ArrayType>
Array<ArrayType>::~Array()
{
	delete[] startptr;
}
