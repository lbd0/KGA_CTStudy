/*
배열 arr가 주어집니다. 배열 arr의 각 원소는 숫자 0부터 9까지로 이루어져 있습니다. 
이때, 배열 arr에서 연속적으로 나타나는 숫자는 하나만 남기고 전부 제거하려고 합니다.
단, 제거된 후 남은 수들을 반환할 때는 배열 arr의 원소들의 순서를 유지해야 합니다. 
예를 들면,

arr = [1, 1, 3, 3, 0, 1, 1] 이면 [1, 3, 0, 1] 을 return 합니다.
arr = [4, 4, 4, 3, 3] 이면 [4, 3] 을 return 합니다.
배열 arr에서 연속적으로 나타나는 숫자는 제거하고 남은 수들을 return 하는 
solution 함수를 완성해 주세요.
*/

#include <vector>
#include <iostream>
#include<stack>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> stk;
    
    stk.push(arr[0]); //stk에 arr백터 0번째 원소 넣기
    
    for(int i=1;i<arr.size();++i) //1번째부터 arr크기미만까지 돌기
    {
        if(stk.top()!=arr[i])  //stk의 제일 위쪽 값과 현재 arr의 값이 같지않다면,
        {
             stk.push(arr[i]); //stk에 넣기
        }
    }

    for(int i=stk.size()-1;i>=0;--i) //0부터 stk.size()까지라고 생각하면됨.
    {
        answer.push_back(stk.top()); //answer에 stk 젤 윗값 넣어주기
        stk.pop(); //stk 젤 윗값 지우기
    }
    
    reverse(answer.begin(),answer.end()); //algorithm이용하여, answer벡터 처음부터 끝까지 뒤집기
    
    
    return answer;
}