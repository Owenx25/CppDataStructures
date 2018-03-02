// Queue

#include <iostream>
#include<string>
#include "..\Linked List\Doubly Linked List\DoublyLinkedList.cpp"

using namespace std;

template<class T>
class Queue {
private:
	DoublyLinkedList<T> list;
public:
	T Front() const;
	T Back() const;
	void Enqueue(T data);
	void Dequeue();
	int Get_size() const;
	bool Is_empty() const;
	friend ostream& operator<<(ostream& os, const Queue<T>& q) {
		os << "--> [" << q.Back() << " ... " << q.Front() << "] -->\n" ;
		return os;
	}
	
	Queue();
};

template<class T>
Queue<T>::Queue() {}

template<class T>
void Queue<T>::Enqueue(T data) {
	list.Push_back(data);
}

template<class T>
void Queue<T>::Dequeue() {
	list.Pop_front();
}

template<class T>
int Queue<T>::Get_size() const {
	return list.Get_size();
}

template<class T>
bool Queue<T>::Is_empty() const{
	return list.Is_empty();
}

template<class T>
T Queue<T>::Front() const{
	return list.Front();
}

template<class T>
T Queue<T>::Back() const{
	return list.Back();
}