// https://school.programmers.co.kr/learn/courses/30/lessons/42748

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int FindK(const vector<int>& array, int i, int j, int k) {
    vector<int> cutArray(j - i + 1);

    for (int a = 0; a < j - i + 1; ++a) {
        cutArray[a] = array[i - 1 + a];
    }

    sort(cutArray.begin(), cutArray.end());

    return cutArray[k - 1];
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); ++i) {
        answer.push_back(FindK(array, commands[i][0], commands[i][1], commands[i][2]));
    }

    return answer;
}