#include <iostream>
#include <string>
#include "Array.cpp"

using namespace std;

int main() {
	// Int Array
	Array<int> IntArr(5);

	for (int i = 0; i < IntArr.get_size(); i++)
	{
		IntArr[i] = i;
		cout << "[" << i << "] = " << IntArr[i] << endl;
	}
	// Expect 1,2,3,4,5

	cout << endl;

	// Double Array
	Array<double> DoubArr(20);
	for (int i = 0; i < DoubArr.get_size(); i++)
	{
		try {
			DoubArr[i] = i * 992012.32142;
			if (DoubArr[i] != 992012.32142 * i)
				throw "double size off";
		}
		catch (exception e)
		{
			cout << "caught exception: " << e.what();
		}
		cout << "[" << i << "] = " << DoubArr[i] << endl;
	}
	// Expect some big double numbers

	cout << endl;

	// String Array
	Array<string> StringArr(5);

	for (int i = 0; i < 5; i++)
	{
		StringArr[i] = "\"" + to_string(i) + "\"";
		cout << "[" << i << "] = " << StringArr[i] << endl;
	}
	// Expect "1","2","3","4","5"

	cout << endl;

	// Invalid Initialization
	try {
		Array<int> BadArr;
	}
	catch (...) {
		cout << "caught exception" << endl;
		exit(1);
	}
	//Expect catch

	return 0;
}