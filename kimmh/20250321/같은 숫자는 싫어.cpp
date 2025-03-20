#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    queue<int> q;
    
    q.push(arr[0]);
    
    for(int temp : arr) {
        if(q.back() != temp) {
            q.push(temp);
        }
    }
    
    vector<int> answer;
    
    while(!q.empty()) {
        answer.push_back(q.front());
        q.pop();
    }

    return answer;
}