/***********분할 가능 배낭 문제***********
최대 무게 T까지 견딜 수 있는 배낭에 주어진 물건들의 가격 합이 최대가 되도록 물건을 담아주세요.
단, 물건은 원하는 형태로 얼마든지 분할할 수 있음.

입력
배낭의 최대 무게 T
물건들의 무게를 담은 벡터
물건들의 가격을 담은 벡터

출력
배낭에 담은 물건들의 전체 무게와 가격

예
8
{1, 2, 5, 9, 2, 3, 4 }
{10, 7, 15, 10, 12, 11, 5}

출력
전체 무게 : 8
전체 가격 : 40

문제 풀이 아이디어
- 물건들의 단위 무게 당 가격이 높은 순으로 담으면 됨!!!
***************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Obj// 물건 구조체 (무게, 가격, 단위 무게 당 가격)
{
	double weight;
	double price;
	double pricePerUnitWeight;

	Obj(double w, double p) : weight(w), price(p), pricePerUnitWeight(p / w) {}

	// sort() 알고리즘 사용 시 단위 무게 당 가격으로 내림차순 정렬
	inline bool operator< (const Obj& obj) const
	{
		return this->pricePerUnitWeight > obj.pricePerUnitWeight;
	}
};

void Bag(int weight, vector<Obj> objects)
{
	double TotalWeight = 0, TotalPrice = 0;

	sort(objects.begin(), objects.end());// 단위 무게 당 가격 순으로 내림차순 정렬

	auto currentObj = objects.begin();// objects 벡터 순회하기 위한 iterator

	do
	{
		TotalWeight += currentObj->weight;// 전체 무게에 현재 물건의 무게 더히기
		TotalPrice += currentObj->price;// 전체 가격에 현재 물건의 가격 더하기

		if (TotalWeight > weight)// 전체 무게가 최대 무게보다 크면
		{
			TotalWeight -= (TotalWeight - weight);// 큰 만큼 전체 무게에서 빼고 (전체 무게 == 최대 무게)
			TotalPrice -= (currentObj->pricePerUnitWeight * (TotalWeight - weight));// 뺀 무게 만큼의 가격을 전체 가격에서 뺌
		}

		if (TotalWeight == weight) break;// 전체 무게 == 최대 무게면 while문 탈출

		currentObj++;// 다음 물건으로 이동
	} while (true);

	cout << "전체 무게 : " << TotalWeight << endl;
	cout << "전체 가격 : " << TotalPrice << endl;
}


int main()
{
	int capacity = 8;
	vector<double> objW = { 1, 2, 5, 9, 2, 3, 4 };
	vector<double> objP = { 10, 7, 15, 10, 12, 11, 5 };

	vector<Obj> objects;

	for (int i = 0; i < objW.size(); i++)
	{
		objects.push_back(Obj(objW[i], objP[i]));// Obj 구조체에 무게, 가격 넣고 벡터에 넣기
	}

	Bag(capacity, objects);
}
