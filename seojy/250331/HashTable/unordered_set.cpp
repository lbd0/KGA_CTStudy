#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

template<typename pair1>
void find_key1(unordered_set<pair1>uset, pair1 key)
{
	if (uset.find(key) != uset.end())
	{
		std::cout << key << "이(가) 존재함 " << endl;
	}
	else
	{
		cout << key << "은(는) 존재하지 않음" << endl;
	}
}

template<typename pair1>
void find_key2(unordered_set<pair1>uset, pair1 key)
{
	//count() : 찾는 수가 있으면 1, 없으면 0 반환
	if (uset.count(30) > 0)
	{
		cout << key << "이(가) 존재함." << endl;
	}
	else
	{
		cout << key << "은(는) 존재하지 않음" << endl;
	}
}

template <typename pair1>
void print_all1(unordered_set<pair1> uset)
{
	for (auto it = uset.begin(); it != uset.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

template<typename pair1>
void print_all2(unordered_set<pair1> uset)
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

	find_key1(us, 22);
	find_key2(us, 4);

	print_all2(us);

	us.erase(99);

	cout << endl << "99지움" << endl;
	print_all2(us);

	//모든 원소 삭제
	us.clear();

	//비어 있는지 확인
	if (us.empty())
	{
		cout << "셋이 비어있음" << endl;
	}
	else
	{
		cout << "셋이 비어 있지 않음" << endl;
	}

	us.insert(10);
	us.insert(3);
	us.insert(22);
	us.insert(99);


	//사용 중인 해시 버킷 개수 반환
	cout << "사용 중인 버킷의 개수 : " << us.bucket_count() << endl;
	//현재 해시 테이블의 적재율을 반환
	cout << "적재율 : " << us.load_factor() << endl;
	
	// 최소 n개의 버킷을 가지도록 재할당
	us.rehash(20);

	// 사용중인 해시 버킷 개수 반환
	cout << "사용 중인 버킷의 개수 : " << us.bucket_count() << endl;

	//현재 해시 테이블의 적재율을 반환 
	cout << "적재율 : " << us.load_factor() << endl;


}
