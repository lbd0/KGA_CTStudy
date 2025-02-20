/*
    https://school.programmers.co.kr/learn/courses/30/lessons/12912?language=cpp
*/

#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;

    if (a == b) {
        return a;
    }

    if (a > b) {
        for (int i = b; i <= a; i++) {
            answer += i;
        }
    }
    else {
        for (int i = a; i <= b; i++) {
            answer += i;
        }
    }

    return answer;
}