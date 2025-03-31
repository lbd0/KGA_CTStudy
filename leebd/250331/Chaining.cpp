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
				cout << "이미 있는 값입니다." << endl;
				return;
			}
		}

		data[HashFunc(value)].push_back(value);
		cout << value << "삽입, 해시값 : " << HashFunc(value) << endl;
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
			cout << value << "지움" << endl;
		}
	}
};

int main() {
	HashMap map(10);

	auto PrintMap = [&](int value)
		{
			if (map.Find(value))
			{
				cout << value << "찾음" << endl;
			}
			else
			{
				cout << value << "못 찾음" << endl;
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