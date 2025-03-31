#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

template<typename pair1, typename pair2>
void print_umap1(unordered_map<pair1, pair2> umap) {
	for (auto& iter:umap){
		cout << iter.first << ":" << iter.second << " ";
	}
	cout << endl;
}


template <typename pair1>
void print_all1(unordered_set<pair1> uset) {
	for (auto it = uset.begin(); it != uset.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

template<typename pair1>
void print_all2(unordered_set<pair1> uset) {
	for (int num : uset) {
		cout << num << " ";
	}
	cout << endl;
}

int main() {
	unordered_map<int, int> um;

	um.insert({ 1,3 });
	um.insert(pair<int, int>(2, 4));
	um[3] = 6;


	cout << "[unordered_map] : ";
	print_umap1(um);

	unordered_set<int>us;

	us.insert(10);
	us.insert(20);
	us.insert(30);

	cout << "unordered_set] print_all1: ";
	print_all1(us);
	cout << "unordered_set] print_all2: ";
	print_all2(us);
}