/*
* https://school.programmers.co.kr/learn/courses/30/lessons/42587
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    queue<int> q;
    priority_queue<int> priorityQ;

    int i = 0;
    for (const int& priority : priorities) {
        q.push(i);
        priorityQ.push(priority);
        ++i;
    }

    while (true) {
        if (priorities[q.front()] < priorityQ.top()) {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        else {
            ++answer;
            if (q.front() == location) {
                break;
            }
            q.pop();
            priorityQ.pop();
        }
    }

    return answer;
}