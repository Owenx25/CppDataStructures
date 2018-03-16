// Adjacency Matrix

#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

template<class T>
class Graph {
private:
// Assume no edges exist until user adds them
	vector<vector<int>> AdjacencyMatrix;
	map<T, int> DataToIndex;
	vector<T> IndexToData;
	bool isDirected;
	Graph();
	int get_index(const T vertex);
public:
	Graph(vector<T> vertices, bool isDirected);
	// Weight has to be >0
	void add_edge(const T fromVertex, const T toVertex, const int weight);
	void remove_edge(const T fromVertex, const T toVertex);
	int get_weight(const T fromVertex, const T toVertex) const;
	int get_degree(const T vertex) const;
	int num_vertices() const;
	vector<T> get_neighbors(const T vertex) const;
	
};

template<class T>
Graph<T>::Graph(vector<T> vertices, bool isDirected) : isDirected(isDirected), IndexToData(vertices) {
	if (vertices.empty())
		throw runtime_error("empty list of vertices");
	//AdjacencyMatrix.reserve(vertices.size() * vertices.size());
	// - Build data->index mapping
	// - build 2D matrix
	// Graph starts with no edges defined
	vector<int> edges(vertices.size(), 0);
	
	for (int i = 0; i < vertices.size() - 1; i++) {
		DataToIndex.insert(make_pair(vertices.at(i), i));
		AdjacencyMatrix.push_back(edges);
	}
}

template<class T>
void Graph<T>::add_edge(const T fromVertex, const T toVertex, const int weight) {
	if (weight < 1)
		throw runtime_error("Weight cannot be less than 1");
	int fromIndex = get_index(fromVertex);
	int toIndex = get_index(toVertex);
	AdjacencyMatrix[fromIndex][toIndex] = weight;
	if (!isDirected)
		AdjacencyMatrix[toIndex][fromIndex] = weight;
}

template<class T>
void Graph<T>::remove_edge(const T fromVertex, const T toVertex) {
	int fromIndex = get_index(fromVertex);
	int toIndex = get_index(toVertex);
	AdjacencyMatrix[fromIndex][toIndex] = 0;
	if (!isDirected)
		AdjacencyMatrix[toIndex][fromIndex] = 0;
}

template<class T>
int Graph<T>::get_weight(const T fromVertex, const T toVertex) const {
	return AdjacencyMatrix[get_index(fromVertex)][get_index(toVertex)];
}

template<class T>
int Graph<T>::num_vertices() const { return AdjacencyMatrix.size(); }

// NEED TO ACCOUNT FOR DIRECTED
template<class T>
int Graph<T>::get_degree(const T vertex) const {
	int index = get_index(toVertex);
	int degree = 0;
	for (int i = 0; i < AdjacencyMatrix.size() - 1; i++) {
		if (AdjacencyMatrix[index][i] > 0)
			degree++;
	}
	return degree;
}

// NEED TO ACCOUNT FOR DIRECTED
template<class T>
vector<T> Graph<T>::get_neighbors(const T vertex) const {
	int index = get_index(toVertex);
	vector<int> neighbors = 0;
	for (int i = 0; i < AdjacencyMatrix.size() - 1; i++) {
		if (AdjacencyMatrix[index][i] > 0)
			neighbors.push_back(IndexToData[i]);
	}
	return neighbors;
}

template<class T>
int Graph<T>::get_index(const T vertex) {
	if (DataToIndex.find(vertex) == DataToIndex.end())
		throw runtime_error("vertex not in graph");
	return DataToIndex[vertex];
}