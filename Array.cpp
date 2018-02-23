// Array.cpp
#include <iostream>

using namespace std;

template <class ArrayType>
class Array{
	private:
		int size;
		ArrayType* startptr;
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
Array<ArrayType>::Array(int size)
{
	this->size = size;
	startptr = new ArrayType[size]();
	if (startptr == NULL)
		exit(1);
}

template<class ArrayType>
ArrayType& Array<ArrayType>::operator[](int index)
{
	if (index > size || index < 0)
	{
		cout << "Index out of range";
		exit(1);
	}

	return *(startptr + index);
}

template<class ArrayType>
void Array<ArrayType>::operator=(const ArrayType& other)
{
	startptr + sizeof(ArrayType) = other;
}

template<class ArrayType>
Array<ArrayType>::~Array()
{
	delete startptr;
}