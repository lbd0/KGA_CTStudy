#include <iostream>
#include <vector>


using namespace std;
vector<long long > dp;


// �Ǻ���ġ ����� ( ��� ���
long long fibonacci(int n) {

	if (n <= 1)
		return n;

	if (dp[n] != -1) {
		return dp[n];
	}

	//����� ���� �����ϸ鼭 ��ȯ
	return dp[n] = fibonacci(n - 1) + fibonacci(n - 2);

}



int main() {

	int n = 100;
	dp.assign(n + 1, -1);
	cout << "Fibonacci (" << n << ") : " << fibonacci(n) << endl;


	return 0;
}

