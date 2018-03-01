// Stack
#include <iostream>
#include <string>
#include "Stack.cpp"

using namespace std;

int main() {
	Stack<int> stack;
	
	stack.Push(1);
	cout << "--> Push 1" << endl;
	stack.Push(25);
	cout << "--> Push 25" << endl;
	stack.Push(69);
	cout << "--> Push 69" << endl;
	cout << "Peek: " << stack.Peek() << endl;
	cout << "Pop: " << stack.Pop() << endl;
	cout << "Pop: " << stack.Pop() << endl;
	cout << "Pop: " << stack.Pop() << endl;
	cout << "Size: " << stack.Get_size() << endl;
	try {
		stack.Pop();
	} catch (exception& e) {
		cout << "Caught exception: " << e.what() << endl;
	}
	
	return 0;
}