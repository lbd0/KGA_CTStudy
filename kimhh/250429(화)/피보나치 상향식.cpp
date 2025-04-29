#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "n 입력: ";
    cin >> n;

    // n이 0이나 1일 때를 처리
    if (n == 0) {
        cout << "Fibonacci(0) = 0" << endl;
        return 0;
    }
    if (n == 1) {
        cout << "Fibonacci(1) = 1" << endl;
        return 0;
    }

    // 피보나치 값을 저장할 배열
    vector<long long> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    // 반복문으로 2부터 n까지 계산
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // 1부터 n까지 출력
    for (int i = 1; i <= n; ++i) {
        cout << "Fibonacci(" << i << ") = " << dp[i] << endl;
    }

    return 0;
}
