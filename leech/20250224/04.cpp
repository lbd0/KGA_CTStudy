/*
Q. 배열 만들기 2

정수 l과 r이 주어졌을 때, l 이상 r이하의 정수 중에서 숫자 "0"과 "5"로만 이루어진 모든 정수를 오름차순으로 저장한 배열을 return 하는 solution 함수를 완성해 주세요.

만약 그러한 정수가 없다면, -1이 담긴 배열을 return 합니다.
*/

#include <vector>

std::vector<int> solution(int l, int r) {
    std::vector<int> answer;
    int temp, a;
    for(int i = l; i <= r; ++i) {
        temp = i;
        a = 1;
        while (temp > 0) {
            if (temp % 10 != 5 && temp % 10 != 0) {
                a = 0;
                break;
            }
            temp /= 10;
        }
        if (a) answer.push_back(i);
    }
    if (answer.size() == 0) answer.push_back(-1);
    return answer;
}