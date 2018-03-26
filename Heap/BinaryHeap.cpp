// Heap Implementation
#include <iostream>
#include <cmath>
#include "..\BinaryTree\ArrayBinaryTree\BinaryTree.cpp"

using namespace std;

enum HeapType { MAX, MIN };

template<class T2>
class HeapNode {
private:
	T2 _data;
	int _key;
public:
	int Key() const { return _key; }
	void Key(const int key) { _key = key; }
	T2 Data() const { return _data; }
	void Data(const T2 data) { _data = data; }
	bool operator==(HeapNode& node) const { return (_data == node.Data()) && (_key == node.Key()); }
	HeapNode(const HeapNode& node) { _data = node.Data(); _key = node.Key(); }
	HeapNode(int key, T2 data) : _data(data), _key(key) {}
	HeapNode() : _data(T2()), _key(NULL) {}
};

template<class T>
class BinaryHeap {
private:
	BinaryTree<HeapNode<T>> tree;
	BinaryHeap();
	void swap(int parentIndex, int childIndex);
	HeapType heapType;
	void max_heapify(int index = 0);
	void min_heapify(int index = 0);
	int find_node_index(HeapNode<T> node);
	int search_tree(HeapNode<T> searchNode, int index = 0); 
public:
	void insert(const int key, const T data);
	HeapNode<T> extract();
	int height();
	void print();
	void modify_key(const HeapNode<T> node, int newKey);
	void modify_key(const int key, const T data, int newKey);
	bool node_exists(const HeapNode<T> node) const;
	bool is_empty() const;
	BinaryHeap(const HeapType heapType);
	BinaryHeap(const HeapType heapType, const int key, const T data);
	BinaryHeap(const HeapType heapType, const HeapNode<T> node);
};

// Constructors
template<class T>
BinaryHeap<T>::BinaryHeap(const HeapType heapType, const int key, const T data) : 
	heapType(heapType), tree(HeapNode<T>(key, data)) {}
	
template<class T>
BinaryHeap<T>::BinaryHeap(const HeapType heapType) : heapType(heapType) {}

template<class T>
BinaryHeap<T>::BinaryHeap(const HeapType heapType, const HeapNode<T> node) : heapType(heapType), tree(node) {}

// Insert
template<class T>
void BinaryHeap<T>::insert(const int key, const T data) {
	HeapNode<T> node = HeapNode<T>(key, data);
	// Can't insert pair that already exists in table
	// if (!node_exists(node))
		// throw runtime_error("Node already in heap");
	if (tree.is_empty()) {
		tree.insert_head(node);
	}
	else {
		int newIndex = tree.insert_in_order(node);
		int parent = floor((newIndex - 1) / 2);
		while ((tree.get_data(parent).Key() < tree.get_data(newIndex).Key() && heapType == MAX) ||
			   (tree.get_data(parent).Key() > tree.get_data(newIndex).Key() && heapType == MIN)) {
			if (newIndex == 0) // We've reached the head
				break;
			swap(parent, newIndex);
			newIndex = parent;
			parent = floor((newIndex - 1) / 2);
		}
	}
}

// Extract
template<class T>
HeapNode<T> BinaryHeap<T>::extract() {
	if (tree.num_nodes() == 0)
		throw runtime_error("Trying to extract empty heap");
	HeapNode<T> oldData = tree.get_data(0);
	tree.set_data(0, tree.get_data(tree.num_nodes() - 1));
	tree.delete_node(tree.num_nodes() - 1);
	//cout << "# Nodes: " << tree.num_nodes() << endl;
	if (heapType == MAX)
		max_heapify();
	else
		min_heapify();
	return oldData;
}

// Both functions below take the head and move
// it to its appropriate spot
template<class T>
void BinaryHeap<T>::max_heapify(int index = 0) {
	int leftIndex = 2 * index + 1;
	int rightIndex = 2 * index + 2;
	int largest = index;
	
	if (tree.has_child(LEFT, index) && tree.get_data(leftIndex).Key() > tree.get_data(largest).Key())
		largest = leftIndex;
	if (tree.has_child(RIGHT, index) && tree.get_data(rightIndex).Key() > tree.get_data(largest).Key())
		largest = rightIndex;
	
	if (largest != index) {
		swap(index, largest);
		min_heapify(largest);
	}
}
template<class T>
void BinaryHeap<T>::min_heapify(int index = 0) {
	int leftIndex = 2 * index + 1;
	int rightIndex = 2 * index + 2;
	int smallest = index;
	
	if (tree.has_child(LEFT, index) && tree.get_data(leftIndex).Key() < tree.get_data(smallest).Key())
		smallest = leftIndex;
	if (tree.has_child(RIGHT, index) && tree.get_data(rightIndex).Key() < tree.get_data(smallest).Key())
		smallest = rightIndex;
	
	if (smallest != index) {
		swap(index, smallest);
		min_heapify(smallest);
	}
}

// Accessor Functions
template<class T>
int BinaryHeap<T>::height() { return tree.height(0); }
template<class T>
void BinaryHeap<T>::print() {
	cout << "{ ";
	for (int i = 0; i <= tree.num_nodes() - 1; ++i) {
		HeapNode<T> node = tree.get_data(i);
		cout << node.Data() << ":" << node.Key() << " ";
	}
	cout << "}\n";
}

template<class T>
bool BinaryHeap<T>::node_exists(const HeapNode<T> node) const {
	return find_node_index(node) != -1;
}

template<class T>
bool BinaryHeap<T>::is_empty() const { return tree.is_empty();}

// Helper Functions
template<class T>
void BinaryHeap<T>::swap(int parentIndex, int childIndex) {
	if (childIndex == (2 * parentIndex + 1) || childIndex == (2 * parentIndex + 2)) {
		HeapNode<T> tempNode = tree.get_data(parentIndex);
		tree.set_data(parentIndex, tree.get_data(childIndex));
		tree.set_data(childIndex, tempNode);
	} else
		throw runtime_error("That's not my kid!");
}

template<class T>
int BinaryHeap<T>::find_node_index(HeapNode<T> node) {
	int currentIndex = 0;
	if (tree.get_data(currentIndex) == node)
			return currentIndex;
	int result = search_tree(node);
	if (result == -1)
		throw runtime_error("key not present in heap");
	return result;
}

template<class T>
int BinaryHeap<T>::search_tree(HeapNode<T> searchNode, int index = 0) {
	if (tree.has_child(LEFT, index)) {
		int left = tree.get_child(index, LEFT);
		HeapNode<T> leftNode = tree.get_data(left);
		if (leftNode == searchNode)
			return left;
		else if ((leftNode.Key() >= searchNode.Key() && heapType == MAX) ||
				 (leftNode.Key() <= searchNode.Key() && heapType == MIN)) {
			int result = search_tree(searchNode, left);
			if (result != -1) { return result; }
		}
	}
	if (tree.has_child(RIGHT, index)) {
		int right = tree.get_child(index, RIGHT);
		HeapNode<T> rightNode = tree.get_data(right);
		if (rightNode == searchNode)
			return right;
		else if ((rightNode.Key() >= searchNode.Key() && heapType == MAX) ||
				 (rightNode.Key() <= searchNode.Key() && heapType == MIN)) {
			int result = search_tree(searchNode, right);
			if (result != -1) { return result; }
		}
	}
	return -1;
}

// Misc functions
template<class T>
void BinaryHeap<T>::modify_key(const HeapNode<T> node, int newKey) {
	int keyIndex = find_node_index(node);
	//cout << "key index is " << keyIndex << endl;
	tree.set_data(keyIndex, HeapNode<T>(newKey, tree.get_data(keyIndex).Data()));
	while (true) {
		if (tree.has_child(LEFT, keyIndex)) {
			int left = tree.get_child(keyIndex, LEFT);
			HeapNode<T> leftNode = tree.get_data(left);
			if ((leftNode.Key() > newKey && heapType == MAX) ||
			    (leftNode.Key() < newKey && heapType == MIN)) {
				swap(keyIndex, left);
				keyIndex = left;
				continue;
		   }
		}
		if (tree.has_child(RIGHT, keyIndex)) {
			int right = tree.get_child(keyIndex, RIGHT);
			HeapNode<T> rightNode = tree.get_data(right);
			if ((rightNode.Key() > newKey && heapType == MAX) ||
			    (rightNode.Key() < newKey && heapType == MIN)) {
				swap(keyIndex, right);
				keyIndex = right;
				continue;
			}
		}
		if (keyIndex != 0) {
			//every node has parent except for root
			int parent = floor((keyIndex - 1) / 2);
			HeapNode<T> parentNode = tree.get_data(parent);
			if ((parentNode.Key() < newKey && heapType == MAX) ||
			    (parentNode.Key() > newKey && heapType == MIN)) {
				swap(parent, keyIndex);
				keyIndex = parent;
				continue;
			}
		}
		return;
	}
}

template<class T>
void BinaryHeap<T>::modify_key(const int key, const T data, int newKey) {
	modify_key(HeapNode<T>(key, data), newKey);
}