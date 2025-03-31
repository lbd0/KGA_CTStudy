#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

template<typename pair1>
void find_key1(unordered_set<pair1>uset, pair1 key)
{
	if (uset.find(key) != uset.end())//키 값이 존재
	{
		cout << key << "이(가) 존재함" << endl;
	}
	else
	{
		cout << key << "은(는) 존재하지 않음" << endl;
	}
}

template<typename pair1>
void find_key2(unordered_set<pair1>uset, pair1 key)
{
	if (uset.count(30) > 0)//
	{
		cout << key << " 존재함" << endl;

	}
	else
	{
		cout << key << " 존재하지 않음" << endl;
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

	find_key1(us, 22);//unordered_set us에 22가 있는지?->존재
	find_key2(us, 4);//unordered_set us에 4가 있는지?->존재X

	print_all2(us);//전부다 프린트

	us.erase(99);//99삭제
	
	print_all2(us);//전부다 프린트

	us.clear();//전부다 삭제

	if (us.empty())//비어있는가?
	{
		cout << "빔" << endl;
	}
	else
	{
		cout << "있음" << endl;
	}

	us.insert(10);
	us.insert(3);
	us.insert(22);
	us.insert(99);

	cout<<us.bucket_count() << endl;//버킷개수 반환

	cout << us.load_factor() << endl;//적재율

	us.rehash(20);//20으로 리해쉬

	cout << us.bucket_count() << endl;

	cout << us.load_factor() << endl;


}