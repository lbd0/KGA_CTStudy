// https://school.programmers.co.kr/learn/courses/30/lessons/12909

#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    stack<bool> stack;

    for (const char &val : s) { // 스트링 안에 들어있는 문자를 하나씩 순회
        if (val == '(') { // 괄호 시작일 경우 스택에 푸쉬
            stack.push(true);
        }
        else if (val == ')') { // 괄호 종료일 경우
            if (stack.size() <= 0) { // 스택이 비었다 = 괄호가 시작하지 않았다.
                answer = false;
                break; // 괄호 시작 안했는데 닫아버리면 올바르지 않은 괄호
            }
            stack.pop(); // 괄호 종료일 경우 스택에 푸쉬
        }
    }

    if (stack.size() > 0) { // 문자열 다 돌았는데 괄호를 열고 닫지 않았을 경우 올바르지 않은 괄호
        answer = false;
    }

    return answer;
}