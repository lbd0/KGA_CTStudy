//���� �Լ��� ���ڿ��� ������ �� ���� �Ѱ踦 �Ѿ����..
//std::hash<std::string>(std::string) ���ڿ����� �ؽ� �� �����ϴ� �Լ� ��ü. 
//unorderedmap�� Ű�� ���� �Բ� ����, unorderedset�� Ű�� ����. 
//2���� �ؽ� ��� �����̳ʷμ� �ؽ� ������ ¥�� �ʾƵ� ǥ�� ���̺귯���� ������ ����.


#include <iostream>
#include <unordered_map>
#include <unordered_set>

void print(const std::unordered_map<int, int>& container) //Ű�� ���� �Բ� ����س� �� �ִ�
{
	for (const auto& element : container)
		std::cout << element.first << ":" << element.second << ",";
	std::cout << std::endl;
}

void find(const std::unordered_map<int, int>& container, const int element)
{
	auto it = container.find(element);
	if (it == container.end())
		std::cout << element << "�˻�: ����" << std::endl;
	else
		std::cout << element << "�˻�: ����, ��:" << it->second << std::endl; //ü�̴� ������� Ű�� ����� �� ã�Ƴ�
}

int main()

{
	std::unordered_map<int, int> squareMap;

	squareMap.insert({ 2, 4 });
	squareMap[3] = 9;			//������ ��� �Ѱ� �ƴϰ� ���Ƿ� �����ѵ�. 
	std::cout << "2, 3�� ���� ����: "; print(squareMap);

	squareMap[20] = 400;
	squareMap[30] = 900;
	std::cout << "20, 30�� ���� ����: "; print(squareMap);

	find(squareMap, 10);
	find(squareMap, 20);
	std::cout << "squareMap[3] =" << squareMap[3] << std::endl;
	std::cout << "squareMap[100] =" << squareMap[100] << std::endl;
	print(squareMap);

	/*
	��� ���
	2, 3�� ���� ����: 2:4,3:9,
	20, 30�� ���� ����: 2:4,3:9,20:400,30:900,
	10 �˻�: ����
	20 �˻�: ����, ��:400
	squareMap[3] =9
	squareMap[100] =0
	2:4, 3:9, 100:0, 20:400, 30:900,
	*/
}
