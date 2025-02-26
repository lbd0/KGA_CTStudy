/*
	https://school.programmers.co.kr/learn/courses/30/lessons/12911
	#include <bitset> 이라는것으로 간결한 코드로 풀 수 있다고 하였다 공부해보자
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;

    // 1의 갯수가 들어갈 것
    int k = 0;

    int copyN = n;

    while(true) {
        if(n % 2 == 1) {
            k++;
        }
        n/=2;    
        if(n == 0)
            break;
    } 

    while(true) {
        copyN++;
        int newN = copyN;
        int newK= 0;
        while(true) {
            if(newN % 2 == 1) {
                newK++;
            }
            newN/=2;    
            if(newN == 0)
                break;
        }
        if(newK == k) {
            return copyN;
        }
    }

    return answer;
}