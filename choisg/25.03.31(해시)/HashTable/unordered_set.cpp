#include <iostream>
#include <unordered_map>
#include <unordered_set>

void print(const std::unordered_set<int>& container) 
{
	for (const auto& element : container)
		std::cout << element << ",";
	std::cout << std::endl;
}

void find(const std::unordered_set<int>& container, const int element)
{
	auto it = container.find(element);
	if (it == container.end())
		std::cout << element << "검색: 실패" << std::endl;
	else
		std::cout << element << "검색: 성공" << std::endl; //key만 찾으면 됨. unordered_map에 비해 간단명료
}

int main()

{
	std::unordered_set<int> set1 = { 1, 2, 3, 4, 5 };

	std::cout << "set1 초깃값: "; print(set1);

	set1.insert(2);
	std::cout << "2 삽입: "; print(set1);

	set1.insert(10);
	set1.insert(300);
	std::cout << "10, 300 삽입: "; print(set1);

	find(set1, 4);
	find(set1, 100);
	
	set1.erase(2);
	std::cout << "2 삭제: "; print(set1);

	find(set1, 2);

	/*
	출력 예제
	set1 초깃값: 1,2,3,4,5,
	2 삽입: 1,2,3,4,5,
	10, 300 삽입: 1,10,2,300,3,4,5,
	4 검색: 성공
	100 검색: 실패
	2 삭제: 1,10,300,3,4,5,
	2 검색: 실패
	*/

}
