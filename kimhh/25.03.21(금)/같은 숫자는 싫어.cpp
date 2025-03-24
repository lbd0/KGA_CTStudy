#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    stack<int> sta;
    for(int num:arr){
        if(sta.empty() || sta.top() != num){
            sta.push(num);
        }
    }
    
    while (!sta.empty()) {
        answer.push_back(sta.top());
        sta.pop();
    }
    reverse(answer.begin(), answer.end());

    return answer;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

stack<int> solution(vector<int> arr) 
{ 
    stack<int> answer;
    for(int num:arr){
        if(answer.empty() || answer.top() != num){
            answer.push(num);
        }
    }

    return answer;
}

#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

stack<int> solution(vector<int> arr) 
{ 
     stack<int> temp;
    for (int num : arr) {
        if (temp.empty() || temp.top() != num) {
            temp.push(num);
        }
    }
    
    // 반환용 스택: temp의 순서를 뒤집어 원래 순서를 유지하게 함
    stack<int> answer;
    while (!temp.empty()) {
        answer.push(temp.top());
        temp.pop();
    }
    return answer;
}
