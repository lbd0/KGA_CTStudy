#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int left = 0;
    int right = 0;
    
    for(char a:s){
        if(a == '('){
            left += 1;
        }
        else if(a == ')'){
            right += 1;
        }
        
        if(left < right) { return false; }
    }
    
    return answer = (left == right) ? true : false;
}

////////////////////////////////////////////////////////////////////////////////

#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> sta;
    for(char c: s){
        if(c == '('){
            sta.push(c);
        }
        else{
            if(sta.empty()) { return false; }
            else { sta.pop(); }
        }
    }
    
    return answer = (sta.empty())? true: false;
}
