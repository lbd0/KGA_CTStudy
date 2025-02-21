/*
    https://school.programmers.co.kr/learn/courses/30/lessons/86051?language=cpp
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end());

    int answer = 0;

    for (int i = 0; i < 10; i++) {
        auto num = find(numbers.begin(), numbers.end(), i);
        if (num == numbers.end()) {
            answer += i;
        }
    }


    return answer;
}