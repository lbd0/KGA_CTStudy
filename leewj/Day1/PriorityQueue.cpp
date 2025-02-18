/*
* https://school.programmers.co.kr/learn/courses/30/lessons/42626
*/

#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;



int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> priorityQ;

    for (const int &scov : scoville) {
        priorityQ.push(scov);
    }

    while (priorityQ.top() < K) {
        if (priorityQ.size() <= 1) {
            answer = -1;
            break;
        }

        int tmp = priorityQ.top();
        priorityQ.pop();

        tmp += priorityQ.top() * 2;
        priorityQ.pop();
        priorityQ.push(tmp);
        ++answer;
    }

    return answer;
}