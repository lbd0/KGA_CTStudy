/*
	https://school.programmers.co.kr/learn/courses/30/lessons/12917?language=cpp
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    return s;
}