//모듈로 함수는 문자열에 적용할 수 없는 한계를 넘어보고자..
//std::hash<std::string>(std::string) 문자열에서 해시 값 생성하는 함수 객체. 
//unorderedmap은 키와 값을 함께 저장, unorderedset은 키만 저장. 
//2개는 해시 기반 컨테이너로서 해시 로직을 짜지 않아도 표준 라이브러리가 구현을 해줌.


#include <iostream>
#include <unordered_map>
#include <unordered_set>

void print(const std::unordered_map<int, int>& container) //키와 값을 함께 출력해낼 수 있다
{
	for (const auto& element : container)
		std::cout << element.first << ":" << element.second << ",";
	std::cout << std::endl;
}

void find(const std::unordered_map<int, int>& container, const int element)
{
	auto it = container.find(element);
	if (it == container.end())
		std::cout << element << "검색: 실패" << std::endl;
	else
		std::cout << element << "검색: 성공, 값:" << it->second << std::endl; //체이닝 방식으로 키와 연결된 값 찾아냄
}

int main()

{
	std::unordered_map<int, int> squareMap;

	squareMap.insert({ 2, 4 });
	squareMap[3] = 9;			//제곱을 어디서 한건 아니고 임의로 설정한듯. 
	std::cout << "2, 3의 제곱 삽입: "; print(squareMap);

	squareMap[20] = 400;
	squareMap[30] = 900;
	std::cout << "20, 30의 제곱 삽입: "; print(squareMap);

	find(squareMap, 10);
	find(squareMap, 20);
	std::cout << "squareMap[3] =" << squareMap[3] << std::endl;
	std::cout << "squareMap[100] =" << squareMap[100] << std::endl;
	print(squareMap);

	/*
	출력 결과
	2, 3의 제곱 삽입: 2:4,3:9,
	20, 30의 제곱 삽입: 2:4,3:9,20:400,30:900,
	10 검색: 실패
	20 검색: 성공, 값:400
	squareMap[3] =9
	squareMap[100] =0
	2:4, 3:9, 100:0, 20:400, 30:900,
	*/
}
