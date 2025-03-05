/*
	https://school.programmers.co.kr/learn/courses/30/lessons/77884?language=cpp
*/

#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int count(int value) {
    vector<int> temp;
    
    for(int i =1; i <= sqrt(value); i++) {
        if(value % i == 0) {
            temp.push_back(i);
            if(i != value / i) {
                temp.push_back(value/i);
            }
        }
    }
    
    return temp.size();
}

int solution(int left, int right) {
    int answer = 0;
    
    for(int i = left; i <= right; ++i) {
        cout << count(i) << endl;
        if(count(i) % 2 == 0) {
            answer += i;
        }
        else {
            answer -= i;
        }
    }
    
    
    
    return answer;
}