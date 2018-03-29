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
	int size_;
	
	public:
	// get the front of the list
	const T front() const;
	// get an element at a specific index
	const T at(const int index) const;
	// check if empty
	const bool is_empty() const;
	// Insert a new node at an index
	Node<T>* insert_at(const int index, const T data);
	// Add Node to end of list
	Node<T>* push_back(const T data);
	// Add Node to start of list
	void push_front(const T data);
	// Remove Node from start
	void pop_front();
	// Remove Node at an index
	void delete_at(const int index);
	// return size
	const int size() const;
	// Default constructor
	LinkedList();
	// One Node Constructor
	LinkedList(Node<T>* newNode);
	// Destructor
	~LinkedList();
	// Copy Constructor
	LinkedList(const LinkedList& copyList);
};

template<typename T>
Node<T>::Node() {
	data = NULL;
	next = NULL;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList& copyList) {
	size_ = 0;
	for (int i = 0; i < copyList.size(); i++)
	{
		this->push_back(copyList.at(i));
	}
}

template<class T>
const int LinkedList<T>::size() const{
	return size_;
}

template<class T>
const T LinkedList<T>::front() const {
	if (!is_empty())
		return head->data;
	else
		throw runtime_error("Trying to Front() empty list");
}

template<class T>
const T LinkedList<T>::at(const int index) const {
	if (index < 0 || index >= size())
		throw runtime_error("bad index in element_at()");
	if (index == 0)
		return front();
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
	size_ = 0;
}

template<class T>
LinkedList<T>::~LinkedList() {
	Node<T>* delNode = head;
	while (delNode != NULL)
	{
		Node<T>* tempNode = delNode->next;
		delete delNode;
		delNode = tempNode;
	}
}

template<class T>
LinkedList<T>::LinkedList(Node<T>* newNode) {
	head = newNode;
	size_ = 1;
}

template<typename T>
Node<T>::Node(T data, Node<T>* next) {
	this->data = data;
	this->next = next;
}

template<class T>
const bool LinkedList<T>::is_empty() const{
	return head == NULL;
}

template<class T>
void LinkedList<T>::pop_front() {
	if (!is_empty()) {
		Node<T>* oldHead = head;
		head = head->next;
		size_--;
		delete oldHead;
	}
	else
		throw runtime_error("Popping empty index");
}

template<class T>
void LinkedList<T>::delete_at(int index) {
	if (index < 0 || index >= size())
		throw runtime_error("Bad Index in Insert_at()");
	if (index == 0)
		pop_front();
	else
	{
		Node<T>* currNode = head;
		for (int i = 0; i < index - 1; ++i)
			currNode = head->next;
		Node<T>* skipNode = currNode->next;
		currNode->next = skipNode->next;
		size_--;
		delete skipNode;
	}
}

template<class T>
Node<T>* LinkedList<T>::insert_at(int index, T data) {
	if (index < 0 || index >= size())
		throw runtime_error("Bad Index in Insert_at()");
	if (index == 0)
		push_front(data);
	else {
		Node<T>* currNode = head;
		for (int i = 0; i < index - 1; ++i)
			currNode = head->next;
		// Should be 1 before where we want to insert
		Node<T>* newNode = new Node<T>(data, currNode->next);
		currNode->next = newNode;
		size_++;
		return newNode;
	}
	return head;
}

template<class T>
void LinkedList<T>::push_front(T data) {
	if (size() > 0) {
		Node<T>* newNode = new Node<T>(data, head);
		head = newNode;
	} else if (size() == 0){
		head = new Node<T>(data, NULL);
	} else {
		throw runtime_error("Invalid size of list");
	}
	size_++;
}

template<class T>
Node<T>* LinkedList<T>::push_back(T data) {
	if (size() > 0) {
		Node<T>* currNode = head;
		Node<T>* newNode = new Node<T>(data, NULL);
		while (currNode->next != NULL)
			currNode = currNode->next;
		currNode->next = newNode;
		size_++;
		return newNode;
	} else if (size() == 0){
		head = new Node<T>(data, NULL);
		size_++;
		return head;
	} else {
		throw runtime_error("Invalid size of list");
	}
}



