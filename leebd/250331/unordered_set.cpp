#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

template <typename T>
void FindKey1(unordered_set<T> uset, T key)
{
	if (uset.find(key) != uset.end())
	{
		cout << key << "��(��) ������" << endl;
	}
	else
	{
		cout << key << "��(��) �������� ����" << endl;
	}
}

template <typename T>
void FindKey2(unordered_set<T> uset, T key)
{
	if (uset.count(key) > 0)
	{
		cout << key << "��(��) ������" << endl;
	}
	else
	{
		cout << key << "��(��) �������� ����" << endl;
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
	cout << endl << "99����" << endl;
	PrintAll2(us);

	// ��� ���� ����
	us.clear();

	// ��� �ִ��� Ȯ��
	if (us.empty())
	{
		cout << "���� �������" << endl;
	}
	else
	{
		cout << "���� ������� ����" << endl;
	}

	us.insert(10);
	us.insert(3);
	us.insert(22);
	us.insert(99);

	cout << "��� ���� ��Ŷ�� ���� : " << us.bucket_count() << endl;
	cout << "������ : " << us.load_factor() << endl;

	us.rehash(20);
	cout << "��� ���� ��Ŷ�� ���� : " << us.bucket_count() << endl;
	cout << "������ : " << us.load_factor() << endl;
}