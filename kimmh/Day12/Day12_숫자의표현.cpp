/*
	https://school.programmers.co.kr/learn/courses/30/lessons/12924
	왜 자꾸 효율성 초과 뜨는지 확인해보니
	디버그를 위한 cout 때문이였다..
*/

#include <string>
#include <vector>
#include <iostream>


using namespace std;

int solution(int n) {
    int answer = 0;
    int startValue = 1;
    while(startValue <= n / 2 + 1) {
        int v = 0;
        for(int i = startValue; i < n;i++) {
            v += i;
            if(v == n) {
                answer++;
                break;
            }
            else if(v > n) {
                break;
            }
        }
        startValue++;
    }
    answer++;
    return answer;
}