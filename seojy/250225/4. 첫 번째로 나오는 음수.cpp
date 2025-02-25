/*
4. 첫 번째로 나오는 음수
정수 리스트 num_list가 주어질 때, 
첫 번째로 나오는 음수의 인덱스를 return하도록 
solution 함수를 완성해주세요. 음수가 없다면 -1을 return합니다.

*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    
    for(int i = 0; i < num_list.size();i++)
    {
        if(num_list.at(i) < 0)
        {
            answer = i;
            return answer;
        }
        
    }
    
    answer = -1;
    return answer;
    
}
