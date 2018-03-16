// Graph main
#include <iostream>
#include <string>
#include <vector>
#include "AdjacencyMatrix.cpp"

using namespace std;

int main() {
	try {
		vector<string> names;
		names.push_back("Abby");
		names.push_back("Ben");
		names.push_back("Carl");
		names.push_back("Daniel");
		names.push_back("Edward");
		Graph<string> test(names, false);
	} catch (exception& e) {
		cout << "Caught exception: " << e.what() << endl;
	}

	return 0;
}