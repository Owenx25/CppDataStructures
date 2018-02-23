#include <iostream>
#include "Array.cpp"

int main() {
	Array<int> Test(5);

	for (int i = 0; i < 5; i++)
	{
		Test[i] = i;
		cout << "[" << i << "] = " << Test[i] << endl;
	}

	return 0;
}