// Graph main
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include "Adjacency Matrix\AdjacencyMatrix.cpp"

using namespace std;

void write_list(string vertex, string operationName, vector<string> list) {
	cout << vertex << "'s " + operationName + ": { ";
	for (int i = 0; i < list.size(); i++)
		cout << list.at(i) << " ";
	cout << "}\n";
}

int main() {
	try {
		// Create Vertices
		vector<string> names;
		names.push_back("Abby");
		names.push_back("Ben");
		names.push_back("Carl");
		names.push_back("Daniel");
		names.push_back("Edward");
		// Setup Graph
		Graph<string> test(names, false);
		test.add_edge("Abby", "Ben", 1);
		test.add_edge("Ben", "Daniel", 2);
		test.add_edge("Daniel", "Edward", 3);
		test.add_edge("Edward", "Carl", 4);
		test.add_edge("Carl", "Abby", 5);
		// Check vertices		
		assert(test.get_degree("Abby") == 2);
		assert(test.get_weight("Abby", "Ben") == 1);
		write_list("Abby", "Neighbors", test.get_neighbors("Abby"));
		assert(test.get_degree("Ben") == 2);
		assert(test.get_weight("Ben", "Daniel") == 2);
		write_list("Ben", "Neighbors", test.get_neighbors("Ben"));
		assert(test.get_degree("Carl") == 2);
		assert(test.get_weight("Carl", "Abby") == 5);
		write_list("Carl", "Neighbors", test.get_neighbors("Carl"));
		assert(test.get_degree("Daniel") == 2);
		assert(test.get_weight("Daniel", "Edward") == 3);
		write_list("Daniel", "Neighbors", test.get_neighbors("Daniel"));
		assert(test.get_degree("Edward") == 2);
		assert(test.get_weight("Edward", "Carl") == 4);
		write_list("Edward", "Neighbors", test.get_neighbors("Edward"));
	} catch (exception& e) {
		cout << "Caught exception: " << e.what() << endl;
	}
	
	cout << "\nDirected:\n";
	// Test Directed Graph
	try {
		// Create Vertices
		vector<string> vertices;
		vertices.push_back("A");
		vertices.push_back("B");
		vertices.push_back("C");
		vertices.push_back("D");
		vertices.push_back("E");
		// Setup Graph
		Graph<string> directedTest(vertices, true);
		directedTest.add_edge("A", "B", 1);
		directedTest.add_edge("B", "A", 1);
		directedTest.add_edge("B", "D", 1);
		directedTest.add_edge("D", "E", 1);
		directedTest.add_edge("D", "D", 1);
		directedTest.add_edge("E", "C", 1);
		directedTest.add_edge("C", "A", 1);
		// Check Vertices
		assert(directedTest.get_degree("A") == 3);
		assert(directedTest.get_degree("B") == 3);
		assert(directedTest.get_degree("C") == 2);
		assert(directedTest.get_degree("D") == 3);
		write_list("A", "Neighbors", directedTest.get_neighbors("A"));
		write_list("B", "Incoming", directedTest.get_incoming("B"));
		write_list("B", "Outgoing", directedTest.get_outgoing("B"));
		write_list("D", "Incoming", directedTest.get_incoming("D"));
		write_list("D", "Outgoing", directedTest.get_outgoing("D"));
	} catch (exception& e) {
		cout << "Caught exception: " << e.what() << endl;
	}
	return 0;
}
