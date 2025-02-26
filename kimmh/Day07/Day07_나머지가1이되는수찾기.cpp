/*
    https://school.programmers.co.kr/learn/courses/30/lessons/87389?language=cpp
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    
    while(true) {
        
        if(n % answer == 1)
            return answer;
        answer++;
    }
    
    return answer;
}