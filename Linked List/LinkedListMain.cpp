#include <iostream>
#include "LinkedList.cpp"

using namespace std;

int main() {
	LinkedList<int> test;
	cout << "Size before: " << test.Get_size() << endl;
	int data = 1;
	test.Push_front(1);
	cout << "Size after: " << test.Get_size() << endl;
	cout << "Front: " << test.Front() << endl;
	
	
	return 0;
}