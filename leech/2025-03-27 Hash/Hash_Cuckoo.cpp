#include <iostream>
#include <vector>

using namespace std;

class hash_map 
{
	// 2���� �ؽ� ���̺�
	vector<int> table1;
	vector<int> table2;

	int size;

	// �ؽ� �Լ� 1
	int hash_func1(int value) 
	{
		return value % size;
	}
	
	// �ؽ� �Լ� 2
	int hash_func2(int value) 
	{
		return (value / size) % size;
	}

public:
	hash_map(int size) : size(size) 
	{
		// ���� ũ��� ����
		table1 = vector<int>(size, -1);
		table2 = vector<int>(size, -1);
	}

	vector<int>::iterator lookup(int key) 
	{
		// ���� ���̺��� ���� �ٸ� �ؽ� �Լ� ���
		if (table1[hash_func1(key)] == key) 
		{
			cout << "���� ������" << endl;
			return table1.begin() + hash_func1(key);
		}

		if (table1[hash_func2(key)] == key) 
		{
			cout << "���� ������" << endl;
			return table1.begin() + hash_func2(key);
		}

		return table2.end();
	}

	void erase(int key) 
	{
		// ���� ã�� ���� lookup ȣ��
		auto addr = lookup(key);

		// �߰����� ���
		if (addr != table2.end())
		{
			// �� ����: ����ֱ� ������ -1�� ����
			*addr = -1;
		}
	}

private:
	void insert_imp1(int key, int cnt, int table) 
	{
		// ���̺� ũ�⺸�� cnt�� ũ�ų� ������ ���ؽ��� �ʿ��ϱ⿡ �ߴ�
		if (cnt >= size) 
		{
			cout << "��ȯ �߻� ���ؽ� �ʿ�" << endl;
			return;
		}
		else 
		{
			// ù ��° �ؽ� ���̺�
			if (table == 1) 
			{
				// �ؽ� �� ��� ��, �ش� ��ġ�� ������� Ȯ��
				if (table1[hash_func1(key)] == -1) 
				{
					// ����
					table1[hash_func1(key)] = key;
				}
				// ������� �ʴٸ�
				else 
				{
					// ������ �ؽ� ���� ����
					int old = table1[hash_func1(key)];
					// ���ο� ���� �ش� ��ġ�� ����
					table1[hash_func1(key)] = key;
					cout << table << "�� ���̺� " << key << "����, ������ " << old << "�̵�" << endl;
					// ������ �ؽ� �� �̵�
					insert_imp1(old, cnt + 1, 2);
				}
			}
			// �� ��° �ؽ� ���̺�
			else
			{
				// �ؽ� �� ��� ��, �ش� ��ġ�� ������� Ȯ��
				if (table2[hash_func2(key)] == -1)
				{
					// ����
					table2[hash_func2(key)] = key;
				}
				// ������� �ʴٸ�
				else
				{
					// ������ �ؽ� ���� ����
					int old = table2[hash_func2(key)];
					// ���ο� ���� �ش� ��ġ�� ����
					table2[hash_func2(key)] = key;
					cout << table << "�� ���̺� " << key << "����, ������ " << old << "�̵�" << endl;
					// ������ �ؽ� �� �̵�
					insert_imp1(old, cnt + 1, 1);
				}
			}
		}
	}

public:
	void insert(int key) 
	{
		insert_imp1(key, 0, 1);
	}

	void print() 
	{
		cout << "Index : ";
		for (int i = 0; i < size; ++i) 
		{
			cout << i << '\t' << endl;
		}

		cout << "\n Table1 : ";
		for (auto value : table1) 
		{
			cout << value << '\t' << endl;
		}

		cout << "\n Table2 : ";
		for (auto value : table2) 
		{
			cout << value << '\t' << endl;
		}
	}
};

int main() {
	hash_map map(7);

	map.print();

	map.insert(10);
	map.insert(20);
	map.insert(30);
	map.insert(104);
	map.insert(2);
	map.insert(70);
	map.insert(9);
	map.insert(90);
	map.insert(2);
	map.insert(7);

	map.print();

	map.insert(14);

	map.print();
}