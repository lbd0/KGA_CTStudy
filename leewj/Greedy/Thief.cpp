// https://school.programmers.co.kr/learn/courses/30/lessons/42862

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for (int i = 0; i < lost.size(); ++i) {
        for (int j = 0; j < reserve.size(); ++j) {
            if (lost[i] == reserve[j]) {
                lost[i] = -1;
                reserve[j] = -1;
                continue;
            }
        }
    }

    answer -= lost.size();

    int j = 0;
    for (int i = 0; i < lost.size(); ++i) {
        if (lost[i] == -1) {
            ++answer;
            continue;
        }
        while (reserve[j] < lost[i] - 1) {
            ++j;
            if (j >= reserve.size()) {
                j = reserve.size() - 1;
                reserve[j] = 999;
                break;
            }
        }
        if (reserve[j] <= lost[i] + 1) {
            ++answer;
            reserve[j++] = -1;
        }
    }

    return answer;
}