#include <iostream>
#include <vector>

using namespace std;

class hash_map {
	std::vector<int> data;

public:
	/// <summary>
	/// 생성자
	/// </summary>
	/// <param name="n">테이블 크기</param>
	hash_map(size_t n) {
		data = vector<int>(n, -1);
	}

	/// <summary>
	/// 해시 함수
	/// </summary>
	/// <param name="value">키</param>
	/// <returns>해시 값</returns>
	int hash_func(int value) {
		return value % data.size();
	}

	/// <summary>
	/// 삽입
	/// </summary>
	/// <param name="value">삽입 값</param>
	void insert(unsigned int value) {
		data[hash_func(value)] = value;
		cout << value << "삽입, 해시값 : " << hash_func(value) << endl;
	}

	/// <summary>
	/// 찾기
	/// </summary>
	/// <param name="value">찾을 값</param>
	/// <returns>true면 해시 테이블 안에 있음, false면 테이블 안에 없음</returns>
	bool find(unsigned int value) {
		return data[hash_func(value)] == value;
	}

	/// <summary>
	/// 삭제
	/// </summary>
	/// <param name="value">삭제할 값</param>
	void erase(unsigned value) {
		if (data[hash_func(value)] == value) {
			data[hash_func(value)] = -1;
		}
	}
};

int main() {
	hash_map map(10);
	
	auto print_map = [&](int value) {
		if (map.find(value)) {
			cout << value << "찾음" << endl;
		}
		else {
			cout << value << "못 찾음" << endl;
		}
	};

	map.insert(10);
	map.insert(5);
	map.insert(100);

	cout << endl;

	print_map(10);	// 못 찾음
	print_map(100);	// 찾음
	print_map(5);	// 찾음
}