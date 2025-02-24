문제 설명
연산 ⊕는 두 정수에 대한 연산으로 두 정수를 붙여서 쓴 값을 반환합니다. 예를 들면 다음과 같습니다.

12 ⊕ 3 = 123
3 ⊕ 12 = 312
양의 정수 a와 b가 주어졌을 때, a ⊕ b와 2 * a * b 중 더 큰 값을 return하는 solution 함수를 완성해 주세요.

단, a ⊕ b와 2 * a * b가 같으면 a ⊕ b를 return 합니다.

제한사항
1 ≤ a, b < 10,000
입출력 예
a	b	result
2	91	364
91	2	912
입출력 예 설명
입출력 예 #1

a ⊕ b = 291 이고, 2 * a * b = 364 입니다. 둘 중 더 큰 값은 364 이므로 364를 return 합니다.
입출력 예 #2

a ⊕ b = 912 이고, 2 * a * b = 364 입니다. 둘 중 더 큰 값은 912 이므로 912를 return 합니다.

#include <iostream>
#include <string>

using namespace std;

int solution(int a, int b) {
    int answer = 0;

    string A = to_string(a); // int를 string으로 변경하는 to_string
    string B = to_string(b);

    if (stoi(A + B) >= 2 * a * b) {
        answer = stoi(A + B); // string을 int로 변경하는 stoi
    }
    else {
        answer = 2 * a * b;

    }

    return answer;
}

int main(void) {

    int n1, n2;

    cin >> n1 >> n2;

    cout << solution(n1, n2);

    return 0;
}