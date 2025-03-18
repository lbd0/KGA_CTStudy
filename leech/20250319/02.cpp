#include <string>
#include <stack>

bool solution(std::string s)
{
    std::stack<char> st;
    
    // 문자열의 처음이 ')'이면 false 반환
    if (s[0] == ')') return false;
    
    // 문자열의 길이만큼 반복
    for (int i = 0; i < s.length(); ++i)
    {
        // '('이면 스택에 넣기
        if (s[i] == '(') 
        {
            st.push(s[i]);
        }
        // ')'이면
        if (s[i] == ')')
        {
            // 스택이 비어있다면 false 반환
            if (st.empty()) return false;
            // 아니라면 스택에서 원소 빼기
            st.pop();
        }
    }
    
    // 스택이 비어있다면 괄호가 바르게 짝지어졌기에
    // 스택이 비었는지 판단하는 st.empty()를 반환
    return st.empty();
}