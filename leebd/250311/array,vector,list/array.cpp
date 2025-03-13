#include <iostream>
#include <array>

int main()
{
	std::array<int, 3> arr = { 1, 2, 3 };		// 크기가 3인 int 타입 배열 선언
	
	for (auto a : arr)
	{
		std::cout << a << std::endl;
	}

}