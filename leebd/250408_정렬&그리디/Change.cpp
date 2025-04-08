/************거스름돈****************
마트에서 계산을 하는 점원이 되었다.
손님에게 거슬러줘야할 돈이 N원일 때 거슬러줘야 할 동전의 최소 개수를 구하라. 이때
거스름돈으로 사용할 동전은 500원, 100원, 50원, 10원으로 무한히 존재하고, N은 10의 배수로 가정

입력 : 거스름돈 N
출력 : 동전의 최소 개수

예 1
입력 : 1,460	
출력 : 8

예 2
입력 : 1,890
출력 : 11

문제 풀이 아이디어
- 큰 가격의 동전부터 주면 최소한의 개수로 줄 수 있음!
- 거스름돈으로 사용할 동전을 내림차순 정렬!
************************************/

#include <iostream>
#include <vector>

using namespace std;

int GetChange(int change)
{
	vector<int> moneys = { 500, 100, 50, 10 };			// 거스름돈으로 줄 수 있는 돈 내림차순 정렬 (*돈이 주어지는 문제라면 내림차순으로 정렬하면 됨)

	int cnt = 0;			// 동전 개수 저장할 변수

	auto money = moneys.begin();			// 거스름돈이 저장된 벡터를 순회할 iterator

	do
	{
		if (change == 0) break;			// 다 거슬러주면 반복문 탈출!

		if (change < *money)			// 동전이 남은 거스름돈보다 크면 다음 동전으로 이동
			money++;

		change -= *money;			// 동전의 가격만큼 거스름돈에서 빼기
		cnt++;								// 동전 개수 증가

	} while (true);

	return cnt;			// 최종 동전 개수 반환
}

int main()
{
	
	cout << GetChange(1460) << endl;
	cout << GetChange(1890) << endl;

}