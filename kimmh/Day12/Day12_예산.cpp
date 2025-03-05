/*
	https://school.programmers.co.kr/learn/courses/30/lessons/12982?language=cpp
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    
    sort(d.begin(), d.end());
    
    for(auto a : d) {
        if(budget - a >= 0) {
            answer++;
            budget -= a;
        }
        else {
            break;
        }
    }
    
    return answer;
}