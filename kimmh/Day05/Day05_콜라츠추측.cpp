/*
    https://school.programmers.co.kr/learn/courses/30/lessons/12943
*/

#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    /*
        왜 long를 썼는가 ?
        int의 범위는 -2,147,483,648 ~ 2,147,483,647 이다
        3번째 테스트 케이스인 626331의 진행을 보면 
        626331 -> 1878994-> ... -> 2139935758 -> 1069967879 -> 3209903638 -> 1604951819 -> 4814855458 ... 와같이 범위를 넘겨버려 다른 값이 도출되는 경우가 생긴다
    */ 
    
    long num2 = num;

    for (int i = 0; i < 500; i++) {
        if (num2 == 1) {
            return answer;
        }
        answer++;
        if (num2 % 2 == 0) {
            num2 /= 2;
        }
        else {
            num2 = num2 * 3 + 1;
        }
    }

    return -1;

}