#include<iostream>
#include<vector>
//key-> 해시함수-> 접근의 로직
class hash_map
{
	std::vector<int> data1;	//왜 뻐꾸기 함수인가 했더니 뻐꾸기가 탁란행위를 해서 그런거라고..
	std::vector<int> data2; //2개를 돌린다 했으니 2개 선언
	int size;

	int hash1(int key) const
	{
		return key % size; //여기서도 모듈로 함수를 사용함
	}

	int hash2(int key) const
	{
		return (key / size) % size; //이것도 모듈로 함수를 쓰는 줄 알았는데 충돌 방식을 다르게 해야 무한 루프에 빠지지 않는다고.
	}

public:
	hash_map(int n) : size(n)
	{
		data1 = std::vector<int>(size, -1); // -1로 초기화. 비워주는 작업
		data2 = std::vector<int>(size, -1); 
	}

	std::vector<int>::iterator lookup(int key) //키를 검색하고 키가 저장된 위치를 나타내는 반복자(포인터?)를 반환. 
	{											//찾은 위치를 기반으로 쉽게 삭제하거나 수정이 가능해짐
		auto hash_value1 = hash1(key);
		if (data1[hash_value1] == key)
		{
			std::cout << "1번 테이블에서" << key << "을(를) 찾았습니다." << std::endl;
			return data1.begin() + hash_value1;		//begin에서 hash_value1까지 간 만큼 가야 찾는 자료가 있을 것이기 때문.
		}

		auto hash_value2 = hash2(key);
		if (data2[hash_value2] == key)
		{
			std::cout << "2번 테이블에서" << key << "을(를) 찾았습니다." << std::endl;
			return data2.begin() + hash_value2;	// hash1과 연결된 연속 로직은 아니라는 점에 유념. 
		}
		return data2.end();		// 어디에서도 key를 찾지 못했다고 나타내는 관습.
	}

	void erase(int key)
	{
		auto position = lookup(key);
		if (position != data2.end())
		{
			*position = -1; // 없는 값
			std::cout << key << "에 해당하는 원소를 삭제했습니다." << std::endl;
		}
		else
		{
			std::cout << key << "키를 찾지 못했습니다" << std::endl;
		}
	}

	void insert(int key)	//재귀적으로 만들어야 하는 삽입함수. 구현부를 따로 만듦.
	{
		insert_impl(key, 0, 1);
	}

	void insert_impl(int key, int cnt, int table) // cnt는 재귀호출 횟수, table은 키를 삽입할 테이블 번호.
	{							//복잡하게 생각할건 없고 쫓겨나면 다른 살길 찾아간다고 생각하면 됨(재귀)
								// 17(key)을 넣고 싶은데 hash1(key)는 key%5, 즉 2 
		if (cnt >= size)
		{
			std::cout << key << "삽입 시 순환 발생! 재해싱이 필요합니다" << std::endl;
			return;
		}

		if (table == 1)
		{
			int hash = hash1(key); 
			if (data1[hash] == -1)  //data1의 hash1[key], 즉 data1[2]를 확인해 비어있다면 삽입
			{
				std::cout << table << "번 테이블에" << key << "삽입" << std::endl;
				data1[hash] = key;
			}
			else						//비어있지 않다면 old는 밀어내고 key를 삽입. old는 이동
			{
				int old = data1[hash];
				data1[hash] = key;
				std::cout << table << "빈 테이블에" << key << "삽입: 기존의" << old << "이동 ->";
				insert_impl(old, cnt + 1, 2);
			}
		}
		else {
			int hash = hash2(key);
			if (data2[hash] == -1)	//data2의 hash2[key], 즉 아까 선언한 return (key / size) % size; 요값을 hash값으로 받아옴.
									
			{
				std::cout << table << "빈 테이블에" << key << "삽입" << std::endl;
				data2[hash] = key;
			}
			else
			{							//얘도 old 있으면 밀어내는 건 마찬가진데 table이 2가 아닌 1로 이동한다는 차이점은 있음.
				int old = data2[hash];
				data2[hash] = key;
				std::cout << table << "빈 테이블에" << key << "삽입: 기존의" << old << "이동 ->";
				insert_impl(old, cnt + 1, 1);
			}
		}
	}

	void print()		//디버깅용 함수로서 적절하다
	{
		std::cout << "Index: ";
		for (int i = 0; i < size; i++)
			std::cout << i << '\t';
		std::cout << std::endl;

		std::cout << "Data1: ";
		for (auto i : data1)
			std::cout << i << '\t';
		std::cout << std::endl;

		std::cout << "Data2: ";
		for (auto i : data2)
			std::cout << i << '\t';
		std::cout << std::endl;
	}
};

int main()

{
	hash_map map(7);
	map.print();
	std::cout << std::endl;

	map.insert(10);
	map.insert(20);
	map.insert(30);
	std::cout << std::endl;

	map.insert(104);
	map.insert(2);
	map.insert(70);
	map.insert(9);
	map.insert(90);
	map.insert(2);
	map.insert(7);
	std::cout << std::endl;
	
	map.insert(14);

	/*
	함수 실행 결과
	Index: 0        1       2       3       4       5       6
	Data1: -1       -1      -1      -1      -1      -1      -1
	Data2: -1       -1      -1      -1      -1      -1      -1

	1번 테이블에 10삽입
	1번 테이블에 20삽입
	1번 테이블에 30삽입

	1빈 테이블에 104 삽입: 기존의20이동 ->2빈 테이블에20삽입
	1빈 테이블에 2 삽입: 기존의30이동 ->2빈 테이블에30삽입
	1번 테이블에 70삽입
	1빈 테이블에 9삽입: 기존의 2이동 ->2빈 테이블에 2삽입
	1빈 테이블에 90삽입: 기존의 104이동 ->2빈 테이블에 104삽입: 기존의2이동 ->1빈 테이블에 2삽입: 기존의 9이동 ->2빈 테이블에 9삽입
	1빈 테이블에 2삽입: 기존의 2이동 ->2빈 테이블에 2삽입: 기존의 104이동 ->1빈 테이블에 104삽입: 기존의 90이동 ->2빈 테이블에	90삽입
	1빈 테이블에 7삽입: 기존의 70이동 ->2빈 테이블에 70삽입

	1빈 테이블에 14삽입: 기존의 7이동 ->2빈 테이블에 7삽입: 기존의 9이동 ->1빈 테이블에 9삽입: 기존의 2이동 ->2빈 테이블에 2삽입:  기존의 2이동 ->1빈 테이블에 2삽입: 기존의 9이동 
	->2빈 테이블에 9삽입: 기존의 7이동 ->1빈 테이블에 7삽입: 기존의 14이동 ->14 삽입 시 순환 발생! 재해싱이 필요합니다
	
	*/
}