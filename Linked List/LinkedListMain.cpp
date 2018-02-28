#include <iostream>
#include <string>
#include "LinkedList.cpp"

using namespace std;

template <typename T>
void printList(LinkedList<T> list) {
	cout << "{";
	for (int i = 0; i < list.Get_size(); i++)
		cout << " " << list.Element_at(i) << " ";
	cout << "}\n";
}

int main() {
	// LL<int test>
	LinkedList<int> test;
	cout << "push 1\n";
	test.Push_front(1);
	printList<int>(test);
	cout << "push 2\n";
	test.Push_front(2);
	printList<int>(test);
	cout << "push back 3\n";
	test.Push_back(3);
	printList<int>(test);
	try {
		cout << "Element at [7]: " << test.Element_at(7) << endl;
	} catch(exception e) {
		cout << "Caught exception: " << e.what() << endl;
	}
	cout << "insert 4 at [1]\n";
	test.Insert_at(1, 4);
	printList<int>(test);
	cout << "pop front\n";
	test.Pop_front();
	printList<int>(test);
	cout << "delete element at [1]\n";
	test.Delete_at(1);
	printList<int>(test);
	
	//LL<string> test
	LinkedList<string> test2;
	cout << "Empty? " << test2.Is_empty() << endl;
	test2.Push_back("Owen");
	test2.Push_back("Wilson");
	test2.Push_back("Jocelyn");
	test2.Push_back("Gary");
	test2.Push_back("Estelle");
	test2.Push_back("Bingo");
	printList<string>(test2);
	cout << "Empty? " << test2.Is_empty();
	
	return 0;
}