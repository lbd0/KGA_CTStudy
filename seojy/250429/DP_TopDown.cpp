#include <iostream>
#include <vector>

using namespace std;
vector<long long> dp;

long long fibonacci(int n)
{
  // n이 1보다 작거나 같을 경우에는 무조건 n(1) 을 반환
  // 재귀가 성립되지 못하고 함수를 빠져나가게 된다.

  if(n<=1)
    return n;

  // 해당 인덱스에 이미 계산된 값이 있다면 반환
  if(dp[n] != -1)
  {
    return dp[n];
  }

  // 계산한 값을 저장하면서 반환 
  return dp[n] = fibonacci(n-1)+fibonacci(n-2);
}

int main()
{
  int n = 50;
  // dp 배열의 크기 : n + 1 / -1 로 초기화해준다.
  dp.assign(n + 1, - 1);

  cout<< " Fibonacci ( " << n << ") = " << fibonacci(n) << endl;
}
