#include <iostream>
#include <array>

int main()
{
	std::array<int, 3> arr = { 1, 2, 3 };		// ũ�Ⱑ 3�� int Ÿ�� �迭 ����
	
	for (auto a : arr)
	{
		std::cout << a << std::endl;
	}

}