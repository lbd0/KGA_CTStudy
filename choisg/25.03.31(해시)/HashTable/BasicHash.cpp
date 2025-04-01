#include<iostream>
#include<vector>

using uint = unsigned int;

class hash_map
{
	std::vector<int> data;

public:
	hash_map(size_t n)
	{
		data = std::vector<int>(n, -1); //생성자 초기화, 모든값이 false
	}

	void insert(uint value)
	{
		int n = data.size();
		data[value % n] = value; //나머지를 반환하는 모듈로 함수. 가장 간단한 해시 함수
		std::cout << value << "을(를) 삽입했습니다." << std::endl;
	}

	bool find(uint value)
	{
		int n = data.size();
		return (data[value % n] == value); //나머지가 같은 값은 무시되는 중
	}

	void erase(uint value)
	{
		int n = data.size();
		if (data[value % n] == value)
		{
			data[value % n] = -1; //초기값에서 -1로 초기화해준거랑 같은 맥락
			std::cout << value << "을(를) 삭제했습니다." << std::endl;
		}
	}
};

int main()
{
	hash_map map(7); //해시 맵 객체 생성. 크기 7짜리 버킷

	auto print = [&](int value) {		// map을 참조함. 람다가 인자로 정수 하나를 받음.(기존 map을 받아서 결과를 찍는 일반함수->람다함수로 간편)
		if (map.find(value))
			std::cout << "해시 맵에서" << value << "을(를) 찾았습니다." << std::endl;
		else
			std::cout << "해시 맵에서" << value << "을(를) 찾지 못했습니다." << std::endl;
		};
	
	map.insert(2);
	map.insert(25);
	map.insert(10);
	print(25);

	map.insert(100);
	print(100);
	print(2);

	map.erase(25);

	/*
	출력 결과
	2을(를) 삽입했습니다.
	25을(를) 삽입했습니다.
	10을(를) 삽입했습니다.
	해시 맵에서25을(를) 찾았습니다.
	100을(를) 삽입했습니다.
	해시 맵에서100을(를) 찾았습니다.
	해시 맵에서2을(를) 찾지 못했습니다.
	25을(를) 삭제했습니다.
	*/
}