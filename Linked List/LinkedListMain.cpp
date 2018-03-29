#include <iostream>
#include <string>
#include <assert.h>
#include "LinkedList.cpp"

using namespace std;

template <typename T>
void printList(LinkedList<T> list) {
	cout << "{";
	for (int i = 0; i < list.size(); i++)
		cout << " " << list.at(i) << " ";
	cout << "}\n";
}

int main() {
	// LL<int test>
	LinkedList<int> test;
	cout << "push 1\n";
	test.push_front(1);
	printList<int>(test);
	cout << "push 2\n";
	test.push_front(2);
	printList<int>(test);
	cout << "push back 3\n";
	test.push_back(3);
	printList<int>(test);
	try {
		cout << "Element at [7]: " << test.at(7) << endl;
	} catch(exception e) {
		cout << "Caught exception: " << e.what() << endl;
	}
	cout << "insert 4 at [1]\n";
	test.insert_at(1, 4);
	assert(test.at(1) == 4);
	printList<int>(test);
	cout << "pop front\n";
	test.pop_front();
	assert(test.at(0) == 4);
	printList<int>(test);
	cout << "delete element at [1]\n";
	test.delete_at(1);
	printList<int>(test);
	
	//LL<string> test
	LinkedList<string> test2;
	assert(test2.is_empty() == true);
	test2.push_back("Owen");
	test2.push_back("Wilson");
	test2.push_back("Jocelyn");
	test2.push_back("Gary");
	test2.push_back("Estelle");
	test2.push_back("Bingo");
	printList<string>(test2);
	assert(test2.size() == 6);
	assert(test2.is_empty() == false);
	
	return 0;
}