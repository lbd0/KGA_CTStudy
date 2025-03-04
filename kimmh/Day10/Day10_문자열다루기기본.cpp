/*
	https://school.programmers.co.kr/learn/courses/30/lessons/12918?language=cpp
*/

#include <string>
#include <vector>
#include <iostream>
#include <cctype>
using namespace std;

bool solution(string s) {
    bool answer = true;
    
    if(s.size() == 4 || s.size() == 6) {
        for(char sword : s) {
            if(isdigit(sword) == 0) 
            {
                return false;
            }
        }
    }
    else {
        return false;
    }
    
    return answer;
}