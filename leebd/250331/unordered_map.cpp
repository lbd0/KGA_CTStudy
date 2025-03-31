#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

template <typename pair1, typename pair2>
void PrintUmap1(unordered_map<pair1, pair2> umap)
{
	for (auto& iter : umap)
	{
		cout << iter.first << " : " << iter.second << " ";
	}
	cout << endl;
}

template <typename pair1, typename pair2>
void PrintKeyAsValueMap1(unordered_map<pair1, pair2> umap, pair1 key)
{
	if (umap.find(key) != umap.end())
	{
		cout << umap.find(key)->second;
	}
	cout << endl;
}

template <typename pair1, typename pair2>
void PrintKeyAsValueMap2(unordered_map<pair1, pair2> umap, pair1 key)
{
	try
	{
		cout << umap.at(key) << endl;
	}
	catch (const exception&)
	{
		cout << "����" << endl;
	}
}

int main()
{
	unordered_map<int, int> um;

	um.insert({ 1, 3 });
	um.insert(pair<int, int>(2, 4));
	um[3] = 6;

	PrintUmap1(um);

	cout << "Ű�� 3�� ���� �� : ";
	PrintKeyAsValueMap1(um, 3);

	cout << "Ű�� 3�� ���� �� : ";
	PrintKeyAsValueMap2(um, 3);

	cout << um[3] << endl;
	cout << um[4] << endl;

	cout << "Ű�� 4�� ���� �� : ";
	PrintKeyAsValueMap1(um, 4);

	cout << "Ű�� 4�� ���� �� : ";
	PrintKeyAsValueMap2(um, 4);

	um.erase(3);

	if (um.count(3))
	{
		cout << "Ű 3�� ���� value ����" << endl;
	}
	else
	{
		cout << "Ű 3�� ���� value ���� X" << endl;
	}

	cout << "����� ���� ���� : " << um.size() << endl;

	um.clear();

	if (um.empty())
	{
		cout << "���� �������" << endl;
	}
	else
	{
		cout << "���� ������� ����" << endl;
	}

	um.insert({ 1, 3 });
	um.insert(pair<int, int>(2, 4));
	um[3] = 6;
	um[4] = 8;
	um[5] = 10;
	um[6] = 12;
	um[7] = 14;

	cout << "��� ���� ��Ŷ�� ���� : " << um.bucket_count() << endl;
	cout << "������ : " << um.load_factor() << endl;

	um.rehash(20);
	cout << "��� ���� ��Ŷ�� ���� : " << um.bucket_count() << endl;
	cout << "������ : " << um.load_factor() << endl;
}