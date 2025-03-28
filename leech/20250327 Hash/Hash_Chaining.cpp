#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class hash_map 
{
	// 체이닝(분리 연결법)
	vector<list<int>> data;

public:
	hash_map(size_t n) 
	{
		data.resize(n);
	}

	// 해시 함수
	int hash_func(int value) 
	{
		return value % data.size();
	}

	void insert(unsigned int value) 
	{
		// 해시 함수에 value를 전달해 해시 값 계산
		// 해시 값에 해당하는 버킷(리스트) 순회
		for (int v : data[hash_func(value)])
		{
			// 이미 있는 값이라면 삽입하지 않고 반환
			if (v == value)
			{
				cout << "이미 있는 값입니다" << endl;
				return;
			}
		}

		// 새로운 값이면 해시 값의 버킷(리스트)에 삽입
		data[hash_func(value)].push_back(value);
		cout << value << "삽입, 해시값 : " << hash_func(value) << endl;
	}

	bool find(unsigned int value) 
	{
		// 해시 함수에 value를 전달해 해시 값 계산
		// 해시 값에 해당하는 버킷(리스트) 순회
		for (int v : data[hash_func(value)]) 
		{
			// 해당되는 값이 있으면 true 반환
			if (v == value) 
			{
				return true;
			}
		}

		// 해당되는 값이 없으면 false 반환
		return false;
	}

	void erase(unsigned value) 
	{
		// 해시 값 계산 후 해당 버킷(리스트) 참조
		auto& ent = data[hash_func(value)];
		// 해당 버킷(리스트)에서 값 찾기
		auto iter = std::find(ent.begin(), ent.end(), value);

		// 값을 찾으면 삭제
		if (iter != ent.end()) 
		{
			ent.erase(iter);
			cout << value << "지움" << endl;
		}
	}
};

int main() {
	hash_map map(10);

	auto print_map = [&](int value) 
	{
		if (map.find(value)) 
		{
			cout << value << "찾음" << endl;
		}
		else 
		{
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

	print_map(5);
}