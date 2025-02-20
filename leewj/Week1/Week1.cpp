// https://school.programmers.co.kr/learn/courses/30/lessons/159994

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int j = 0;
    int k = 0;
    for (int i = 0; i < goal.size(); ++i) {
        if (goal[i] == cards1[j]) {
            ++j;
            continue;
        }
        else if (goal[i] == cards2[k]) {
            ++k;
            continue;
        }
        else {
            return "No";
        }
    }

    return "Yes";
}