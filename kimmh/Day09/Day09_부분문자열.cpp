/*
	https://school.programmers.co.kr/learn/courses/30/lessons/181842?language=cpp
*/	
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string str1, string str2) {
    
    if(str2.find(str1) == string::npos) {
        return 0;
    }
    else {
        return 1;
    }
    
}