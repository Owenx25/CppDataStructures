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
	int insertIndex;
	void swap(int parentIndex, int childIndex);
	HeapType heapType;
	void max_heapify(int index);
	void min_heapify(int index);
public:
	void insert(int key, T data);
	void extract();
	int height();
	void print();
	BinaryHeap(const HeapType heapType, const int key,const T data);
};

// Constructors
template<class T>
BinaryHeap<T>::BinaryHeap(const HeapType heapType, const int key, const T data) : 
	heapType(heapType), tree(make_pair(key,data)), insertIndex(1) {}

// Insert
template<class T>
void BinaryHeap<T>::insert(int key, T data) {
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

// Extract
template<class T>
void BinaryHeap<T>::extract() {
	if (tree.num_nodes() == 0)
		throw runtime_error("Trying to extract empty heap");
	tree.set_data(0, tree.get_data(tree.num_nodes() - 1));
	tree.delete_node(tree.num_nodes() - 1);
	if (heapType == MAX)
		max_heapify(0);
	else
		min_heapify(0);
}
template<class T>
void BinaryHeap<T>::max_heapify(int index) {
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
void BinaryHeap<T>::min_heapify(int index) {
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
