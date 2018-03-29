// Stack
#include "..\..\Linked List\LinkedList.cpp"

using namespace std;

template <class T>
class Stack {
	private:
		// head will be the top of the stack
		LinkedList<T> list;
	public:
		T pop();
		void push(T data);
		T peek();
		Stack();
		Stack(T data);
		int size();
};

template <class T>
Stack<T>::Stack() {}

template <class T>
Stack<T>::Stack(T data) {
	list.push_front(data);
}

template <class T>
void Stack<T>::push(T data) {
	list.push_front(data);
}

template <class T>
T Stack<T>::pop() {
	T top = list.front();
	list.pop_front();
	return top;
}

template <class T>
T Stack<T>::peek() {
	return list.front();
}

template <class T>
int Stack<T>::size() {
	return list.size();
}

