/*
정수 l과 r이 주어졌을 때, l 이상 r이하의 정수 중에서 숫자 "0"과 "5"로만 
이루어진 모든 정수를 오름차순으로 저장한 배열을 return 하는 solution 함수를 
완성해 주세요.

만약 그러한 정수가 없다면, -1이 담긴 배열을 return 합니다.
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    int count=0;
    
    for(int i=l; i<=r;++i)
    {
        string temp = to_string(i);
        
        for(int k=0;k<temp.size();++k)
        {
            if(temp[k]!='0'&&temp[k]!='5')
            {
                ++count;
            }
        }
        if(count==0)
        {
            answer.push_back(stoi(temp));
        }
        count=0;
    }
    if(answer.empty()==1)
    {
        answer.push_back(-1);
    }
    return answer;
}