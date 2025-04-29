#include <iostream>
#include <vector>

using namespace std;

vector<long long> dp1, dp2;

// �����
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

// �����
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
	cout << "����� �Ǻ���ġ : " << Dfibonacci(n) << endl;

	cout << "����� �Ǻ���ġ : " << Ufibonacci(n) << endl;

	return 0;
}