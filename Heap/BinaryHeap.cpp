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
	T2 Data() const { return _name; }
	void Data(const T2 data) { _data = data; }
	
	HeapNode(T2 data, int key) : _data(data), _key(key) {} 
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
	int get_index(int key);
	int find_key(int key, int index = 0); 
public:
	void insert(HeapNode<T> newNode);
	HeapNode<T> extract();
	int height();
	void print();
	void modify_key(int key, int newKey);
	bool is_empty() const;
	BinaryHeap(const HeapType heapType);
	BinaryHeap(const HeapType heapType, const HeapNode<T> heapNode);
};

// Constructors
template<class T>
BinaryHeap<T>::BinaryHeap(const HeapType heapType, const HeapNode<T> node) : 
	heapType(heapType), tree(node) {}
	
template<class T>
BinaryHeap<T>::BinaryHeap(const HeapType heapType) : heapType(heapType) {}

// Insert
template<class T>
void BinaryHeap<T>::insert(const HeapNode<T> node) {
	// Can't insert pair that already exists in table
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
	const HeapNode<T> oldData = tree.get_data(0);
	tree.set_data(0, tree.get_data(tree.num_nodes() - 1));
	tree.delete_node(tree.num_nodes() - 1);
	if (heapType == MAX)
		max_heapify();
	else
		min_heapify();
	return oldData;
}
template<class T>
void BinaryHeap<T>::max_heapify(int index = 0) {
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int largest = index;
	
	if (left <= tree.num_nodes() && tree.get_data(left).first > tree.get_data(largest).first)
		largest = left;
	if (right <= tree.num_nodes() && tree.get_data(right).first > tree.get_data(largest).first)
		largest = right;
	
	if (largest != index) {
		swap(index, largest);
		max_heapify(largest);
	}
}
template<class T>
void BinaryHeap<T>::min_heapify(int index = 0) {
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int smallest = index;
	
	if (left <= tree.num_nodes() && tree.get_data(left).first < tree.get_data(smallest).first)
		smallest = left;
	if (right <= tree.num_nodes() && tree.get_data(right).first < tree.get_data(smallest).first)
		smallest = right;
	
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
bool BinaryHeap<T>::is_empty() const { return tree.is_empty();}

// Helper Functions
template<class T>
void BinaryHeap<T>::swap(int parentIndex, int childIndex) {
	if (childIndex == (2 * parentIndex + 1) || childIndex == (2 * parentIndex + 2)) {
		const HeapNode<T> tempNode = tree.get_data(parentIndex);
		tree.set_data(parentIndex, tree.get_data(childIndex));
		tree.set_data(childIndex, tempNode);
	} else
		throw runtime_error("That's not my kid!");
}

template<class T>
int BinaryHeap<T>::get_index(int key) {
	int currentIndex = 0;
	if (tree.get_data(currentIndex).Key() == key)
			return currentIndex;
	int result = find_key(key);
	if (result == -1)
		throw runtime_error("key not present in heap");
	return result;
}

template<class T>
int BinaryHeap<T>::find_key(int key, int index = 0) {
	if (tree.has_child(LEFT, index)) {
		int left = tree.get_child(index, LEFT);
		HeapNode<T> node = tree.get_data(left);
		if (node.Key() == key)
			return left;
		else if ((node.Key() > key && heapType == MAX) ||
				 (node.Key() < key && heapType == MIN)) {
			int result = find_key(key, left);
			if (result != -1) { return result; }
		}
	}
	if (tree.has_child(RIGHT, index)) {
		int right = tree.get_child(index, RIGHT);
		HeapNode<T> node = tree.get_data(right);
		if (node.Key() == key)
			return right;
		else if ((node.Key() > key && heapType == MAX) ||
				(node.Key() < key && heapType == MIN)) {
			int result = find_key(key, right);
			if (result != -1) { return result; }
		}
	}
	return -1;
}

// Misc functions
template<class T>
void BinaryHeap<T>::modify_key(int key, int newKey) {
	int keyIndex = get_index(key);
	cout << "key index is " << keyIndex << endl;
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