// https://school.programmers.co.kr/learn/courses/30/lessons/389478

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    vector<vector<int>> boxes(((n - 1) / w) + 1, vector<int>(w, 0));

    for (int i = 0; i < boxes.size(); ++i) {
        for (int j = 0; j < w; ++j) {
            if (i * w + j + 1 <= n) {
                if (i % 2 == 0) {
                    boxes[i][j] = i * w + j + 1;
                }
                else {
                    boxes[i][w - 1 - j] = i * w + j + 1;
                }
            }
        }
    }

    for (int i = 0; i < boxes.size(); ++i) {
        for (int j = 0; j < boxes[i].size(); ++j) {
            cout << boxes[i][j] << " ";
        }
        cout << "\n";
    }

    int i = (num - 1) / w;
    int j = i % 2 == 0 ? (num - 1) % w : w - ((num - 1) % w) - 1;

    while (i < boxes.size()) {
        if (boxes[i][j] == 0) {
            break;
        }
        ++i;
        ++answer;
    }

    return answer;
}