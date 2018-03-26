// Adjacency List Graph Implementation
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include "..\..\Linked List\Doubly Linked List\DoublyLinkedList.cpp"
#include "..\..\Heap\BinaryHeap.cpp"

using namespace std;

template<class T>
class Graph {
private:
// Assume no edges exist until user adds them
	map<T, DoublyLinkedList<pair<int, T>>> AdjacencyList;
	bool isDirected;
	Graph();
	int bucket_size(const T vertex);
public:
	Graph(DoublyLinkedList<T> vertices, bool isDirected);
	// Weight has to be >0
	void add_edge(const T fromVertex, const T toVertex, const int weight);
	void remove_edge(const T fromVertex, const T toVertex);
	void add_vertex(const T newVertex);
	void remove_vertex(T delVertex);
	int get_weight(const T fromVertex, const T toVertex);
	int get_degree(const T vertex);
	DoublyLinkedList<T> get_all_vertices() const;
	int num_vertices() const;
	DoublyLinkedList<T> get_dijkstras(const T start, const T goal);
	DoublyLinkedList<T> get_neighbors(const T vertex);
	DoublyLinkedList<pair<int, T>> get_incoming(const T vertex);
	DoublyLinkedList<pair<int, T>> get_outgoing(const T vertex);
};

template<class T>
Graph<T>::Graph(DoublyLinkedList<T> vertices, bool isDirected) : isDirected(isDirected) {
	if (vertices.Is_empty())
		throw runtime_error("Initializing graph with empty list of vertices");
	// Graph starts with no edges defined
	for (int i = 0; i < vertices.Get_size(); i++)
		AdjacencyList[vertices.Element_at(i)] = DoublyLinkedList<pair<int, T>>();
}

template<class T>
int Graph<T>::bucket_size(const T vertex) { return AdjacencyList[vertex].Get_size(); }

/* Exception Cases: 
1) Weight > 0
2) Vertex not in graph
3) Edge already in graph */
template<class T>
void Graph<T>::add_edge(const T fromVertex, const T toVertex, const int weight) {
	if (weight < 1) // Ex 1
		throw runtime_error("Weight cannot be less than 1");
	if (AdjacencyList.find(fromVertex) == AdjacencyList.end() ||
	    AdjacencyList.find(toVertex) == AdjacencyList.end()) // Ex 2
		throw runtime_error("Cannot add, one of the vertices does not exist");
	for (int i = 0; i < bucket_size(fromVertex); i++) { // Ex 3
		if (AdjacencyList[fromVertex].Element_at(i).second == toVertex)
			throw runtime_error("Cannot add edge already present in graph");
		// Making the assumption that an edge will never exist going one way in
		// an undirected graph.
		// if (!isDirected && AdjacencyList[toVertex].Element_at(i).second == toVertex)
			// throw runtime_error("Cannot add edge already present in graph");
	}
	// Push_back new vertex
	AdjacencyList[fromVertex].Push_back(make_pair(weight, toVertex));
	if (!isDirected)
		AdjacencyList[toVertex].Push_back(make_pair(weight, fromVertex));
}

// Make sure you remove from BOTH places
/* Exception Cases: 
1) Vertex not in graph
2) Edge not in graph */
template<class T>
void Graph<T>::remove_edge(const T fromVertex, const T toVertex) {
	if (AdjacencyList.find(fromVertex) == AdjacencyList.end() ||
	    AdjacencyList.find(toVertex) == AdjacencyList.end()) // Ex 1
		throw runtime_error("Cannot remove, one of the vertices does not exist");
	bool edgePresent = false;
	int toIndex = -1;
	int fromIndex = -1;
	// Making same assumption from add_edge(if an undirected edge is in one place, its in both)
	for (int i = 0; i < bucket_size(fromVertex); i++;) {
		if (AdjacencyList[fromVertex].Element_at(i).second == toVertex) { 
			edgePresent = true;
			toIndex = i;
		}
	}
	if (!edgePresent) // Ex 2
		throw runtime_error("Cannot remove, edge not present in graph");
	if (!isDirected) {
		edgePresent = false;
		for (int i = 0; i < bucket_size(toVertex); i++;) {
			if (AdjacencyList[toVertex].Element_at(i).second == fromVertex) { 
				edgePresent = true;
				fromIndex = i;
			}
		}
		if (!edgePresent) // Ex 2
			throw runtime_error("Cannot remove, edge not present in graph");
	}
	
	AdjacencyList[fromVertex].Delete_at(toIndex);
	if (!isDirected)
		AdjacencyList[toVertex].Delete_at(fromIndex);
}

template<class T>
void Graph<T>::add_vertex(const T newVertex) {
	AdjacencyList[newVertex] = DoublyLinkedList<pair<int, T>>();
}

template<class T>
void Graph<T>::remove_vertex(T delVertex) {
	if (AdjacencyList.find(delVertex) == AdjacencyList.end())
		throw runtime_error("Cannot remove vertex that does not exist");
	/* Gonna need to:
		- Drop map entry
		- remove any references leftover in the other vertices */
	AdjacencyList.erase(delVertex);
	for(map<T, DoublyLinkedList<pair<int, T>>>::iterator iter = AdjacencyList.begin(); iter != AdjacencyList.end(); ++iter) {
		vector<int> deleteIndexes;
		for(int i = 0; i < iter->second.Get_size(); i++) {
			if (iter->second.Element_at(i).second == delVertex) {
				deleteIndexes.push_back(i);
			}
		}
		for(vector<int>::const_iterator index_itr = deleteIndexes.begin(); index_itr != deleteIndexes.end(); ++index_itr) {
			cout << "Deleting: " << *index_itr << "\nFrom List ";
			cout << iter->first << "\nList Length: " << iter->second.Get_size()  << endl;
			iter->second.Delete_at(*index_itr);
		}
	}
}

template<class T>
DoublyLinkedList<T> Graph<T>::get_all_vertices() const {
	DoublyLinkedList<T> vertexList;
	for(map<T, DoublyLinkedList<pair<int, T>>>::iterator iter = AdjacencyList.begin(); iter != AdjacencyList.end(); ++iter)
		vertexList.Push_back(iter->first);
	return vertexList;
}

template<class T>
int Graph<T>::get_weight(const T fromVertex, const T toVertex) {
	if (AdjacencyList.find(fromVertex) == AdjacencyList.end() ||
	    AdjacencyList.find(toVertex) == AdjacencyList.end()) // Ex 1
		throw runtime_error("Cannot get weight, one of the vertices does not exist");
	for(int i = 0; i < bucket_size(fromVertex); i++) {
		pair<int, T> element = AdjacencyList[fromVertex].Element_at(i);
		if (element.second == toVertex)
			return element.first;
	}
	throw runtime_error("Cannot get weight, edge not in graph");
}

template<class T>
int Graph<T>::num_vertices() const { return AdjacencyList.size(); }

template<class T>
DoublyLinkedList<T> Graph<T>::get_dijkstras(const T start, const T goal) {
	map<T, int> dist;
	map<T, T> prev;
	dist[start] = 0;	
	BinaryHeap<T> Q(MIN);
	
	for(map<T, DoublyLinkedList<pair<int, T>>>::iterator iter = AdjacencyList.begin(); iter != AdjacencyList.end(); ++iter) {
		if (iter->first != start) {
			dist[iter->first] = 999999; // supposed to be infinity
			prev[iter->first] = T();
		}
		Q.insert(dist[iter->first], iter->first);
	}
	
	while (!Q.is_empty()) {
		HeapNode<T> hn = Q.extract();
		const T currentVertex = hn.Data();
		if (currentVertex == goal) 
			break;
		//throw runtime_error("CurrentVertex is " + currentVertex);
		DoublyLinkedList<T> neighbors = get_neighbors(currentVertex);
		for (int i = 0; i < neighbors.Get_size(); i++) {
			T vertex = neighbors.Element_at(i);
			int alt = dist[currentVertex] + get_weight(vertex, currentVertex);
			if (alt < dist[vertex]) {
				Q.modify_key(dist[vertex], vertex, alt); 
				dist[vertex] = alt;
				prev[vertex] = currentVertex;
			}
		}
	}
	
	T vertex = goal;
	DoublyLinkedList<T> finalPath;
	while (vertex != start) {
		finalPath.Push_front(vertex);
		vertex = prev[vertex];
	}
	finalPath.Push_front(vertex);
	return finalPath;
}

// In Directed need to add Column and row elements
template<class T>
int Graph<T>::get_degree(const T vertex) {
	if (AdjacencyList.find(vertex) == AdjacencyList.end())
		throw runtime_error("Cannot get degree, vertex does not exist");
	if (!isDirected)
		return AdjacencyList[vertex].Get_size();
	else {
		int degree = AdjacencyList[vertex].Get_size();
		for(map<T, DoublyLinkedList<pair<int, T>>>::iterator iter = AdjacencyList.begin(); iter != AdjacencyList.end(); ++iter) {
			if (iter->first != vertex) {
				for(int i = 0; i < iter->second.Get_size(); i++) {
					if (iter->second.Element_at(i).second == vertex)
						degree++;
				}
			}
		}
		return degree;
	}
	// Directed has to find the other linked lists containing the vertex :(
}

template<class T>
DoublyLinkedList<T> Graph<T>::get_neighbors(const T vertex) {
	if (AdjacencyList.find(vertex) == AdjacencyList.end())
		throw runtime_error("Cannot get neighbor, vertex \"" + vertex + "\" does not exist");
	// map holds all unique neighbors
	map<T,T> uniqueVertices;
	// Copy vertex neighbor's data into the map
	for (int i = 0; i < AdjacencyList[vertex].Get_size(); i++) {
		const pair<int, T> element = AdjacencyList[vertex].Element_at(i);
		if (element.second != vertex && uniqueVertices.find(element.second) == uniqueVertices.end()) {
			uniqueVertices[element.second] = element.second;
		}
	}
	// Directed graphs need to check all the other lists
	if (isDirected) {	
		for(map<T, DoublyLinkedList<pair<int, T>>>::iterator iter = AdjacencyList.begin(); iter != AdjacencyList.end(); ++iter) {
			if (iter->first != vertex) {
				for(int i = 0; i < iter->second.Get_size(); i++) {
					pair<int, T> element = iter->second.Element_at(i);
					if (element.second == vertex && uniqueVertices.find(iter->first) == uniqueVertices.end())
						uniqueVertices[iter->first] = iter->first;
				}
			}
		}
	}
	// copy map into LL and return
	DoublyLinkedList<T> returnCopy;
	for(map<T, T>::iterator iter = uniqueVertices.begin(); iter != uniqueVertices.end(); ++iter)
		returnCopy.Push_back(iter->first);
	return returnCopy;
}

// directed broken
template<class T>
DoublyLinkedList<pair<int, T>> Graph<T>::get_incoming(const T vertex) {
	if (!isDirected)
		throw runtime_error("Cannot get incoming when graph is not directed");
	if (AdjacencyList.find(vertex) == AdjacencyList.end())
		throw runtime_error("Cannot get degree, vertex does not exist");
	
	// map holds all unique neighbors
	map<T,int> uniqueVertices;
	// Directed graphs need to check all the other lists
	for(map<T, DoublyLinkedList<pair<int, T>>>::iterator iter = AdjacencyList.begin(); iter != AdjacencyList.end(); ++iter) {
		// looping list inside of Vertex Element
		for(int i = 0; i < iter->second.Get_size(); i++) {
			pair<int, T> element = iter->second.Element_at(i);
			if (element.second == vertex && uniqueVertices.find(iter->first) == uniqueVertices.end())
				uniqueVertices[iter->first] = element.first;
		}
	}
	// copy map into LL and return
	DoublyLinkedList<pair<int, T>> returnCopy;
	for(map<T, int>::iterator iter = uniqueVertices.begin(); iter != uniqueVertices.end(); ++iter)
		returnCopy.Push_back(make_pair(iter->second,iter->first));
	return returnCopy;
}
template<class T>
DoublyLinkedList<pair<int, T>> Graph<T>::get_outgoing(const T vertex) {
	if (!isDirected)
		throw runtime_error("Cannot get outgoing when graph is not directed");
	if (AdjacencyList.find(vertex) == AdjacencyList.end())
		throw runtime_error("Cannot get degree, vertex does not exist");
	
	return AdjacencyList[vertex];
}