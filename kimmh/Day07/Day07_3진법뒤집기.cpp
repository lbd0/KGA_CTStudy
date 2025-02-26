/*
    https://school.programmers.co.kr/learn/courses/30/lessons/68935

*/

#include <string>
#include <vector>

using namespace std;

string Ternary(int intValue) {
    string tempString = "";

    while (intValue != 0) {
        tempString.insert(0, to_string(intValue % 3));
        intValue /= 3;
    }

    int tempStringLength = tempString.length();

    return tempString;
}

int solution(int n) {
    int answer = 0;
    string ternary = Ternary(n);
    
    for(int i = 0; i < ternary.size(); i++) {
        if(ternary[i] == '1') {
            int add = 1;
            for(int j = 0; j < i; j++){
                add *= 3;
            }
            answer += add * 1;
        }
        else if(ternary[i] == '2') {
            int add = 1;
            for(int j = 0; j < i; j++){
                add *= 3;
            }
            answer += add * 2;
        }
    }
    
    
    
    return answer;
}