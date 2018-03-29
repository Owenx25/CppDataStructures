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
	T front() const;
	T back() const;
	void enqueue(T data);
	void dequeue();
	int size() const;
	bool is_empty() const;
	friend ostream& operator<<(ostream& os, const Queue<T>& q) {
		os << "--> [" << q.back() << " ... " << q.front() << "] -->\n" ;
		return os;
	}
	
	Queue();
};

template<class T>
Queue<T>::Queue() {}

template<class T>
void Queue<T>::enqueue(T data) {
	list.push_back(data);
}

template<class T>
void Queue<T>::dequeue() {
	list.pop_front();
}

template<class T>
int Queue<T>::size() const {
	return list.size();
}

template<class T>
bool Queue<T>::is_empty() const{
	return list.is_empty();
}

template<class T>
T Queue<T>::front() const{
	return list.front();
}

template<class T>
T Queue<T>::back() const{
	return list.back();
}