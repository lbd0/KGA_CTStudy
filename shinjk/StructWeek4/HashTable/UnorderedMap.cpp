#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

template<typename pair1,typename pair2>
void print_umap1(unordered_map<pair1, pair2>umap)//unordered_map Ű, �� ���
{
	for (auto& iter : umap)
	{
		cout << iter.first << " : " << iter.second << " ";

	}
	cout << endl;
}

template<typename pair1, typename pair2>
void print_key_as_value_map1(unordered_map<pair1,pair2>umap,pair1 key)//unordered_map Ű�� ���� �� ã�Ƴ���
{
	if (umap.find(key) != umap.end())
	{
		cout << umap.find(key)->second;
	}
	cout << endl;
}

template<typename pair1, typename pair2>
void print_key_as_value_map2(unordered_map<pair1, pair2>umap, pair1 key)//unordered_map Ű�� ���� �� ã�Ƴ���2
{
	try
	{
		cout << umap.at(key) << endl;//���ܹ߻� ��������
	}
	catch (const std::exception&)
	{
		cout << "����" << endl;//����ó�� �ڵ�
	}
}


//int main()
//{
//	unordered_map<int, int>um;
//
//	um.insert({ 1,3 });//Ű 1, �� 3 ����
//	um.insert(pair<int, int>(2, 4));//Ű2, �� 4 ����
//	um[3] = 6;//Ű3, �� 6 ����
//
//	print_umap1(um);//���� ����Ʈ
//
//	cout << endl;
//
//	cout << "Ű�� 3�� ���� �� : ";
//	print_key_as_value_map1(um, 3);//Ű 3�� �ش��ϴ� �� ���
//
//	print_key_as_value_map2(um, 3);// ����
//
//	cout << um[3] << endl;
//	cout << um[4] << endl;
//
//	cout << "Ű�� 4�� ���� �� : ";
//	print_key_as_value_map1(um, 4);//Ű 4�� �ش��ϴ� �� ���
//
//	print_key_as_value_map2(um, 4);//����
//
//	um.erase(3);//Ű 3 ����
//
//	if (um.count(3))//3�� �����ϴ� �� ������ true
//	{
//		cout << "Ű 3�� ���� �� ������" << endl;
//	}
//	else
//	{
//		cout << "Ű 3�� ���� �� �������� ����" << endl;
//	}
//
//	cout << "����� ������ ���� : " << um.size() << endl;//����� ������ ����
//
//	um.clear();//����
//
//	if (um.empty())//����ִ��� ����
//	{
//		cout << "�������" << endl;
//	}
//	else
//	{
//		cout << "����" << endl;
//	}
//
//	um.insert({ 1,3 });//�� ����
//	um.insert(pair<int, int>(2, 4));//�� ����
//	um[3] = 6;//�� ����
//	um[4] = 8;//Ű4, �� 8
//	um[5] = 10;//Ű5, �� 10
//
//
//	cout << "��� ���� ��Ŷ�� ���� : " << um.bucket_count() << endl;//��� ���� ��Ŷ ���� ��ȯ
//	cout << "������ : " << um.load_factor() << endl;//������ ��ȯ
//
//	um.rehash(20);//20���� ��Ŷ�� ����ϵ��� ���� ����
//	cout << "��� ���� ��Ŷ�� ���� : " << um.bucket_count() << endl;
//	cout << "������ : " << um.load_factor() << endl;
//
//}