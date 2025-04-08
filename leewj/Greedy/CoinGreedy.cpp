#include <iostream>
#include <string>
#include <vector>

int main(int argc, char** argv) {
	std::vector<int> coin = { 500, 100, 50, 10 };

	int n;

	std::cin >> n;

	int count = 0;

	for (int val : coin) {
		count += n / val;
		n %= val;
	}

	std::cout << count;

	return 0;
}

/*
***********거스름돈****************
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
***********************************
*/