// https://school.programmers.co.kr/learn/courses/30/lessons/181925

#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(vector<int> numLog) {
    stringstream answer;

    for (int i = 1; i < numLog.size(); ++i) {
        switch (numLog[i] - numLog[i - 1]) {
        case 1:
            answer << "w";
            break;
        case -1:
            answer << "s";
            break;
        case 10:
            answer << "d";
            break;
        case -10:
            answer << "a";
            break;
        default:
            break;
        }
    }

    return answer.str();
}