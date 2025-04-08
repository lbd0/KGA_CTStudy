#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> price = { 500,100,50,10 }; //동전 벡터

	int pay;
	cin >> pay; //지불한 돈
	int count = 0; //동전 갯수

	for (int i = 0; i < price.size(); ++i)
	{
		int temp = pay / price[i]; //현재 돈에서 가격으로 나누기
		count += temp; //동전 갯수 증가
		pay -= temp*price[i]; //현재 돈 갱신
	}


	cout << count;

}

/*
int pay;
cin >> pay; //돈 입력

int crane;
crane = pay / 500; //500원 갯수
pay -= crane * 500; //500원 제외된 금액 바꿔주기

int sunshin;
sunshin = pay / 100; //100원 갯수
pay -= sunshin * 100; //500,100원 제외된 금액 바꿔주기

int rice;
rice = pay / 50; //50원 갯수
pay -= rice * 50; //500,100,50원 제외된 금액 바꿔주기

int pagoda;
pagoda = pay / 10; //10원 갯수

int count = crane + sunshin + rice + pagoda;
cout << count; //모든 동전 갯수
}
*/