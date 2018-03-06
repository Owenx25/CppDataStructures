// Binary tree

#include <iostream>
#include <string>
#include "..\..\Linked List\LinkedList.cpp"

using namespace std;

template <typename T>
struct TreeNode {
	// Data payload of the TreeNode
	T data;
	//Parent TreeNode
	TreeNode<T>* parent;
	// left child TreeNode
	TreeNode<T>* childLeft;
	// right child TreeNode
	TreeNode<T>* childRight;
	
	bool Has_left(TreeNode<T>* TreeNode) const;
	bool Has_right(TreeNode<T>* TreeNode) const;
	
	TreeNode(T data, TreeNode<T>* childLeft, TreeNode<T>* childRight, TreeNode<T>* parent);
	TreeNode(T data);
	TreeNode();
};

enum TraverseType { PreOrder, InOrder, PostOrder };

template<class T>
class BinaryTree {
private:
	int Find_height(TreeNode<T>* TreeNode);
	void Delete_traverse(TreeNode<T>* TreeNode);
	void Search_tree(TreeNode<T>* node, TraverseType type, LinkedList<TreeNode<T>>* list);
	int height;
	int Max(int a, int b);
	BinaryTree();
public:
	TreeNode<T>* root;
	int Get_height() const;
	BinaryTree(TreeNode<T>* root);
	~BinaryTree();
	void Insert_between(TreeNode<T>* TreeNodeAbove, TreeNode<T>* TreeNodeBelow, T data);
	TreeNode<T>* Insert_left(TreeNode<T>* leafTreeNode, T data);
	TreeNode<T>* Insert_right(TreeNode<T>* leafTreeNode, T data);
	// need to make sure not ambiguous
	void Delete_TreeNode(TreeNode<T>* delTreeNode);
	LinkedList<TreeNode<T>>* Get_pre_order();
	LinkedList<TreeNode<T>>* Get_in_order();
	LinkedList<TreeNode<T>>* Get_post_order();
};

// TreeNode Constructors
template<typename T>
TreeNode<T>::TreeNode() : data(NULL), childLeft(NULL), childRight(NULL), parent(NULL) {}
template<typename T>
TreeNode<T>::TreeNode(T data) : data(data), childLeft(NULL), childRight(NULL), parent(NULL) {}
template<typename T>
TreeNode<T>::TreeNode(T data, TreeNode<T>* childLeft, TreeNode<T>* childRight, TreeNode<T>* parent) {
	this->data = data;
	this->childLeft = childLeft;
	this->childRight = childRight;
	this->parent = parent;
}

// Binary Tree Constructors
template<class T>
BinaryTree<T>::BinaryTree(TreeNode<T>* root) : root(root), height(0) {}
template<class T>
BinaryTree<T>::BinaryTree(){}

// Destructor
template<class T>
BinaryTree<T>::~BinaryTree() { Delete_traverse(root); }
template<class T>
void BinaryTree<T>::Delete_traverse(TreeNode<T>* TreeNode) {
	if (TreeNode == NULL)
		return;
	Delete_traverse(TreeNode->childLeft);
	Delete_traverse(TreeNode->childRight);
	delete TreeNode;
}

// Traversals
template<class T>
LinkedList<TreeNode<T>>* BinaryTree<T>::Get_pre_order() {
	LinkedList<TreeNode<T>>* list = new LinkedList<TreeNode<T>>();
	Search_tree(root, TraverseType::PreOrder, list);
	return list;
}
template<class T>
LinkedList<TreeNode<T>>* BinaryTree<T>::Get_in_order() {
LinkedList<TreeNode<T>>* list = new LinkedList<TreeNode<T>>();
	Search_tree(root, TraverseType::InOrder, list);
	return list;
}
template<class T>
LinkedList<TreeNode<T>>* BinaryTree<T>::Get_post_order() {
	LinkedList<TreeNode<T>>* list = new LinkedList<TreeNode<T>>();
	Search_tree(root, TraverseType::PostOrder, list);
	return list;
}
template<class T>
void BinaryTree<T>::Search_tree(TreeNode<T>* node, TraverseType type, LinkedList<TreeNode<T>>* list) {
	if (node == NULL)
		return;
	if (type == TraverseType::PreOrder)
		list->Push_back(*node);
	Search_tree(node->childLeft, type, list);
	if (type == TraverseType::InOrder)
		list->Push_back(*node);
	Search_tree(node->childRight, type, list);
	if (type == TraverseType::PostOrder)
		list->Push_back(*node);
}

// Insertion Functions
template<class T>
void BinaryTree<T>::Insert_between(TreeNode<T>* TreeNodeAbove, TreeNode<T>* TreeNodeBelow, T data) {
	TreeNode<T>* newTreeNode = new TreeNode<T>(data, NULL, NULL, TreeNodeAbove);
	if (TreeNodeAbove->childLeft == TreeNodeBelow) {
		TreeNodeAbove->childLeft = newTreeNode;
		newTreeNode->childLeft = TreeNodeBelow;
	} else if (TreeNodeAbove->childRight == TreeNodeBelow) {
		TreeNodeAbove->childRight = newTreeNode;
		newTreeNode->childLeft = TreeNodeBelow;
	}
	height = Get_height(root);
}
template<class T>
TreeNode<T>* BinaryTree<T>::Insert_left(TreeNode<T>* leafTreeNode, T data) {
	if (leafTreeNode->childLeft != NULL) 
		throw runtime_error("left child already defined.");
	TreeNode<T>* newTreeNode = new TreeNode<T>(data, NULL, NULL, leafTreeNode);
	leafTreeNode->childLeft = newTreeNode;
	height = Find_height(root);
	return newTreeNode;
}
template<class T>
TreeNode<T>* BinaryTree<T>::Insert_right(TreeNode<T>* leafTreeNode, T data) {
	if (leafTreeNode->childRight != NULL) 
		throw runtime_error("right child already defined.");
	TreeNode<T>* newTreeNode = new TreeNode<T>(data, NULL, NULL, leafTreeNode);
	leafTreeNode->childRight = newTreeNode;
	height = Find_height(root);
	return newTreeNode;
}

// ChildTreeNode getters
template<class T>
bool TreeNode<T>::Has_left(TreeNode<T>* TreeNode) const { return TreeNode->childLeft != NULL }
template<class T>
bool TreeNode<T>::Has_right(TreeNode<T>* TreeNode) const { return TreeNode->childRight != NULL }

template<class T>
void BinaryTree<T>::Delete_TreeNode(TreeNode<T>* delTreeNode) {
	if (delTreeNode == NULL)
		throw runtime_error("Trying to delete empty TreeNode");
	// Bad deletion
	if (delTreeNode->childLeft != NULL && delTreeNode->childRight != NULL) {
			throw runtime_error("Ambiguous deletion: TreeNode has 2 children");
	// Deleting a leaf TreeNode
	} else if (delTreeNode->childLeft == NULL && delTreeNode->childRight == NULL) {
		TreeNode<T>* delParent = delTreeNode->parent;
		if (delParent->childLeft == delTreeNode)
			delParent->childLeft = NULL;
		else if (delParent->childRight == delTreeNode) {
			delParent->childRight = NULL;
		}
	// Non-ambiguous deletion
	} else {
		// childRight is promoted
		if (delTreeNode->childLeft == NULL) {
			TreeNode<T>* delParent = delTreeNode->parent;
			TreeNode<T>* delChild = delTreeNode->childRight;
			delParent->childRight = delChild;
			delChild->parent = delParent;
		// childLeft is promoted
		} else if (delTreeNode->childRight == NULL) {
			TreeNode<T>* delParent = delTreeNode->parent;
			TreeNode<T>* delChild = delTreeNode->childLeft;
			delParent->childLeft = delChild;
			delChild->parent = delParent;
		}
	}
	height = Find_height(root);
	delete delTreeNode;
}

// Height Functions
template<class T>
int BinaryTree<T>::Find_height(TreeNode<T>* TreeNode) {
	if (TreeNode == NULL)
		return 0;
	return Max(Find_height(TreeNode->childLeft), Find_height(TreeNode->childRight)) + 1;
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