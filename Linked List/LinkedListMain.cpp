#include <iostream>
#include "LinkedList.cpp"

using namespace std;

void printList(LinkedList<int> list) {
	cout << "{";
	for (int i = 0; i < list.Get_size(); i++)
		cout << " " << list.Element_at(i) << " ";
	cout << "}\n";
}

int main() {
	LinkedList<int> test;
	cout << "push 1\n";
	test.Push_front(1);
	printList(test);
	cout << "push 2\n";
	test.Push_front(2);
	printList(test);
	cout << "push back 3\n";
	test.Push_back(3);
	printList(test);
	try {
		cout << "Element at [7]: " << test.Element_at(7) << endl;
	} catch(exception e) {
		cout << "Caught exception: " << e.what() << endl;
	}
	cout << "insert 4 at [1]\n";
	test.Insert_at(1, 4);
	printList(test);
	cout << "pop front\n";
	test.Pop_front();
	printList(test);
	cout << "delete element at [1]\n";
	test.Delete_at(1);
	printList(test);
	
	return 0;
}