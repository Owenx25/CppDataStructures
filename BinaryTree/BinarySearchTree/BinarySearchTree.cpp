// Binary Search Tree
#include "..\NodeBinaryTree\BinaryTree.cpp"
#include <iostream>
#include <string>

using namespace std;

template<class T>
class BST {
private:
	// Each TreeNode in the tree has a (key, value) pair
	BinaryTree<pair<int, T>> tree;
	BST();
public:
	TreeNode<pair<int, T>>* Search(T key);
	TreeNode<pair<int, T>>* Insert(int key, T value);
	void Delete(int key, TreeNode<pair<int, T>> searchNode);
	TreeNode<pair<int, T>>* Find_max(TreeNode<pair<int, T>>* subTreeRoot);
	TreeNode<pair<int, T>>* Find_min(TreeNode<pair<int, T>>* subTreeRoot);
	BST(TreeNode<pair<int, T>>* root);
	BST(int rootKey, T rootValue);
	~BST();
};

// Constructors
template<class T>
BST<T>::BST() {}
template<class T>
BST<T>::BST(TreeNode<pair<int, T>>* root) : tree(root) {}
template<class T>
BST<T>::BST(int rootKey, T rootValue) : tree(new TreeNode<pair<int, T>>(pair<int, T>(rootKey, rootValue))){}

// Destructor
template<class T>
BST<T>::~BST() {}

template<class T>
TreeNode<pair<int, T>>* BST<T>::Search(T key) {
	TreeNode<pair<int, T>> searchTreeNode = tree.root;
	while (searchTreeNode != NULL) {
		if (key == searchTreeNode->data.first)
			return searchTreeNode;
		if (key < searchTreeNode->data.first)
			searchTreeNode = searchTreeNode->childLeft;
		else
			searchTreeNode = searchTreeNode->childRight;
	}
	return searchTreeNode;
}

template<class T>
TreeNode<pair<int, T>>* BST<T>::Insert(int key, T value) {
	pair<int, T> newPair(key, value);
	TreeNode<pair<int, T>> searchTreeNode = tree.root;
	TreeNode<pair<int, T>>* TreeNodeBefore;
	int key = newPair.first;
	while (searchTreeNode != NULL) {
		TreeNodeBefore = searchTreeNode;
		if (key == searchTreeNode->data.first)
			throw runtime_error("Data already in tree");
		if (key < searchTreeNode->data.first)
			searchTreeNode = searchTreeNode->childLeft;
		else
			searchTreeNode = searchTreeNode->childRight;
	}
	if (TreeNodeBefore->data.first > key)
		return Insert_left(TreeNodeBefore, newPair);
	else
		return Insert_right(TreeNodeBefore, newPair);
	return NULL;
}

template<class T>
void BST<T>::Delete(int key, TreeNode<pair<int, T>> searchNode) {
	while (searchNode != NULL) {
		// Found our TreeNode to delete
		if (key == searchNode->data.first) {
			// Cases with a leaf or One child are easily dealt with
			try { Delete_TreeNode(searchNode); }
			catch (exception& e) {
				// Get either inOrder Predecessor or Successor
				TreeNode<pair<int, T>>* successor = searchNode->childRight->Find_min();
				// overwrite key and data of delete node
				searchNode->data = successor->data;
				// delete predecessor or successor(call function again)
				Delete(successor.first, searchNode);
			}	
		}
		if (key < searchNode->data.first)
			searchNode = searchNode->childLeft;
		else
			searchNode = searchNode->childRight;
	}
	throw runtime_error("Cannot delete key missing from tree");
}

template<class T>
TreeNode<pair<int, T>>* BST<T>::Find_min(TreeNode<pair<int, T>>* subTreeRoot) {
	while (subTreeRoot->Has_left())
		subTreeRoot = subTreeRoot->childLeft
	return subTreeRoot;
}
template<class T>
TreeNode<pair<int, T>>* BST<T>::Find_max(TreeNode<pair<int, T>>* subTreeRoot) {
	while (subTreeRoot->Has_right())
		subTreeRoot = subTreeRoot->childRight
	return subTreeRoot;
}

