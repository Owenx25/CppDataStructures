// Main for Hash Table

#include <iostream>
#include <string>
#include <assert.h>
#include "HashMap.cpp"

using namespace std;

int main() {
	try {
		HashTable<string, string> HM;
		HM.insert("EXCELSIOR", "New York");
		HM.insert("FUSION", "Philadelphia");
		HM.insert("SPITFIRE", "London");
		HM.insert("UPRISING", "Boston");
		HM.insert("MAYHEM", "Florida");
		HM.insert("GLADIATORS", "Los Angeles");
		HM.insert("DYNASTY", "Seoul");
		HM.insert("DRAGONS", "Shanghai");
		HM.insert("SHOCK", "San Francisco");
		HM.insert("VALIANT", "Los Angeles");
		HM.insert("OUTLAWS", "Houston");
		HM.insert("FUEL", "Dallas");
		//cout << HM.get("") << endl;
		assert(HM.Size() == 12);
		assert(HM.get("SPITFIRE") == "London");
		assert(HM.get("SHOCK") == "San Francisco");
		assert(HM.get("UPRISING") == "Boston");
		//HM.erase("EXCELSIOR");
		//HM.get("EXCELSIOR");
		HM.set("EXCELSIOR", "Stage 2 winners");
		assert(HM.get("EXCELSIOR") == "Stage 2 winners");
	} catch (exception& e) {
		cout << "Exception Caught: " << e.what() << endl;
	}
	return 0;
}