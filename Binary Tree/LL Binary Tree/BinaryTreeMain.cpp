// Binary Tree Test
#include <iostream>
#include "LLBinaryTree.cpp"

using namespace std;

int main() {
	BinaryTree<int> myTree(new Node<int>(0));
	myTree.Insert_left(myTree.root, 1);
	myTree.Insert_right(myTree.root, 2);
	
	cout << "Root: " << myTree.root->data << endl; 
	cout << "L Child: " << myTree.root->childLeft->data << endl; 
	cout << "R Child: " << myTree.root->childRight->data << endl; 
	
	
	return 0;
}