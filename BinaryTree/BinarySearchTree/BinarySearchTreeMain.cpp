// BST Tests
#include <iostream>
#include <string>
#include "BinarySearchTree.cpp"
#include <assert.h>

using namespace std;

int main() {
	// BSTs use an int key and T value Pair
	// In this case T = string
	BST<string> BST(10, "Faith");
	BST.Insert(7, "Ezio");
	BST.Insert(3, "Aloy");
	BST.Insert(8, "Moira");
	BST.Insert(12, "Geralt");
	BST.Insert(11, "Joel");
	BST.Insert(15, "Bayek");
	BST.Insert(13, "David");
	
	// Have to search by key
	assert(BST.Search(13)->data.second == "David");
	assert(BST.Search(8)->data.second == "Moira");
	assert(BST.Search(12)->data.second == "Geralt");
	try { BST.Search(16); }
	catch (exception& e) {
		cout << "Caught exception: " << e.what() << endl;
	}
	BST.List_in_order();
	
	
	return 0;
}