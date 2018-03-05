// Binary tree

#include <iostream>

using namespace std;

template <typename T>
struct Node {
	// Data payload of the node
	T data;
	//Parent Node
	Node<T>* parent;
	// left child node
	Node<T>* childLeft;
	// right child node
	Node<T>* childRight;
	
	Node(T data, Node<T>* childLeft, Node<T>* childRight, Node<T>* parent);
	Node(T data);
	Node();
};

template<class T>
class BinaryTree {
private:
	int Find_height(Node<T>* node);
	void Delete_traverse(Node<T>* node);
	int height;
	int Max(int a, int b);
	BinaryTree();
public:
	Node<T>* root;
	int Get_height() const;
	BinaryTree(Node<T>* root);
	~BinaryTree();
	void Insert_between(Node<T>* nodeAbove, Node<T>* nodeBelow, T data);
	void Insert_left(Node<T>* leafNode, T data);
	void Insert_right(Node<T>* leafNode, T data);
	bool Has_left(Node<T>* node) const;
	bool Has_right(Node<T>* node) const;
	// need to make sure not ambiguous
	void Delete_node(Node<T>* delNode);
	void Print_pre_order(Node<T>* node);
	void Print_in_order(Node<T>* node);
	void Print_post_order(Node<T>* node);
};

// Node Constructors
template<typename T>
Node<T>::Node() : data(NULL), childLeft(NULL), childRight(NULL), parent(NULL) {}
template<typename T>
Node<T>::Node(T data) : data(data), childLeft(NULL), childRight(NULL), parent(NULL) {}
template<typename T>
Node<T>::Node(T data, Node<T>* childLeft, Node<T>* childRight, Node<T>* parent) {
	this->data = data;
	this->childLeft = childLeft;
	this->childRight = childRight;
	this->parent = parent;
}

// Binary Tree Constructors
template<class T>
BinaryTree<T>::BinaryTree(Node<T>* root) : root(root), height(0) {}
template<class T>
BinaryTree<T>::BinaryTree(){}

// Destructor
template<class T>
BinaryTree<T>::~BinaryTree() { Delete_traverse(root); }
template<class T>
void BinaryTree<T>::Delete_traverse(Node<T>* node) {
	if (node == NULL)
		return;
	Delete_traverse(node->childLeft);
	Delete_traverse(node->childRight);
	delete node;
}

// Print loops
template<class T>
void BinaryTree<T>::Print_pre_order(Node<T>* node) {
	if (node == NULL)
		return;
	cout << node->data << " ";
	Print_pre_order(node->childLeft);
	Print_pre_order(node->childRight);
}
template<class T>
void BinaryTree<T>::Print_in_order(Node<T>* node) {
	if (node == NULL)
		return;
	Print_in_order(node->childLeft);
	cout << node->data << " ";
	Print_in_order(node->childRight);
}
template<class T>
void BinaryTree<T>::Print_post_order(Node<T>* node) {
	if (node == NULL)
		return;
	Print_post_order(node->childLeft);
	Print_post_order(node->childRight);
	cout << node->data << " ";
}

// Insertion Functions
template<class T>
void BinaryTree<T>::Insert_between(Node<T>* nodeAbove, Node<T>* nodeBelow, T data) {
	Node<T>* newNode = new Node<T>(data, NULL, NULL, nodeAbove);
	if (nodeAbove->childLeft == nodeBelow) {
		nodeAbove->childLeft = newNode;
		newNode->childLeft = nodeBelow;
	} else if (nodeAbove->childRight == nodeBelow) {
		nodeAbove->childRight = newNode;
		newNode->childLeft = nodeBelow;
	}
	height = Get_height(root);
}
template<class T>
void BinaryTree<T>::Insert_left(Node<T>* leafNode, T data) {
	if (leafNode->childLeft == NULL) {
		Node<T>* newNode = new Node<T>(data, NULL, NULL, leafNode);
		leafNode->childLeft = newNode;
		height = Find_height(root);
	} else {
		throw runtime_error("left child already defined.");
	}
}
template<class T>
void BinaryTree<T>::Insert_right(Node<T>* leafNode, T data) {
	if (leafNode->childRight == NULL) {
		Node<T>* newNode = new Node<T>(data, NULL, NULL, leafNode);
		leafNode->childRight = newNode;
		height = Find_height(root);
	} else {
		throw runtime_error("right child already defined.");
	}
}

// ChildNode getters
template<class T>
bool BinaryTree<T>::Has_left(Node<T>* node) const { return node->childLeft != NULL }
template<class T>
bool BinaryTree<T>::Has_right(Node<T>* node) const { return node->childRight != NULL }

template<class T>
void BinaryTree<T>::Delete_node(Node<T>* delNode) {
	if (delNode == NULL)
		throw runtime_error("Trying to delete empty node");
	// Bad deletion
	if (delNode->childLeft != NULL && delNode->childRight != NULL) {
			throw runtime_error("Ambiguous deletion: Node has 2 children");
	// Deleting a leaf node
	} else if (delNode->childLeft == NULL && delNode->childRight == NULL) {
		Node<T>* delParent = delNode->parent;
		if (delParent->childLeft == delNode)
			delParent->childLeft = NULL;
		else if (delParent->childRight == delNode) {
			delParent->childRight = NULL;
		}
	// Non-ambiguous deletion
	} else {
		// childRight is promoted
		if (delNode->childLeft == NULL) {
			Node<T>* delParent = delNode->parent;
			Node<T>* delChild = delNode->childRight;
			delParent->childRight = delChild;
			delChild->parent = delParent;
		// childLeft is promoted
		} else if (delNode->childRight == NULL) {
			Node<T>* delParent = delNode->parent;
			Node<T>* delChild = delNode->childLeft;
			delParent->childLeft = delChild;
			delChild->parent = delParent;
		}
	}
	height = Find_height(root);
	delete delNode;
}

// Height Functions
template<class T>
int BinaryTree<T>::Find_height(Node<T>* node) {
	if (node == NULL)
		return 0;
	return Max(Find_height(node->childLeft), Find_height(node->childRight)) + 1;
}
template<class T>
int BinaryTree<T>::Get_height() const { return height; }
template<class T>
int BinaryTree<T>::Max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}