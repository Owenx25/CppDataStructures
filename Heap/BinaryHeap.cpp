// Heap Implementation
#include <iostream>
#include <cmath>
#include "..\BinaryTree\ArrayBinaryTree\BinaryTree.cpp"

using namespace std;

enum HeapType { MAX, MIN };

template<class T>
class BinaryHeap {
private:
	BinaryTree<pair<int, T>> tree;
	BinaryHeap();
	void swap(int parentIndex, int childIndex);
	HeapType heapType;
	void max_heapify(int index = 0);
	void min_heapify(int index = 0);
	int get_index(int key);
	int find_key(int key, int index = 0); 
public:
	void insert(int key, T data);
	T extract();
	int height();
	void print();
	void modify_key(int key, int newKey);
	bool is_empty() const;
	BinaryHeap(const HeapType heapType);
	BinaryHeap(const HeapType heapType, const int key,const T data);
};

// Constructors
template<class T>
BinaryHeap<T>::BinaryHeap(const HeapType heapType, const int key, const T data) : 
	heapType(heapType), tree(make_pair(key,data)) {}
	
template<class T>
BinaryHeap<T>::BinaryHeap(const HeapType heapType) : heapType(heapType) {}

// Insert
template<class T>
void BinaryHeap<T>::insert(int key, T data) {
	if (tree.is_empty()) {
		tree.insert_head(make_pair(key, data));
	}
	else {
		int newIndex = tree.insert_in_order(make_pair(key, data));
		int parent = floor((newIndex - 1) / 2);
		while ((tree.get_data(parent).first < tree.get_data(newIndex).first && heapType == MAX) ||
			   (tree.get_data(parent).first > tree.get_data(newIndex).first && heapType == MIN)) {
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
T BinaryHeap<T>::extract() {
	if (tree.num_nodes() == 0)
		throw runtime_error("Trying to extract empty heap");
	const T oldData = tree.get_data(0).second;
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
	for (int i = 0; i <= tree.num_nodes() - 1; ++i)
		cout << tree.get_data(i).first << ":" << tree.get_data(i).second << " ";
	cout << "}\n";
}

template<class T>
bool BinaryHeap<T>::is_empty() const { return tree.is_empty();}

// Helper Functions
template<class T>
void BinaryHeap<T>::swap(int parentIndex, int childIndex) {
	if (childIndex == (2 * parentIndex + 1) || childIndex == (2 * parentIndex + 2)) {
		pair<int, T> dataTemp = tree.get_data(parentIndex);
		tree.set_data(parentIndex, tree.get_data(childIndex));
		tree.set_data(childIndex, dataTemp);
	} else
		throw runtime_error("That's not my kid!");
}

template<class T>
int BinaryHeap<T>::get_index(int key) {
	int currentIndex = 0;
	if (tree.get_data(currentIndex).first == key)
			return currentIndex;
	int result = find_key(key);
	if (result == -1)
		throw runtime_error("key not present in heap");
	return result;
}

template<class T>
int BinaryHeap<T>::find_key(int key, int index = 0) {
	if (tree.has_child(LEFT, index)) {
		//cout << "checked left\n";
		int left = tree.get_child(index, LEFT);
		if (tree.get_data(left).first == key)
			return left;
		else if ((tree.get_data(left).first > key && heapType == MAX) ||
				(tree.get_data(left).first < key && heapType == MIN)) {
			int result = find_key(key, left);
			if (result != -1) { return result; }
		}
	}
	if (tree.has_child(RIGHT, index)) {
		//cout << "checked right\n";
		int right = tree.get_child(index, RIGHT);
		if (tree.get_data(right).first == key)
			return right;
		else if ((tree.get_data(right).first > key && heapType == MAX) ||
				(tree.get_data(right).first < key && heapType == MIN)) {
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
	tree.set_data(keyIndex, make_pair(newKey, tree.get_data(keyIndex).second));
	while (true) {
		if (tree.has_child(LEFT, keyIndex)) {
			int left = tree.get_child(keyIndex, LEFT);
			if ((tree.get_data(left).first > newKey && heapType == MAX) ||
			   (tree.get_data(left).first < newKey && heapType == MIN)) {
				swap(keyIndex, left);
				keyIndex = left;
				continue;
		   }
		}
		if (tree.has_child(RIGHT, keyIndex)) {
			int right = tree.get_child(keyIndex, RIGHT);
			if ((tree.get_data(right).first > newKey && heapType == MAX) ||
			   (tree.get_data(right).first < newKey && heapType == MIN)) {
				swap(keyIndex, right);
				keyIndex = right;
				continue;
			}
		}
		if (keyIndex != 0) {
			//every node has parent except for root
			int parent = floor((keyIndex - 1) / 2);
			if ((tree.get_data(parent).first < newKey && heapType == MAX) ||
			   (tree.get_data(parent).first > newKey && heapType == MIN)) {
				swap(parent, keyIndex);
				keyIndex = parent;
				continue;
			}
		}
		return;
	}
}