#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

template<typename pair1>
void find_key1(unordered_set<pair1>uset, pair1 key)
{
	if (uset.find(key) != uset.end())//Ű ���� ����
	{
		cout << key << "��(��) ������" << endl;
	}
	else
	{
		cout << key << "��(��) �������� ����" << endl;
	}
}

template<typename pair1>
void find_key2(unordered_set<pair1>uset, pair1 key)
{
	if (uset.count(30) > 0)//
	{
		cout << key << " ������" << endl;

	}
	else
	{
		cout << key << " �������� ����" << endl;
	}
}

template<typename pair1>
void print_all1(unordered_set<pair1>uset)
{
	for (auto it = uset.begin(); it != uset.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

template<typename pair1>
void print_all2(unordered_set<pair1>uset)
{
	for (int num : uset)
	{
		cout << num << " ";
	}
	cout << endl;
}




int main()
{
	unordered_set<int> us;

	us.insert(10);
	us.insert(3);
	us.insert(22);
	us.insert(99);

	find_key1(us, 22);//unordered_set us�� 22�� �ִ���?->����
	find_key2(us, 4);//unordered_set us�� 4�� �ִ���?->����X

	print_all2(us);//���δ� ����Ʈ

	us.erase(99);//99����
	
	print_all2(us);//���δ� ����Ʈ

	us.clear();//���δ� ����

	if (us.empty())//����ִ°�?
	{
		cout << "��" << endl;
	}
	else
	{
		cout << "����" << endl;
	}

	us.insert(10);
	us.insert(3);
	us.insert(22);
	us.insert(99);

	cout<<us.bucket_count() << endl;//��Ŷ���� ��ȯ

	cout << us.load_factor() << endl;//������

	us.rehash(20);//20���� ���ؽ�

	cout << us.bucket_count() << endl;

	cout << us.load_factor() << endl;


}