#include <iostream>
#include <vector>

using namespace std;

vector<long long> dp1, dp2;

// 하향식
long long Dfibonacci(int n)
{
	if (n <= 1)
	{
		return n;
	}

	if (dp1[n] != -1)
	{
		return dp1[n];
	}

	return dp1[n] = Dfibonacci(n - 1) + Dfibonacci(n - 2);
}

// 상향식
long long Ufibonacci(int n)
{
	vector<long long> dp2(n + 1);
	dp2[0] = 0;

	if (n >= 1)
	{
		dp2[1] = 1;
	}

	for (int i = 2; i <= n; ++i)
	{
		dp2[i] = dp2[i - 1] + dp2[i - 2];
	}

	return dp2[n];
}

int main()
{
	int n = 10;
	dp1.assign(n + 1, -1);
	cout << "하향식 피보나치 : " << Dfibonacci(n) << endl;

	cout << "상향식 피보나치 : " << Ufibonacci(n) << endl;

	return 0;
}