#include<iostream>
#include<vector>
//key-> �ؽ��Լ�-> ������ ����
class hash_map
{
	std::vector<int> data1;	//�� ���ٱ� �Լ��ΰ� �ߴ��� ���ٱⰡ Ź�������� �ؼ� �׷��Ŷ��..
	std::vector<int> data2; //2���� ������ ������ 2�� ����
	int size;

	int hash1(int key) const
	{
		return key % size; //���⼭�� ���� �Լ��� �����
	}

	int hash2(int key) const
	{
		return (key / size) % size; //�̰͵� ���� �Լ��� ���� �� �˾Ҵµ� �浹 ����� �ٸ��� �ؾ� ���� ������ ������ �ʴ´ٰ�.
	}

public:
	hash_map(int n) : size(n)
	{
		data1 = std::vector<int>(size, -1); // -1�� �ʱ�ȭ. ����ִ� �۾�
		data2 = std::vector<int>(size, -1); 
	}

	std::vector<int>::iterator lookup(int key) //Ű�� �˻��ϰ� Ű�� ����� ��ġ�� ��Ÿ���� �ݺ���(������?)�� ��ȯ. 
	{											//ã�� ��ġ�� ������� ���� �����ϰų� ������ ��������
		auto hash_value1 = hash1(key);
		if (data1[hash_value1] == key)
		{
			std::cout << "1�� ���̺���" << key << "��(��) ã�ҽ��ϴ�." << std::endl;
			return data1.begin() + hash_value1;		//begin���� hash_value1���� �� ��ŭ ���� ã�� �ڷᰡ ���� ���̱� ����.
		}

		auto hash_value2 = hash2(key);
		if (data2[hash_value2] == key)
		{
			std::cout << "2�� ���̺���" << key << "��(��) ã�ҽ��ϴ�." << std::endl;
			return data2.begin() + hash_value2;	// hash1�� ����� ���� ������ �ƴ϶�� ���� ����. 
		}
		return data2.end();		// ��𿡼��� key�� ã�� ���ߴٰ� ��Ÿ���� ����.
	}

	void erase(int key)
	{
		auto position = lookup(key);
		if (position != data2.end())
		{
			*position = -1; // ���� ��
			std::cout << key << "�� �ش��ϴ� ���Ҹ� �����߽��ϴ�." << std::endl;
		}
		else
		{
			std::cout << key << "Ű�� ã�� ���߽��ϴ�" << std::endl;
		}
	}

	void insert(int key)	//��������� ������ �ϴ� �����Լ�. �����θ� ���� ����.
	{
		insert_impl(key, 0, 1);
	}

	void insert_impl(int key, int cnt, int table) // cnt�� ���ȣ�� Ƚ��, table�� Ű�� ������ ���̺� ��ȣ.
	{							//�����ϰ� �����Ұ� ���� �Ѱܳ��� �ٸ� ��� ã�ư��ٰ� �����ϸ� ��(���)
								// 17(key)�� �ְ� ������ hash1(key)�� key%5, �� 2 
		if (cnt >= size)
		{
			std::cout << key << "���� �� ��ȯ �߻�! ���ؽ��� �ʿ��մϴ�" << std::endl;
			return;
		}

		if (table == 1)
		{
			int hash = hash1(key); 
			if (data1[hash] == -1)  //data1�� hash1[key], �� data1[2]�� Ȯ���� ����ִٸ� ����
			{
				std::cout << table << "�� ���̺�" << key << "����" << std::endl;
				data1[hash] = key;
			}
			else						//������� �ʴٸ� old�� �о�� key�� ����. old�� �̵�
			{
				int old = data1[hash];
				data1[hash] = key;
				std::cout << table << "�� ���̺�" << key << "����: ������" << old << "�̵� ->";
				insert_impl(old, cnt + 1, 2);
			}
		}
		else {
			int hash = hash2(key);
			if (data2[hash] == -1)	//data2�� hash2[key], �� �Ʊ� ������ return (key / size) % size; �䰪�� hash������ �޾ƿ�.
									
			{
				std::cout << table << "�� ���̺�" << key << "����" << std::endl;
				data2[hash] = key;
			}
			else
			{							//�굵 old ������ �о�� �� ���������� table�� 2�� �ƴ� 1�� �̵��Ѵٴ� �������� ����.
				int old = data2[hash];
				data2[hash] = key;
				std::cout << table << "�� ���̺�" << key << "����: ������" << old << "�̵� ->";
				insert_impl(old, cnt + 1, 1);
			}
		}
	}

	void print()		//������ �Լ��μ� �����ϴ�
	{
		std::cout << "Index: ";
		for (int i = 0; i < size; i++)
			std::cout << i << '\t';
		std::cout << std::endl;

		std::cout << "Data1: ";
		for (auto i : data1)
			std::cout << i << '\t';
		std::cout << std::endl;

		std::cout << "Data2: ";
		for (auto i : data2)
			std::cout << i << '\t';
		std::cout << std::endl;
	}
};

int main()

{
	hash_map map(7);
	map.print();
	std::cout << std::endl;

	map.insert(10);
	map.insert(20);
	map.insert(30);
	std::cout << std::endl;

	map.insert(104);
	map.insert(2);
	map.insert(70);
	map.insert(9);
	map.insert(90);
	map.insert(2);
	map.insert(7);
	std::cout << std::endl;
	
	map.insert(14);

	/*
	�Լ� ���� ���
	Index: 0        1       2       3       4       5       6
	Data1: -1       -1      -1      -1      -1      -1      -1
	Data2: -1       -1      -1      -1      -1      -1      -1

	1�� ���̺� 10����
	1�� ���̺� 20����
	1�� ���̺� 30����

	1�� ���̺� 104 ����: ������20�̵� ->2�� ���̺�20����
	1�� ���̺� 2 ����: ������30�̵� ->2�� ���̺�30����
	1�� ���̺� 70����
	1�� ���̺� 9����: ������ 2�̵� ->2�� ���̺� 2����
	1�� ���̺� 90����: ������ 104�̵� ->2�� ���̺� 104����: ������2�̵� ->1�� ���̺� 2����: ������ 9�̵� ->2�� ���̺� 9����
	1�� ���̺� 2����: ������ 2�̵� ->2�� ���̺� 2����: ������ 104�̵� ->1�� ���̺� 104����: ������ 90�̵� ->2�� ���̺�	90����
	1�� ���̺� 7����: ������ 70�̵� ->2�� ���̺� 70����

	1�� ���̺� 14����: ������ 7�̵� ->2�� ���̺� 7����: ������ 9�̵� ->1�� ���̺� 9����: ������ 2�̵� ->2�� ���̺� 2����:  ������ 2�̵� ->1�� ���̺� 2����: ������ 9�̵� 
	->2�� ���̺� 9����: ������ 7�̵� ->1�� ���̺� 7����: ������ 14�̵� ->14 ���� �� ��ȯ �߻�! ���ؽ��� �ʿ��մϴ�
	
	*/
}