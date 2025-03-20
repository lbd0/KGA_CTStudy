#include<string>
#include <iostream>
#include <queue>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    queue<char> q;
    string str ="";
    
    int count = 0;
    for(int n = 0; n < s.length();n++)
    {
       if(s.at(n) == '(')
       {
           q.push(s.at(n));    
       }
        else if(s.at(n) == ')')
        {
            if(q.front() == '(')
            {
                q.pop();
            }
            else
            {
                answer = false;
            }
        }
    }
    
    if(!q.empty())
        answer = false;
    
    
    return answer;
}
