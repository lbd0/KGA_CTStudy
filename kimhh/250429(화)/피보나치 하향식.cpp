#include <iostream>
#include <vector>

using namespace std;

// 메모이제이션(함수의 결과를 저장해두고, 같은 입력값으로 함수가 다시 호출될 때 저장된 결과를 재사용하는 기법)을 위한 배열
vector<long long> memo;

long long Fibonacci(int n) {
    // 기저 조건(재귀함수에서 재귀 호출을 멈추기 위한 조건)
    if (n == 0) return 0;
    if (n == 1) return 1;

    // 이미 계산된 값이면 반환
    if (memo[n] != -1) return memo[n];

    // 새로 계산해서 저장 후 반환
    memo[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
    return memo[n];
}

int main() {
    int n;
    cout << "n 입력: ";
    cin >> n;

    // -1로 초기화
    memo.assign(n + 1, -1);

    // 1부터 n까지 출력
    for (int i = 1; i <= n; ++i) {
        cout << "Fibonacci(" << i << ") = " << Fibonacci(i) << endl;
    }
    return 0;
}
