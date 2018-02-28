#include <iostream>
#include "LinkedList.cpp"

using namespace std;

int main() {
	LinkedList<int> test;
	cout << "Size before anything: " << test.Get_size() << endl;
	int data = 1;
	test.Push_front(1);
	cout << "Size after pushing {1}: " << test.Get_size() << endl;
	cout << "Front: " << test.Front() << endl;
	test.Push_front(2);
	cout << "Size after pushing front {2}: " << test.Get_size() << endl;
	test.Push_back(3);
	cout << "Front: " << test.Front() << endl;
	cout << "Size after pushing back {3}: " << test.Get_size() << endl;
	cout << "Front: " << test.Front() << endl;
	cout << "Element at [2]: " << test.Element_at(2) << endl;
	try {
		cout << "Element at [7]: " << test.Element_at(7) << endl;
	} catch(exception e) {
		cout << "Caught exception: " << e.what() << endl;
	}
	
	
	return 0;
}