#include <vector>
#include <stack>
#include <algorithm>

std::vector<int> solution(std::vector<int> arr) 
{
    std::stack<int> st;
    std::vector<int> answer;
    
    // arr의 첫 원소를 스택에 넣기
    st.push(arr[0]);
    
    // arr의 원소를 하나씩 꺼냄
    for (const auto& a : arr)
    {
        // 스택의 최상위 데이터가 a가 아니면 스택에 넣기
        if (st.top() != a) st.push(a);
    }
    
    while (!st.empty())
    {
        // 스택의 최상위 데이터를 벡터에 넣기
        answer.push_back(st.top());
        // 스택에서 원소 빼주기
        st.pop();
    }
    
    // 벡터 뒤집기
    reverse(answer.begin(), answer.end());
    
    return answer;
}