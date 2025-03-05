/*
	https://school.programmers.co.kr/learn/courses/30/lessons/147355?language=cpp
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    int psize = p.size();
    
    vector<string> temp;
    int count = 0;
    while(count + psize <= t.size()) {
        temp.push_back(t.substr(count, psize));
        cout << t.substr(count, psize) << endl;
        count++;
    }
    
    for(auto a : temp) {
        if(stoull(a) <= stoull(p)) {
            answer++;
        }
    }
    
    return answer;
}