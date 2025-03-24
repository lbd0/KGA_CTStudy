#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/// <summary>
/// 전체 출력하는 함수
/// </summary>
/// <typeparam name="pair1">맵의 key 자료형</typeparam>
/// <typeparam name="pair2">맵의 value 자료형</typeparam>
/// <param name="umap">전체 출력할 맵</param>
template <typename pair1, typename pair2>
void print_umap1(unordered_map<pair1, pair2> umap) {
	for (auto& iter : umap) {
		cout << iter.first << " : " << iter.second << " ";
	}
	cout << endl;
}

/// <summary>
/// 맵에서 키로 값을 출력하는 함수 1
/// </summary>
/// <typeparam name="pair1">맵의 key 자료형</typeparam>
/// <typeparam name="pair2">맵의 value 자료형</typeparam>
/// <param name="umap">찾을 맵</param>
/// <param name="key">키 값</param>
template <typename pair1, typename pair2>
void print_key_as_value_map1(unordered_map<pair1, pair2> umap, pair1 key) {
	if (umap.find(key) != umap.end()) {
		cout << umap.find(key)->second;
	}
	cout << endl;
}

/// <summary>
/// 맵에서 키로 값을 출력하는 함수 2
/// </summary>
/// <typeparam name="pair1">맵의 key 자료형</typeparam>
/// <typeparam name="pair2">맵의 value 자료형</typeparam>
/// <param name="umap">찾을 맵</param>
/// <param name="key">키 값</param>
template <typename pair1, typename pair2>
void print_key_as_value_map2(unordered_map<pair1, pair2> umap, pair1 key) {
	try
	{
		cout << umap.at(key) << endl;
	}
	catch (const std::exception&)
	{
		cout << "없음" << endl;
	}
}

int main() {

	unordered_map<int, int> um;

	// 맵에 삽입하는 방법
	um.insert({ 1, 3 });				// 방법 1
	um.insert(pair<int, int>(2, 4));	// 방법 2
	um[3] = 6;							// 방법 3

	print_umap1(um);

	cout << endl;

	// 맵의 값을 받는 방법
	cout << "키가 3인것의 값 : ";
	
	print_key_as_value_map1(um, 3);

	cout << "키가 3인것의 값 : ";
	print_key_as_value_map2(um, 3);


	cout << um[3] << endl;
	cout << um[4] << endl;

	// 맵의 값을 받는 방법
	cout << "키가 4인것의 값 : ";

	print_key_as_value_map1(um, 4);

	cout << "키가 4인것의 값 : ";
	print_key_as_value_map2(um, 4);

	um.erase(3); // 해당 key를 삭제

	//um.count(3);	// key가 존재하는지 확인(1 또는 0 반환)
	if (um.count(3)) {
		cout << "키 3에 대한 value가 존재함" << endl;
	}
	else {
		cout << "키 3에 대한 value가 존재하지 않음" << endl;
	}
	
	cout << "저장된 원소 개수 : " << um.size() << endl;	// 저장된 원소 개수 반환
	
	um.clear();	// 모든 원소 삭제

	// 비어 있는지 확인
	if (um.empty()) {
		cout << "맵이 비어있음" << endl;
	}
	else {
		cout << "맵이 비어있지 않음" << endl;
	}

	// 맵에 삽입하는 방법
	um.insert({ 1, 3 });				// 방법 1
	um.insert(pair<int, int>(2, 4));	// 방법 2
	um[3] = 6;							// 방법 3
	um[4] = 8;							// 방법 3
	um[5] = 10;							// 방법 3
	um[6] = 12;							// 방법 3
	um[7] = 14;							// 방법 3
	
	cout << "사용 중인 버킷의 개수 : " << um.bucket_count() << endl;	//사용 중인 해시 버킷 개수 반환
	cout << "적재율 : " << um.load_factor() << endl;	//현재 해시 테이블의 적재율을 반환(요소 수 / 버킷 수)
	um.rehash(20);	//최소 n개의 버킷을 가지도록 재할당(성능 최적화)

	cout << "사용 중인 버킷의 개수 : " << um.bucket_count() << endl;	//사용 중인 해시 버킷 개수 반환
	cout << "적재율 : " << um.load_factor() << endl;	//현재 해시 테이블의 적재율을 반환(요소 수 / 버킷 수)

}