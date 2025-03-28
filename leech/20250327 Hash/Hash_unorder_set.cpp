#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

template <typename pair1>
void find_key1(unordered_set<pair1> uset, pair1 key) 
{
	if (uset.find(key) != uset.end()) 
	{
		std::cout << key << "��(��) ������" << endl;
	}
	else {
		std::cout << key << "��(��) �������� ����" << endl;
	}
}

template <typename pair1>
void find_key2(unordered_set<pair1> uset, pair1 key) 
{
	// count(): ã�� ���� ������ 1, ������ 0 ��ȯ
	if (uset.count(30) > 0) 
	{
		std::cout << key << "��(��) ������" << endl;
	}
	else 
	{
		std::cout << key << "��(��) �������� ����" << endl;
	}
}

template <typename pair1>
void print_all1(unordered_set<pair1> uset) 
{
	for (auto it = uset.begin(); it != uset.end(); ++it) 
	{
		std::cout << *it << " ";
	}
	cout << endl;
}

template <typename pair1>
void print_all2(unordered_set<pair1> uset) 
{
	for (int num : uset) 
	{
		std::cout << num << " ";
	}
	cout << endl;
}


int main() {
	unordered_set<int> us;

	us.insert(10);
	us.insert(3);
	us.insert(22);
	us.insert(99);

	find_key1(us, 22);
	find_key2(us, 4);

	print_all2(us);

	us.erase(99);
	cout << endl << "99����" << endl;
	print_all2(us);

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

	//��� ���� �ؽ� ��Ŷ ���� ��ȯ
	cout << "��� ���� ��Ŷ�� ���� : " << us.bucket_count() << endl;
	//���� �ؽ� ���̺��� �������� ��ȯ(��� �� / ��Ŷ ��)
	cout << "������ : " << us.load_factor() << endl;

	//�ּ� n���� ��Ŷ�� �������� ���Ҵ�(���� ����ȭ)
	us.rehash(20);
	//��� ���� �ؽ� ��Ŷ ���� ��ȯ
	cout << "��� ���� ��Ŷ�� ���� : " << us.bucket_count() << endl;
	//���� �ؽ� ���̺��� �������� ��ȯ(��� �� / ��Ŷ ��)
	cout << "������ : " << us.load_factor() << endl;
}