#include<iostream>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

class hash_map
{
	vector<list<int>>data;//int���� list�� ���� �ִ� vector

public:
	hash_map(size_t n)
	{
		data.resize(n);//data ���� �뷮 ���Ҵ�
	}

	int hash_func(int value)
	{
		return value % data.size();//���� value ���� data.size�� ���� ������(�ؽ��Լ�)
	}

	void insert(unsigned int value)
	{
		for (int v : data[hash_func(value)])//�ؽ̰��� ����� �� ã��
		{
			if (v == value)//for�� ��������, ���� ���� �ִٸ�,
			{
				cout << "�̹� �ִ� ���Դϴ�." << endl;//���
				return;
			}
		}

		data[hash_func(value)].push_back(value);//���ٸ�, ���� �ؽ��Լ��� ����Ͽ� �ؽ̰��� ����
		cout << value << "����, �ؽð� : " << hash_func(value) << endl;
	}

	bool find(unsigned int value)
	{
		for (int v : data[hash_func(value)])//�ؽ̰��� ����� �� ã��
		{
			if (v == value)//for�� ��������, ���� ���� �ִٸ�
			{
				return true;//true ����
			}
		}

		return false;//�ƴϸ� false ����
	}

	void erase(unsigned value)
	{
		auto& ent = data[hash_func(value)];//�ؽ��� ����� �ش� ����Ʈ ����

		auto iter = std::find(ent.begin(), ent.end(), value);//ent for�� ������ value �� ã��

		if (iter != ent.end())//for�� ������ �������� ���Դٸ�
		{
			ent.erase(iter);//�ش��ϴ� �༮�� ������
			cout << value << "����" << endl;
		}

	}


};

//int main()
//{
//	hash_map map(10);
//
//	auto print_map = [&](int value)
//	{
//		if (map.find(value))
//		{
//			cout << value<<"ã��" << endl;
//		}
//
//		else
//		{
//			cout << value << "��ã��" << endl;
//		}
//
//	};
//
//	map.insert(10);
//	map.insert(5);
//	map.insert(100);
//
//	cout << endl;
//
//	print_map(10);
//	print_map(100);
//	print_map(5);
//
//	map.erase(5);
//
//	print_map(5);
//	
//}