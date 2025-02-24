/*
    https://school.programmers.co.kr/learn/courses/30/lessons/12919?language=cpp
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";

    auto addr = find(seoul.begin(), seoul.end(), "Kim");

    answer = "김서방은 " + to_string(addr - seoul.begin()) + "에 있다";

    return answer;
}