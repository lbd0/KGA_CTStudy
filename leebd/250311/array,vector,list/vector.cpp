#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec0;		// 크기가 0인 벡터 선언

	vec0.push_back(1); 
	vec0.emplace_back(3);

	vec0.insert(vec0.begin(), 0);
	vec0.emplace(vec0.begin() + 2, 2);

	vec0.pop_back();

	for (auto v : vec0)
	{
		std::cout << v << std::endl;
	}


}