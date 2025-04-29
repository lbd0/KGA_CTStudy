#include <iostream>
#include <vector>

using namespace std;


long long fibonacci(int n) {
	vector<long long> dp(n + 1);
	dp[0] = 0;

	if (n >= 1) {
		dp[1] = 1;
	}

	for (int i = 2; i <= n; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}

int main() {

	int n = 100;
	//dp.assign(n + 1, -1);
	cout << "Fibonacci (" << n << ") : " << fibonacci(n) << endl;


	return 0;
}