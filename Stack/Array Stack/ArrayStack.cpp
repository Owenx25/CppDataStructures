// Stack
#include "..\..\Array\Array.cpp"

using namespace std;

template <class T>
class Stack {
	private:
		// Stack will be limited to 100 cells by default
		Array<T> block;
		int size;
	public:
		T Pop();
		void Push(T data);
		T Peek();
		Stack();
		Stack(int capacity);
		int Get_size();
};

template <class T>
Stack<T>::Stack() : block(100), size(0){}

template <class T>
Stack<T>::Stack(int capacity) : block(capacity), size(1) {}

template <class T>
void Stack<T>::Push(T data) {
	if (size >= block.Get_size())
		throw runtime_error("Stack had reached max capacity");
	block[size] = data;
	size++;
}

template <class T>
T Stack<T>::Pop() {
	if (size <= 0)
		throw runtime_error("trying to pop an empty stack");
	size--;
	return block[size];
}

template <class T>
T Stack<T>::Peek() {
	return block[size - 1];
}

template <class T>
int Stack<T>::Get_size() {
	return size;
}

