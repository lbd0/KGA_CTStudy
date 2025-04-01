#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using uint = unsigned int;

class hash_map
{
	std::vector<std::list<int>> data; // vector를 쓰는 해쉬와 연결된 값을 받아오기 위한 list의 혼합

public:
	hash_map(size_t n)
	{
		data.resize(n);	// resize가 데이터의 요소 개수를 원하는 크기로 조정하는 표준 라이브러리 함수라고 한다.
	}
	
	void insert(uint value)
	{
		int n = data.size();
		data[value % n].push_back(value); //기본 hash에서는 그냥 value로 초기화했다면 이번엔 value를 push_back 한다는 차이가 있음.
		std::cout << value << "을(를) 삽입했습니다" << std::endl;
	}

	bool find(uint value)
	{
		int n = data.size();
		auto& entries = data[value % n]; //data는 여러 버킷을 담고 있는 배열. data[value%n]으로 해당 버킷에 접근해 참조(entries)로 꺼내옴. 
		return std::find(entries.begin(), entries.end(), value) != entries.end(); //entries를 다 돌았을 때 값이 찾아지면 true 아니면 false
	}
	
	void erase(uint value)
	{
		int n = data.size();
		auto& entries = data[value % n];
		auto iter = std::find(entries.begin(), entries.end(), value);

		if (iter != entries.end())	//얘도 마찬가지로 순회하면서 값이 찾아지면 삭제
		{
			entries.erase(iter);
			std::cout << value << "을(를) 삭제했습니다." << std::endl;
		}
	}
};

int main()
{
	hash_map map(7);

	auto print = [&](int value) { //람다는 실전에서 쓰이는게 맞는겨....
		if (map.find(value))
			std::cout << "해시 맵에서" << value << "을(를) 찾았습니다";
		else
			std::cout << "해시 맵에서" << value << "을(를) 찾지 못했습니다";
		std::cout << std::endl;
		};
	map.insert(2);
	map.insert(25);
	map.insert(10);
	map.insert(100);
	map.insert(55);

	print(100);
	print(2);

	map.erase(2);

	/*
	출력 화면
	2을(를) 삽입했습니다
	25을(를) 삽입했습니다
	10을(를) 삽입했습니다
	100을(를) 삽입했습니다
	55을(를) 삽입했습니다
	해시 맵에서100을(를) 찾았습니다
	해시 맵에서2을(를) 찾았습니다
	2을(를) 삭제했습니다.
	*/
}