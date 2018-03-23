// Graph main
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include "AdjacencyList.cpp"

using namespace std;

void write_neighbors(string vertex, string operationName, DoublyLinkedList<string> list) {
	cout << vertex << "'s " + operationName + ": { ";
	for (int i = 0; i < list.Get_size(); i++)
		cout << list.Element_at(i) << " ";
	cout << "}\n";
}

void write_directed(string vertex, string operationName, DoublyLinkedList<pair<int, string>> list) {
	cout << vertex << "'s " + operationName + ": { ";
	for (int i = 0; i < list.Get_size(); i++) {
		const pair<int, string> element = list.Element_at(i);
		cout << element.second << ":";
		cout << element.first << " ";
	}
	cout << "}\n";
}

int main() {
	try {
		// Create Vertices
		DoublyLinkedList<string> names;
		names.Push_back("Abby");
		names.Push_back("Ben");
		names.Push_back("Carl");
		names.Push_back("Daniel");
		names.Push_back("Edward");
		//Setup Graph
		Graph<string> test(names, false);
		test.add_edge("Abby", "Ben", 1);
		test.add_edge("Ben", "Daniel", 2);
		test.add_edge("Daniel", "Edward", 3);
		test.add_edge("Edward", "Carl", 4);
		test.add_edge("Carl", "Abby", 5);
		//Check vertices		
		assert(test.get_degree("Abby") == 2);
		assert(test.get_weight("Abby", "Ben") == 1);
		write_neighbors("Abby", "Neighbors", test.get_neighbors("Abby"));
		assert(test.get_degree("Ben") == 2);
		assert(test.get_weight("Ben", "Daniel") == 2);
		write_neighbors("Ben", "Neighbors", test.get_neighbors("Ben"));
		assert(test.get_degree("Carl") == 2);
		assert(test.get_weight("Carl", "Abby") == 5);
		write_neighbors("Carl", "Neighbors", test.get_neighbors("Carl"));
		assert(test.get_degree("Daniel") == 2);
		assert(test.get_weight("Daniel", "Edward") == 3);
		write_neighbors("Daniel", "Neighbors", test.get_neighbors("Daniel"));
		assert(test.get_degree("Edward") == 2);
		assert(test.get_weight("Edward", "Carl") == 4);
		write_neighbors("Edward", "Neighbors", test.get_neighbors("Edward"));
		
		//Adding/Removing Vertices
		test.add_vertex("Zarya");
		test.add_edge("Abby", "Zarya", 20);
		write_neighbors("Zarya", "Neighbors", test.get_neighbors("Zarya"));
		write_neighbors("Abby", "Neighbors", test.get_neighbors("Abby"));
		test.remove_vertex("Zarya");
		write_neighbors("Abby", "Neighbors", test.get_neighbors("Abby"));
	} catch (exception& e) {
		cout << "Caught exception: " << e.what() << endl;
	}
	
	cout << "\nDirected:\n";
	// Test Directed Graph
	try {
		// Create Vertices
		DoublyLinkedList<string> vertices;
		vertices.Push_back("A");
		vertices.Push_back("B");
		vertices.Push_back("C");
		vertices.Push_back("D");
		vertices.Push_back("E");
		// Setup Graph
		Graph<string> directedTest(vertices, true);
		directedTest.add_edge("A", "B", 1);
		directedTest.add_edge("B", "A", 6);
		directedTest.add_edge("B", "D", 2);
		directedTest.add_edge("D", "E", 3);
		directedTest.add_edge("D", "D", 1);
		directedTest.add_edge("E", "C", 4);
		directedTest.add_edge("C", "A", 5);
		// Check Vertices
		assert(directedTest.get_degree("A") == 3);
		assert(directedTest.get_degree("B") == 3);
		assert(directedTest.get_degree("C") == 2);
		assert(directedTest.get_degree("D") == 3);
		write_neighbors("A", "Neighbors", directedTest.get_neighbors("A"));
		write_neighbors("B", "Neighbors", directedTest.get_neighbors("B"));
		write_neighbors("C", "Neighbors", directedTest.get_neighbors("C"));
		write_neighbors("D", "Neighbors", directedTest.get_neighbors("D"));
		write_neighbors("E", "Neighbors", directedTest.get_neighbors("E"));
		write_directed("A", "Incoming", directedTest.get_incoming("A"));
		write_directed("A", "Outgoing", directedTest.get_outgoing("A"));
		write_directed("B", "Incoming", directedTest.get_incoming("B"));
		write_directed("B", "Outgoing", directedTest.get_outgoing("B"));
		write_directed("D", "Incoming", directedTest.get_incoming("D"));
		write_directed("D", "Outgoing", directedTest.get_outgoing("D"));
	} catch (exception& e) {
		cout << "Caught exception: " << e.what() << endl;
	}
	
	cout << "\nDijkstra's:\n";
	// Test Dijkstras
	try {
		// Create Vertices
		DoublyLinkedList<string> D_vertices;
		D_vertices.Push_back("A");
		D_vertices.Push_back("B");
		D_vertices.Push_back("C");
		D_vertices.Push_back("D");
		D_vertices.Push_back("E");
		D_vertices.Push_back("F");
		D_vertices.Push_back("G");
		D_vertices.Push_back("H");
		// Setup graph
		Graph<string> D_graph(D_vertices, false);
		D_graph.add_edge("A", "G", 2);
		D_graph.add_edge("A", "F", 2);
		D_graph.add_edge("G", "B", 1);
		D_graph.add_edge("F", "C", 3);
		D_graph.add_edge("B", "C", 4);
		D_graph.add_edge("B", "H", 2);
		D_graph.add_edge("C", "D", 2);
		D_graph.add_edge("C", "E", 1);
		D_graph.add_edge("D", "E", 2);
		D_graph.add_edge("D", "H", 1);
		//Dijkstra's
		D_graph.get_dijkstras("A", "D");
	} catch (exception& e) {
		cout << "Caught exception: " << e.what() << endl;
	}
	return 0;
}
