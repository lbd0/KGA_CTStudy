/*
	https://school.programmers.co.kr/learn/courses/30/lessons/12934?language=cpp
*/

#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <cctype>

using namespace std;

long long solution(long long n) {
    long long answer = 0;

    if(long(sqrt(n)) * long(sqrt(n)) == n) {
        return (long(sqrt(n)) + 1) * (long(sqrt(n)) + 1);
    }
    else {
        return -1;
    }
    
    return answer;
}