// https://school.programmers.co.kr/learn/courses/30/lessons/43105

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = -1;

    vector<vector<int>> sums;

    sums.push_back(vector<int>(1, 7));

    for (int i = 1; i < triangle.size(); ++i) {
        sums.push_back(vector<int>(triangle[i].size()));
        for (int j = 0; j < sums[i].size(); ++j) {
            if (j == 0) {
                sums[i][j] = sums[i - 1][0] + triangle[i][0];
            }
            else if (j == sums[i].size() - 1) {
                sums[i][j] = sums[i - 1][sums[i - 1].size() - 1] + triangle[i][triangle[i].size() - 1];
            }
            else {
                sums[i][j] = max(sums[i - 1][j - 1] + triangle[i][j], sums[i - 1][j] + triangle[i][j]);
            }
            answer = max(answer, sums[i][j]);
        }
    }

    
    return answer;
}
