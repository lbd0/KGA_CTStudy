/*
3. 정수 찾기
정수 리스트 num_list와 찾으려는 정수 n이 주어질 때, num_list안에 n이 있으면 1을 없으면 0을 return하도록 solution 함수를 완성해주세요.
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list, int n) {
    int answer = 0;
    
    for(int num : num_list)
    {
        if(num == n)
        {
            answer = 1;
            return answer;
        }
    }
    
    answer = 0;
    
    return answer;
}
