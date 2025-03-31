#include <iostream>
#include <vector>

using namespace std;

class HashMap
{
	vector<int> table1;
	vector<int> table2;

	int size;

	int HashFunc1(int value)
	{
		return value % size;
	}

	int HashFunc2(int value)
	{
		return (value / size) % size;
	}

public:
	HashMap(int size) : size(size)
	{
		table1 = vector<int>(size, -1);
		table2 = vector<int>(size, -1);
	}

	vector<int>::iterator LookUp(int key)
	{
		if (table1[HashFunc1(key)] == key)
		{
			cout << "값이 존재함" << endl;
			return table1.begin() + HashFunc1(key);
		}

		if (table1[HashFunc2(key)] == key)
		{
			cout << "값이 존재함" << endl;
			return table1.begin() + HashFunc2(key);
		}

		return table2.end();
	}

	void Erase(int key)
	{
		auto addr = LookUp(key);
		
		if (addr != table2.end())
		{
			*addr = -1;
		}
	}

private:
	void InsertImp1(int key, int cnt, int table)
	{
		if (cnt >= size)
		{
			cout << "순환 발생 재해싱 필요" << endl;
			return;
		}
		else
		{
			if (table == 1)
			{
				if (table1[HashFunc1(key)] == -1)
				{
					table1[HashFunc1(key)] = key;
				}
				else
				{
					int old = table1[HashFunc1(key)];
					table1[HashFunc1(key)] = key;
					cout << table << " 번 테이블에 " << key << "삽입, 기존의 " << old << "이동" << endl;
					InsertImp1(old, cnt + 1, 2);
				}
			}
			else
			{
				if (table2[HashFunc2(key)] == -1)
				{
					table2[HashFunc2(key)] = key;
				}
				else
				{
					int old = table2[HashFunc2(key)];
					table2[HashFunc2(key)] = key;
					cout << table << " 번 테이블에 " << key << "삽입, 기존의 " << old << "이동" << endl;
					InsertImp1(old, cnt + 1, 1);
				}
			}
		}
	}

public:
	void Insert(int key)
	{
		InsertImp1(key, 0, 1);
	}

	void Print()
	{
		cout << "Index : ";
		for (int i = 0; i < size; i++)
		{
			cout << i << '\t' << endl;
		}

		cout << "\n Table1 : ";
		for (auto value : table1)
		{
			cout << value << '\t' << endl;
		}

		cout << "\n Tanle 2 : ";
		for (auto value : table2)
		{
			cout << value << '\t' << endl;
		}
	}
};

int main() {
	HashMap map(7);

	map.Print();

	map.Insert(10);
	map.Insert(20);
	map.Insert(30);
	map.Insert(104);
	map.Insert(2);
	map.Insert(70);
	map.Insert(9);
	map.Insert(90);
	map.Insert(2);
	map.Insert(7);

	map.Print();

	map.Insert(14);

	map.Print();
}