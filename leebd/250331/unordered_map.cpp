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
		cout << "없음" << endl;
	}
}

int main()
{
	unordered_map<int, int> um;

	um.insert({ 1, 3 });
	um.insert(pair<int, int>(2, 4));
	um[3] = 6;

	PrintUmap1(um);

	cout << "키가 3인 것의 값 : ";
	PrintKeyAsValueMap1(um, 3);

	cout << "키가 3인 것의 값 : ";
	PrintKeyAsValueMap2(um, 3);

	cout << um[3] << endl;
	cout << um[4] << endl;

	cout << "키가 4인 것의 값 : ";
	PrintKeyAsValueMap1(um, 4);

	cout << "키가 4인 것의 값 : ";
	PrintKeyAsValueMap2(um, 4);

	um.erase(3);

	if (um.count(3))
	{
		cout << "키 3에 대한 value 존재" << endl;
	}
	else
	{
		cout << "키 3에 대한 value 존재 X" << endl;
	}

	cout << "저장된 원소 개수 : " << um.size() << endl;

	um.clear();

	if (um.empty())
	{
		cout << "맵이 비어있음" << endl;
	}
	else
	{
		cout << "맵이 비어있지 않음" << endl;
	}

	um.insert({ 1, 3 });
	um.insert(pair<int, int>(2, 4));
	um[3] = 6;
	um[4] = 8;
	um[5] = 10;
	um[6] = 12;
	um[7] = 14;

	cout << "사용 중인 버킷의 개수 : " << um.bucket_count() << endl;
	cout << "적재율 : " << um.load_factor() << endl;

	um.rehash(20);
	cout << "사용 중인 버킷의 개수 : " << um.bucket_count() << endl;
	cout << "적재율 : " << um.load_factor() << endl;
}