/*
괄호가 바르게 짝지어졌다는 것은 '(' 문자로 열렸으면 반드시 짝지어서 ')' 
문자로 닫혀야 한다는 뜻입니다. 예를 들어

"()()" 또는 "(())()" 는 올바른 괄호입니다.
")()(" 또는 "(()(" 는 올바르지 않은 괄호입니다.
'(' 또는 ')' 로만 이루어진 문자열 s가 주어졌을 때, 
문자열 s가 올바른 괄호이면 true를 return 하고, 올바르지 않은 괄호이면 
false를 return 하는 solution 함수를 완성해 주세요.
*/

#include<string>
#include <iostream>
#include <queue>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int count=0; //무게 추 같은 느낌
    
    queue<char>q;
    
    for(int i=0;i<s.size();++i)
    {
        q.push(s[i]); // q에 s의 i번째 넣기
        if(s[i]=='(')
        {
            ++count; // 만약 (이면 count 1증가
        }
        else
        {
            --count; // 만약 )이면 count 1감소
        }
        
        if(count<0)
        {
            answer=false; // 만약 count가 음수라면 답 false로 바꾸고, for문 종료
            break;
        }
    }
    
    if(q.front()==')'||q.back()=='(')
    {
        answer=false; // 맨 앞이 )이거나 맨 뒤가 (이면 false(굳이 필요하진 않았을듯)
    }
    
    else if(count!=0)
    {
        answer=false; // 짝이 맞아야하니까 count가 양수여도 안됨.
    }

    return answer;
}