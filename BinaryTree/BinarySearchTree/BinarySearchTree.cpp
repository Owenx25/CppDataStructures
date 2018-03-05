// Binary Search Tree
#include "..\NodeBinaryTree\BinaryTree.cpp"
#include <iostream>

using namespace std;

template<class T>
class BST {
private:
	// Each node in the tree has a (key, value) pair
	BinaryTree<tuple<int, T>> tree;
	BST();
public:
	Node<tuple<int, T>>* Search(T key);
	Node<tuple<int, T>>* Insert(Node<T>* root, tuple<int, T> newPair);
	void Delete(int key);
	BST(Node<tuple<int, T>>* root);
	~BST();
};

// Constructors
template<class T>
BST<T>::BST() {}
template<class T>
BST<T>::BST(Node<tuple<int, T>>* root) : tree(root) {}

// Destructor
template<class T>
BST<T>::~BST() {}

