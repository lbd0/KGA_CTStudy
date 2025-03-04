// https://school.programmers.co.kr/learn/courses/30/lessons/181938

#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int ab = stoi(to_string(a) + to_string(b));
    int ab2 = 2 * a * b;

    return max(ab, ab2);
}