#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>

class Hash_Map { // 기본 해시 맵
	std::vector<int> data;

public :
	Hash_Map(size_t n) {
		data = std::vector<int>(n, -1);
	}

	int Hash_Func(int value) {
		return value % data.size();
	}

	void insert(unsigned int value) {
		data[Hash_Func(value)] = value;
	}
};

class Hash_Map_Chaining { // 체이닝을 사용한 해시 맵
	std::vector<std::list<int>> data;

public:
	Hash_Map_Chaining(size_t n) {
		data.resize(n);
	}

	int Hash_Func(int value) {
		return value % data.size();
	}

	void insert(unsigned int value) {
		for (int v : data[Hash_Func(value)])
		{
			if (v == value)
			{
				std::cout << "이미 있는 값입니다" << "\n";
				return;
			}
		}

		data[Hash_Func(value)].push_back(value);
		std::cout << value << "삽입, 해시값 : " << Hash_Func(value) << "\n";
	}
};

//unordered_map
void Print_UMap1(std::unordered_map<int, int> umap) {
	for (auto& iter : umap) {
		std::cout << iter.first << " : " << iter.second << " ";
	}
	std::cout << "\n";
}

// unordered_set
template <typename pair1>
void Print_All1(std::unordered_set<pair1> uset)
{
	for (auto it = uset.begin(); it != uset.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";
}

template <typename pair1>
void Print_All2(std::unordered_set<pair1> uset)
{
	for (int num : uset)
	{
		std::cout << num << " ";
	}
	std::cout << "\n";
}

int main() {
	// unordered_map
	std::unordered_map<int, int> um;

	um.insert({ 1, 3 });
	um.insert(std::pair<int, int>(2, 4));
	um[3] = 6;

	// unordered_set
	std::unordered_set<int> us;

	return 0;
}