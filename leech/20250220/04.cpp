/*
Q. 문자열 곱하기

문자열 my_string과 정수 k가 주어질 때,
my_string을 k번 반복한 문자열을 return 하는
solution 함수를 작성해 주세요.
*/

#include <vector>
#include <cmath>

int solution(std::vector<int> num_list) {
    int add = 0, mul = 1;

    for (int a : num_list)
    {
        add += a;
        mul *= a;
    }

    return mul < pow(add, 2) ? 1 : 0;
}