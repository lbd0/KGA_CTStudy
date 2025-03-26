#include<string>
#include <iostream>
#include <queue>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    queue<char> q;
    
    for(auto c : s) {
        if(q.empty()) {
            if(c == ')') {
                return false;
            }
            q.push(c);
            continue;
        }
        
        if(c == '(') {
            q.push(c);
        }
        else {
            if(q.front() == '(') {
                q.pop();
            }
            else {
                return false;
            }
        }
        
    }
    
    if(!q.empty()) {
        return false;
    }
    
    
    return answer;
}