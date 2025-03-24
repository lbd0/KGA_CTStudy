#include <iostream>
#include <vector>

using namespace std;

class hash_map {
	vector<int> table1;
	vector<int> table2;
	int size;

	int hash_func1(int value) {
		return value % size;
	}
	
	int hash_func2(int value) {
		return (value / size) % size;
	}

public:
	hash_map(int size) : size(size) {
		table1 = vector<int>(size, -1);
		table2 = vector<int>(size, -1);
	}

	vector<int>::iterator lookup(int key) {
		if (table1[hash_func1(key)] == key) {
			cout << "값이 존재함" << endl;
			return table1.begin() + hash_func1(key);
		}

		if (table1[hash_func2(key)] == key) {
			cout << "값이 존재함" << endl;
			return table1.begin() + hash_func2(key);
		}

		return table2.end();
	}

	void erase(int key) {
		auto addr = lookup(key);
		if (addr != table2.end()) {
			*addr = -1;
		}
	}
private:
	void insert_imp1(int key, int cnt, int table) {
		if (cnt >= size) {
			cout << "순환 발생 재해싱 필요" << endl;
			return;
		}
		else {
			if (table == 1) {
				if (table1[hash_func1(key)] == -1) {
					table1[hash_func1(key)] = key;
				}
				else {
					int old = table1[hash_func1(key)];
					table1[hash_func1(key)] = key;
					cout << table << "번 테이블에 " << key << "삽입, 기존의 " << old << "이동" << endl;
					insert_imp1(old, cnt + 1, 2);
				}
			}
			else {
				if (table2[hash_func2(key)] == -1) {
					table2[hash_func2(key)] = key;
				}
				else {
					int old = table2[hash_func2(key)];
					table2[hash_func2(key)] = key;
					cout << table << "번 테이블에 " << key << "삽입, 기존의 " << old << "이동" << endl;
					insert_imp1(old, cnt + 1, 1);
				}
			}
			
		}

	}

public:
	void insert(int key) {
		insert_imp1(key, 0, 1);
	}

	void print() {
		cout << "Index : ";
		for (int i = 0; i < size; i++) {
			cout << i << '\t' << endl;
		}

		cout << "\n Table1 : ";
		for (auto value : table1) {
			cout << value << '\t' << endl;
		}

		cout << "\n Table2 : ";
		for (auto value : table2) {
			cout << value << '\t' << endl;
		}
	}
};

int main() {
	hash_map map(7);

	map.print();

	map.insert(10);
	map.insert(20);
	map.insert(30);
	map.insert(104);
	map.insert(2);
	map.insert(70);
	map.insert(9);
	map.insert(90);
	map.insert(2);
	map.insert(7);

	map.print();

	map.insert(14);
}