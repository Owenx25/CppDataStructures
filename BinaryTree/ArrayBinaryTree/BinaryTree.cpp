// Array-Implemented Binary Tree
#include <iostream>

using namespace std;

enum ChildType { LEFT = 1, RIGHT = 2 }

template<class T>
class BinaryTree {
private:
	vector<pair<bool,T> tree;
	BinaryTree();
	void check_OOB(const int index);
	bool child_empty(const ChildType child, const int index);
public:
	
	BinaryTree(const T Data);
	void insert_between(const int parent, const int child,const T data);
	void insert_child(const ChildType child, const T data);
	void delete_node(int delNode);
	bool has_child(ChildType child, int index) const;
	int height() const;
	int num_nodes() const;
	int get_Child(const ChildType child) const;
};

// Constructors
template<class T>
BinaryTree<T>::BinaryTree(const T data) { tree.push_back(data); }

// Insert Functions
template<class T>
void BinaryTree<T>::insert_between(const int parent, const ChildType child, const T data) {
	check_OOB(parent);
	int childIndex = 2 * parent + child;
	check_OOB(childIndex);
	T childData = tree[childIndex].second;
	tree[childIndex].second = data;
	// Child of the child is empty
	if (child_empty(ChildType.LEFT, child) {
		insert_child(ChildType.LEFT, data, child);
	} else if(child_empty(ChildType.RIGHT, child)) {
		insert_child(ChildType.RIGHT, data, child);
	// Child of Child not empty
	} else {
		insert_between(child, ChildType.LEFT, childData);
	}
}
template<class T>
void BinaryTree<T>::insert_child(const ChildType child, const T data, const parentIndex) {
	check_OOB(parentIndex);
	int childIndex = 2 * parentIndex + child;
	// if we already have space for a child
	if (childIndex <= tree.size() - 1) {
		if (tree[childIndex].first)
			throw runtime_error("Child already exists");
	}
	// normally cellsNeeded would be one less but it 
	// works nice with the while loop this way
	int cellsNeeded = childIndex - tree.size();
	for (--cellsNeeded)
		tree.push_back(new pair<bool, T>(false, T()));
	tree[childIndex] = new pair<bool, true, data);
}

// Delete Functions
template<class T>
void BinaryTree<T>::delete_node(int delNode) {
	
}

// Accessor Functions
template<class T>
int BinaryTree<T>::get_Child(int const index, const ChildType child) const {
	check_OOB(index);
	if (!this->has_child(child, index)
		throw runtime_error("Child does not exist");
	return 2 * index + child;
}
template<class T>
bool BinaryTree<T>::has_child (ChildType child, int index) const {
	check_OOB(index);
	if (index + child > size - 1)
		return false;
	else {
		if (tree[index + child].first)
			return true;
	}
	return false;
}

// Helpers
template<class T>
void BinaryTree<T>::check_OOB(const int index) {
	if (index < 0 || index >= (tree.size() - 1))
		throw runtime_error("Index is out of bounds");
}
bool BinaryTree<T>::child_empty(const ChildType child, const int index) {
	check_OOB(index);
	if (index + child > size - 1)
		return false;
	else {
		if (tree[index + child].first)
			return false;
	}
	return true;
}