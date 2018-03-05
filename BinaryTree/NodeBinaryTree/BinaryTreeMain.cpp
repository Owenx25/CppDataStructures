// Binary Tree Test
#include <iostream>
#include <string>
#include "BinaryTree.cpp"

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
	cout << "Post-order: \t{ ";myTree.Print_post_order(root); cout << "}\n\nString Test:\n\n";
	
	Node<string>* root2 = new Node<string>("FPS");
	BinaryTree<string> myTree2(root2);
	myTree2.Insert_left(root2, "ARMA");
	myTree2.Insert_right(root2, "HALF LIFE");
	myTree2.Insert_left(root2->childLeft, "BATTLGROUNDS");
	myTree2.Insert_right(root2->childLeft, "SQUAD");
	myTree2.Insert_right(root2->childRight, "PREY");
	myTree2.Insert_left(root2->childRight, "DEUS EX");
	
	cout << "Pre-order: \t{ ";myTree2.Print_pre_order(root2); cout << "}\n";
	cout << "In-order: \t{ ";myTree2.Print_in_order(root2); cout << "}\n";
	cout << "Post-order: \t{ ";myTree2.Print_post_order(root2); cout << "}\n";
	
	myTree2.Delete_node(root2->childRight->childLeft);
	
	cout << "\nPre-order: \t{ ";myTree2.Print_pre_order(root2); cout << "}\n";
	cout << "In-order: \t{ ";myTree2.Print_in_order(root2); cout << "}\n";
	cout << "Post-order: \t{ ";myTree2.Print_post_order(root2); cout << "}\n";
	
	myTree2.Insert_left(root2->childRight, "DEUS EX");
	myTree2.Insert_left(root2->childRight->childLeft, "DISHONORED");
	myTree2.Delete_node(root2->childRight->childLeft);
	
	cout << "\nPre-order: \t{ ";myTree2.Print_pre_order(root2); cout << "}\n";
	cout << "In-order: \t{ ";myTree2.Print_in_order(root2); cout << "}\n";
	cout << "Post-order: \t{ ";myTree2.Print_post_order(root2); cout << "}\n";
	
	return 0;
}