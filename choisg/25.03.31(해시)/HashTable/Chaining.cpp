#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using uint = unsigned int;

class hash_map
{
	std::vector<std::list<int>> data; // vector�� ���� �ؽ��� ����� ���� �޾ƿ��� ���� list�� ȥ��

public:
	hash_map(size_t n)
	{
		data.resize(n);	// resize�� �������� ��� ������ ���ϴ� ũ��� �����ϴ� ǥ�� ���̺귯�� �Լ���� �Ѵ�.
	}
	
	void insert(uint value)
	{
		int n = data.size();
		data[value % n].push_back(value); //�⺻ hash������ �׳� value�� �ʱ�ȭ�ߴٸ� �̹��� value�� push_back �Ѵٴ� ���̰� ����.
		std::cout << value << "��(��) �����߽��ϴ�" << std::endl;
	}

	bool find(uint value)
	{
		int n = data.size();
		auto& entries = data[value % n]; //data�� ���� ��Ŷ�� ��� �ִ� �迭. data[value%n]���� �ش� ��Ŷ�� ������ ����(entries)�� ������. 
		return std::find(entries.begin(), entries.end(), value) != entries.end(); //entries�� �� ������ �� ���� ã������ true �ƴϸ� false
	}
	
	void erase(uint value)
	{
		int n = data.size();
		auto& entries = data[value % n];
		auto iter = std::find(entries.begin(), entries.end(), value);

		if (iter != entries.end())	//�굵 ���������� ��ȸ�ϸ鼭 ���� ã������ ����
		{
			entries.erase(iter);
			std::cout << value << "��(��) �����߽��ϴ�." << std::endl;
		}
	}
};

int main()
{
	hash_map map(7);

	auto print = [&](int value) { //���ٴ� �������� ���̴°� �´°�....
		if (map.find(value))
			std::cout << "�ؽ� �ʿ���" << value << "��(��) ã�ҽ��ϴ�";
		else
			std::cout << "�ؽ� �ʿ���" << value << "��(��) ã�� ���߽��ϴ�";
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
	��� ȭ��
	2��(��) �����߽��ϴ�
	25��(��) �����߽��ϴ�
	10��(��) �����߽��ϴ�
	100��(��) �����߽��ϴ�
	55��(��) �����߽��ϴ�
	�ؽ� �ʿ���100��(��) ã�ҽ��ϴ�
	�ؽ� �ʿ���2��(��) ã�ҽ��ϴ�
	2��(��) �����߽��ϴ�.
	*/
}