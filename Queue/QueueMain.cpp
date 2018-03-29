// Queue Tests

#include "Queue.cpp"
#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

int main () {
	// Int Test
	Queue<int> test;
	
	test.enqueue(11);
	test.enqueue(22);
	test.enqueue(33);
	test.enqueue(44);
	test.enqueue(55);
	assert(test.size() == 5);
	assert(test.front() == 11);
	assert(test.back() == 55);
	test.dequeue();
	test.dequeue();
	assert(test.size() == 3);
	assert(test.front() == 33);
	assert(test.back() == 55);
	cout << test;
	
	// String test
	Queue<string> test2;
	
	test2.enqueue("a");
	test2.enqueue("b");
	test2.enqueue("c");
	test2.enqueue("d");
	assert(test2.front() == "a");
	assert(test2.back() == "d");
	test2.dequeue();
	assert(test2.front() == "b");
	assert(test2.back() == "d");
	assert(!test2.is_empty());
	cout << test2;
	
	return 0;
}