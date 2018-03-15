// Array-Implemented Binary Tree
#include <iostream>
#include <vector>
#include <tuple>
#include <utility>

using namespace std;

enum ChildType { LEFT = 1, RIGHT = 2 };

template<class T>
class BinaryTree {
private:
	vector<pair<bool,T>> tree;
	BinaryTree();
	void check_OOB(const int index) const;
public:
	BinaryTree(const T Data);
	void insert_child(const ChildType child, const T data, const int parentIndex);
	void delete_node(int delIndex);
	bool has_child(ChildType child, int index) const;
	int height() const;
	int num_nodes() const;
	T get_data(int const index) const;
	int get_child(int const index, const ChildType child) const;
	void printBFS();
};

// Constructors
template<class T>
BinaryTree<T>::BinaryTree(const T data) { tree.push_back(pair<bool, T>(true, data)); }

// Insert Functions
template<class T>
void BinaryTree<T>::insert_child(const ChildType child, const T data, const int parentIndex) {
	check_OOB(parentIndex);
	int childIndex = 2 * parentIndex + child;
	// if we already have space for a child
	if (childIndex <= tree.size() - 1) {
		if (tree[childIndex].first)
			throw runtime_error("Child already exists");
	}
	// normally cellsNeeded would be one less but it 
	// works nice with the while loop this way
	int cellsNeeded = childIndex - (tree.size() - 1);
	while (cellsNeeded > 0) {
		--cellsNeeded;
		tree.push_back(pair<bool, T>(false, T()));
	}
	tree[childIndex] = pair<bool, T>(true, data);
}

// Delete Functions
template<class T>
void BinaryTree<T>::delete_node(int delIndex) {
	check_OOB(delIndex);
	bool left = has_child(LEFT, delIndex);
	bool right = has_child(RIGHT, delIndex);
	// 3 Cases
	if (left && right) {
		// Two children
		throw runtime_error("Ambiguous deletion");
	} else if (left && !right) {
		// One Child => see comment below
		int childIndex = get_child(delIndex, LEFT);
		tree[delIndex].second = get_data(childIndex);
		delete_node(childIndex);
	} else if (!left && right) {
		// One Child => copy child to parent then delete child
		int childIndex = get_child(delIndex, RIGHT);
		tree[delIndex].second = get_data(childIndex);
		delete_node(childIndex);
	} else {
		// Leaf => node is cleared
		tree[delIndex].first = false;
		tree[delIndex].second = T();
	}
}

// Accessor Functions
template<class T>
int BinaryTree<T>::get_child(int const index, const ChildType child) const {
	check_OOB(index);
	if (!has_child(child, index))
		throw runtime_error("Child does not exist");
	return 2 * index + child;
}
template<class T>
T BinaryTree<T>::get_data(int const index) const{
	check_OOB(index);
	return tree[index].second;
}
template<class T>
bool BinaryTree<T>::has_child (ChildType child, int index) const {
	check_OOB(index);
	int childIndex = 2 * index + child;
	if (childIndex > tree.size() - 1)
		return false;
	else {
		if (tree[childIndex].first)
			return true;
	}
	return false;
}
template<class T>
int BinaryTree<T>::num_nodes() const { return tree.size(); };

// Helpers
template<class T>
void BinaryTree<T>::check_OOB(const int index) const{
	if (index < 0 || index > (tree.size() - 1))
		throw runtime_error("Index is out of bounds");
}

// Misc Functions
template<class T>
void BinaryTree<T>::printBFS() {
	cout << "{ ";
	for (vector<pair<bool, T>>::iterator itr = tree.begin(); itr != tree.end(); ++itr) {
		if (!itr->first)
			cout << "NULL ";
		else
			cout << itr->second << " ";
	}
	cout << "}\n";
}
