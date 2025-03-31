#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

template<typename pair1,typename pair2>
void print_umap1(unordered_map<pair1, pair2>umap)//unordered_map 키, 값 출력
{
	for (auto& iter : umap)
	{
		cout << iter.first << " : " << iter.second << " ";

	}
	cout << endl;
}

template<typename pair1, typename pair2>
void print_key_as_value_map1(unordered_map<pair1,pair2>umap,pair1 key)//unordered_map 키를 통해 값 찾아내기
{
	if (umap.find(key) != umap.end())
	{
		cout << umap.find(key)->second;
	}
	cout << endl;
}

template<typename pair1, typename pair2>
void print_key_as_value_map2(unordered_map<pair1, pair2>umap, pair1 key)//unordered_map 키를 통해 값 찾아내기2
{
	try
	{
		cout << umap.at(key) << endl;//예외발생 예상지역
	}
	catch (const std::exception&)
	{
		cout << "없음" << endl;//예외처리 코드
	}
}


//int main()
//{
//	unordered_map<int, int>um;
//
//	um.insert({ 1,3 });//키 1, 값 3 삽입
//	um.insert(pair<int, int>(2, 4));//키2, 값 4 삽입
//	um[3] = 6;//키3, 값 6 삽입
//
//	print_umap1(um);//전부 프린트
//
//	cout << endl;
//
//	cout << "키가 3인 것의 값 : ";
//	print_key_as_value_map1(um, 3);//키 3에 해당하는 값 출력
//
//	print_key_as_value_map2(um, 3);// 동일
//
//	cout << um[3] << endl;
//	cout << um[4] << endl;
//
//	cout << "키가 4인 것의 값 : ";
//	print_key_as_value_map1(um, 4);//키 4에 해당하는 값 출력
//
//	print_key_as_value_map2(um, 4);//동일
//
//	um.erase(3);//키 3 제거
//
//	if (um.count(3))//3에 대응하는 값 있으면 true
//	{
//		cout << "키 3에 대한 값 존재함" << endl;
//	}
//	else
//	{
//		cout << "키 3에 대한 값 존재하지 않음" << endl;
//	}
//
//	cout << "저장된 원소의 갯수 : " << um.size() << endl;//저장된 원소의 갯수
//
//	um.clear();//삭제
//
//	if (um.empty())//비어있는지 여부
//	{
//		cout << "비어있음" << endl;
//	}
//	else
//	{
//		cout << "있음" << endl;
//	}
//
//	um.insert({ 1,3 });//위 동일
//	um.insert(pair<int, int>(2, 4));//위 동일
//	um[3] = 6;//위 동일
//	um[4] = 8;//키4, 값 8
//	um[5] = 10;//키5, 값 10
//
//
//	cout << "사용 중인 버킷의 갯수 : " << um.bucket_count() << endl;//사용 중인 버킷 갯수 반환
//	cout << "적재율 : " << um.load_factor() << endl;//적재율 반환
//
//	um.rehash(20);//20개의 버킷을 사용하도록 강제 지정
//	cout << "사용 중인 버킷의 갯수 : " << um.bucket_count() << endl;
//	cout << "적재율 : " << um.load_factor() << endl;
//
//}