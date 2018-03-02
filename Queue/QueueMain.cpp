// Queue Tests

#include "Queue.cpp"
#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

int main () {
	// Int Test
	Queue<int> test;
	
	test.Enqueue(11);
	test.Enqueue(22);
	test.Enqueue(33);
	test.Enqueue(44);
	test.Enqueue(55);
	assert(test.Get_size() == 5);
	assert(test.Front() == 11);
	assert(test.Back() == 55);
	test.Dequeue();
	test.Dequeue();
	assert(test.Get_size() == 3);
	assert(test.Front() == 33);
	assert(test.Back() == 55);
	
	cout << test;
	
	// String test
	Queue<string> test2;
	
	test2.Enqueue("a");
	test2.Enqueue("b");
	test2.Enqueue("c");
	test2.Enqueue("d");
	assert(test2.Front() == "a");
	assert(test2.Back() == "d");
	test2.Dequeue();
	assert(test2.Front() == "b");
	assert(test2.Back() == "d");
	assert(!test2.Is_empty());
	cout << test2;
	
	return 0;
}