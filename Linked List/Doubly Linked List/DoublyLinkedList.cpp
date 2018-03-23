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
	int size;
	// return node at specific index
	Node<T>* Get_node_at(int index) const;
	
	public:
	// get the front of the list
	T Front() const;
	// get the back of the list
	T Back() const;
	// get an element at a specific index
	T Element_at(int index) const;
	// check if empty
	bool Is_empty() const;
	// Insert a new node at an index
	Node<T>* Insert_at(int index, T data);
	// Add Node to end of list
	void Push_back(T data);
	// Add Node to start of list
	void Push_front(T data);
	// Remove Node from start
	void Pop_front();
	// Remove Node from end
	void Pop_back();
	// Remove Node at an index
	void Delete_at(int index);
	// return size
	int Get_size() const;
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
	this->size = 0;
	for (int i = 0; i < copyList.Get_size(); i++)
		this->Push_back(copyList.Element_at(i));
}

template<class T>
int DoublyLinkedList<T>::Get_size() const{
	return size;
}

template<class T>
T DoublyLinkedList<T>::Front() const {
	if (!Is_empty())
		return head->data;
	else
		throw runtime_error("Trying to Front() empty list");
}

template<class T>
T DoublyLinkedList<T>::Back() const {
	if (!Is_empty())
		return tail->data;
	else
		throw runtime_error("Trying to Back() empty list");
}

template<class T>
T DoublyLinkedList<T>::Element_at(int index) const {
	if (index < 0 || index >= size)
		throw runtime_error("bad index in element_at()");
	if (index == 0)
		return Front();
	else if (index == size - 1)
		return Back();
	else
		return Get_node_at(index)->data;
}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {
	head = NULL;
	tail = NULL;
	size = 0;
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
	size = 1;
}

template<typename T>
Node<T>::Node(T data, Node<T>* next, Node<T>* prev) : data(data), next(next), prev(prev) {}

template<class T>
bool DoublyLinkedList<T>::Is_empty() const{
	return size == 0;
}

template<class T>
void DoublyLinkedList<T>::Pop_front() {
	if (!Is_empty()) {
		Node<T>* oldHead = head;
		head = head->next;
		if (size == 1)
			tail = NULL;
		size--;
		delete oldHead;
	}
	else
		throw runtime_error("Popping empty index");
}

template<class T>
void DoublyLinkedList<T>::Pop_back() {
	if (Is_empty())
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
void DoublyLinkedList<T>::Delete_at(int index) {
	if (index < 0 || index >= size)
		throw runtime_error("Bad Index in Delete_at()");
	if (index == 0)
		Pop_front();
	else if (index == size - 1)
		Pop_back();
	else {
		Node<T>* beforeNode = Get_node_at(index - 1);
		Node<T>* skipNode = beforeNode->next;
		Node<T>* afterNode = skipNode->next;
		beforeNode->next = afterNode;
		afterNode->prev = beforeNode;
		size--;
		delete skipNode;
	}
}

template<class T>
Node<T>* DoublyLinkedList<T>::Insert_at(int index, T data) {
	if (index < 0 || index >= size)
		throw runtime_error("Bad Index in Insert_at()");
	if (index == 0) {
		Push_front(data);
		return head;
	} else if (index == size - 1) {
		Push_back(data);
		return tail;
	} else {
		Node<T>* beforeNode = Get_node_at(index - 1);
		Node<T>* afterNode = beforeNode->next;
		Node<T>* newNode = new Node<T>(data, afterNode, beforeNode);
		beforeNode->next = newNode;
		afterNode->prev = newNode;
		size++;
		return newNode;
	}
	return NULL;
}

template<class T>
void DoublyLinkedList<T>::Push_front(T data) {
	if (size > 0) {
		Node<T>* newNode = new Node<T>(data, head, NULL);
		head = newNode;
	} else if (size == 0){
		head = new Node<T>(data, NULL, NULL);
		tail = head;
	} else {
		throw runtime_error("Invalid size of list");
	}
	size++;
}

template<class T>
void DoublyLinkedList<T>::Push_back(T data) {
	if (size > 0) {
		Node<T>* currNode = tail;
		Node<T>* newNode = new Node<T>(data, NULL, currNode);
		currNode->next = newNode;
		tail = newNode;
		size++;
	} else if (size == 0){
		head = new Node<T>(data, NULL, NULL);
		tail = head;
		size++;
	} else {
		throw runtime_error("Invalid size of list");
	}
}

template<class T>
Node<T>* DoublyLinkedList<T>::Get_node_at(int index) const{
	if (Is_empty())
		throw runtime_error("List is empty");
	if (index == 0)
		return head;
	else if (index == size - 1)
		return tail;
	else if (index <= ((size - 1) / 2)) {
		Node<T>* tempNode = head;
		for (int i = 0; i < index; i++)
		{
			tempNode = tempNode->next;
		}
		return tempNode;
	} else if (index > ((size - 1) / 2)) {
		Node<T>* tempNode = tail;
		for (int i = size - 1; i > index; i--)
		{
			tempNode = tempNode->prev;
		}
		return tempNode;
	}
	return NULL;
}


