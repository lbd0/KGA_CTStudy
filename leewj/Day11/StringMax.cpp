// https://school.programmers.co.kr/learn/courses/30/lessons/181939

#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    string ab = to_string(a) + to_string(b);
    string ba = to_string(b) + to_string(a);

    return max(stoi(ab), stoi(ba));
}