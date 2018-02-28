// Singly Linked List
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>
struct Node {
	// Data payload of the node
	T data;
	// Pointer to next node
	Node<T>* next;
	
	Node(T data, Node<T>* next);
	Node();
};

template <class T>
class LinkedList {
	private:
	// First node in the list
	Node<T>* head;
	// Size of the list
	int size;
	
	public:
	// get the front of the list
	T Front();
	// get an element at a specific index
	T Element_at(int index);
	// Insert a new node at an index
	Node<T>* Insert_at(int index, T data);
	// Add Node to end of list
	Node<T>* Push_back(T data);
	// Add Node to start of list
	void Push_front(T data);
	// Remove Node from start
	void Pop_front();
	// Remove Node from an index
	//T Delete_at(int index);
	// return size
	int Get_size();
	// Default constructor
	LinkedList();
	// One Node Constructor
	LinkedList(Node<T>* newNode);
};

template<typename T>
Node<T>::Node() {
	data = NULL;
	next = NULL;
}

template<class T>
int LinkedList<T>::Get_size() {
	return size;
}

template<class T>
T LinkedList<T>::Front() {
	return head->data;
}

template<class T>
T LinkedList<T>::Element_at(int index) {
	if (index < 0 || index >= size)
		throw runtime_error("bad index in element_at()");
	if (index == 0)
		Front();
	else {
		Node<T>* tempNode = head;
		for (int i = 0; i < index; i++)
		{
			tempNode = tempNode->next;
		}
		return tempNode->data;
	}
}

template<class T>
LinkedList<T>::LinkedList() {
	head = NULL;
	size = 0;
}

template<class T>
LinkedList<T>::LinkedList(Node<T>* newNode) {
	head = newNode;
	size = 1;
}

template<typename T>
Node<T>::Node(T data, Node<T>* next) {
	this->data = data;
	this->next = next;
}

template<class T>
void LinkedList<T>::Pop_front() {
	Node<T>* oldHead = &head;
	head = head.->next;
	delete oldHead;
}

template<class T>
Node<T>* LinkedList<T>::Insert_at(int index, T data) {
	if (index < 0 || index >= size)
		throw runtime_exception("Bad Index");
	
	if (index == 0)
		Push_front(data);
	else {
		Node<T> currNode = *head;
		Node<T>* p_newNode = new Node<T>(data, NULL);
		while (index - 1 >= 0)
		{
			currNode = head->next;
			index--;
		}
		// Should be 1 before where we want to insert
		p_newNode->next = currNode->next;
		currNode->next = p_newNode;
		size++;
	}
}

template<class T>
void LinkedList<T>::Push_front(T data) {
	if (size > 0) {
		Node<T>* newNode = new Node<T>(data, head);
		head = newNode;
	} else if (size == 0){
		head = new Node<T>(data, NULL);
	} else {
		throw runtime_error("Invalid size of list");
	}
	size++;
}

template<class T>
Node<T>* LinkedList<T>::Push_back(T data) {
	if (size > 0) {
		Node<T>* currNode = head;
		Node<T>* newNode = new Node<T>(data, NULL);
		while (currNode->next != NULL)
			currNode = head->next;
		currNode->next = newNode;
		size++;
		return newNode;
	} else if (size == 0){
		head = new Node<T>(data, NULL);
		size++;
		return head;
	} else {
		throw runtime_error("Invalid size of list");
	}
}



