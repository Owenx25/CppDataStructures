// Stack
#include <iostream>
#include <string>
#include "LLStack.cpp"

using namespace std;

int main() {
	Stack<int> stack;
	
	stack.push(1);
	cout << "--> Push 1" << endl;
	stack.push(25);
	cout << "--> Push 25" << endl;
	stack.push(69);
	cout << "--> Push 69" << endl;
	cout << "Peek: " << stack.peek() << endl;
	cout << "Pop: " << stack.pop() << endl;
	cout << "Pop: " << stack.pop() << endl;
	cout << "Pop: " << stack.pop() << endl;
	cout << "Size: " << stack.size() << endl;
	try {
		stack.pop();
	} catch (exception& e) {
		cout << "Caught exception: " << e.what() << endl;
	}
	
	return 0;
}