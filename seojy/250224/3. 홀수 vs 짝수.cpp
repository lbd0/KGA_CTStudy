/*

3. 홀수 vs 짝수
정수 리스트 num_list가 주어집니다. 
가장 첫 번째 원소를 1번 원소라고 할 때, 
홀수 번째 원소들의 합과 짝수 번째 원소들의 합 중 큰 값을 return 하도록 
solution 함수를 완성해주세요. 두 값이 같을 경우 그 값을 return합니다.

*/


#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int odd = 0;
    int even = 0;

    for(int i = 1; i <= num_list.size();i++)
    {
        if(i % 2 != 0)
        {
            odd += num_list.at(i - 1);
        }
        else
        {
            even += num_list.at(i - 1);
        }
    }
    
    if(odd > even)
    {
        answer = odd;
    }
    else
    {
        answer = even;
    }
    
    return answer;
}
