#include <iostream>
#include <vector>

using namespace std;

long long fibonacci(int n)
{
  vector<long long> dp(n+1);
  dp[0] = 0;

  //n이 1보다 클 때, dp[1] 의 초기값을 1로 준다.
  if(n >= 1)
    dp[1] = 1;

  // 0과 1은 초기값이 지정됨. 2부터 for문을 시작.
  for(int i = 2; i <= n; ++i)
  {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  return dp[n];
  
}

int main()
{
  int n = 50;
  cout<< " Fibonacci ( " << n << ") = " << fibonacci(n) << endl;
}
