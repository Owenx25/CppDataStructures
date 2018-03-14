// Binary Tree Test
#include <iostream>
#include <string>
#include "BinaryTree.cpp"

using namespace std;

int main() {
	BinaryTree<int> tree(1);

	try {
		// Inserting Children
		tree.insert_child(LEFT, 2, 0);
		tree.insert_child(RIGHT, 3, 0);
		tree.insert_child(LEFT, 4, 1);
		tree.insert_child(RIGHT, 5, 1);
		tree.insert_child(LEFT, 6, 2);
		tree.insert_child(RIGHT, 7, 2);
		tree.insert_child(LEFT, 8, 3);
		
		tree.printBFS();
		
		// Inserting between two nodes
		tree.insert_between(0, LEFT, 0);
		tree.printBFS();
	} 
	catch(exception& e) {
		cout << "Caught exception: " << e.what() << endl;
	}
	
	
	
	return 0;
}