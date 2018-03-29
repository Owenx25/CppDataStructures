#include <iostream>
#include <string>
#include <assert.h>
#include "Array.cpp"

using namespace std;

int main() {
	// Test: Normal Int Array
	// Expect: 1,2,3,4,5
	Array<int> IntArr(5);
	for (int i = 0; i < IntArr.Size(); i++)
	{
		IntArr[i] = i;
		cout << "[" << i << "] = " << IntArr[i] << endl;
	}
	assert(IntArr.Size() == 5);

	// Test: Normal Double Array
	// Expect some big double numbers
	Array<double> DoubArr(20);
	for (int i = 0; i < DoubArr.Size(); i++)
	{
		DoubArr[i] = i * 992012.32142;
		cout << "[" << i << "] = " << DoubArr[i] << endl;
	}	
	assert(DoubArr.Size() == 20);

	// Test: Normal String Array
	// Expect: "1","2","3","4","5"
	Array<string> StringArr(5);
	for (int i = 0; i < 5; i++)
	{
		StringArr[i] = "\"" + to_string(i) + "\"";
		cout << "[" << i << "] = " << StringArr[i] << endl;
	}
	assert(StringArr.Size() == 5);
	
	// Test: Invalid Index Access
	// Expect: 2 Index out of range exceptions
	Array<int> BadArr1(5);
	for (int i = 0; i < 5; i++)
		BadArr1[i] = i;
	try {
		cout << BadArr1[5];
	}
	catch (exception& e) {
		cout << "caught exception: " << e.what() << endl;
	}
	try {
		cout << BadArr1[-3];
	}
	catch (exception& e) {
		cout << "caught exception: " << e.what() << endl;
	}
	

	// Test: Invalid Initialization
	// Expect: Error on compilation
	//Array<int> BadArr2;
	return 0;
}