// Doubly Linked List
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
	// Pointer to previous node
	Node<T>* prev;
	
	Node(T data, Node<T>* next, Node<T>* prev);
	Node();
};

template <class T>
class DoublyLinkedList {
	private:
	// First node in the list
	Node<T>* head;
	// Last node in the list
	Node<T>* tail;
	// Size of the list
	int size_;
	// return node at specific index
	Node<T>* Get_node_at(int index) const;
	
	public:
	// get the front of the list
	T front() const;
	// get the back of the list
	T back() const;
	// get an element at a specific index
	T at(int index) const;
	// Set an element at a particular index
	void set(int index, T data);
	// check if empty
	bool is_empty() const;
	// Insert a new node at an index
	Node<T>* insert_at(int index, T data);
	// Add Node to end of list
	void push_back(T data);
	// Add Node to start of list
	void push_front(T data);
	// Remove Node from start
	void pop_front();
	// Remove Node from end
	void pop_back();
	// Remove Node at an index
	void delete_at(int index);
	// return size
	const int size() const;
	// Default constructor
	DoublyLinkedList();
	// One Node Constructor
	DoublyLinkedList(Node<T>* newNode);
	// Destructor
	~DoublyLinkedList();
	// Copy Constructor
	DoublyLinkedList(const DoublyLinkedList& copyList);
};

template<typename T>
Node<T>::Node() {
	data = NULL;
	next = NULL;
}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& copyList) {
	this->size_ = 0;
	for (int i = 0; i < copyList.size(); i++)
		this->push_back(copyList.at(i));
}

template<class T>
const int DoublyLinkedList<T>::size() const{
	return size_;
}

template<class T>
T DoublyLinkedList<T>::front() const {
	if (!is_empty())
		return head->data;
	else
		throw runtime_error("Trying to Front() empty list");
}

template<class T>
T DoublyLinkedList<T>::back() const {
	if (!is_empty())
		return tail->data;
	else
		throw runtime_error("Trying to Back() empty list");
}

template<class T>
T DoublyLinkedList<T>::at(int index) const {
	if (index < 0 || index >= size())
		throw runtime_error("bad index in element_at()");
	if (index == 0)
		return front();
	else if (index == size() - 1)
		return back();
	else
		return Get_node_at(index)->data;
}

template<class T>
void DoublyLinkedList<T>::set(int index, T data) {
	if (index < 0 || index >= size())
		throw runtime_error("bad index in element_at()");
	if (index == 0)
		head->data = data;
	else if (index == size() - 1)
		tail->data = data;
	else
		Get_node_at(index)->data = data;
}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {
	head = NULL;
	tail = NULL;
	size_ = 0;
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	Node<T>* delNode = head;
	while (delNode != NULL)
	{
		Node<T>* tempNode = delNode->next;
		delete delNode;
		delNode = tempNode;
	}
}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(Node<T>* newNode) {
	head = newNode;
	tail = newNode;
	size_ = 1;
}

template<typename T>
Node<T>::Node(T data, Node<T>* next, Node<T>* prev) : data(data), next(next), prev(prev) {}

template<class T>
bool DoublyLinkedList<T>::is_empty() const{
	return size() == 0;
}

template<class T>
void DoublyLinkedList<T>::pop_front() {
	if (!is_empty()) {
		Node<T>* oldHead = head;
		head = head->next;
		if (size() == 1)
			tail = NULL;
		size_--;
		delete oldHead;
	}
	else
		throw runtime_error("Popping empty index");
}

template<class T>
void DoublyLinkedList<T>::pop_back() {
	if (is_empty())
		throw runtime_error("Trying to pop_back empty list");
	Node<T>* firstNode = head; 
	if (firstNode->next == NULL) {
		delete firstNode;
		firstNode = NULL;
		return;
	}
	while (firstNode->next && firstNode->next->next != NULL) {
		firstNode = firstNode->next;
	}
	delete firstNode->next;
	firstNode->next = NULL;
}

template<class T>
void DoublyLinkedList<T>::delete_at(int index) {
	if (index < 0 || index >= size())
		throw runtime_error("Bad Index in Delete_at()");
	if (index == 0)
		pop_front();
	else if (index == size() - 1)
		pop_back();
	else {
		Node<T>* beforeNode = Get_node_at(index - 1);
		Node<T>* skipNode = beforeNode->next;
		Node<T>* afterNode = skipNode->next;
		beforeNode->next = afterNode;
		afterNode->prev = beforeNode;
		size_--;
		delete skipNode;
	}
}

template<class T>
Node<T>* DoublyLinkedList<T>::insert_at(int index, T data) {
	if (index < 0 || index >= size())
		throw runtime_error("Bad Index in Insert_at()");
	if (index == 0) {
		push_front(data);
		return head;
	} else if (index == size() - 1) {
		push_back(data);
		return tail;
	} else {
		Node<T>* beforeNode = Get_node_at(index - 1);
		Node<T>* afterNode = beforeNode->next;
		Node<T>* newNode = new Node<T>(data, afterNode, beforeNode);
		beforeNode->next = newNode;
		afterNode->prev = newNode;
		size_++;
		return newNode;
	}
	return NULL;
}

template<class T>
void DoublyLinkedList<T>::push_front(T data) {
	if (size() > 0) {
		Node<T>* newNode = new Node<T>(data, head, NULL);
		head->prev = newNode;
		head = newNode;	
	} else if (size() == 0){
		head = new Node<T>(data, NULL, NULL);
		tail = head;
	} else {
		throw runtime_error("Invalid size of list");
	}
	size_++;
}

template<class T>
void DoublyLinkedList<T>::push_back(T data) {
	if (size() > 0) {
		Node<T>* currNode = tail;
		Node<T>* newNode = new Node<T>(data, NULL, currNode);
		currNode->next = newNode;
		tail = newNode;
		size_++;
	} else if (size() == 0){
		head = new Node<T>(data, NULL, NULL);
		tail = head;
		size_++;
	} else {
		throw runtime_error("Invalid size of list");
	}
}

template<class T>
Node<T>* DoublyLinkedList<T>::Get_node_at(int index) const{
	if (is_empty())
		throw runtime_error("List is empty");
	if (index == 0)
		return head;
	else if (index == size() - 1)
		return tail;
	else if (index <= ((size() - 1) / 2)) {
		Node<T>* tempNode = head;
		for (int i = 0; i < index; i++)
		{
			tempNode = tempNode->next;
		}
		return tempNode;
	} else if (index > ((size() - 1) / 2)) {
		Node<T>* tempNode = tail;
		for (int i = size() - 1; i > index; i--)
		{
			tempNode = tempNode->prev;
		}
		return tempNode;
	}
	return NULL;
}


