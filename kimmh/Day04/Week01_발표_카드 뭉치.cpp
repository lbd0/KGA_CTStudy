/*
	https://school.programmers.co.kr/learn/courses/30/lessons/159994
*/

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";

    while (true) {
        if (cards1.front() == goal.front()) {
            cards1.erase(cards1.begin());
            goal.erase(goal.begin());

            if (goal.size() == 0) {
                return "Yes";
            }
        }
        else if (cards2.front() == goal.front()) {
            cards2.erase(cards2.begin());
            goal.erase(goal.begin());

            if (goal.size() == 0) {
                return "Yes";
            }
        }
        else {
            return "No";
        }
    }

    return answer;
}