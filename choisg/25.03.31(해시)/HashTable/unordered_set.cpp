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
		std::cout << element << "�˻�: ����" << std::endl;
	else
		std::cout << element << "�˻�: ����" << std::endl; //key�� ã���� ��. unordered_map�� ���� ���ܸ��
}

int main()

{
	std::unordered_set<int> set1 = { 1, 2, 3, 4, 5 };

	std::cout << "set1 �ʱ갪: "; print(set1);

	set1.insert(2);
	std::cout << "2 ����: "; print(set1);

	set1.insert(10);
	set1.insert(300);
	std::cout << "10, 300 ����: "; print(set1);

	find(set1, 4);
	find(set1, 100);
	
	set1.erase(2);
	std::cout << "2 ����: "; print(set1);

	find(set1, 2);

	/*
	��� ����
	set1 �ʱ갪: 1,2,3,4,5,
	2 ����: 1,2,3,4,5,
	10, 300 ����: 1,10,2,300,3,4,5,
	4 �˻�: ����
	100 �˻�: ����
	2 ����: 1,10,300,3,4,5,
	2 �˻�: ����
	*/

}
