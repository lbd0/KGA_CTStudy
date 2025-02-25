/*
1.n 번째 원소까지
정수 리스트 num_list와 정수 n이 주어질 때, 
num_list의 첫 번째 원소부터 n 번째 원소까지의 모든 원소를 담은 리스트를
 return하도록 solution 함수를 완성해주세요.
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> answer;
    
    for(int i = 0; i < n;i++)
    {
        answer.push_back(num_list.at(i));
    }
    
    return answer;
}
