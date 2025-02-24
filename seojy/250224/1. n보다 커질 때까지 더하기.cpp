/*
1. n보다 커질 때까지 더하기
정수 배열 numbers와 정수 n이 매개변수로 주어집니다. 
numbers의 원소를 앞에서부터 하나씩 더하다가 
그 합이 n보다 커지는 순간 
이때까지 더했던 원소들의 합을 return 하는 solution 함수를 작성해 주세요.
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int n) {
    int answer = 0;
    
    for(int num : numbers)
    {
        if(answer > n)
        {
            break;
        }
        
        answer += num;
    }
    
    return answer;
}
