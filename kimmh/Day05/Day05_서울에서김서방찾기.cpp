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

    answer = "�輭���� " + to_string(addr - seoul.begin()) + "�� �ִ�";

    return answer;
}