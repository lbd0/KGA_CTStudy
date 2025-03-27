#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class hash_map 
{
	// ü�̴�(�и� �����)
	vector<list<int>> data;

public:
	hash_map(size_t n) 
	{
		data.resize(n);
	}

	// �ؽ� �Լ�
	int hash_func(int value) 
	{
		return value % data.size();
	}

	void insert(unsigned int value) 
	{
		// �ؽ� �Լ��� value�� ������ �ؽ� �� ���
		// �ؽ� ���� �ش��ϴ� ��Ŷ(����Ʈ) ��ȸ
		for (int v : data[hash_func(value)])
		{
			// �̹� �ִ� ���̶�� �������� �ʰ� ��ȯ
			if (v == value)
			{
				cout << "�̹� �ִ� ���Դϴ�" << endl;
				return;
			}
		}

		// ���ο� ���̸� �ؽ� ���� ��Ŷ(����Ʈ)�� ����
		data[hash_func(value)].push_back(value);
		cout << value << "����, �ؽð� : " << hash_func(value) << endl;
	}

	bool find(unsigned int value) 
	{
		// �ؽ� �Լ��� value�� ������ �ؽ� �� ���
		// �ؽ� ���� �ش��ϴ� ��Ŷ(����Ʈ) ��ȸ
		for (int v : data[hash_func(value)]) 
		{
			// �ش�Ǵ� ���� ������ true ��ȯ
			if (v == value) 
			{
				return true;
			}
		}

		// �ش�Ǵ� ���� ������ false ��ȯ
		return false;
	}

	void erase(unsigned value) 
	{
		// �ؽ� �� ��� �� �ش� ��Ŷ(����Ʈ) ����
		auto& ent = data[hash_func(value)];
		// �ش� ��Ŷ(����Ʈ)���� �� ã��
		auto iter = std::find(ent.begin(), ent.end(), value);

		// ���� ã���� ����
		if (iter != ent.end()) 
		{
			ent.erase(iter);
			cout << value << "����" << endl;
		}
	}
};

int main() {
	hash_map map(10);

	auto print_map = [&](int value) 
	{
		if (map.find(value)) 
		{
			cout << value << "ã��" << endl;
		}
		else 
		{
			cout << value << "�� ã��" << endl;
		}
	};

	map.insert(10);
	map.insert(5);
	map.insert(100);

	cout << endl;

	print_map(10);
	print_map(100);
	print_map(5);

	map.erase(5);

	print_map(5);
}