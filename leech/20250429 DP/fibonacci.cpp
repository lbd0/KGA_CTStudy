#include <iostream>
#include <vector>

using namespace std;

vector<long long> dp1;

// 피보나치 하향식 (재귀)
long long fibonacci_down(int n)
{    
    // n이 1보다 작거나 같을 경우 재귀 X
    if (n <= 1) return n;
    
    // 해당 인덱스에 이미 계산된 값이 있으면 반환
    if(dp1[n] != -1)
    {
        return dp1[n];
    }
    
    // 계산한 값을 저장 후 반환
    return dp1[n] = fibonacci_down(n - 1) + fibonacci_down(n - 2);
}

// 피보나치 상향식
long long fibonacci_up(int n)
{
    vector<long long> dp(n + 1);
    dp[0] = 0;
    
    // n이 1보다 클 때, 초기값을 1로 설정
    if (n >= 1) dp[1] = 1;
    
    // 0과 1은 초기값이 지정되어 2부터 시작
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    return dp[n];
}

int main() 
{
    int n = 50;
    
    dp1.assign(n + 1, -1);
    // 하향식
    cout << "fibonacci_down -> " << fibonacci_down(n) << endl;
    
    // 상향식
    cout << "fibonacci_up -> " << fibonacci_up(n) << endl;

    return 0;
}
