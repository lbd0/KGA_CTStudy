#include <iostream>
#include <vector>

using namespace std;

class hash_map 
{
	// 2개의 해시 테이블
	vector<int> table1;
	vector<int> table2;

	int size;

	// 해시 함수 1
	int hash_func1(int value) 
	{
		return value % size;
	}
	
	// 해시 함수 2
	int hash_func2(int value) 
	{
		return (value / size) % size;
	}

public:
	hash_map(int size) : size(size) 
	{
		// 같은 크기로 생성
		table1 = vector<int>(size, -1);
		table2 = vector<int>(size, -1);
	}

	vector<int>::iterator lookup(int key) 
	{
		// 각각 테이블에서 서로 다른 해시 함수 사용
		if (table1[hash_func1(key)] == key) 
		{
			cout << "값이 존재함" << endl;
			return table1.begin() + hash_func1(key);
		}

		if (table1[hash_func2(key)] == key) 
		{
			cout << "값이 존재함" << endl;
			return table1.begin() + hash_func2(key);
		}

		return table2.end();
	}

	void erase(int key) 
	{
		// 값을 찾기 위해 lookup 호출
		auto addr = lookup(key);

		// 발견했을 경우
		if (addr != table2.end())
		{
			// 값 삭제: 비어있기 때문에 -1로 설정
			*addr = -1;
		}
	}

private:
	void insert_imp1(int key, int cnt, int table) 
	{
		// 테이블 크기보다 cnt가 크거나 같으면 재해싱이 필요하기에 중단
		if (cnt >= size) 
		{
			cout << "순환 발생 재해싱 필요" << endl;
			return;
		}
		else 
		{
			// 첫 번째 해시 테이블
			if (table == 1) 
			{
				// 해시 값 계산 후, 해당 위치가 비었는지 확인
				if (table1[hash_func1(key)] == -1) 
				{
					// 삽입
					table1[hash_func1(key)] = key;
				}
				// 비어있지 않다면
				else 
				{
					// 이전의 해시 값을 저장
					int old = table1[hash_func1(key)];
					// 새로운 값을 해당 위치에 저장
					table1[hash_func1(key)] = key;
					cout << table << "번 테이블에 " << key << "삽입, 기존의 " << old << "이동" << endl;
					// 이전의 해시 값 이동
					insert_imp1(old, cnt + 1, 2);
				}
			}
			// 두 번째 해시 테이블
			else
			{
				// 해시 값 계산 후, 해당 위치가 비었는지 확인
				if (table2[hash_func2(key)] == -1)
				{
					// 삽입
					table2[hash_func2(key)] = key;
				}
				// 비어있지 않다면
				else
				{
					// 이전의 해시 값을 저장
					int old = table2[hash_func2(key)];
					// 새로운 값을 해당 위치에 저장
					table2[hash_func2(key)] = key;
					cout << table << "번 테이블에 " << key << "삽입, 기존의 " << old << "이동" << endl;
					// 이전의 해시 값 이동
					insert_imp1(old, cnt + 1, 1);
				}
			}
		}
	}

public:
	void insert(int key) 
	{
		insert_imp1(key, 0, 1);
	}

	void print() 
	{
		cout << "Index : ";
		for (int i = 0; i < size; ++i) 
		{
			cout << i << '\t' << endl;
		}

		cout << "\n Table1 : ";
		for (auto value : table1) 
		{
			cout << value << '\t' << endl;
		}

		cout << "\n Table2 : ";
		for (auto value : table2) 
		{
			cout << value << '\t' << endl;
		}
	}
};

int main() {
	hash_map map(7);

	map.print();

	map.insert(10);
	map.insert(20);
	map.insert(30);
	map.insert(104);
	map.insert(2);
	map.insert(70);
	map.insert(9);
	map.insert(90);
	map.insert(2);
	map.insert(7);

	map.print();

	map.insert(14);

	map.print();
}