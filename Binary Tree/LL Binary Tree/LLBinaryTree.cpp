// Binary tree

#include <iostream>

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

template<class T>
class BinaryTree {
private:
	Node<T>* left;
	Node<T>* right;
	
	int height;

public:
	BinaryTree();
	~BinaryTree();
	void Insert_node();
	// need to make sure not ambiguous
	void Delete_node();
};