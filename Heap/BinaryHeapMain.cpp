// Binary Heap Main
#include <iostream>
#include <string>
#include "BinaryHeap.cpp"

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
	
	heap.extract();
	heap.print();
	
	BinaryHeap<int> brokeHeap(MAX, 1, 0);
	brokeHeap.print();
	brokeHeap.extract();
	try {
		brokeHeap.extract();
	}
	catch(exception& e) { cout << "Caught exception: " << e.what() << endl; }
	brokeHeap.print();
	
	return 0;
}