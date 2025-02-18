/*
* https://school.programmers.co.kr/learn/courses/30/lessons/12909
*/

#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<bool> stack;

    for (const char &val : s) {
        if (val == '(') {
            stack.push(true);
        }
        else if (val == ')') {
            if (stack.size() <= 0) {
                answer = false;
                break;
            }
            stack.pop();
        }
    }

    if (stack.size() > 0) {
        answer = false;
    }

    return answer;
}