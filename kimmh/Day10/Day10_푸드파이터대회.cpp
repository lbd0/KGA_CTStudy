/*
	https://school.programmers.co.kr/learn/courses/30/lessons/134240
*/

#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string temp = "";
    for(int i = 1; i < food.size(); i ++) {
        for(int j =0; j < food[i]/2; j++) {
            temp += to_string(i);
        }
    }
    
    answer = temp;
    answer += "0";
    for(int i = temp.size() -1; i > -1; i--) {
        answer += temp[i];
    }
    
    return answer;
}