#include<iostream>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

class hash_map
{
	vector<list<int>>data;//int형의 list를 갖고 있는 vector

public:
	hash_map(size_t n)
	{
		data.resize(n);//data 변수 용량 재할당
	}

	int hash_func(int value)
	{
		return value % data.size();//들어온 value 값을 data.size로 나눈 나머지(해싱함수)
	}

	void insert(unsigned int value)
	{
		for (int v : data[hash_func(value)])//해싱값에 저장된 값 찾기
		{
			if (v == value)//for문 돌렸을때, 같은 값이 있다면,
			{
				cout << "이미 있는 값입니다." << endl;//출력
				return;
			}
		}

		data[hash_func(value)].push_back(value);//없다면, 값을 해싱함수를 사용하여 해싱값에 저장
		cout << value << "삽입, 해시값 : " << hash_func(value) << endl;
	}

	bool find(unsigned int value)
	{
		for (int v : data[hash_func(value)])//해싱값에 저장된 값 찾기
		{
			if (v == value)//for문 돌렸을때, 같은 값이 있다면
			{
				return true;//true 리턴
			}
		}

		return false;//아니면 false 리턴
	}

	void erase(unsigned value)
	{
		auto& ent = data[hash_func(value)];//해쉬값 계산후 해당 리스트 참조

		auto iter = std::find(ent.begin(), ent.end(), value);//ent for문 돌려서 value 값 찾기

		if (iter != ent.end())//for문 끝까지 돌렸을때 나왔다면
		{
			ent.erase(iter);//해당하는 녀석을 지워라
			cout << value << "지움" << endl;
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
//			cout << value<<"찾음" << endl;
//		}
//
//		else
//		{
//			cout << value << "못찾음" << endl;
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