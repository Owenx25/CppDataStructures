// Binary Tree Test
#include <iostream>
#include <string>
#include "BinaryTree.cpp"

using namespace std;

int main() {
	TreeNode<int>* root = new TreeNode<int>(0);
	BinaryTree<int> myTree(root);
	myTree.Insert_left(root, 1);
	myTree.Insert_right(root, 2);
	myTree.Insert_left(root->childLeft, 3);
	myTree.Insert_right(root->childLeft, 4);
	myTree.Insert_right(root->childRight, 5);
	myTree.Insert_left(root->childRight, 99);
	
	LinkedList<int>* preList = myTree.Get_pre_order();
	LinkedList<int>* inList = myTree.Get_in_order();
	LinkedList<int>* postList = myTree.Get_post_order();
	cout << "PreOrder: { ";
	for (int i = 0; i < preList->size(); i++)
		cout << preList->at(i) << " ";
	cout << "}\n";
	cout << "inOrder: { ";
	for (int i = 0; i < inList->size(); i++)
		cout << inList->at(i) << " ";
	cout << "}\n";
	cout << "PostOrder: { ";
	for (int i = 0; i < postList->size(); i++)
		cout << postList->at(i) << " ";
	cout << "}\n\n";
	
	myTree.Delete_TreeNode(root->childRight->childLeft);
	
	preList = myTree.Get_pre_order();
	inList = myTree.Get_in_order();
	postList = myTree.Get_post_order();
	cout << "PreOrder: { ";
	for (int i = 0; i < preList->size(); i++)
		cout << preList->at(i) << " ";
	cout << "}\n";
	cout << "inOrder: { ";
	for (int i = 0; i < inList->size(); i++)
		cout << inList->at(i) << " ";
	cout << "}\n";
	cout << "PostOrder: { ";
	for (int i = 0; i < postList->size(); i++)
		cout << postList->at(i) << " ";
	cout << "}\n\n";
	
	myTree.Insert_left(root->childRight, 99);
	myTree.Insert_left(root->childRight->childLeft, 66);
	myTree.Delete_TreeNode(root->childRight->childLeft);
	
	preList = myTree.Get_pre_order();
	inList = myTree.Get_in_order();
	postList = myTree.Get_post_order();
	cout << "PreOrder: { ";
	for (int i = 0; i < preList->size(); i++)
		cout << preList->at(i) << " ";
	cout << "}\n";
	cout << "inOrder: { ";
	for (int i = 0; i < inList->size(); i++)
		cout << inList->at(i) << " ";
	cout << "}\n";
	cout << "PostOrder: { ";
	for (int i = 0; i < postList->size(); i++)
		cout << postList->at(i) << " ";
	cout << "}\n\n";
	
	TreeNode<string>* root2 = new TreeNode<string>("FPS");
	BinaryTree<string> myTree2(root2);
	myTree2.Insert_left(root2, "ARMA");
	myTree2.Insert_right(root2, "HALF-LIFE");
	myTree2.Insert_left(root2->childLeft, "BATTLGROUNDS");
	myTree2.Insert_right(root2->childLeft, "SQUAD");
	myTree2.Insert_right(root2->childRight, "PREY");
	myTree2.Insert_left(root2->childRight, "DEUS-EX");
	
	LinkedList<string>* preList2 = myTree2.Get_pre_order();
	LinkedList<string>* inList2 = myTree2.Get_in_order();
	LinkedList<string>* postList2 = myTree2.Get_post_order();
	cout << "PreOrder: { ";
	for (int i = 0; i < preList2->size(); i++)
		cout << preList2->at(i) << " ";
	cout << "}\n";
	cout << "inOrder: { ";
	for (int i = 0; i < inList2->size(); i++)
		cout << inList2->at(i) << " ";
	cout << "}\n";
	cout << "PostOrder: { ";
	for (int i = 0; i < postList2->size(); i++)
		cout << postList2->at(i) << " ";
	cout << "}\n\n";
	
	myTree2.Delete_TreeNode(root2->childRight->childLeft);

	preList2 = myTree2.Get_pre_order();
	inList2 = myTree2.Get_in_order();
	postList2 = myTree2.Get_post_order();
	cout << "PreOrder: { ";
	for (int i = 0; i < preList2->size(); i++)
		cout << preList2->at(i) << " ";
	cout << "}\n";
	cout << "inOrder: { ";
	for (int i = 0; i < inList2->size(); i++)
		cout << inList2->at(i) << " ";
	cout << "}\n";
	cout << "PostOrder: { ";
	for (int i = 0; i < postList2->size(); i++)
		cout << postList2->at(i) << " ";
	cout << "}\n\n";
	
	myTree2.Insert_left(root2->childRight, "DEUS-EX");
	myTree2.Insert_left(root2->childRight->childLeft, "DISHONORED");
	myTree2.Delete_TreeNode(root2->childRight->childLeft);

	preList2 = myTree2.Get_pre_order();
	inList2 = myTree2.Get_in_order();
	postList2 = myTree2.Get_post_order();
	cout << "PreOrder: { ";
	for (int i = 0; i < preList2->size(); i++)
		cout << preList2->at(i) << " ";
	cout << "}\n";
	cout << "inOrder: { ";
	for (int i = 0; i < inList2->size(); i++)
		cout << inList2->at(i) << " ";
	cout << "}\n";
	cout << "PostOrder: { ";
	for (int i = 0; i < postList2->size(); i++)
		cout << postList2->at(i) << " ";
	cout << "}\n\n";
	
	return 0;
}