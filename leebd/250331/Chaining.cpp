#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class HashMap
{
	vector<list<int>> data;

public:
	HashMap(size_t n)
	{
		data.resize(n);
	}

	int HashFunc(int value)
	{
		return value % data.size();
	}

	void Insert(unsigned int value)
	{
		for (int v : data[HashFunc(value)])
		{
			if (v == value)
			{
				cout << "�̹� �ִ� ���Դϴ�." << endl;
				return;
			}
		}

		data[HashFunc(value)].push_back(value);
		cout << value << "����, �ؽð� : " << HashFunc(value) << endl;
	}

	bool Find(unsigned int value)
	{
		for (int v : data[HashFunc(value)])
		{
			if (v == value)
			{
				return true;
			}
		}

		return false;
	}

	void Erase(unsigned value)
	{
		auto& ent = data[HashFunc(value)];
		auto iter = find(ent.begin(), ent.end(), value);

		if (iter != ent.end())
		{
			ent.erase(iter);
			cout << value << "����" << endl;
		}
	}
};

int main() {
	HashMap map(10);

	auto PrintMap = [&](int value)
		{
			if (map.Find(value))
			{
				cout << value << "ã��" << endl;
			}
			else
			{
				cout << value << "�� ã��" << endl;
			}
		};

	map.Insert(10);
	map.Insert(5);
	map.Insert(100);

	cout << endl;

	PrintMap(10);
	PrintMap(100);
	PrintMap(5);

	map.Erase(5);

	PrintMap(5);
}