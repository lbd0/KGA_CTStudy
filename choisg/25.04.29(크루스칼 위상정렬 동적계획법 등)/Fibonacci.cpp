#include <iostream>
#include <vector>

using namespace std;

//바텀 업 방식
int fib_bottom_up(int n)
{
    vector<int> dp(n + 1);
    dp[0] = 0;
    if (n >= 1) dp[1] = 1;              

    for (int i = 2; i <= n; ++i)         // 2부터 누적
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}


//탑다운 방식
int fib_top_down(int n, vector<int>& memo)
{
    if (n <= 1) return n;                
    int& ref = memo[n];            // 참조로 받아서 메모이제이션
    if (ref != -1) return ref;           // 이미 계산된 값

    // 처음 계산하는 경우 재귀 호출
    ref = fib_top_down(n - 1, memo) + fib_top_down(n - 2, memo);
    return ref;
}

int fib_top_down(int n)
{
    vector<int> memo(n + 1, -1);   // -1은 미계산
    return fib_top_down(n, memo);
}


int main()
{

    int n = 50;
    cout  << fib_bottom_up(n) << '\n';
    cout  << fib_top_down(n) << '\n';
    return 0;
}
