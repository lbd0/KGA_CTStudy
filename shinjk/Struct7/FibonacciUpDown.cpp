#include<iostream>
#include<vector>

using namespace std;
vector<long long> dp;

long long fibonacciDown(int n)
{
	if (n <= 1)
	{
		return n;
	}

	if (dp[n] != -1)
	{
		return dp[n];
	}

	return dp[n] = fibonacciDown(n - 1) + fibonacciDown(n - 2);
}

long long fibonacciUp(int n)
{
	vector<long long>dp1(n + 1);
	dp1[0] = 0;

	if (n >= 1)
	{
		dp1[1] = 1;
	}

	for (int i = 2; i <= n; ++i)
	{
		dp1[i] = dp1[i - 1] + dp1[i - 2];
	}

	return dp1[n];
}


int main()
{
	int n = 50;
	dp.assign(n + 1, -1);
	cout << "Fibonacci(" << n << ") = " << fibonacciDown(n) << endl;

	return 0;
}