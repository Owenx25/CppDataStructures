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
	void shift_subtree_down(const int root, vector<tuple<int, T, ChildType>>& subtree_data, int index);
	vector<tuple<int, T, ChildType>>& get_subtree_data(const int root, vector<tuple<int, T, ChildType>>& subtree_data);
public:
	BinaryTree(const T Data);
	void insert_between(const int parent, const ChildType child, const T data);
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
void BinaryTree<T>::insert_between(const int parent, const ChildType child, const T data) {
	check_OOB(parent);
	int childIndex = 2 * parent + child;
	check_OOB(childIndex);
	T childData = tree[childIndex].second;
	vector<tuple<int, T, ChildType>> sub_data;
	sub_data.push_back(make_tuple(childIndex, tree[childIndex].second, LEFT));
	shift_subtree_down(childIndex, get_subtree_data(childIndex, sub_data), 0);
	tree[childIndex].second = data;
}
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
	bool left = hasChild(LEFT, delIndex);
	bool right = hasChild(RIGHT, delIndex);
	// 3 Cases
	if (left && right) {
		// Two children
		throw runtime_error("Ambiguous deletion");
	} else if (left && !right) {
		// One Child => see comment below
		int childIndex = get_child(delIndex, Left);
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
	return tree[index];
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
template<class T>
vector<tuple<int, T, ChildType>>& BinaryTree<T>::get_subtree_data(const int root, vector<tuple<int, T, ChildType>>& subtree_data) {
	check_OOB(root);
	if (has_child(LEFT, root)) {
		int childLeft = get_child(root, LEFT);
		subtree_data.push_back(make_tuple(childLeft, tree[childLeft].second, LEFT));
		get_subtree_data(childLeft, subtree_data);
	}
	if(has_child(RIGHT, root)) {
		int childRight = get_child(root, RIGHT);
		subtree_data.push_back(make_tuple(childRight, tree[childRight].second, RIGHT));
		get_subtree_data(childRight, subtree_data);
	}
	
	return subtree_data;
}
template<class T>
void BinaryTree<T>::shift_subtree_down(const int root, vector<tuple<int, T, ChildType>>& subtree_data, int index) {
	//Index should start at 1
	for (vector<tuple<int, T, ChildType>>::iterator itr = subtree_data.begin(); itr != subtree_data.end(); ++itr) {
		
		int newIndex = 2 * get<0>(*itr);
		if (get<2>(*itr) == LEFT)
			newIndex += 1;
		else
			newIndex -= 1;
		while (newIndex > tree.size() - 1) {
			//cout << "stuck on cell add?\n";
			tree.push_back(pair<bool, T>(false, T()));
		}
		tree[newIndex] = make_pair(true, get<1>(*itr)); 
	}
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
