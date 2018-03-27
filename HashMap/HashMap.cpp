// Hash Map Implementation

#include <functional>
#include <iostream>
#include <utility>
#include <string>
#include "..\Linked List\Doubly Linked List\DoublyLinkedList.cpp"

using namespace std;


// T1 = Key type, T2 = value type
template<class T1,class T2>
class HashTable {
private:
	DoublyLinkedList<pair<T1, T2>>* pDataSet;
	int Hash(const T1 &key);
	int capacity;
	int size;
	
public:
	//const T2& operator []();
	void insert(T1 key, T2 value);
	void set(T1 key, T2 value);
	void erase(T1 key);
	T2 get(T1 key);
	int Size();
	
	HashTable();
	HashTable(int capacity);
	~HashTable();
};

// Constructors
template<class T1,class T2>
HashTable<T1, T2>::HashTable() : HashTable(100) {}

template<class T1,class T2>
HashTable<T1, T2>::HashTable(int capacity) : capacity(capacity) {
	pDataSet = new DoublyLinkedList<pair<T1, T2>>[capacity];
	if (pDataSet == NULL)
		throw runtime_error("Could not allocate memory");
	while (--capacity)
		pDataSet[capacity] = DoublyLinkedList<pair<T1, T2>>();
	size = 0;
}

// Destructor
template<class T1,class T2>
HashTable<T1, T2>::~HashTable() {
	// Delete each bucket
	// for (int i = 0; i < size; i++) {
		// delete pDataSet[i];
		// pDataSet[i] = NULL;
	// }
	delete[] pDataSet;
	pDataSet = NULL;
}

// Public Functions
template<class T1,class T2>
void HashTable<T1, T2>::insert(T1 key, T2 value) {
	if(size == capacity)
		throw runtime_error("Cannot insert, Hash table is full");
	const int addIndex = Hash(key);
	pDataSet[addIndex].Push_back(make_pair(key, value));
	size++;
}

template<class T1,class T2>
void HashTable<T1, T2>::set(T1 key, T2 value) {
	const int setIndex = Hash(key);
	for (int i = 0; i < pDataSet[setIndex].Get_size(); i++) {
		if (pDataSet[setIndex].Element_at(i).first == key) {
			pDataSet[setIndex].Set_element(i, make_pair(key, value));
			return;
		}
	}
	throw runtime_error("Cannot set, Key does not exist in table");
}

template<class T1,class T2>
void HashTable<T1, T2>::erase(T1 key) {
	const int remIndex = Hash(key);
	for (int i = 0; i < pDataSet[remIndex].Get_size(); i++) {
		if (pDataSet[remIndex].Element_at(i).first == key) {
			pDataSet[remIndex].Delete_at(i);
			size--;
			return;
		}
	}
	throw runtime_error("Cannot remove, Key does not exist in table");
}

template<class T1,class T2>
T2 HashTable<T1, T2>::get(T1 key) {
	const int getIndex = Hash(key);
	for (int i = 0; i < pDataSet[getIndex].Get_size(); i++) {
		const pair<T1, T2> ret_pair = pDataSet[getIndex].Element_at(i);
		if (ret_pair.first == key) {		
			return ret_pair.second;
		}
	}
	throw runtime_error("Cannot get, Key does not exist in table");
}

template<class T1,class T2>
int HashTable<T1, T2>::Size() { return size; }

template<class T1, class T2>
int HashTable<T1, T2>::Hash(const T1 &key) {
	size_t key_hash = hash<T1>()(key);
	return key_hash % capacity;
}

