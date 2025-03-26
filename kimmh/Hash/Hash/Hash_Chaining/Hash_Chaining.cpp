#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class hash_map {
	vector<list<int>> data;

public:
	hash_map(size_t n) {
		data.resize(n);
	}

	int hash_func(int value) {
		return value % data.size();
	}

	void insert(unsigned int value) {
		for (int v : data[hash_func(value)]) {
			if (v == value) {
				cout << "이미 있는 값입니다" << endl;
				return;
			}
		}

		data[hash_func(value)].push_back(value);
		cout << value << "삽입, 해시값 : " << hash_func(value) << endl;
	}

	bool find(unsigned int value) {
		for (int v : data[hash_func(value)]) {
			if (v == value) {
				return true;
			}
		}
		 
		return false;
	}

	void erase(unsigned value) {
		auto& ent = data[hash_func(value)];
		auto iter = std::find(ent.begin(), ent.end(), value);

		if (iter != ent.end()) {
			ent.erase(iter);
			cout << value <<  "지움" << endl;
		}
	}
};

int main() {
	hash_map map(10);

	auto print_map = [&](int value) {
		if (map.find(value)) {
			cout << value << "찾음" << endl;
		}
		else {
			cout << value << "못 찾음" << endl;
		}
	};

	map.insert(10);
	map.insert(5);
	map.insert(100);

	cout << endl;

	print_map(10);
	print_map(100);
	print_map(5);

	map.erase(5);
}