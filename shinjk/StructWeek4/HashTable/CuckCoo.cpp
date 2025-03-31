#include<iostream>
#include<vector>

using namespace std;

class hash_map
{
	vector<int>hashtable1;//해쉬테이블1
	vector<int>hashtable2;//해쉬테이블2

	int size;//해쉬테이블크기

	int hashfunc1(int value)//해쉬함수1
	{
		return value % size;
	}

	int hashfunc2(int value)//해쉬함수2
	{
		return (value / size) % size;
	}

public:
	hash_map(int size) :size(size)
	{
		hashtable1 = vector<int>(size, -1);
		hashtable2 = vector<int>(size, -1);
	}

	vector<int>::iterator lookup(int key)
	{
		if (hashtable1[hashfunc1(key)] == key)//해쉬테이블1에 해쉬함수1로 계산된 key가 존재하는가?
		{
			cout << "값이 존재함" << endl;
			return hashtable1.begin() + hashfunc1(key);
		}

		if (hashtable2[hashfunc2(key)] == key)//해쉬테이블2에 해쉬함수2로 계산된 key가 존재하는가?
		{
			cout << "값이 존재함" << endl;
			return hashtable2.begin() + hashfunc2(key);//hashtable1 오류난 것 같습니다.
		}

		return hashtable2.end();
	}

	void erase(int key)
	{
		auto addr = lookup(key);//lookup함수 이용하여 찾기

		if (addr != hashtable2.end())//해당 값이 있다면
		{
			*addr = -1;//빈 것으로 만들기
		}
	}

private:
	void insert_imp1(int key, int cnt, int table)
	{
		if (cnt >= size)//cnt가 사이즈보다 크거나 같다면
		{
			cout << "순환 발생 재해싱 필요" << endl;
			return;

		}

		else
		{
			if (table == 1)//hashtable이 1이라면
			{
				if (hashtable1[hashfunc1(key)] == -1)//hashtable1의 해쉬함수1을 이용한 값이 비어있다면
				{
					hashtable1[hashfunc1(key)] = key;//값 넣어주기

				}
				else
				{
					int old = hashtable1[hashfunc1(key)];//기존에 있던 값을 저장하고
					hashtable1[hashfunc1(key)] = key;//그 공간에 현재 key값 넣기
					cout << table << "번 테이블에" << key << "삽입,기존의 " << old << "이동" << endl;
					insert_imp1(old, cnt + 1, 2);//기존값을 테이블2로 옮기는 재귀함수
				}
			}
			else
			{
				if (hashtable2[hashfunc2(key)] == -1)//이하 동일
				{
					hashtable2[hashfunc2(key)] = key;

				}
				else
				{
					int old = hashtable2[hashfunc2(key)];
					hashtable2[hashfunc2(key)] = key;
					cout << table << "번 테이블에" << key << "삽입, 기존의 " << old << "이동" << endl;
					insert_imp1(old, cnt +1, 1);//기존값을 테이블1로 옮기는 재귀함수(나중에 cnt 값이 size와 크거나 같게되면 종료)
				}
			}
		}
	}

public:
	void insert(int key)
	{
		insert_imp1(key, 0, 1);//기본 insert. cnt=0, table=1
	}

	void print()
	{
		cout << "Index : ";
		for (int i = 0; i < size; ++i)
		{
			cout << i << '\t' << endl;
		}

		cout << "\n Table1 : ";
		for (auto value : hashtable1)
		{
			cout << value << '\t' << endl;
		}

		cout << "\n Table2 : ";
		for (auto value : hashtable2)
		{
			cout << value << '\t' << endl;
		}

	}
};



//int main()
//{
//	hash_map map(7);
//
//	map.print();
//
//	map.insert(10);
//	map.insert(20);
//	map.insert(30);
//	map.insert(104);
//	map.insert(2);
//	map.insert(70);
//	map.insert(9);
//	map.insert(90);
//	map.insert(2);
//	map.insert(7);
//
//	map.print();
//
//	map.insert(14);
//
//	map.print();
//}