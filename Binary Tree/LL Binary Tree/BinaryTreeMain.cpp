// Binary Tree Test
#include <iostream>
#include "LLBinaryTree.cpp"

using namespace std;

int main() {
	Node<int>* root = new Node<int>(0);
	BinaryTree<int> myTree(root);
	myTree.Insert_left(root, 1);
	myTree.Insert_right(root, 2);
	myTree.Insert_left(root->childLeft, 3);
	myTree.Insert_right(root->childLeft, 4);
	myTree.Insert_right(root->childRight, 5);
	myTree.Insert_left(root->childRight, 99);
	
	cout << "Pre-order: \t{ ";myTree.Print_pre_order(root); cout << "}\n";
	cout << "In-order: \t{ ";myTree.Print_in_order(root); cout << "}\n";
	cout << "Post-order: \t{ ";myTree.Print_post_order(root); cout << "}\n";
	
	myTree.Delete_node(root->childRight->childLeft);
	
	cout << "\nPre-order: \t{ ";myTree.Print_pre_order(root); cout << "}\n";
	cout << "In-order: \t{ ";myTree.Print_in_order(root); cout << "}\n";
	cout << "Post-order: \t{ ";myTree.Print_post_order(root); cout << "}\n";
	
	myTree.Insert_left(root->childRight, 99);
	myTree.Insert_left(root->childRight->childLeft, 66);
	myTree.Delete_node(root->childRight->childLeft);
	
	cout << "\nPre-order: \t{ ";myTree.Print_pre_order(root); cout << "}\n";
	cout << "In-order: \t{ ";myTree.Print_in_order(root); cout << "}\n";
	cout << "Post-order: \t{ ";myTree.Print_post_order(root); cout << "}\n";
	
	return 0;
}