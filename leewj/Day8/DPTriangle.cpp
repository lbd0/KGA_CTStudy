// https://school.programmers.co.kr/learn/courses/30/lessons/43105
// �� Ʋ�ȴ��� ��¥ ��
// �� �� �ߴµ� ��ǻ�Ͱ� ��û�ؼ� Ʋ�Ⱦ�ääääääääääääää������;Ȥ���Ӥ��ߵ�;��'������������;������

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<vector<long long>> sums(triangle.size());

    sums[0].push_back(triangle[0][0]);
    for (int i = 0; i < triangle.size() - 1; ++i) {
        for (int j = 0; j < triangle[i].size(); ++j) {
            sums[i + 1].push_back(sums[i][j] + triangle[i + 1][j]);
            sums[i + 1].push_back(sums[i][j] + triangle[i + 1][j + 1]);

        }
    }

    for (const vector<long long>& line : sums) {
        for (const long long val : line) {
            cout << val << " ";
        }
        cout << "\n";
    }

    long long max = -1;
    int line = sums.size() - 1;
    for (int i = 0; i < sums[line].size(); ++i) {
        if (sums[line][i] > max) {
            max = sums[line][i];
        }
    }

    return max;
}
