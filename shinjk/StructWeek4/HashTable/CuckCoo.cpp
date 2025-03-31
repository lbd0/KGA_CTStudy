#include<iostream>
#include<vector>

using namespace std;

class hash_map
{
	vector<int>hashtable1;//�ؽ����̺�1
	vector<int>hashtable2;//�ؽ����̺�2

	int size;//�ؽ����̺�ũ��

	int hashfunc1(int value)//�ؽ��Լ�1
	{
		return value % size;
	}

	int hashfunc2(int value)//�ؽ��Լ�2
	{
		return (value / size) % size;
	}

public:
	hash_map(int size) :size(size)
	{
		hashtable1 = vector<int>(size, -1);
		hashtable2 = vector<int>(size, -1);
	}

	vector<int>::iterator lookup(int key)
	{
		if (hashtable1[hashfunc1(key)] == key)//�ؽ����̺�1�� �ؽ��Լ�1�� ���� key�� �����ϴ°�?
		{
			cout << "���� ������" << endl;
			return hashtable1.begin() + hashfunc1(key);
		}

		if (hashtable2[hashfunc2(key)] == key)//�ؽ����̺�2�� �ؽ��Լ�2�� ���� key�� �����ϴ°�?
		{
			cout << "���� ������" << endl;
			return hashtable2.begin() + hashfunc2(key);//hashtable1 ������ �� �����ϴ�.
		}

		return hashtable2.end();
	}

	void erase(int key)
	{
		auto addr = lookup(key);//lookup�Լ� �̿��Ͽ� ã��

		if (addr != hashtable2.end())//�ش� ���� �ִٸ�
		{
			*addr = -1;//�� ������ �����
		}
	}

private:
	void insert_imp1(int key, int cnt, int table)
	{
		if (cnt >= size)//cnt�� ������� ũ�ų� ���ٸ�
		{
			cout << "��ȯ �߻� ���ؽ� �ʿ�" << endl;
			return;

		}

		else
		{
			if (table == 1)//hashtable�� 1�̶��
			{
				if (hashtable1[hashfunc1(key)] == -1)//hashtable1�� �ؽ��Լ�1�� �̿��� ���� ����ִٸ�
				{
					hashtable1[hashfunc1(key)] = key;//�� �־��ֱ�

				}
				else
				{
					int old = hashtable1[hashfunc1(key)];//������ �ִ� ���� �����ϰ�
					hashtable1[hashfunc1(key)] = key;//�� ������ ���� key�� �ֱ�
					cout << table << "�� ���̺�" << key << "����,������ " << old << "�̵�" << endl;
					insert_imp1(old, cnt + 1, 2);//�������� ���̺�2�� �ű�� ����Լ�
				}
			}
			else
			{
				if (hashtable2[hashfunc2(key)] == -1)//���� ����
				{
					hashtable2[hashfunc2(key)] = key;

				}
				else
				{
					int old = hashtable2[hashfunc2(key)];
					hashtable2[hashfunc2(key)] = key;
					cout << table << "�� ���̺�" << key << "����, ������ " << old << "�̵�" << endl;
					insert_imp1(old, cnt +1, 1);//�������� ���̺�1�� �ű�� ����Լ�(���߿� cnt ���� size�� ũ�ų� ���ԵǸ� ����)
				}
			}
		}
	}

public:
	void insert(int key)
	{
		insert_imp1(key, 0, 1);//�⺻ insert. cnt=0, table=1
	}

	void print()
	{
		cout << "Index : ";
		for (int i = 0; i < size; ++i)
		{
			cout << i << '\t' << endl;
		}

		cout << "\n Table1 : ";
		for (auto value : hashtable1)
		{
			cout << value << '\t' << endl;
		}

		cout << "\n Table2 : ";
		for (auto value : hashtable2)
		{
			cout << value << '\t' << endl;
		}

	}
};



//int main()
//{
//	hash_map map(7);
//
//	map.print();
//
//	map.insert(10);
//	map.insert(20);
//	map.insert(30);
//	map.insert(104);
//	map.insert(2);
//	map.insert(70);
//	map.insert(9);
//	map.insert(90);
//	map.insert(2);
//	map.insert(7);
//
//	map.print();
//
//	map.insert(14);
//
//	map.print();
//}