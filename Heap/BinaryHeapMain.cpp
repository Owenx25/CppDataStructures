// Binary Heap Main
#include <iostream>
#include <string>
#include "BinaryHeap.cpp"
#include <assert.h>

using namespace std;

int main() {
	BinaryHeap<string> heap(MAX, 1, "a");
	heap.insert(2, "b");
	heap.insert(3, "c");
	heap.insert(4, "d");
	heap.insert(5, "e");
	heap.insert(6, "f");
	heap.insert(7, "g");
	heap.insert(8, "h");
	heap.insert(9, "i");
	heap.insert(10, "j");
	heap.insert(11, "k");
	heap.insert(12, "l");
	heap.insert(13, "m");
	heap.insert(14, "n");
	heap.insert(15, "o");
	heap.insert(16, "p");
	heap.insert(17, "q");
	heap.insert(18, "r");
	heap.insert(19, "s");
	heap.insert(20, "t");
	heap.insert(21, "u");
	heap.insert(22, "v");
	heap.insert(23, "w");
	heap.insert(24, "x");
	heap.insert(25, "y");
	heap.insert(26, "z");
	heap.print();
	
	assert(heap.extract().Data() == "z");
	heap.print();
	
	BinaryHeap<int> brokeHeap(MAX, 1, 0);
	brokeHeap.print();
	assert(brokeHeap.extract().Data() == 0);
	try {
		brokeHeap.extract();
	}
	catch(exception& e) { cout << "Caught exception: " << e.what() << endl; }
	brokeHeap.print();	
	try {
		cout << "\nAdding to Empty Heap:\n";
		BinaryHeap<int> brokeHeap(MIN);
		brokeHeap.print();
		assert(brokeHeap.is_empty());
		brokeHeap.insert(1, 25);
		brokeHeap.insert(6, 35);
		brokeHeap.insert(2, 5);
		brokeHeap.insert(10, 205);
		brokeHeap.insert(23, 7);
		assert(!brokeHeap.is_empty());
		brokeHeap.print();
		brokeHeap.modify_key(23, 7, 5);
		brokeHeap.print();
	}
	catch(exception& e) { cout << "Caught exception: " << e.what() << endl; }
	
	try {
		cout << "\nAdding data with the same key:\n";
		BinaryHeap<int> newHeap(MAX);
		newHeap.insert(25, 0);
		newHeap.insert(11, 1);
		newHeap.insert(11, 2);
		newHeap.print();
		newHeap.insert(10, 3);
		newHeap.print();
	}
	catch(exception& e) { cout << "Caught exception: " << e.what() << endl; }
	
	return 0;
}