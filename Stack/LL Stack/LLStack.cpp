// Stack
#include "..\..\Linked List\LinkedList.cpp"

using namespace std;

template <class T>
class Stack {
	private:
		// head will be the top of the stack
		LinkedList<T> list;
	public:
		T Pop();
		void Push(T data);
		T Peek();
		Stack();
		Stack(T data);
		int Get_size();
};

template <class T>
Stack<T>::Stack() {}

template <class T>
Stack<T>::Stack(T data) {
	list.Push_front(data);
}

template <class T>
void Stack<T>::Push(T data) {
	list.Push_front(data);
}

template <class T>
T Stack<T>::Pop() {
	T top = list.Front();
	list.Pop_front();
	return top;
}

template <class T>
T Stack<T>::Peek() {
	return list.Front();
}

template <class T>
int Stack<T>::Get_size() {
	return list.Get_size();
}

