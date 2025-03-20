#include <string>
#include <queue>

bool solution(std::string s)
{
    std::queue<char> que;
    
    // 문자열의 처음이 ')'이면 false 반환
    if (s[0] == ')') return false;
    
    // 문자열의 길이만큼 반복
    for (int i = 0; i < s.length(); ++i)
    {
        // '('이면 큐에 넣기
        if (s[i] == '(') 
        {
            que.push(s[i]);
        }
        // ')'이면
        if (s[i] == ')')
        {
            // 큐가 비어있다면 false 반환
            if (que.empty()) return false;
            // 아니라면 큐에서 원소 빼기
            que.pop();
        }
    }
    
    // 큐가 비어있다면 괄호가 바르게 짝지어졌기에
    // 큐가 비었는지 판단하는 empty()를 반환
    return que.empty();
}
