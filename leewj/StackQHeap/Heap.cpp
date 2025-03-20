// https://school.programmers.co.kr/learn/courses/30/lessons/42628

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    priority_queue<int, vector<int>, greater<int>> maxDelete;
    priority_queue<int> minDelete;

    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;
    int count = 0;

    for (const string& val : operations) {
        if (val[0] == 'I') {
            int num = stoi(val.substr(2, val.length() - 2));
            max.push(num);
            min.push(num);
            ++count;
        }
        // 1 5
        else {
            if (count > 0) {
                if (val[2] == '1') {
                    maxDelete.push(max.top());
                    max.pop();
                    while (!max.empty() && !minDelete.empty() && max.top() == minDelete.top()) {
                        max.pop();
                        minDelete.pop();
                    }
                    --count;
                }
                else {
                    minDelete.push(min.top());
                    min.pop();
                    while (!min.empty() && !maxDelete.empty() && min.top() == maxDelete.top()) {
                        min.pop();
                        maxDelete.pop();
                    }
                    --count;
                }
            }
        }
    }

    if (count <= 0) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(max.top());
        answer.push_back(min.top());
    }

    return answer;
}
