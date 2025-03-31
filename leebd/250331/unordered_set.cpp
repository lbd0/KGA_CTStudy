#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

template <typename T>
void FindKey1(unordered_set<T> uset, T key)
{
	if (uset.find(key) != uset.end())
	{
		cout << key << "이(가) 존재함" << endl;
	}
	else
	{
		cout << key << "은(는) 존재하지 않음" << endl;
	}
}

template <typename T>
void FindKey2(unordered_set<T> uset, T key)
{
	if (uset.count(key) > 0)
	{
		cout << key << "이(가) 존재함" << endl;
	}
	else
	{
		cout << key << "은(는) 존재하지 않음" << endl;
	}
}

template <typename T>
void PrintAll1(unordered_set<T> uset)
{
	for (auto it = uset.begin(); it != uset.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

template <typename T>
void PrintAll2(unordered_set<T> uset)
{
	for (T value : uset)
	{
		cout << value << " ";
	}
	cout << endl;
}

int main() {
	unordered_set<int> us;

	us.insert(10);
	us.insert(3);
	us.insert(22);
	us.insert(99);

	FindKey1(us, 22);
	FindKey2(us, 4);

	PrintAll1(us);

	us.erase(99);
	cout << endl << "99지움" << endl;
	PrintAll2(us);

	// 모든 원소 삭제
	us.clear();

	// 비어 있는지 확인
	if (us.empty())
	{
		cout << "셋이 비어있음" << endl;
	}
	else
	{
		cout << "셋이 비어있지 않음" << endl;
	}

	us.insert(10);
	us.insert(3);
	us.insert(22);
	us.insert(99);

	cout << "사용 중인 버킷의 개수 : " << us.bucket_count() << endl;
	cout << "적재율 : " << us.load_factor() << endl;

	us.rehash(20);
	cout << "사용 중인 버킷의 개수 : " << us.bucket_count() << endl;
	cout << "적재율 : " << us.load_factor() << endl;
}