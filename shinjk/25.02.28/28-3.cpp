/*
정수가 담긴 리스트 num_list가 주어질 때, num_list의 원소 중 짝수와 홀수의 개수를 
담은 배열을 return 하도록 solution 함수를 완성해보세요.
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    int odd=0;
    int even=0;
    
    for(int i=0;i<num_list.size();++i)
    {
        num_list[i]%2==0?++even:++odd;
    }
    answer.push_back(even);
    answer.push_back(odd);
    
    return answer;
}