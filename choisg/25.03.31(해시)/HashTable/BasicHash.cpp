#include<iostream>
#include<vector>

using uint = unsigned int;

class hash_map
{
	std::vector<int> data;

public:
	hash_map(size_t n)
	{
		data = std::vector<int>(n, -1); //������ �ʱ�ȭ, ��簪�� false
	}

	void insert(uint value)
	{
		int n = data.size();
		data[value % n] = value; //�������� ��ȯ�ϴ� ���� �Լ�. ���� ������ �ؽ� �Լ�
		std::cout << value << "��(��) �����߽��ϴ�." << std::endl;
	}

	bool find(uint value)
	{
		int n = data.size();
		return (data[value % n] == value); //�������� ���� ���� ���õǴ� ��
	}

	void erase(uint value)
	{
		int n = data.size();
		if (data[value % n] == value)
		{
			data[value % n] = -1; //�ʱⰪ���� -1�� �ʱ�ȭ���ذŶ� ���� �ƶ�
			std::cout << value << "��(��) �����߽��ϴ�." << std::endl;
		}
	}
};

int main()
{
	hash_map map(7); //�ؽ� �� ��ü ����. ũ�� 7¥�� ��Ŷ

	auto print = [&](int value) {		// map�� ������. ���ٰ� ���ڷ� ���� �ϳ��� ����.(���� map�� �޾Ƽ� ����� ��� �Ϲ��Լ�->�����Լ��� ����)
		if (map.find(value))
			std::cout << "�ؽ� �ʿ���" << value << "��(��) ã�ҽ��ϴ�." << std::endl;
		else
			std::cout << "�ؽ� �ʿ���" << value << "��(��) ã�� ���߽��ϴ�." << std::endl;
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
	��� ���
	2��(��) �����߽��ϴ�.
	25��(��) �����߽��ϴ�.
	10��(��) �����߽��ϴ�.
	�ؽ� �ʿ���25��(��) ã�ҽ��ϴ�.
	100��(��) �����߽��ϴ�.
	�ؽ� �ʿ���100��(��) ã�ҽ��ϴ�.
	�ؽ� �ʿ���2��(��) ã�� ���߽��ϴ�.
	25��(��) �����߽��ϴ�.
	*/
}